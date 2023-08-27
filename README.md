# Trabalho de Aquecimento: Top k elementos
# introdução
<p align="justify">
		O algoritmo aqui apresentado tem como objetivo guardar todas as palavras de arquivos de entrada "inputX.txt", sendo X o número do input, em uma tabela hash e depois fazer o uso de um heap mínimo para descobrir as k palavras que mais aparecem nos textos dos inputs.
</p>
<p align="justify">
	 O heap deve ser usado de modo que ele primeiro é carregado com um vetor que armazena k palavras e faz uma operação de heap no vetor pra fazer com que o valor mínimo fique na posição 0. A cada inserção no heap, após ele ser carregado a primeira vez, a operação pra achar o valor mínimo é realizada novamete. Essa operação é feita com base na frequencia em que as palavras aparecem no texto.
</p>
<p align="justify">
	Na classe tabelaHash, há um método que faz com que cada palavra da hash seja comparada com o mínimo do heap por meio da função do heap "addPalavra(Palavra p)", que coloca a palavra p na posição zero do heap caso ela seja maior que o mínimo e faz a operação de heap novamente. Dessa forma, após toda tabela ser percorrida, apenas as palavras com as maiores frequências permanescerão no heap, de modo que elas serão as k palavras mais frequentes do texto.
</p>

<p align="justify">
	Para se carregar a tabela hash com as palavras dos inputs e mostrar as palavras mais frequentes de cada input, é utilizado um for que leva em conta a constante inteira "numberOfFiles" pra ler todos os inputs, aramazenar suas palavras na hash e mostrar as k palavras mais frequentes. O k, que é o tamanho do heap, no código é a variável global definida no arquivo "hash.hpp" como "tamHeap".
</p>

# Modo como palavras são armazenadas na hash
<p align="justify">
	As palavras são armazenadas na hash em lowercase e com os acentos, porem certas palavras, precedias, ou sucedidas por caracteres especiais, permanecem com esses caracteres ao serem armazenados na hash. Alguns desses casos são os caracteres "”" e "—", que são representados nas palavras da hash como "⠝" e "⠴". Como essas palavras são contadas como distintas das mesmas palavras sem os caracteres especiais, pode haver uma subcontagem das "<i>top words". Na figura a seguir esse fato é mostrado com um exemplo feito com um arquivo de teste, que continha a palavra " ministros” "
</p>


![ProfundoPe](https://github.com/Eduardo-Rabelo/t1_AED2/blob/main/imagens/img1.png)

<p align="justify">
	Na hash, os índices das posições em que as palavras serão armazenadas são calculados com base em soma mod tamanho da tabela, que é a variável global definida no arquivo "hash.hpp" como "tam". Soma seria a soma dos números inteiros que representam os caracteres ASCII da palavra. Caso já haja uma palavra armanzenada no índice, outro índice é calculado da mesma forma, porém a soma é mudada de modo que ela passa a ser a soma dos caracteres multiplicados pelas suas posições na própria palavra. O caractere vda posição 0, por exemplo, sempre terá valor 0. Os caracteres especiais são substituidos por caracteres ASCII para se fazer esse cálculo.
</p>

<p align="justify">
	Caso, mesmo calculando duas vezes o índice, haja colisão, a palavra é armazenada em uma lista na posição da hash indicada pelo segundo índice.
</p>

# Toy Example

![LarguraPe](https://github.com/Eduardo-Rabelo/t1_AED2/blob/main/imagens/img2.png)

<p align="justify">
	A imagem a seguir mostra qual seria a saída do arquivo de exemplo mostrado na imagem anterior, para k=10. É possível notar que as palavras com caracteres especiais também contam pro calculo do heap.
</p>

![LarguraG](https://github.com/Eduardo-Rabelo/t1_AED2/blob/main/imagens/img3.png)

# Custo
<p align="justify">
	O custo do algoritmo, em questão de memória alocada, é da ordem de Teta de n, sendo n o número de palavras do texto. Em questão de iterações, as palavras, após serem armazenadas na hash, são conferidas uma a uma para ver se entram no heap, o que também tem custo Teta de n. Essas operações se repetem pra cada arquivo, ou seja, o custo total do código em tempo é da classe de Teta de n*m, sendo m o número de arquivos de input.
</p>

# Conclusão
<p align="justify">
	Em suma, o algorítimo consiste em, para cada arquivo de input, criar uma hash com todas as palavras do arquivo e calcular as k "<i>top words" por meio de um heap mínimo baseado na frequencia das palavras no texto. O custo do algorítimo é linear em relação ao total de palavras de todos os arquivos e há um problema de conversão de caracteres especiais que deverá ser corrigido na próxima versão do trabalho.
</p>



# Output
<p align="justify">
O output desse código é, para cada arquivo, o nome do arquivo analisado segido do número de palavras na hash e o heap do arquivo, como pode-se ver na imagem seguinte.
</p>

![Output](https://github.com/Eduardo-Rabelo/t1_AED2/blob/main/imagens/img4.png)

# Observações
<p align="justify">
Além do problema das palavras com caracteres especiais, a Hash suporta apenas cerca de 25600 palavras. Não foi possível ler as últimas 400 linhas do texto Semana_Machado_Assis por esta razão. O arquivo "input1.txt" não contem essas linhas.
</p>

# Compilação e Execução

<p align="justify">
O arquivo Makefile permite o uso das seguintes diretrizes de execução:
</p>


| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a pasta build                                        |
|  `make`                | Executa a compilação e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


