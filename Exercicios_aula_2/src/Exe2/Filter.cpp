#include <iostream>

int filter_v1(int *first_, int *last_){
	int tam = (last_ - first_);

	int i = 0;
	while(i < tam){
		if (first_[i] <= 0){
			for (int j = 0; j < tam - 1; ++j){
				first_[j] = first_[j+1];
			}
			--tam;
		} else {
			++i;
		}
	}
	return tam;
}

int main(int argc, char const *argv[])
{
	int *vetor;
	vetor = new int[10];
	int *vetor_end = vetor + 10;

	for (int i = 0; i < 10; ++i){
		vetor[i] = i*(100+i) + i*(100+i) - i*100 - 400;
	}

	std::cout << "Antes: ";
	std::cout << "[ ";
	for (int i = 0; i < 10; ++i){
		std::cout << vetor[i] << " ";
	}
	std::cout << "]\n";

	int vet = filter_v1(vetor,vetor_end);

	std::cout << "Depois: ";
	std::cout << "[ ";
	for (int i = 0; i < vet; ++i){
		std::cout << vetor[i] << " ";
	}
	std::cout << "]\n";

	return 0;
}