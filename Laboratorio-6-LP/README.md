# Laboratório 6
### Namespaces e Bibliotecas

- Aluno: João Vítor Venceslau Coelho
- Professor: Silvio Costa Sampaio

## Objetivo
O objetivo deste exercício é colocar em prática conceitos de namespaces e bibliotecas na linguagem de programação C++.

### Questão 01
Uma das principais razões para o uso de bibliotecas é a reutilização de código, permitindo que outros programas utilizem partes de códigos comuns. Seguindo este princípio, reimplemente a Lista 1 – Formas Geométricas aplicando os conceitos de Programação Orientada a Objetos. Você deve criar a sua biblioteca <seu_nome> (por exemplo, paulo), contendo as classes correspondentes. Os componentes da biblioteca deverão ser organizados no namespace geometria. Você também deverá apresentar um Makefile que permita gerar as versões estática e dinâmica da biblioteca para os sistemas operacionais Linux e Windows.

#### Questão 1 - Lista 1 - Formas Geométricas
A tarefa principal a ser realizada neste exercício é a implementação de um programa que calcula as medidas de diversas figuras geométricas planas e espaciais. O programa em execução deve apresentar ao usuário uma lista de opções referentes às figuras e, após a escolha de uma dessas opções, deve solicitar ao usuário que forneça os dados necessários aos cálculos das medidas. Como resultado, o programa deve exibir as respectivas medidas (área, perímetro, volume) da figura escolhida. Note que, para figuras geométricas planas, o programa deve exibir apenas a área e o perímetro; para figuras geométricas espaciais, o programa deve exibir apenas a área e o volume da figura.

##### Exemplos de entrada e saída
Conforme mencionado anteriormente, o programa em execução deve primeiramente apresentar ao usuário uma lista com nove opções, numeradas de 0 a 8, referentes às figuras geométricas planas e espaciais das quais deseja-se obter as medidas. Quando o usuário digitar 0 como opção, o programa deverá ter sua execução finalizada. Caso seja digitada uma opção diferente das disponíveis, o programa deverá emitir uma mensagem informando da entrada inválida e solicitando que o usuário digite uma nova opção.

	$ ./geometrica
	Calculadora de Geometria Plana e Espacial
	(1) Triangulo equilatero
	(2) Retangulo
	(3) Quadrado
	(4) Circulo
	(5) Piramide com base quadrangular
	(6) Cubo
	(7) Paralelepipedo
	(8) Esfera
	(0) Sair
	Digite a sua opcao:

Depois de o usuário digitar a opção escolhida, o programa deverá solicitar os dados necessários para o cálculo das medidas de acordo com a figura em questão. Por exemplo, suponha que o usuário tenha escolhido a opção 2, para cálculo das medidas referentes a um retângulo. Pelo fato de um retângulo ser uma figura geométrica plana, serão calculados apenas a sua área e o seu perímetro, de modo que é necessário informar o tamanho da base e da altura do retângulo.

	Digite a sua opcao: 2
	Digite o tamanho da base do retangulo: 5
	Digite o tamanho da altura do retangulo: 3

Uma vez que o usuário informou os dados necessários aos cálculos, o programa deverá chamar as respectivas funções de cálculos das medidas de acordo com a figura geométrica em questão e exibir os resultados correspondentes. Ainda considerando o exemplo anterior das medidas referentes a um retângulo, o programa exibirá as medidas da área e do perímetro do retângulo.

	Area do retangulo: 15
	Perimetro do retangulo: 16

Após a exibição dos resultados das medidas de uma figura geométrica, o programa deverá exibir novamente a lista com as nove opções do menu inicial.

### Questão 02
Implemente duas versões de seu programa principal: uma versão utilizando a biblioteca estática e outra utilizando a biblioteca dinâmica. Lembre-se que a sua biblioteca pode ser eventualmente utilizada por outros, portanto, documente corretamente sua implementação e gere uma documentação adequada com o Doxygen. Isso facilitará a utilização de sua biblioteca.

## Compilação
Para a compilação das questões utilize o comando 'make' no terminal do Linux.
Para gerar a documentação digite 'make doxy'.

## Executar os programas
Antes de executar digite
	
	make install
para copiar as bibliotecas no seu sistema e após o termino do programa, caso queira digite
	
	make uninstall
para deletar as bibliotecas que foram copiadas

Digite

	./bin/geometrica_estatico
No terminal do Linux para executar a versão estatica do programa
ou
Digite

	./bin/geometrica_dinamico
No terminal do Linux para executar a versão dinamica do programa


Link legal: https://www.calculat.org