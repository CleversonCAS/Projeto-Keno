#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "kenoH.h"
#include <ctime> 
#include <cstdlib>
#include <random>

using namespace std;


void ordenaVetor(std::vector<number_type> &vet)
{	
	int aux;
	for(int i=0;i<vet.size();i++)
	{
		aux=0;
		for(int j=i+1;j<vet.size();j++)
		{
			if(vet[i]>vet[j])
        	{
        		aux=vet[i];
        		vet[i]=vet[j];
        		vet[j]=aux;
        	}
        }
     }
}

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
    uniform_int_distribution<> dis(1, 80);

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

bool verificaNumero(number_type valor,number_type valor2)
{	
	return valor==valor2;
}

bool KenoBet::verificaCredito(float credito){
	return credito > 0;
}

void KenoBet::reset(){
	credito = 0;
}

void KenoBet::geraNumSorteados(std::vector<number_type> &vec)
{	
	int v;	//Auxiliar que garante que não existirá numero repetido em no Vector, 
	vec.reserve(20);
		//Gera vetor com os numeros sorteados 
		for(number_type j = 0; j < 20; j++)
		{	
				vec[j] = rand_number();
				for(int i = 0 ; i<j ; i++)
				{
					while(verificaNumero(vec[i],vec[j])) //Deveria garantir que o numero inserido n é repetido
					{
						v = rand_number();
						vec[j] = v;
						i=0;
					}
				}
		}
}
float creditoAtual(float x, int multi , float apostaAtual)
{	
	return (apostaAtual * multi) - x;
}

float creditoSoma(float creditoAtual, float creditoTotal)
{
	return creditoTotal + creditoAtual;
}