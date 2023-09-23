# Trabalho 1: Árvores
# introdução
<p align="justify">
		O algoritmo aqui apresentado tem como objetivo aproveitar o trabalho anterior para construir árvores binária simples, AVL e de Huffman para guardar as top k palavras de cada texto. Deveria haver um arquivo input.data, no qual o usuário colocaria as palavras que gostaria de pesquisar sobre, para que fossem construídas as três árvores pra cada texto em que a palavra aparece, por palavra pesquisada. Infelizmente, em razão de problemas de tempo, só foi possível criar as três estruturas pra cada texto, não levando em conta as palavras do usuário.
</p>


# Árvore Binária Simples
<p align="justify">
	A árvore binária simples é funcional, embora conte apenas com os métodos de inserção e remoção. Seus nós pertencem à classe blocoR, que conta com atributos e métodos que jamais serão usados pela árvore binária simples, porém serão usados nas demais árvores, de modo a garantir o pleno funcionamento delas, no quesito de balanceamento, por exemplo.
</p>

# Árvore AVL

<p align="justify">
	A árvore AVL funciona de modo a manter-se balanceada, aceitando, no máximo, um grau de desbalanceamento com módulo maior que 1, ou eja, um nível de desbalanceamento. Nessqa árvore, cada nó tem seu grau de desbalanceamento, que consiste na diferença entre o nível do nó mais baixo da subárvore a direita do nó, e o nível do nó mais baixo da subárvore a esquerda do mesmo. Caso um nó tenha um grau de desbalanceamento  maior que 1, há regras de balanceamento para fazer com que seu grau seja menor que dois.
</p>

<p align="justify">
	Caso um nó tenha grau maior que um, se seu filho direito tiver grau positivo, simplesmente faz-se uma rotação simples pra esquerda. O filho direito passa a ocupar o lugar do pai, que se torna seu filho esquerdo, e a subárvore esquerda do antigo filho direito, se torna a subárvore direita do antigo pai.
</p>

<p align="justify">
	De modo semelhante, caso um nó tenha grau menor que -1, se seu filho esquerdo tiver grau negativo, faz-se uma rotação simples para a direita. O filho esquerdo passa a ocupar o lugar do pai, que se torna seu filho direito, e a subárvore direita do antigo filho esquerdo, se torna a subárvore esquerda do antigo pai.
</p>

<p align="justify">
	Também há as rotações duplas. Caso os sinais sejam diferentes, do pai e do filho analizado, primeiro faz-se a rotação do filho, depois do pai. No caso de o grau do pai ser positivo, e do filho direito ser negativo, primeiro faz-se uma rotação simples a direita no filho esquerdo, depois uma rotação simples a esquerda no pai. De modo semelhante, acontece no caso de o pai ser negativo e o filho positivo, porém o filho é rotacionado pra esquerda, e o pai a direita.
</p>

# Observações AVL
<p align="justify">
	A raiz da AVL implementada pra esse trabalho não é capaz de rotacionar, funcionando como uma espécie de sentinela. Para versões futuras do trabalho isso deve ser corrigido, porém com o tempo disponível, não foi possível corrigir esse problema.
</p>

# Huffman
<p align="justify">
	O algoritmo de Huffman consiste em separar os dados desejados, e ajunta-los em pares, os de menor relevancia, ou frequência, ficam juntos. Depois disso, esses pares são aglutinados em árvores, que são fundidas as outras árvores até se formar uma árvore com todos os dados, de modo que os de maior relevancia fiquem mais póximos da raiz.
</p>


# Toy Example
<p align="justify">
	A seguir, é demonstrado como os dados do heap do "input2.txt" ficam na árvore binária simples. É possível notar que ela está desbalanciada, pois não há mecanismos de rebalanceamento pra essa árvore.
</p>
![binaria](https://github.com/Eduardo-Rabelo/Trabalho2_AED2/blob/main/imagens/binariaSimples.jpeg)
![tantoFaz](https://github.com/Eduardo-Rabelo/Trabalho2_AED2/blob/main/imagens/avl.jpeg)

<p align="justify">
	A imagem a seguir mostra a árvore AVL para os mesmos dados. É visível a efetividade do balanceamento na questão de pesquisa, pois, como a árvore balanceada tem uma altura de log(n), o custo da pesquisa é da ordem de teta de log(n). Como a raiz não pode ser movida e ela é o item de menor frequencia, a árvore sempre vai pender pra direita, porém como a raiz é apenas um nó, ela não altera a ordem do custo computacional.
</p>

![LarguracG](https://github.com/Eduardo-Rabelo/Trabalho2_AED2/blob/main/imagens/binariaSimples.jpeg)
![LarguracG](https://github.com/Eduardo-Rabelo/Trabalho2_AED2/blob/main/imagens/avl.jpeg)
![LarguracG](https://github.com/Eduardo-Rabelo/Trabalho2_AED2/blob/main/imagens/huffman.jpeg)

<p align="justify">
	Por fim, a imagem a seguir mostra a árvore de Huffman para os mesmos dados. A grande vantagem do algoritmo de Huffman é o acesso rápido às palavras mais relevantes. O custo da árvore continua sendo da ordem de teta de log(n), porém, para as pesquisas provavelmente mais comuns, essa árvore é extremamente eficiente.
</p>
![huffman](https://github.com/Eduardo-Rabelo/Trabalho2_AED2/blob/main/imagens/huffman.jpeg)

# Custo
<p align="justify">
	O custo do algoritmo, analisando apenas as árvores, em questão de memória alocada, é da ordem de Teta de n, sendo n o número de palavras das árvores. Em questão de iterações, para pesquisa, os custos da AVL e da árvore de Huffman, como mencionado anteriormente, são da ordem de teta de log(n), porém o custo da binária, no pior dos casos, chega a ser linear. Em questão de montagem porém, a avl é extremamente cara dependendo de quantas vezes é necessãrio fazer rebalanceamentos na árvore.
</p>

# Conclusão
<p align="justify">
	Em suma, o algorítimo consiste em, para cada arquivo de input, criar os três tipos de árvore, com base nas top k palavras do heap. As árvores de Huffman e AVL se mostram mais eficientes que a binária comum, ao menos em termos de pesquisa, embora a AVL seja menos eficiente caso hajam mais operações de remoção e inserção, do que operações de pesquisa, pois rotações são caras.
</p>



# Output
<p align="justify">
Por hora, o output é apenas a impressão das três árvores dos três modos conhecidos, central, pré ordem, e pós ordem.
</p>

# Observações
<p align="justify">
O algoritimo não entrega todas as especificações do trabalho, porém as três estruturas principais estão prontas e, com excessão do problema na raiz da AVL, funcionando corretamente. Para futuras versões, o algoritmo será capaz de indicar as árvores para cada palavra que o usuário propuser.
</p>

# Referências
CORMEN, Thomas H. et al. Algoritmos: Teoria e Prática. 3. ed. Elsevier, 2009.

# Compilação e Execução

<p align="justify">
O arquivo Makefile permite o uso das seguintes diretrizes de execução:
</p>


| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a pasta build                                        |
|  `make`                | Executa a compilação e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


