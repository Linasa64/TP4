/*************************************************************************
                           Historique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Historique> (fichier Historique.h) ----------------
#if ! defined ( HISTORIQUE_H )
#define HISTORIQUE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Historique>
//
//
//------------------------------------------------------------------------

class Historique : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Historique & operator = ( const Historique & unHistorique );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Historique ( const Historique & unHistorique );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Historique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Historique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Historique>

#endif // HISTORIQUE_H

