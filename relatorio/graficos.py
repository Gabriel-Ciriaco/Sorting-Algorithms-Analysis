import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('testes_ordenacao.csv')

plt.figure(figsize=(10,6))

algoritmos = df['Algoritmo'].unique()

for algoritmo in algoritmos:
    df_algo = df[df['Algoritmo'] == algoritmo]
    plt.plot(df_algo['NumeroEntradas'], df_algo['Tempo'], label=algoritmo, marker='o')


plt.title('Análise dos Algoritmos de Ordenação')
plt.xlabel('Número de Entradas')
plt.ylabel('Tempo (segundos)')
plt.legend(title='Análise dos Algoritmos de Ordenação')

plt.grid(True)
plt.show()