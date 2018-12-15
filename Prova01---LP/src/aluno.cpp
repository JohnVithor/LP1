#include <iostream>
#include <string>
#include "aluno.h"

Aluno::Aluno() {

}

Aluno::Aluno(std::string _matricula, std::string _nome) {
	matricula = _matricula;
	nome = _nome;
}

Aluno::~Aluno() {

}

std::string Aluno::getNome() {
	return nome;
}

std::ostream& operator<< (std::ostream &o, Aluno &aluno_){
	o << "Nome: " << aluno_.nome << std::endl
	  << "Matricula: " << aluno_.matricula << std::endl;
	return o;
}

bool Aluno::operator==(const Aluno &aluno_) const {
	if (this->nome == aluno_.nome or this->matricula == aluno_.matricula){
		return true;
	} else {
		return false;
	}
}

bool Aluno::operator==(const std::string &str_) const {
	if (this->nome == str_ or this->matricula == str_){
		return true;
	} else {
		return false;
	}
}


//////////////////////////////
AlunoTurma::AlunoTurma() {

}

AlunoTurma::AlunoTurma(Aluno* _discente, int _faltas, double _nota) {
	discente = _discente;
	faltas = _faltas;
	nota = _nota;
}

AlunoTurma::~AlunoTurma() {

}

Aluno* 
AlunoTurma::getDiscente() {
	return discente;
}
double 
AlunoTurma::getNota() {
	return nota;
}

std::ostream& operator<< (std::ostream &o, AlunoTurma &aluno_){
	o << *(aluno_.discente)
	  << "Faltas: " << aluno_.faltas << std::endl
	  << "Nota: " << aluno_.nota << std::endl;
	return o;
}

bool AlunoTurma::operator==(const AlunoTurma &aluno_) const {
	if (*(this->discente) == *(aluno_.discente)){
		return true;
	} else {
		return false;
	}
}

bool AlunoTurma::operator==(const std::string &str_) const {
	if (*(this->discente) == str_){
		return true;
	} else {
		return false;
	}
}