Eduardo Camargo Neves
GRR20196066


Neste trabalho foi usando seis bibliotecas, sendo elas:

 - libleitura.c:
   Para poder fazer a leitura do livro de cifras e do arquivos de chaves, foi usadas as funções:
  
   - ler_livro_cifra: para ler o livro de cifras, a função recebe como parâmetro o nome do arquivo e uma lista, dentro da função é feito a leitura do arquivo e a inserção dos caracteres e das posições na lista.
  
   - ler_arquivos_de_chaves: para ler o arquivo de chaves, a função recebe como parâmetro o nome do arquivo e uma lista, dentro da função é feito a leitura do arquivo e a inserção das chaves na lista.
  
   - separa_caractere: para separar o primeiro caractere da string, a função recebe como parâmetro a string e retorna o primeiro caractere da string.

 - libcodificar.c:
   Para poder codificar a mensagem com o livro de chaves, foi usada a função:

     - codificar_mensagem_original: a função recebe como parâmetro a mensagem original, lista de chaves e o arquivo de saída, dentro da função o arquivo da mensagem original é aberto, leio palavra por palavra, depois que leio uma palavra, mando ela para a função "codificar_palavra", para poder codificar cada letra, se não for achado a letra dentro do arquivo de chaves ou do livro cifra, o programa para a execução e mostra a mensagem "não é possível codificar essa mensagem".


     - codificar_palavra: a função recebe como parâmetro palavra para ser codificada, o arquivo de saída e a lista de chaves. Leio cada letra da palavra, faço uma busca pela letra na lista de chave, se achar a letra, retorno o nodo da lista que está esse caractere, depois mando o nodo para a função "gerar_num" que retorna o índice que representa a letra no livro de cifras, depois guardo esse valor no arquivo de saída.
    
     - gerar_num: a função recebe como parâmetro o nodo que contém o caractere, dentro da função eu pego a lista de numeros que tem esse nodo, gerou um número aleatório entre 0 e o tamanho da lista de numeros que tem esse nodo, o número que foi gerado é o índice do nodo da lista de números, procuro esse nodo e retorno o valor deste nodo.

 - libdecodificar.c:
   Nesta biblioteca veremos o processo de decodificação da mensagem, para isso foi usada as funções:

     - decodificar_mensagem_codificada: a função recebe como parâmetro a mensagem codificada, lista de chaves e o arquivo de saída, dentro da função o arquivo da mensagem codificada é aberto, leio cada número e depois mando o numero para a função "decodificar_palavra", para poder deodificar a mensagem, se não for achado o número dentro da lista de chaves, o programa para a execução e mostra a mensagem "não é possível decodificar essa mensagem".
    
     - decodificar_palavra: a função recebe como parâmetro o número para ser decodificado, o arquivo de saída e a lista de chaves, a função faz a busca do número na lista, para descobrir o caracter que representa aquele número, quando é achado o carácter, já é gravado no arquivo de saída e retorna um flag que indica que o número foi decodificado.

 - libimprimir.c:
   Nesta biblioteca é feita a impressão das chaves em um arquivo txt.

 Agora veremos as biblioteca mais importantes para a estrutura de dados usado no trabalho, que são a liblistacarect.c e a liblistanum.c, cada uma lib tem funções normal de lista como inserir, buscar, criar a lista, criar nodo, liberar a lista e de exibir a lista.
 No "liblistacarect.c" a função "insere_caracter" tem um algoritmo diferente para inserir na lista, que seria inserir ordenado os caracteres, e quando leio um caracteres que já esteja na lista, eu somente adiciona o indice do livro de cifra na lista de números daquele caráter.

 A estrutura para guardar e criar as chaves, está sendo uma lista de caracteres que dentro cada nodo, tem uma lista de números que indica a posição da palavra no livro cifra.

