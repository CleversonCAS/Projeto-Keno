//ALUNOS:: CLEVERSON SOUZA , SAID OLIVEIRA
#ifndef KENOH_H
#define KENOH_H
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <ctime> 
#include <cstdlib>

using number_type = int; //<! data type for a keno hit.

void ordenaVetor(std::vector<number_type> &vet);

void encerraPrograma(float creditoInicial, float creditoFinal);

bool verificaNumero(number_type valor,number_type valor2);//Verifica se o numero selecionado está no vetor

void geraNumSorteados(std::vector<number_type> &vec);

int qtdAcertos(std::vector<number_type> &numapostados , std::vector<number_type> &numsorteados,std::vector<number_type> &matchs);//Returna a quatidade de coicidencias entre os numeros apostados e os numeros sorteados
																																 //e devolve um vetor com numeros sorteados;
int rand_number();

void imprimeVetor(std::vector<number_type> &vector);

void imprimePonto();

float creditoAtual(float x, float multi , float apostaAtual);//recebe o credito atual e atualiza de acordo com a tabela

float creditoSoma(float creditoAtual, float creditoDaRodada);	//recebe o credito atual e e o inicial e faz a soma

class KenoBet{
	private:
		number_type rodadas;         	  //<!The player's rounds.
		std::vector<number_type> apostas; //<!The player's bet.
		float credito;     
		float creditoAtual;
		float creditoSoma;               //<!The player's wage.
		std::vector<number_type> apostafinal;
		std::vector<number_type> numApostados;


	public:

		void setCredito(float x);			//recebe o credito
		float getCredito();					//devolve o credito

		void setRodadas(number_type x);		//recebe num de rodadas
		number_type getRodadas();			//devolve num de rodadas

		void setApostas(std::vector<number_type> &apostas);//Recebe um vetor com as apostas dadas pelo jogador no arquivo //Atualizar para que devolva apenas as apostas uteis

		bool verificaCredito(float apostaDada);//Verifica se a aposta é válida

		void reset(void);//Zera a aposta(?)

		void geraNumSorteados(std::vector<number_type> &vec);

		
};

#endif