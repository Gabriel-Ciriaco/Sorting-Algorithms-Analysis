<div align="center">
	<h1>Sorting Algorithms Analysis
		<h4>Uma análise empírica da complexidade dos algoritmos de ordenação.</h4>
</div>

---

Este repositório contém uma implementação de vários algoritmos de ordenação, incluindo:

- Bubble Sort
- Quick Sort (com várias versões)
- Merge Sort
- Heap Sort
- Selection Sort
- Shell Sort

Além disso, este projeto possui scripts de análise e geração de relatórios sobre o desempenho desses algoritmos.

## Estrutura do Repositório

- **algorithms/**: Contém os arquivos `.c` com a implementação dos algoritmos de ordenação.
- **export.h**: Arquivo de cabeçalho para exportação de funções.
- **main.h**: Cabeçalho principal do programa.
- **sort_algorithms.h**: Cabeçalho contendo as declarações dos algoritmos de ordenação.
- **relatorio/**: Contém o arquivo `.csv` com os dados gerados pelos testes e o Jupyter Notebook que faz a análise empírica.

## Como Compilar

Este projeto foi desenvolvido utilizando C, e você pode compilar as bibliotecas dinâmicas necessárias para rodar os algoritmos em diferentes sistemas operacionais. Elas também podem ser encontradas prontas para download em [Releases](releases).

### No Windows (Gerar `.dll`)

Para compilar o código em uma biblioteca dinâmica `.dll` no Windows, siga os seguintes passos:

1. Abra o terminal e navegue até a pasta onde os arquivos `.c` estão localizados.
2. Compile os arquivos usando o `gcc` com a opção `-shared` para criar uma biblioteca dinâmica. Execute o seguinte comando:

   ```bash
   gcc -shared -o C_Algorithms_Library.dll algorithms/*.c -I. -fPIC
   ```
    Explicação dos parâmetros:

    * `-shared`: Instrução para gerar uma biblioteca compartilhada (DLL).
    * `-o C_Algorithms_Library.dll`: Define o nome do arquivo de saída como `C_Algorithms_Library.dll`.
    * `-I.`: Adiciona o diretório atual como caminho para os arquivos de cabeçalho.
    * `-fPIC`: Gera código independente de posição, necessário para bibliotecas compartilhadas.

3. O arquivo `C_Algorithms_Library.dll` será gerado na pasta onde você executou o comando.

### No Linux (Gerar `.so`)

Para compilar o código em uma biblioteca compartilhada `.so` no Linux, basta seguir os seguintes passos:

1. Abra o terminal e navegue até a pasta onde os arquivos `.c` estão localizados.

2. Compile os arquivos utilizando o `gcc` da seguinte maneira:

   ```bash
   gcc -shared -o C_Algorithms_Library.so algorithms/*.c -I. -fPIC
   ```

   Explicação dos parâmetros:

   * `-shared`: Gera uma biblioteca compartilhada (SO).
   * `-o C_Algorithms_Library.so`: Define o nome do arquivo de saída como `C_Algorithms_Library.so`.
   * `-I.`: Adiciona o diretório atual como caminho para os arquivos de cabeçalho.
   * `-fPIC`: Gera código independente de posição, necessário para bibliotecas compartilhadas.

3. O arquivo `C_Algorithms_Library.so` será gerado na pasta onde você executou o comando.

### Uso da Biblioteca

Uma vez gerada a biblioteca (`.dll` ou `.so`), você pode usá-la no seu código principal. Para testar os algoritmos, você deve carregar a biblioteca dinamicamente e usar as funções de ordenação que ela exporta.

## Relatório e Análise

* O arquivo de dados gerado pelos testes de desempenho pode ser encontrado na pasta `relatorio` em formato `.csv`.
* O Jupyter Notebook que analisa o desempenho dos algoritmos com base nos dados do `.csv` também está disponível. Você pode abrir o notebook diretamente no Google Colab [![Open in Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/1IXtnTpqqYNJm8TmE5U8GY-qFDlFUxvbp?usp=sharing) ou executar localmente.


## Author ✨

<table>
	<tr>
		<td align="center">
			<a href="https://github.com/Gabriel-Ciriaco">
				<img src="https://avatars.githubusercontent.com/u/66225865" width="100px;" alt=""/>
				<br>
				<sub>
					<b>Gabriel C. de Carvalho</b>
				</sub>
		</td>
		<td align="center">
			<a href="https://github.com/Carol-Nunes">
				<img src="https://avatars.githubusercontent.com/u/18383333" width="100px;" alt=""/>
				<br>
				<sub>
					<b>Caroline N. Araujo</b>
				</sub>
		</td>
	</tr>
</table>

## Contribuição

Se você quiser contribuir para este projeto, sinta-se à vontade para fazer um fork, enviar um pull request com suas melhorias ou abrir uma *issue*, caso tenha alguma dúvida ou sugestão!

## Licença

Este projeto está licenciado sob a Licença GNU General Public License v3.0 - veja o arquivo [LICENSE](LICENSE) para mais detalhes.
