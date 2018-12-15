# Laboratório 2
### Classes, Objetos, Métodos Construtores, Método Destrutor e Sobrecarga de Operadores

- Aluno: João Vítor Venceslau Coelho
- Professor: Silvio Costa Sampaio

## Objetivo
O objetivo deste exercício é colocar em prática conceitos iniciais do paradigma de Programação Orientada a Objetos (POO) na linguagem de programação C++, em particular a implementação de classes, objetos, métodos construtores, método destrutor e sobrecarga de operadores.

### Programa 01
Implemente um programa em C++ que atenda aos seguintes critérios:

- a) Contenha uma classe que representa um funcionário, registrando seu nome, salário e data de admissão;
- b) Contenha também uma classe que representa uma empresa, registrando seu nome, CNPJ e lista de funcionários;
- c) O programa deverá permitir criar uma empresa;
- d) O programa deverá permitir que se adicione funcionários (um por vez) a uma empresa e não deve permitir adicionar um funcionário que já tenha sido anteriormente adicionado, sendo neste caso exibida uma mensagem de erro. Os funcionários de uma empresa poderão ser mantidos em um array, vector ou list, ou ainda alguma estrutura de dados que você já implementou em EDB1 e que considere conveniente.
- e) O programa deverá permitir listar os dados de todos os funcionários de uma empresa, sobrecarregando-se o operador de inserção em stream (<<);
- f) O programa deverá permitir que seja dado um aumento de X% a todos os funcionários de uma determinada empresa;
- g) O programa deverá permitir listar os dados de todos os funcionários de uma empresa em período de experiência, ou seja, contratados há menos de 90 dias considerando a data corrente;
- h) O programa deverá permitir listar a média de funcionários por empresa. O cálculo deve ser realizado a partir de atributos estáticos das próprias classes (Empresa e Funcionário).

### Programa 02
Utilizando classes, implemente em C++ um jogo de dados hipotético, no qual cada jogador (de vários) deve lançar dois dados em sua vez. A soma dos valores dos dados deve ser acumulada para cada jogador. O objetivo é ficar o mais próximo e abaixo do valor N a ser estabelecido como configuração geral do jogo e visível a todos os jogadores. Ao obter um valor agregado superior a N, o jogador é considerado excluído da rodada. A cada vez de jogar, o jogador pode optar por jogar os dados ou parar (e não jogar mais na rodada). Uma rodada é finalizada quando:
- (1) resta apenas um jogador, uma vez que os outros foram excluídos;
- (2) quando não há mais jogadores a jogar, ou seja, todos os jogadores “ativos” decidiram parar, ou;
- (3) quando um dos jogadores atinge exatamente o valor N. 

Vence a rodada o jogador que permanecer na rodada (ou seja, não for excluído) e obtiver o número de pontos agregados mais próximo de N. Ao final de cada rodada, o programa deverá listar os pontos agregados obtidos por cada jogar e declarar o campeão da rodada.

## Compilação
Após clonar este repositório deverão ser criado os diretórios "bin","build" e "doc", para isso:
- crie os diretórios manualmente com o comando mkdir.

ou

- digite "make dir" no terminal.

Para a compilação das questões utilize o comando 'make' no terminal do Linux.


## Executar o programa
- O programa do Programa 1 - Não precisa de argumento algum, todos os valores são inseridos após a execução do programa.
- O programa do Programa 2 - Não precisa de argumento algum, todos os valores são inseridos após a execução do programa.
