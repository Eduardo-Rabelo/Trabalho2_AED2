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
	As palavras são armazenadas na hash em lowercase e com os acentos, porem certas palavras, precedias, ou sucedidas por caracteres especiais, permanecem com esses caracteres ao serem armazenados na hash. Alguns desses casos são os caracteres "”" e "—", que são representados nas palavras da hash como "⠝" e "⠴". Como essas palavras são contadas como distintas das mesmas palavras sem os caracteres especiais, há uma subcontagem das "<i>top words".
</p>


![ProfundoPe](https://github.com/Eduardo-Rabelo/Trabalho3_AED__2023_Final/blob/main/ImagensTrabalho3_AED/ProfundoPe.png)

		
<p align="justify">	
	Na imagem acima, é mostrado como a busca em profundidade ocorre, primeiro, o personagem tenta as duas primeiras direções na ordem de prioridade, porém há paredes bloqueando seu caminho, de modo que ele vai para a direita. Ao parar na borda da matriz, ele vai direto para a quarta direção prioritária. Caso as demais direções além das três de maior prioridade estivessem bloqueadas, ele voltaria na mais prioritaria, depois na segunda e na terceira até uma ser possível. E, caso não seja, a posição é desempilhada e o personagem volta para a casa que estava anteriormente, mesmo ela sendo já marcada.
</p>

![LarguraPe](https://github.com/Eduardo-Rabelo/Trabalho3_AED__2023_Final/blob/main/ImagensTrabalho3_AED/LargoPe.png)

<p align="justify">
	A última imagem, por sua vez, mostra como a busca em largura funciona. Como o personagem toma todas as direções possíveia a partir de onde ele está, ele tende a encontrar muito mais perigos e percorrer mais casas, sobretudo quando a condição de fim se encontra próxima ao final da matriz, como é demonstrado na imagem a seguir. 
</p>

![LarguraG](https://github.com/Eduardo-Rabelo/Trabalho3_AED__2023_Final/blob/main/ImagensTrabalho3_AED/LarguraG.png)

<p align="justify">
	Para a mesma matriz, o DFS segue somente uma direção, ou seja, o personagem anda muito menos casas que no método BFS. Porém, caso a interrogação estivesse logo abaixo da casa inicial,o custo de percorrer a matriz seria teta de 1. 
</p>

![LProfundoG](https://github.com/Eduardo-Rabelo/Trabalho3_AED__2023_Final/blob/main/ImagensTrabalho3_AED/ProfundoG.png)
	
	
	
# Custo
<p align="justify">
	O custo do algoritmo, em questão de memória alocada, depende da ordem das matrizes. Para percorrer a matriz, o custo pertence à classe Teta de n, sendo n o numero de elementos da matriz. No mínimo o custo seria 2n para criar os vectors que representa a matriz e a matriz verdade,porém,dependendo do número de perigos e do método usado, o custo aumenta, podendo chegar no pior caso, que seria uma matriz composta somente por perigos, a Teta de n!.
	
</p>
<p align="justify">
	O custo de cada método depende mais de onde os perigos estão posicionados do que de quantas casas são percorridas. Porém, quanto mais casas são percorridas, maior é a chance de se encontrar prigos e, por essa razão, no geral, caso o símbolo de parada esteja próximo ao fim da matriz,o BFS tende a ser pior que o DFS, pois , no BFS, são percorridas muito mais casas e há grandes chances de se encontrar mais perigos.
</p>

# Conclusão
<p align="justify">
	Em suma, comparados ao método aleatório, os métodos BFS e DFS são muito mais previsíveis e, portanto, mais indicados, porém, há casos em que eles se tornão tão ruins, ou piores que o aleatório, de modo que, se houver alguma informação a respeito do local provável de se encontrar a condição de finalização, é possível escolher o método que provavelmente busca melhor na matriz.
</p>	



# Output
<p align="justify">
No arquivo "output.data",  são mostradas a matriz percorrida e a matriz verdade de cada um dos três métodos, aleatório, DFS e BFS respectivamente. Na figura a seguir, é mostrado o output do DFS.
</p>	

![Output](https://github.com/Eduardo-Rabelo/Trabalho3_AED__2023_Final/blob/main/ImagensTrabalho3_AED/Output.png)

<p align="justify">
Já na própria tela, são printadas a matriz a ser percorrida, a matriz percorrida, o número de casas percorridas ao menos uma vez na matriz, o número de perigos enfrentados, a pontuação e o tempo de execução do método. A seguir, mostra-se o output do DFS.
</p>

![cout](https://github.com/Eduardo-Rabelo/Trabalho3_AED__2023_Final/blob/main/ImagensTrabalho3_AED/cout.png)

<p align="justify">
A única excessão é o método aleatório, que é mostrado como era no trabalho anterior, além da matriz percorrida, também são mostrados todos os caminhos percorridos até o final da matriz.
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


