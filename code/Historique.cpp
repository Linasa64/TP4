/*************************************************************************
                           Historique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Historique> (fichier Historique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Historique.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Historique::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Historique & Historique::operator = ( const Historique & unHistorique )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Historique::Historique ( const Historique & unHistorique )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Historique>" << endl;
#endif
} //----- Fin de Historique (constructeur de copie)


Historique::Historique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Historique>" << endl;
#endif
} //----- Fin de Historique


Historique::~Historique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Historique>" << endl;
#endif
} //----- Fin de ~Historique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

