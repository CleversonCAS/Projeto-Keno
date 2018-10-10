#ifndef KENO_H
#define KENO_H
#include <vector>
#include <stdlib.h>

using number_type = unsigned short int; //<! data type for a keno hit.

class randomNumber{
public:
	int randomNumberGenerator(){
		return (rand() % 80);
	}
};

class KenoBet{
	private:
		number_type rodadas;         	  //<!The player's rounds.
		std::vector<number_type> apostas; //<!The player's bet.
		float credito;                    //<!The player's wage.
		std::vector<numer_type> apostafinal;

	public:
		float getCredito();
		void setCredito(float x);
		number_type getRodadas();
		void setRodadas(number_type x);
		void setApostas(std::vector<number_type> &apostas);//Recebe um vetor com as apostas dadas pelo jogador no arquivo

		bool verificaNumero(number_type num);//Verifica se o numero selecionado está no vetor
		bool verificaCredito(float apostaDada);//Verifica sea aposta é válida
		void reset(void);//Zera a aposta(?)
		

		
};

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

bool KenoBet::verificaNumero(number_type num){
	for(int i = 0; i < apostas.size(); i++){
		if(apostas[i] == num){
			return false;
		}
	}
	return true;
}

bool KenoBet::verificaCredito(float credito){
	return credito > 0;
}

void KenoBet::reset(){
	credito = 0;
}

#endif