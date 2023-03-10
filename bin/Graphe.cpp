/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <map>

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Historique.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Graphe::Graphe(map<string, pair<int, map<string, int>>> &m, map<string, int> mapCles, string nomFic)
// Algorithme :
// Le constructeur de Graphe remplit le fichier .dot qui sert à la génération du graphe
// puis lance la commande système de génération du graphe en image
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif

    gFile.open(nomFic);
    gFile << "digraph {" << endl;

    // Lister tous les nodes de l'historique avec leur bon id (numéro)
    for (auto itr = mapCles.begin(); itr != mapCles.end(); itr++)
    {
        gFile << "node" << mapCles[itr->first] << " [label=\"" << itr->first << "\"];" << endl;
    }

    // Boucle sur les cibles
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        // Boucle sur les referer de la cible courante
        for (auto itr2 = itr->second.second.begin(); itr2 != itr->second.second.end(); itr2++)
        {
            gFile << "node" << mapCles[itr2->first] << " -> node" << mapCles[itr->first] << " [label=\"" << m[itr->first].second.at(itr2->first) << "\"];" << endl;
        }
    }

    gFile << "}" << endl;
    gFile.close();
    string n = nomFic;
    n.erase(n.size() - 4, 4);
    system(("dot -Tpng -o " + n + ".jpg " + nomFic).c_str());
    return;
} //----- Fin de Graphe

Graphe::~Graphe()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
