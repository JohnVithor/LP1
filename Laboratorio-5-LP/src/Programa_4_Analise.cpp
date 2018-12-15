#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <algorithm>
using std::transform;

// Retorna o quadrado do número indicado
int square(int val) {
	return val * val;
}

int main(int argc, char* argv[]) {
	vector<int> col;
	vector<int> col2;

	// Preenche o 'col' utilizando o push_back, que posiciona o número indicado no final de 'col'
	for (int i = 1; i <= 9; ++i) {
		col.push_back(i);
	}

	// A partir dos números de 'col', é calculado o quadrado de cada um e
	// o resultado é inserido no fim de 'col2'
	transform(col.begin(), col.end(), back_inserter(col2), square);
	
	// Imprime os números presentes no 'col2'
	for (vector<int>::iterator it = col2.begin(); it != col2.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
	return 0;
}

/*
	O propósito do código é basicamente: a partir dos números de um container,
	preencher outro container com os quadrados desses números e mostrar o resultado na tela.
*/