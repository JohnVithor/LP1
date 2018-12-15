#include <iostream>
#include <algorithm>
#include "turma.h"

Turma::Turma() {}

Turma::~Turma() {}

int 
Turma::addAluno(AlunoTurma _aluno) {
	/* Adiciona um aluno na lista de alunos */
	std::vector<AlunoTurma>::iterator result;
	result = std::find(alunos.begin(), alunos.end(), _aluno);
	if (result == alunos.end())
	{
		alunos.push_back(_aluno);
		return 0;
	} 
	return -1;
}

Aluno* 
Turma::buscaAlunoPorNome (std::string _nome) {
	/* Busca por um aluno na lista de alunos com o nome indicado. 
	   Retorna um apontador para o objeto aluno se encontrado. 
	   Retorna nulo, caso não encontre um aluno com o nome indicado. */

	std::vector<AlunoTurma>::iterator result;
	result = std::find(alunos.begin(), alunos.end(), _nome);
	if (result != alunos.end()){
		AlunoTurma *p = &(*result);
		return p->getDiscente();
	} else {
		return NULL;
	}
}

Aluno* 
Turma::buscaAlunoPorMatricula (std::string _matricula) {
	/* Busca por um aluno na lista de alunos com a matricula indicada. 
       Retorna um apontador para o objeto aluno se encontrado. 
       Retorna nulo, caso não encontre um aluno com a matricula indicada. */
	std::vector<AlunoTurma>::iterator result;
	result = std::find(alunos.begin(), alunos.end(), _matricula);
	if (result != alunos.end()){
		AlunoTurma *p = &(*result);
		return p->getDiscente();
	} else {
		return NULL;
	}
}

int 
Turma::removeAlunoPorNome (std::string _nome) {
	/* Remove o aluno com o nome indicado.
	   Retorna 0 caso o aluno seja encontrado e removido com sucesso.
	   Retorna -1 em caso contrário.
	   Dica: Para remover um elemento do vetor, utilize o metodo erase().
	*/
	std::vector<AlunoTurma>::iterator result;
	result = std::find(alunos.begin(), alunos.end(), _nome);
	if (result != alunos.end()){
		alunos.erase(result);
		return 0;
	} else {
		return -1;
	}

}

int 
Turma::removeAlunoPorMatricula (std::string _matricula) {
    /* Remove o aluno com a matricula indicada.
	   Retorna 0 caso o aluno seja encontrado e removido com sucesso.
	   Retorna -1 em caso contrário.
	   Dica: Para remover um elemento do vetor, utilize o metodo erase().
	*/
	std::vector<AlunoTurma>::iterator result;
	result = std::find(alunos.begin(), alunos.end(), _matricula);
	if (result != alunos.end()){
		alunos.erase(result);
		return 0;
	} else {
		return -1;
	}
}

void 
Turma::listaAlunos() {
	/* Lista os dados de todos os alunos da turma, incluindo o total de faltas e nota.
	Utilize a sobrecarga do operador de inserção para a impressão dos dados do aluno. 
	Deve listar ainda a quantidade de alunos e a média das notas dos alunos nesta turma.
	*/
	std::cout << "Temos um total de " << alunos.size() << " alunos na turma." << std::endl
	<< "A média das notas da turma é de " << getMedia() << " pontos."<< std::endl
	<< "Os alunos dessa turma são:" << std::endl << std::endl;
	for (std::vector<AlunoTurma>::iterator i = alunos.begin(); i != alunos.end(); ++i)
	{
		std::cout << *i << std::endl;
	};;;;;;;
}

int
Turma::getQntAlunos(){
	return alunos.size();
}

double
Turma::getMedia(){
	double media = 0;
	for (std::vector<AlunoTurma>::iterator i = alunos.begin(); i != alunos.end(); ++i)
	{
		media += (*i).getNota();
	}
	return media/alunos.size();


}