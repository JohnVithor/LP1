#ifndef _ALUNO_H_
#define _ALUNO_H_

#include <string>

class Aluno {
private:
	std::string matricula;
	std::string nome;
	int faltas;
	double nota;

public:
	Aluno();
	Aluno(std::string _matricula, std::string _nome);
	~Aluno();

	std::string getNome();

	friend std::ostream& operator<< (std::ostream &o, Aluno &aluno_);
	bool operator==(const Aluno &aluno_) const;
	bool operator==(const std::string &str_) const;
};

class AlunoTurma {
private:
	Aluno* discente;
	int faltas;
	double nota;

public:
	AlunoTurma();
	AlunoTurma(Aluno* _discente, int _faltas, double _nota);
	~AlunoTurma();

	Aluno* getDiscente();
	double getNota();

	friend std::ostream& operator<< (std::ostream &o, AlunoTurma &aluno_);
	bool operator==(const AlunoTurma &aluno_) const;
	bool operator==(const std::string &str_) const;
};

#endif