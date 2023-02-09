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
// Contient toutes les requêtes voulues, en fait un top10 et trie les requêtes selon
// la cible et les referer associés et selon le nombre de hit
//------------------------------------------------------------------------

class Historique
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void Top10();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjoutRequete(Requete *rq);
    // Mode d'emploi :
    //
    // Contrat :
    //

    map<string, pair<int, map<string, int>>> GetMapComplete();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    map<string, int> GetMapClesCible();
    // Mode d'emploi :
    //
    // Contrat :
    //

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
