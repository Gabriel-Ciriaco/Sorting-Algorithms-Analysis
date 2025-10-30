#ifndef EXPORT_H
#define EXPORT_H

#ifdef _WIN32
  #ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
  #else
    #define DLL_EXPORT __declspec(dllimport)
  #endif
#else
  #define DLL_EXPORT
#endif // _WIN32

#endif // EXPORT_H
