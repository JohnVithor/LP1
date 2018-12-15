# Laboratório 1
### Uso das ferramentas de desenvolvimento de programas em C++.

- Aluno: João Vítor Venceslau Coelho
- Professor: Silvio Costa Sampaio

## Objetivo
O objetivo deste exercício é realizar a implementação de dois programas na linguagem de programação C++ utilizando ferramentas de suporte ao programador, tais como o compilador e um sistema de controle de versão, e aplicando modularização e outras boas práticas de programação.

### Questão 01
A tarefa principal a ser realizada neste exercício é a implementação de um programa que calcula as medidas de diversas figuras geométricas planas e espaciais. O programa em execução deve apresentar ao usuário uma lista de opções referentes às figuras e, após a escolha de uma dessas opções, deve solicitar ao usuário que forneça os dados necessários aos cálculos das medidas. Como resultado, o programa deve exibir as respectivas medidas (área, perímetro, volume) da figura escolhida. Note que, para figuras geométricas planas, o programa deve exibir apenas a área e o perímetro; para figuras geométricas espaciais, o programa deve exibir apenas a área e o volume da figura.

### Questão 02
Escreva um programa chamado anterior que lê um valor inteiro e retorna o maior número primo inteiro anterior ao valor do fatorial desse número. Você deverá obedecer aos seguintes detalhes de implementação:
- O valor do número inteiro deve ser lido através da linha de comando.

- Implemente o seu programa de forma modular. Crie o conjunto de arquivos fatorial.h/.cpp (com a implementação da função de fatorial), primalidade.h/.cpp (com a implementação das funções que testam a primalidade de um valor inteiro e que retorna o maior primo inteiro anterior a X) e um arquivo main.cpp (contendo o programa principal). Crie um Makefile para a compilação e geração do binário/executável.

- Utilize conceitos de recursividade para o cálculo do fatorial e para a obtenção do maior número primo anterior ao valor do fatorial do número em questão.

Por fim, com a ajuda do profiller Gprof, analise a execução de seu código e indique qual a função que é mais
chamada e qual consome mais tempo.

### Questão 03
Com a ajuda do depurador GDB, apresente os valores das variáveis arg1 e arg2 após a chamada de cada função, justificando os valores apresentados.

## Compilação
Após clonar este repositório deverão ser criado os diretórios "bin","build" e "doc", para isso:
- crie os diretórios manualmente com o comando mkdir.

ou

- digite "make dir" no terminal.

Para a compilação das questões utilize o comando 'make' no terminal do Linux.


## Executar o programa
- O programa da questão 01 - geometrica - não precisa de argumento algum, todos os valores são inseridos após a execução do programa.
- O programa da questão 02 - anterior - necessita de um número como argumento, que será o número para o calculo do fatorial.
    ./bin/anterior <número> (A análise do Gprof é habilitada com o uso do comando make debug. A análise do Gprof está no diretório - Analises)
- O programa da questão 03 - questao03 - não precisa de argumento algum, e a análise do código está no diretório - Análises
