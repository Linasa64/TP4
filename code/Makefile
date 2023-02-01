EXE = analog
OBJETS = GestionFlux.o Requete.o analog.o 
FLAGS = -c -std=c++11 -ansi -Wall -pedantic # pour débug -c -DMAP -std=c++11 -ansi -Wall -pedantic

$(EXE): $(OBJETS)
	g++ -o $(EXE) $(OBJETS)
	rm *.o

Requete.o: Requete.cpp
	g++ $(FLAGS) Requete.cpp

GestionFlux.o: GestionFlux.cpp
	g++ $(FLAGS) Requete.cpp

analog.o: analog.cpp
	g++ $(FLAGS) analog.cpp

clean:
	rm $(OBJETS) $(EXE)
