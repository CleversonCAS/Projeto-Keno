
keno:	keno.o kenoimp.o 
	g++	 keno.o kenoimp.o 

keno.o: keno.cpp
	g++  -c keno.cpp -std=c++11 

kenoimp.o: kenoimp.cpp 
	g++	-c kenoimp.cpp -std=c++11 

kenoH.o: kenoH.h 
	g++ -c kenoH.h -std=c++11 

clean:
	rm *.o