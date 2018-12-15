#include <iostream>

int minDist(int *first_, int *last_){
	int dmin = 2147483647; // Max int
	int tam = (last_ - first_);
	for (int i = 0; i < tam; ++i){
		for (int j = 0; j < tam; ++j){
			if (i != j and abs(*( first_ + i )-*(first_ + j)) < dmin){
				dmin = abs(*( first_ + i )-*(first_ + j));
			}
		}
	}
	return dmin;
}

int main(int argc, char const *argv[])
{
	int *vetor;
	vetor = new int[10];
	int *vetor_end = vetor + 10;

	for (int i = 0; i < 10; ++i){
		vetor[i] = i;
	}

	std::cout << "[ ";
	for (int i = 0; i < 10; ++i){
		std::cout << vetor[i] << ", ";
	}
	std::cout << " ]\n";

	int min = minDist(vetor,vetor_end);
	std::cout << ">>>>> Menor é: " << min << std::endl;
	return 0;
}