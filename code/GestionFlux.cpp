/*************************************************************************
                           GestionFlux  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <GestionFlux> (fichier GestionFlux.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <regex>
#include <cstdlib>
#include <list>

//------------------------------------------------------ Include personnel
#include "GestionFlux.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


void GestionFlux::LectureFichier()
// Algorithme :
//
{
    string line;

    while (getline(fic, line))
    {
        string l = line;
        Requete *rq = new Requete(l);
        listRq.push_back(rq);
    }
}
//----- Fin de Méthode

const list<Requete *> GestionFlux::GetlistRq() const
// Algorithme :
//
{
    return listRq;
}
//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

GestionFlux::GestionFlux(string nomFic)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GestionFlux>" << endl;
#endif
    if ((nomFic.substr(nomFic.size() - 3) != "txt") && (nomFic.substr(nomFic.size() - 3) != "log"))
    {
        cerr << "____ EXTENSION INCONNUE ____" << endl;
        exit(EXIT_FAILURE);
    }
    fic.open(nomFic, ios_base::in);
    if (!fic)
    {
        cerr << "____ FICHIER INEXISTANT ____"  << endl;
        exit (EXIT_FAILURE);
    } 
    if(fic.get() != EOF)
        LectureFichier();
    else
        cerr << "Fichier vide" << endl;

    fic.close();
} //----- Fin de GestionFlux

GestionFlux::~GestionFlux()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionFlux>" << endl;
#endif

} //----- Fin de ~GestionFlux

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
