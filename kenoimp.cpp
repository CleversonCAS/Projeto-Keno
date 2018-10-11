#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "kenoH.h"
#include <ctime> 
#include <cstdlib>
#include <random>

using namespace std;


void encerraPrograma(float creditoInicial, float creditoFinal)
	{
		cout<<"		 ---RESUMO---\nValor apostado -> "<<creditoInicial<<"\nValor ganhado no jogo - >"
			<<creditoFinal-creditoInicial<<"\nEstais saindo da mesa com -> "<<creditoFinal<<endl;
	}

void imprimePonto()
{
	cout<<"\n\n-----------------------------------------------------------------------------\n\n";
}

void imprimeVetor(std::vector<number_type> &vector1)
{
	for (int i = 0; i < vector1.size(); i++)
	{
		cout<<vector1[i]<<' ';
	}
	cout<<endl;
}

int rand_number(){
	random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(1, 25);

	return round(dis(gen));
}

int qtdAcertos(std::vector<number_type> &numapostados , std::vector<number_type> &numsorteados,std::vector<number_type> &matchs)
{
	int acertos=0;
	for(number_type k=0 ; k <= numapostados.size() ; k++)
	{
		for(number_type l = 0 ; l < 20 ; l++)
		{
			if(numapostados[k] == numsorteados[l])
			{
				matchs.push_back(numapostados[k]);
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

bool verificaNumero(std::vector<number_type> &testeNum,int tam, number_type valor)
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

void KenoBet::geraNumSorteados(std::vector<number_type> &vec)
{	
	int v;	//Auxiliar que garante que não existirá numero repetido em numero randoms, (atualizar para função essa etapa)
	vec.reserve(25);
		//Gera vetor com os numeros sorteados  //fazer função pra isso  //como retornar um vector e utiliza-lo(?)
		for(number_type j = 0; j < 20; j++)
		{	
			vec[j] = rand_number();
			while(verificaNumero(vec,j,vec[j])) //Deveria garantir que o numero inserido n é repetido
			{
				v = rand_number();
				vec[j] = v;
			}
		}
}