#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "keno.h"
#include <ctime> 
#include <cstdlib>
#include <random>
										//Como passar a tabela sem ser com 225 if/if else(?)
										
using std::cout;
using std::endl;
using std::vector;

int main(){

vector< std::vector< float > > payout_table =									
{
{ 0, 3 }, // 1 spot
{ 0, 1, 9 }, // 2 spots
{ 0, 1, 2, 16 }, // 3 spots
{ 0, 0.5, 2, 6, 12 }, // 4 spots
{ 0, 0.5, 1, 3, 15, 50 }, // 5 spots
{ 0, 0.5, 1, 2, 3, 30, 75 }, // 6 spots
{ 0, 0.5, 0.5, 1, 6, 12, 36, 100 }, // 7 spots
{ 0, 0.5, 0.5, 1, 3, 6, 19, 90, 720 }, // 8 spots
{ 0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200 }, // 9 spots
{ 0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800 }, // 10 spots
{ 0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000 }, // 11 spots
{ 0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000 }, // 12 spots
{ 0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000 }, // 13 spots
{ 0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500 }, // 14 spots
{ 0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000 } // 15 spots
};
	std::ifstream file("keno.txt");		//abre o arquivo.txt
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

	if (!(Keno.verificaCredito(Keno.getCredito())))
	{
		cout<<"Insira um crédito válido";
		return 0;
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
	for(number_type k = 0; k < Keno.getRodadas(); k++)		//Gera vetor com os numeros sorteados  //fazer função pra isso  //como retornar um vector e utiliza-lo(?)
	{
		for(number_type j = 0; j < 20; j++)
		{	
			numerosRandoms[j] = rand_number();
			while(Keno.verificaNumero(numerosRandoms,j,numerosRandoms[j])) //Deveria garantir que o numero inserido n é repetido
			{
				v = rand_number();
				numerosRandoms[j] = v;
			}
		}

			for(number_type j = 0; j < 20; j++)
			{
				cout << numerosRandoms[j] << ' '; 
			}


		//Aqui deve haver a atualização do credito por rodada 


		if (!(Keno.verificaCredito(Keno.getCredito())))		//Garante que se credito = 0 o programa encerra
		{
			cout<<"";
			return 0;
		}
		int a = qtdAcertos( numeros , numerosRandoms );		//Devolve a qtd de acertos
		cout <<"QTD DE ACERTOS::::" <<a <<endl;
		

		}


		
	

	return 0;
} 
/*
se você quer por exemplo a posição 3 dele (`

payout_table[3]`

)
ela irá retornar o vetor {0, 1, 2, 16}
ai dentor dele vc pode iterar, acessar diretamente, oq vc quiser
se vc quisesse iterar sobre ele, poderia utilizar os iteradores que já existem na biblioteca do vector, ou seja, fazer um 
for( auto &i : payout_table[3] ){ ... } (caso esteja acostumado com essa sintaxe já
Se quiser acessar diretamente, poderia simplesmente fazer payout_table[3][n] sendo n o número do elemento que vc quer ({0, 1, 2, 16})*/