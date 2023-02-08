/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include <iostream>
#include <fstream>
#include <map>
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Historique.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Graphe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe ( const Graphe & unGraphe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphe>" << endl;
#endif
} //----- Fin de Graphe (constructeur de copie)


Graphe::Graphe (map<string, pair<int, map<string, int>>> &m, map<string, int> mapCles)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif

    gFile.open("gFile.dot");
    gFile << "digraph {" << endl;

    for (auto itr = mapCles.begin(); itr != mapCles.end(); itr++) {
        gFile << "node" << mapCles[itr->first] << " [label=\"" << itr->first << "\"];" << endl;
    }
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        for (auto itr2 = itr->second.second.begin(); itr2 != itr->second.second.end(); itr2++) {
            gFile << "node" << mapCles[itr2->first] << " -> node" << mapCles[itr->first] << " [label=\"" << m[itr->first].second.at(itr2->first) << "\"];" << endl; 
        }
    }

    gFile << "}" << endl;
    gFile.close();
    system("dot -Tpng -o court.png court.dot");
    return;
} //----- Fin de Graphe


Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

