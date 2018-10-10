#include <iostream>
#include <vector>
#include <fstream>
#include "keno.h"

using namespace std;

int main(){
	ifstream file("keno.txt");

	KenoBet Keno;
	int cont = 1;
	int value;
	vector<unsigned short int> numeros;
	while(true){
		if(!(file >> value)){
			break;
		}
		if(cont == 1){
			Keno.setCredito(value);
		}else if(cont == 2){
			Keno.setRodadas(value);
		}else if(cont > 2){
			numeros.push_back(value);
		}
		if(!file.eof()){
			cont++;
		}
	}

	Keno.setApostas(numeros);

	cout <<"Credito do jogador: " << Keno.getCredito() << endl;
	cout <<"Numero de rodadas: " << Keno.getRodadas() << endl;

	cout <<"Numeros apostados: ";
	for(int i = 0; i < numeros.size(); i++){
		cout << numeros[i] << " ";
	}
	cout << endl;
	
	return 0;
} 
