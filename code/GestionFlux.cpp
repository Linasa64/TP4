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
// type GestionFlux::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


list<Requete *> GestionFlux::LectureFichier(){
    
// Lecture du fichier
    string line;

    while(getline(fic, line))
    {
        Requete * rq = new Requete(line);
        listRq.push_back(rq);
    }
    //listRq.back().printRequete();
    return listRq;            
}

const list<Requete *> GestionFlux::GetlistRq() const{
    return listRq;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
GestionFlux::GestionFlux ( const GestionFlux & unGestionFlux )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionFlux>" << endl;
#endif
} //----- Fin de GestionFlux (constructeur de copie)


GestionFlux::GestionFlux ( string nomFic )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GestionFlux>" << endl;
#endif
    if((nomFic.substr(nomFic.size() - 3) != "txt") && (nomFic.substr(nomFic.size() - 3) != "log")){
        cerr << "____ EXTENSION INCONNUE ____"  << endl;
        exit (EXIT_FAILURE);
    }
    if (!fic){
        cerr << "____ FICHIER INEXISTANT ____"  << endl;
        exit (EXIT_FAILURE);
    } 
    
    fic.open(nomFic, ios_base::in);
    
    LectureFichier();
    //listRq.back().printRequete();
} //----- Fin de GestionFlux


GestionFlux::~GestionFlux ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionFlux>" << endl;
#endif
    fic.close();
} //----- Fin de ~GestionFlux


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
