# Laboratório 4
### Programação genérica e utilização de TADs genéricos

- Aluno: João Vítor Venceslau Coelho
- Professor: Silvio Costa Sampaio

## Objetivo
O objetivo deste exercício é colocar em prática conceitos de templates de classes na linguagem de programação C++, em particular pela utilização do Tipo Abstrato de Dados (TAD) Pilha (Stack) e a implementação de uma Lista Duplamente Encadeada.

### Programa 01
Escreva um programa, utilizando a estrutura de Pilha (Stack) já implementada por você em aulas anteriores, que permita avaliar se uma palavra (ou frase) é ou não palíndroma. Uma palavra ou frase é dita palíndromo se a sequência de letras que a forma é a mesma, seja ela lida da esquerda para a direita ou vice-versa. Exemplos: “arara”, “raiar”, “hanah” ou “Socorram-me, SUBI NO ÔNIBUS EM MARROCOS”. Na comparação das letras que formam a palavra, acentos e outros caracteres (fora de A-Z, a-z, 0-9) devem ser desprezados. Maiúsculas e minúsculas também não são diferenciadas, ou seja, (A == a).

Dica: Utilize as características da estrutura de dados Pilha para facilitar a resolução do problema.
Nota: Sua implementação de Pilha (código fonte) deve ser incorporada ao seu projeto.

### Programa 02
Escreva um programa, utilizando a TAD mais adequada entre as estudadas nesta unidade (Pilha, Fila, Lista, Deque ou Tabela de Dispersão), que permita avaliar uma dada expressão em notação polonesa inversa. Notação Polonesa Inversa (ou RPN na sigla em inglês, de Reverse Polish Notation), também conhecida como notação pós-fixada, foi inventada pelo filósofo e cientista da computação australiano Charles Hamblin em meados dos anos 1950, para habilitar armazenamento de memória de endereço zero. Ela deriva da notação polonesa, introduzida em 1920 pelo matemático polonês Jan Łukasiewicz. (Wikipedia)
Exemplos de expressões para testes:

Expressão: 2 3 + 5 *		Resultado: 25 Infixa: (2 + 3) * 5

Expressão: 4 2 / 8 + 6 *	Resultado: 60 Infixa: ((4 / 2) + 8 ) * 6

Expressão: 5 3 * 2 * 10 /	Resultado: 3 Infixa: ((5 * 3) * 2) / 10

Por razões de simplicidade, assuma que os operandos e operadores serão digitados sempre com um espaço entre eles.

### Programa 03
Implemente em C++ as respectivas classes, atributos e métodos (incluindo construtores e destrutor) necessários para atender às especificações de uma lista duplamente encadeada ordenada com sentinelas genérica, ou seja, capaz de operar com qualquer tipo de dado. Note que o fato da lista ser ordenada implica em alterações apenas na inserção e eliminação dos itens. Note ainda que a lista duplamente encadeada ordenada deve ser implementada como uma classe especializada (subclasse) lista duplamente encadeada. Assim, o uso de herança irá evitar a repetição de código.

Dica: Faça uso de sobrecarga de operadores para realizar as operações necessárias sobre as listas.

## Compilação
Após clonar este repositório deverão ser criado os diretórios "bin","build" e "doc", para isso:
- crie os diretórios manualmente com o comando mkdir.

ou

- digite "make dir" no terminal.

Para a compilação das questões utilize o comando 'make' no terminal do Linux.

## Executar os programas
- O programa do Programa 1 - Não precisa de argumento algum, todos os valores são inseridos após a execução do programa.

- O programa do Programa 2 - Não precisa de argumento algum, todos os valores são inseridos após a execução do programa.

- O programa do Programa 3 - Não precisa de argumento algum, apenas mostra na os resultados de alguns testes testes realizados
