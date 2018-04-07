
play: main.o utility.o character.o barbarian.o vampire.o bluemen.o medusa.o harrypotter.o
	g++ -std=c++0x -g main.o utility.o character.o barbarian.o vampire.o bluemen.o medusa.o harrypotter.o -o play 

main.o: main.cpp character.cpp barbarian.cpp vampire.cpp bluemen.cpp medusa.cpp harrypotter.cpp
	g++ -std=c++0x -g -c main.cpp character.cpp barbarian.cpp vampire.cpp bluemen.cpp medusa.cpp harrypotter.cpp 

utility.o: utility.cpp utility.hpp
	g++ -std=c++0x -g -c utility.cpp

character.o: character.cpp character.hpp
	g++ -std=c++0x -g -c character.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -std=c++0x -g -c barbarian.cpp 

vampire.o: vampire.cpp vampire.hpp
	g++ -std=c++0x -g -c vampire.cpp

bluemen.o: bluemen.cpp bluemen.hpp
	g++ -std=c++0x -g -c bluemen.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -std=c++0x -g -c medusa.cpp

harrypotter.o: harrypotter.cpp harrypotter.hpp
	g++ -std=c++0x -g -c harrypotter.cpp

clean:
	rm *.o play 
