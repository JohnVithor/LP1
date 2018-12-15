# Laboratório 5
### Standard Template Library (STL)

- Aluno: João Vítor Venceslau Coelho
- Professor: Silvio Costa Sampaio

## Objetivo
O objetivo deste exercício é colocar em prática conceitos de containers, iteradores e algoritmos da STL (Standard Template Library) na linguagem de programação C++.

### Questão 01
Implemente uma função template closest2mean que receba como parâmetro um intervalo especificado por dois iteradores da categoria InputIterator e retorne um iterador para o elemento nesse intervalo cujo valor é o mais próximo da média do intervalo. Tal função deverá ter obrigatoriamente a seguinte assinatura:

	template<typename InputIterator>
	InputIterator closest2mean(InputIterator first, InputIterator last);

Um exemplo de utilização dessa função seria conforme mostrado no trecho de código a seguir:
	
	#include <iostream>
	using std::cout;
	using std::endl;
	#include <vector>
	using std::vector;
	int main() {
		vector<int> v { 1, 2, 3, 30, 40, 50 };
		auto result = closest2mean(v.begin(), v.end());
		cout << (*result) << endl;
		return 0;
	}

Como a média dos valores inteiros contidos no intervalo considerado (do início ao fim do vetor v) é 21, logo o programa imprime o valor 30 na saída padrão, referindo-se ao elemento mais próximo dessa média. Pesquise e utilize os algoritmos disponíveis na STL a fim de reduzir o seu código ao máximo.

### Questão 02
Implemente uma função template print_elements que receba como parâmetros um container qualquer seguido de um label e um separador a serem usados na impressão de todos os elementos do container. Tal função deverá conterá a seguinte assinatura:

	template<typename TContainer>
	void print_elements(const TContainer& collection, const char* label="",
	const char separator=' ');

Um exemplo de utilização dessa função seria conforme mostrado no trecho de código a seguir:

	#include <set>
	using std::set;
	int main() {
		set<int> numeros;
		numeros.insert(3);
		numeros.insert(1);
		numeros.insert(4);
		numeros.insert(1);
		numeros.insert(2);
		numeros.insert(5);
		print_elementos(numeros, "Set: ");
		print_elementos(numeros, "CSV Set: ", ';');
		return 0;
	}

Um exemplo de execução desse programa seria:

	$ ./print
	Set: 1 2 3 4 5
	CSV Set: 1;2;3;4;5

### Questão 03
Predicado é outro conceito importante e muito empregado na STL. Predicados são funções que retornam um valor booleano e são normalmente usadas em critérios de busca ou ordenação. Um predicado sempre retorna o mesmo resultado para o mesmo valor. Predicados podem ser implementados como funções booleanas ou functors.
Fazendo uso de uma functor, implemente um programa que, dado um container de inteiros, encontre o primeiro número primo do conjunto. Utilize esta função para imprimir todos os valores primos no container. Em outras palavras, o programa deverá ler um valor N fornecido como entrada via linha de comando e imprimir todos os valores primos de 1 a N. Você deverá utilizar o algoritmo find_if disponível na STL para encontrar o próximo número primo.
Um exemplo de execução do programa seria:

	$ ./showprimos 50
	$ Numeros primos [1-50]: 1 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47


### Questão 04
Após analisar o código a seguir, indique o seu propósito e descreva o uso dos elementos da STL.

	#include <iostream>
	using std::cout;
	using std::endl;
	#include <iterator>
	using std::back_inserter;
	#include <vector>
	using std::vector;
	#include <algorithm>
	using std::transform;
	int square(int val) {
		return val * val;
	}
	int main(int argc, char* argv[]) {
		vector<int> col;
		vector<int> col2;
		for (int i = 1; i <= 9; ++i) {
			col.push_back(i);
		}
		transform(col.begin(), col.end(), back_inserter(col2), square);
		for (vector<int>::iterator it = col2.begin(); it != col2.end(); ++it) {
			cout << (*it) << " ";
		}
		cout << endl;
		return 0;
	}

## Compilação
Após clonar este repositório deverão ser criado os diretórios "bin","build" e "doc", para isso:
- crie os diretórios manualmente com o comando mkdir.

ou

- digite "make dir" no terminal.

Para a compilação das questões utilize o comando 'make' no terminal do Linux.

## Executar os programas
- O programa do Programa 1 - Não precisa de argumento algum, todos os valores são inseridos após a execução do programa.

- O programa do Programa 2 - Não precisa de argumento algum, todos os valores são inseridos após a execução do programa.

- O programa do Programa 3 - Deve ser informado, via linha de comando, o limite superior do intervalo onde os números primos devem ser procurados ( impressos ).
