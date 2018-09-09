# Overview
Aluno: Matheus de Sousa Lemos Fernandes 16/0137969
Aluno: Saulo Mendes Feitosa 16/0144884

Compilacao:
    Para compilar bastar digitar o comando "make" (sem aspas) no terminal, para gerar um arquivo executável main.
    Em seguida digite "./main" (sem aspas) para executar o algoritmo.

Codigo:
    Os comentarios do codigo estao contidos nos .cpp junto a implementacao dos metodos.

Saida:
    O programa imprime na tela em ordem o que foi pedido na especificação do projeto.
    As impressões são respectivamente: Vértices e seus graus, Cliques Maximais, Coeficientes de aglomeração, Coeficiente Médio do grafo e são feitas de uma só vez ao se excutar o programa "main".

Execucao:
    Ha um makefile na pasta do projeto que deixa facil a compilacao do mesmo, utilizando este para compilar o programa e o "./main" para rodar o mesmo no terminal,o programa e executado.
    O programa ao ser executado, primeiramente le o arquivo "karate.gml", enquanto le o arquivo o programa monta um grafo baseado em uma estrutura ja definida. Apos montar o grafo o programa passa por seus vertices para imprimir seus graus, aplica o algoritmo de Bron Kerbosch para calcular e os seus cliques maximais e mostra-los na tela, aplica um algoritmo que calcula os Coeficiente de aglomeracao de cada vertice no grafo para mostrar na tela e por fim calcula o coeficiente medio do grafo e o mostra em tela, o que encerra o programa.
