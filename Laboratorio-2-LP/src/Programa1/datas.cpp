/**
* @file		datas.cpp
* @brief	Definição da classe Datas, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	02/09/2017
* @date		09/09/2017
*/
#include <iostream>

#include "datas.h"
#include "../ler_entradas.h"

Datas::Datas( int dia_, int mes_, int ano_){
	if (dia_ <= 0 or mes_ <= 0 or dia_ > 30 or mes_ > 12){
		dia = 0;
		mes = 0;
		ano = 0;
	} else {
		dia = dia_;
		mes = mes_;
		ano = ano_;
	}
	
}

Datas::~Datas(){

}

Datas Datas::set_data(){
	std::cout << "Digite o dia: ";
	dia = get_int();
	while(dia <= 0 or dia > 30){
		std::cout << "Digite um dia válido (0 < d < 31): ";
		dia = get_int();
	}
	
	std::cout << "Digite o mes: ";
	mes = get_int();
	while(mes <= 0 or mes > 12){
		std::cout << "Digite um mes válido (0 < d < 13): ";
		mes = get_int();
	}

	std::cout << "Digite o ano: ";
	ano = get_int();

	Datas data(dia, mes, ano);
	return data;
}

Datas& Datas::operator+ (Datas &data_){
	int anoR = ano + data_.ano;
	int mesR = mes + data_.mes;
	int diaR = dia + data_.dia;
	if (diaR > 30)
	{
		diaR -= 30;
		++mesR;
	}	
	if (mesR > 12)
	{
		mesR -= 12;
		++anoR;
	}

	Datas *data = new Datas( anoR, mesR, diaR);
	return *data;
}

Datas& Datas::operator- (Datas &data_){
	unsigned long long int count1 = 0u;

	for (int i = 0; i < ano; ++i){
		count1 += 365u;
	}
	for (int i = 0; i < mes; ++i)
	{
		count1 += 30u;
	}
	for (int i = 0; i < dia; ++i)
	{
		++count1;
	}

	unsigned long long int count2 = 0u;

	for (int i = 0; i < data_.ano; ++i){
		count2 += 365u;
	}
	for (int i = 0; i < data_.mes; ++i)
	{
		count2 += 30u;
	}
	for (int i = 0; i < data_.dia; ++i)
	{
		++count2;
	}

	unsigned long long int countR = abs(count1 - count2);

	int anoR = 0;
	int mesR = 0;
	while(countR >= 365){
		++anoR;
		countR -= 365;
	}
	while(countR >= 30){
		++mesR;
		countR -= 30;
	}
	int diaR = countR;

	Datas *data = new Datas( diaR, mesR, abs(anoR));
	return *data;
}

bool Datas::operator>(const Datas &data_) const {
	unsigned long long int count1 = 0u;

	for (int i = 0; i < ano; ++i){
		count1 += 365u;
	}
	for (int i = 0; i < mes; ++i)
	{
		count1 += 30u;
	}
	for (int i = 0; i < dia; ++i)
	{
		++count1;
	}

	unsigned long long int count2 = 0u;

	for (int i = 0; i < data_.ano; ++i){
		count2 += 365u;
	}
	for (int i = 0; i < data_.mes; ++i)
	{
		count2 += 30u;
	}
	for (int i = 0; i < data_.dia; ++i)
	{
		++count2;
	}

	if (count1 > count2)
	{
		return true;
	} else {
		return false;
	}
}

bool Datas::operator<(const Datas &data_) const {
	unsigned long long int count1 = 0u;

	for (int i = 0; i < ano; ++i){
		count1 += 365u;
	}
	for (int i = 0; i < mes; ++i)
	{
		count1 += 30u;
	}
	for (int i = 0; i < dia; ++i)
	{
		++count1;
	}

	unsigned long long int count2 = 0u;

	for (int i = 0; i < data_.ano; ++i){
		count2 += 365u;
	}
	for (int i = 0; i < data_.mes; ++i)
	{
		count2 += 30u;
	}
	for (int i = 0; i < data_.dia; ++i)
	{
		++count2;
	}

	if (count1 < count2)
	{
		return true;
	} else {
		return false;
	}
}

bool Datas::operator==(const Datas &data_) const {
	if (dia == data_.dia and mes == data_.mes and ano == data_.ano)
	{
		return true;
	} else {
		return false;
	}

}

Datas& Datas::operator=(const Datas &data_) {
	ano = data_.ano;
	mes = data_.mes;
	dia = data_.dia;
	return *this;
}

std::ostream& operator<< (std::ostream &o, Datas &data_){
	
	o << data_.dia << "/" << data_.mes << "/" << data_.ano;

	return o;
}