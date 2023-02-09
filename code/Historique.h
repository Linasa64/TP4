/*************************************************************************
                           Historique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Historique> (fichier Historique.h) ----------------
#if !defined(HISTORIQUE_H)
#define HISTORIQUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Requete.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Historique>
//
//
//------------------------------------------------------------------------

class Historique
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Top10();
    void AjoutRequete(Requete *rq);
    map<string, pair<int, map<string, int>>> GetMapComplete();
    map<string, int> GetMapClesCible();

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Historique();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Historique();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    map<string, pair<int, map<string, int>>> mapComplete;
    multimap<int, string> mpTop10;
    map<string, int> mapClesCible;
};

//-------------------------------- Autres définitions dépendantes de <Historique>

#endif // HISTORIQUE_H
