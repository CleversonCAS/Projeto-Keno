#include <fstream>
#include "keno.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <vector>

using namespace std;
int rand_number(){
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 50);

	return std::round(dis(gen));
}

int main()
{
	vector<int> a;
	a.reserve(10);
	for(int i = 0 ; i<3 ; i++ )
	{
		for(int i = 0 ; i<10 ; i++ )
		{
			a[i] = rand_number();
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}

return 0;
} 
