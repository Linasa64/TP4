/*************************************************************************
                           GestionFlux  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <GestionFlux> (fichier GestionFlux.h) ----------------
#if !defined(GESTIONFLUX_H)
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

    void LectureFichier();
    // Mode d'emploi : Remplie une liste de requête à partir d'un flux en attribut
    //  
    // Contrat : 
    //

    const list<Requete *> GetlistRq() const;
    // Mode d'emploi : Renvoi la liste de requête formée
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    GestionFlux(string nomFic);
    // Mode d'emploi : En paramètre le nom du fichier à lire
    //
    // Contrat :
    //

    virtual ~GestionFlux();
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
