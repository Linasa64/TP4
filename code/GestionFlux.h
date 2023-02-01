/*************************************************************************
                           GestionFlux  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GestionFlux> (fichier GestionFlux.h) ----------------
#if ! defined ( GESTIONFLUX_H )
#define GESTIONFLUX_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <string>
#include <iostream>
#include <forward_list>
#include "Requete.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GestionFlux>
//
//
//------------------------------------------------------------------------

class GestionFlux
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    forward_list<Requete> LectureFichier();

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    GestionFlux ( const GestionFlux & unGestionFlux );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GestionFlux ( string nomFic );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GestionFlux ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

void LectureIp(string & line);
void LectureCible(string & line);
void LectureReferer(string & line);
void LectureHeure(string & line);
void LectureCodeHTTP(string & line);
void LectureExtension(string & line);
void LectureUser(string & line);
void LectureLogName(string & line);
void LectureAutenticatedUser(string & line);

//----------------------------------------------------- Attributs protégés

forward_list<Requete> fwlistRq;
ifstream fic;

};

//-------------------------------- Autres définitions dépendantes de <GestionFlux>

#endif // GESTIONFLUX_H

