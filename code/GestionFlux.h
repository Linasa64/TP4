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
#include <list>
#include <fstream>
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
    list<Requete *> LectureFichier();
    const list<Requete *> GetlistRq() const;

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
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


//----------------------------------------------------- Attributs protégés

list<Requete *> listRq;
ifstream fic;

};

//-------------------------------- Autres définitions dépendantes de <GestionFlux>

#endif // GESTIONFLUX_H

