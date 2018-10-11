#ifndef KENO_H
#define KENO_H
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <ctime> 
#include <cstdlib>

using number_type = unsigned short int; //<! data type for a keno hit.




int qtdAcertos(std::vector<number_type> &numapostados , std::vector<number_type> &numsorteados );//Returna a quatidade de coicidencias entre os numeros apostados e os numeros sorteados

int rand_number();

class KenoBet{
	private:
		number_type rodadas;         	  //<!The player's rounds.
		std::vector<number_type> apostas; //<!The player's bet.
		float credito;                    //<!The player's wage.
		std::vector<number_type> apostafinal;
		std::vector<number_type> numApostados;


	public:
		float getCredito();					//devolve o credito
		void setCredito(float x);			//recebe o credito
		number_type getRodadas();			//devolve num de rodadas
		void setRodadas(number_type x);		//recebe num de rodadas
		void setApostas(std::vector<number_type> &apostas);//Recebe um vetor com as apostas dadas pelo jogador no arquivo //Atualizar para que devolva apenas as apostas uteis

		bool verificaNumero(std::vector<number_type> &testeNum,int tam, number_type valor);//Verifica se o numero selecionado está no vetor
		bool verificaCredito(float apostaDada);//Verifica se a aposta é válida
		void reset(void);//Zera a aposta(?)


		
};




#endif