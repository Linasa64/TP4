EXE = analog
OBJETS = analog.o Requete.o GestionFlux.o Historique.o Graphe.o
FLAGS = -c -ansi -pedantic -std=c++11 -Wall # pour débug -c -DMAP -std=c++11 -ansi -Wall -pedantic

$(EXE): $(OBJETS)
	g++ -o $(EXE) $(OBJETS)
	rm *.o

Requete.o: Requete.cpp
	g++ $(FLAGS) Requete.cpp

GestionFlux.o: GestionFlux.cpp
	g++ $(FLAGS) GestionFlux.cpp

Historique.o: Historique.cpp
	g++ $(FLAGS) Historique.cpp
	
Graphe.o: Graphe.cpp
	g++ $(FLAGS) Graphe.cpp

analog.o: analog.cpp
	g++ $(FLAGS) analog.cpp

clean:
	rm $(EXE)
