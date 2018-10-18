//ALUNOS:: CLEVERSON SOUZA , SAID OLIVEIRA
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "kenoH.h"
#include <ctime> 
#include <cstdlib>
#include <random>
										
										
using std::cout;
using std::endl;
using std::vector;
//using 20 = 20;

int main(){

vector< std::vector< float > > tabela =									
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
	int value,a;							//Valor lido do arq.txt
	vector<number_type> numeros;		//Vetor com os numeros apostados 
	vector<number_type> numerosRandoms;	//Vetor com os numeros sorteados 
	numerosRandoms.reserve(20);			//Reserva o espaço de 20 no vector dos numeros randoms				
	vector<number_type> matchs;			//Vetor com numeros acertados na rodada
	int aux;
	float somaAtual,somaTotal,apostaAtual;

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
		cout<<"Insira Valores válidos";
		return 0;
	}



	cout<< "Acertos 	 Multiplicador do cŕedito"<<endl;		//Imprime a tabela Inicial
	for(int i=0 ; i<=numeros.size() ; i++)
	{
		cout<<i<<" 	 .	 "<<tabela[numeros.size()-1][i]<<endl;
	}



	Keno.setApostas(numeros);			//vide .h

	cout <<"Credito do jogador: " << Keno.getCredito() << endl;
	cout <<"Numero de rodadas: " << Keno.getRodadas() << endl;
	cout <<"Numeros apostados: ";
	ordenaVetor(numeros);
	imprimeVetor(numeros);//Imprime numero apostados

	imprimePonto();

	apostaAtual = Keno.getCredito()/Keno.getRodadas(); //Aposta atual é o valor apostado em todas as rodadas
	somaTotal = Keno.getCredito();//Soma total inicializada como o credito inicial
	for(int i(1) ; i<=Keno.getRodadas() ; i++) //Inicio do jogo
	{
		matchs.clear();
		cout << ">>>Rodada número "<<i<<" de "<<Keno.getRodadas()<< "<<<"<<endl<<endl;
		cout << ">>>Sua aposta é de: "<<apostaAtual<< endl;
		cout << ">>>Numeros sorteados: ";
		Keno.geraNumSorteados(numerosRandoms);
		ordenaVetor(numerosRandoms);
		


		//------------------------------------------------------------------------------------------
		//imprimeVetor(numerosRandoms);//Imprime Os numeros sorteados//A FUNÇÃO NAO FUNCIONA PARA OS NUMEROS RANDOMS	
		for(int i=0;i<20;i++)
		{
				
			aux=0;
			for(int j=i+1;j<20;j++)						//Ordena o vetor dos sorteados de modo batata
			{	
				if(numerosRandoms[i]>numerosRandoms[j])
        		{
        			aux=numerosRandoms[i];
        			numerosRandoms[i]=numerosRandoms[j];
        			numerosRandoms[j]=aux;
        		}
        	}
    	}
		for(int i=0 ; i<20 ; i++)
		{	
		cout<<numerosRandoms[i]<<' ';
		}
		//----------------------------------------------------------------------------------------------





		a = qtdAcertos( numeros , numerosRandoms, matchs );		//Devolve a qtd de acertos e vetor com os numeros acertados 

		somaAtual = creditoAtual(Keno.getCredito()/Keno.getRodadas(), tabela[numeros.size()-1][a] , apostaAtual);
		//somaTotal = creditoSoma(somaAtual,somaTotal);
		//cout<<"\n\n valor multiplicativo>>>>>>"<<tabela[numeros.size()-1][a]<<"\n\nSoma atual>>>"<<somaAtual<<"\n\n";
		somaTotal = somaTotal + somaAtual;

		cout <<"\nQuantidade de acertos >>>" <<a <<endl;
		cout <<"Numeros acertados:  ";
		imprimeVetor(matchs);
		cout<<"O valor multiplicativo de sua aposta é de "<< tabela[numeros.size()-1][a]<<endl;
		if (somaAtual==0)
		{
		cout<<"Nessa rodada você não ganhou nada"<< endl;
		}
		if (somaAtual>0)
		{
		cout<<"Nessa rodada voce ganhou  >"<<somaAtual<<endl;;
		}
		if (somaAtual<0)
		{
		cout<<"Nessa rodada voce perdeu  >"<<-somaAtual<<endl;
		}
		if (!(Keno.verificaCredito(somaTotal)))		//Garante que se credito = 0 o programa encerra
		{
			cout<<"Vc perdeu TU-DO";
			cout<<endl;
			return 0;
		}
		cout<<"Voce esta com um montante de >  "<<somaTotal<<"  <"<<endl;
		imprimePonto();
	}	

	encerraPrograma(Keno.getCredito(), somaTotal);


		
	

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