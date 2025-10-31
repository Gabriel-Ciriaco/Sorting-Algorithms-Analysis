from functools import wraps
from typing import Optional, Union, Callable
import warnings

import ctypes
from ctypes import c_int, c_double, POINTER

import numpy as np


class Sorting_Algorithms:

    def __init__(self, dll_path):
        self.lib = ctypes.CDLL(dll_path)

        # Same as typedef void (*sort_function)(int*, int, int)
        self.SORT_FUNC = ctypes.CFUNCTYPE(None, POINTER(c_int), c_int, c_int)
        
        self.funcs = {
            "run_sort_function": ([self.SORT_FUNC, POINTER(c_int), c_int, c_int], c_double),
            "quick_sort": ([POINTER(c_int), c_int, c_int], None),
            "central_quick_sort": ([POINTER(c_int), c_int, c_int], None),
            "merge_sort": ([POINTER(c_int), c_int, c_int], None),
            "bubble_sort": ([POINTER(c_int), c_int, c_int], None),
            "better_bubble_sort": ([POINTER(c_int), c_int, c_int], None),
            "insertion_sort": ([POINTER(c_int), c_int, c_int], None),
            "selection_sort": ([POINTER(c_int), c_int, c_int], None),
            "heap_sort": ([POINTER(c_int), c_int, c_int], None),
        }

        self.load_functions()

    '''Functions signatures for documentation'''
    def run_sort_function(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None,
        sort_algorithm: Optional[Union[Callable, ctypes._CFuncPtr]] = None
    ) -> float:
        ...

    def quick_sort(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None
    ) -> np.ndarray[tuple[int], np.int32]:  
        ...

    def central_quick_sort(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None
    ) -> np.ndarray[tuple[int], np.int32]:  
        ...

    def merge_sort(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None
    ) -> np.ndarray[tuple[int], np.int32]:  
        ...

    def bubble_sort(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None
    ) -> np.ndarray[tuple[int], np.int32]:  
        ...

    def better_bubble_sort(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None
    ) -> np.ndarray[tuple[int], np.int32]:  
        ...

    def insertion_sort(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None
    ) -> np.ndarray[tuple[int], np.int32]:  
        ...

    def selection_sort(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None
    ) -> np.ndarray[tuple[int], np.int32]:  
        ...

    def heap_sort(
        self,
        array: np.ndarray[tuple[int], np.int32],  
        ini: int = 0,
        fim: Optional[int] = None
    ) -> np.ndarray[tuple[int], np.int32]:  
        ...


    def load_functions(self):
        for alg_name, (argtypes, restype) in self.funcs.items():
            c_function = getattr(self.lib, alg_name)
            c_function.argtypes = argtypes
            c_function.restype = restype

            setattr(self, alg_name, self.__wrapper_functions__(c_function))


    def __wrapper_functions__(self, function: ctypes._CDLLFuncPointer):
        @wraps(function) # Preserves the information about "function"
        def wrapper(array: np.ndarray = None,
                    ini: int = 0,
                    fim: Optional[int] = None,
                    sort_algorithm: Optional [ctypes._CFuncPtr]=None
                ) -> (np.ndarray | float):

            if not isinstance(array, np.ndarray):
                raise TypeError("Array must be a NumPy ndarray.")

            if array.dtype != np.int32:
                warnings.warn(
                    message=f"Array dtype is {array.dtype}, converting to int32 for C function compatibility.",
                    category=UserWarning
                )

                temp_array = array.astype(np.int32, copy=False)
            else:
                temp_array = array

            if not temp_array.flags['C_CONTIGUOUS']:
                temp_array = np.ascontiguousarray(temp_array)
            
            if fim is None:
                fim = len(temp_array) - 1
            
            # Convert the NumPy array to C pointer (ctypes)
            array_pointer = temp_array.ctypes.data_as(POINTER(c_int))

            if function.__name__ == "run_sort_function":
                if sort_algorithm is None:
                    raise ValueError("Must provide sort_algorithm when calling run_sort_function")

                lib_sort_algorithm = getattr(self.lib, sort_algorithm.__name__)
                
                callback = self.SORT_FUNC(lib_sort_algorithm)

                return float(function(callback, array_pointer, ini, fim))
            else:
                function(array_pointer, ini, fim)

            if temp_array is not array:
                np.copyto(array, temp_array)

            return array

        return wrapper