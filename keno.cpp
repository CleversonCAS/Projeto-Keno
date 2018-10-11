#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "keno.h"
#include <ctime> 
#include <cstdlib>
#include <random>

using namespace std;

int main(){

	ifstream file("keno.txt");			//abre o arquivo.txt
	KenoBet Keno;						//Cria o objeto Keno da classe KenoBet
	int cont = 1;						//Contador para garantir que a info está sendo lida da linha correta
	int value;							//Valor lido do arq.txt
	vector<number_type> numeros;		//Vetor com os numeros apostados (CRIAR FUNÇÃO GET E INSERIR PARA A VARIAVEL apostas CRIADA NO .h)
	vector<number_type> numerosRandoms;	//Vetor com os numeros sorteados (CRIAR FUNÇÃO GET E INSERIR PARA A VARIAVEL apostas CRIADA NO .h)
	numerosRandoms.reserve(20);			//Reserva o espaço de 20 no vector dos numeros randoms
	number_type v;						//Auxiliar que garante que não existirá numero repetido em numero randoms, (atualizar para função essa etapa)
	
	while(true){						//Lendo o arquivo e salvando nas variaveis
		if(!(file >> value)){
			break;
		}
		if(cont == 1){
			Keno.setCredito(value);		//Recebe o credito
		}else if(cont == 2){
			Keno.setRodadas(value);		//Recebe num de rodadas
		}else if(cont > 2){
			numeros.push_back(value);	//Salva os numeros apostados(atualizar para garantir que seja menos de 15 e q n exista num repetidos)
		}
		if(!file.eof()){
			cont++;
		}
	}	

	Keno.setApostas(numeros);			//vide .h

	cout <<"Credito do jogador: " << Keno.getCredito() << endl;
	cout <<"Numero de rodadas: " << Keno.getRodadas() << endl;
	cout <<"Numeros apostados: ";
	for(number_type i = 0; i < numeros.size(); i++){
		cout << numeros[i] << " ";
	}
	cout << endl;

	cout << "Numeros sorteados: " << endl;
	for(number_type k = 0; k < Keno.getRodadas(); k++)		//Gera vetor com os numeros sorteados
	{
		for(number_type j = 0; j < 20; j++)
		{
			v = rand_number();
			numerosRandoms[j] = rand_number();
		}
			for(number_type j = 0; j < 20; j++)
			{
				cout << numerosRandoms[j] << ' '; 
			}
		int a = qtdAcertos( numeros , numerosRandoms );		//Devolve a qtd de acertos
		cout <<"QTD DE ACERTOS::::" <<a <<endl;
		}
		/*for(number_type j = 0; j < 20; j++)
		{
			while(Keno.verificaNumero(numerosRandoms,20,numerosRandoms[j]))
			{
				v = rand_number();
			}
			numerosRandoms[j] = v;
		}*/
	

	return 0;
} 
