
keno:	keno.o kenoimp.o 
	g++	 keno.o kenoimp.o -Wall

keno.o: keno.cpp
	g++  -c keno.cpp -std=c++11 -Wall

kenoimp.o: kenoimp.cpp 
	g++	-c kenoimp.cpp -std=c++11 -Wall

kenoH.o: kenoH.h 
	g++ -c kenoH.h -std=c++11 -Wall

clean:
	rm *.o