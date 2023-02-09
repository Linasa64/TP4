/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if !defined(Graphe_H)
#define Graphe_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
// Crée le .dot des requêtes et l'image du graphe
//
//------------------------------------------------------------------------

class Graphe
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Graphe(map<string, pair<int, map<string, int>>> &m, map<string, int> mapCles, string nomFicDot);
    // Mode d'emploi : 
    //
    // Contrat :
    //

    virtual ~Graphe();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    ofstream gFile;
};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // Graphe_H
