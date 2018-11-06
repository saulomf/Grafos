# Projeto 3 - Teoria e Aplicação de Grafos - 2/2018
Aluno: Saulo Mendes Feitosa 16/0144884
Aluno: Matheus de Sousa Lemos Fernandes 16/0137969

## Overview
O projeto é composto por algoritmos de leitura de arquivo e de emparelhamento estável; além de contar com funções para montagem de um grafo e impressão do mesmo.
Foi utilizado o algoritmo de Gale Shapley para encontrar o emparelhamento estável no grafo que é bipartido entre professores e escolas.

## Compilação
Para compilar bastar digitar o comando
``` make && ./main ```
(sem aspas ou caracteres especiais) para gerar um executável e executá-lo logo em seguida

## Código
Os comentarios do codigo estao contidos nos .cpp junto a implementacao dos metodos.

## Saida:
O programa ao ser executado, ocultamente lê um arquivo texto e monta com seus dados um grafo bipartido, após a montagem o programa executa o algoritmo de Gale Shapley para encontrar um emparelhamento estável e após ele apresenta ao usuário o emparelhamento encontrado.
