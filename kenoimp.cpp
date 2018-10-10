#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "keno.h"
#include <ctime> 
#include <cstdlib>
#include <random>

using namespace std;

int rand_number(){
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(1, 25);

	return round(dis(gen));
}

int qtdAcertos(std::vector<number_type> &numapostados , std::vector<number_type> &numsorteados )
{
	int acertos=0;
	for(number_type k=0 ; k <= numapostados.size() ; k++)
	{
		for(number_type l = 0 ; l < 20 ; l++)
		{
			if(numapostados[k] == numsorteados[l])
			{
				acertos++;
			}
		}
	}
	return acertos;
}

float KenoBet::getCredito(){
	return credito;
}

void KenoBet::setCredito(float x){
	credito = x;
}
number_type KenoBet::getRodadas(){
	return rodadas;
}

void KenoBet::setRodadas(number_type x){
	rodadas = x;
}

void KenoBet::setApostas(std::vector<number_type> &apostas){}

bool KenoBet::verificaNumero(std::vector<number_type> &testeNum,int tam, number_type valor)
{	
	for(number_type i = 0; i < tam; i++)
	{
		if (testeNum[i] == valor)
		{
			return true;
		}
		return false;	
	}
}

bool KenoBet::verificaCredito(float credito){
	return credito > 0;
}

void KenoBet::reset(){
	credito = 0;
}