EXE = analog
OBJETS = analog.o Requete.o GestionFlux.o Historique.cpp
FLAGS = -c -ansi -pedantic -std=c++11 -Wall # pour débug -c -DMAP -std=c++11 -ansi -Wall -pedantic

$(EXE): $(OBJETS)
	g++ -o $(EXE) $(OBJETS)

Requete.o: Requete.cpp
	g++ $(FLAGS) Requete.cpp

GestionFlux.o: GestionFlux.cpp
	g++ $(FLAGS) GestionFlux.cpp

Historique.o: Historique.cpp
	g++ $(FLAGS) Historique.cpp

analog.o: analog.cpp
	g++ $(FLAGS) analog.cpp

clean:
	rm $(OBJETS) $(EXE)
