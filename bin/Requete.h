/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if !defined(REQUETE_H)
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <string>
#include <regex>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//
//
//------------------------------------------------------------------------

class Requete
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );


    const void printRequete() const;
    // Mode d'emploi : Affichage des attributs de la requête
    //
    // Contrat :
    //

    // ---- Get ---- //
    const string GetIp() const;
    const string GetLogName() const;
    const string GetAuthenticatedUser() const;
    const string GetFuseau() const;
    const string GetType() const;
    const string GetDate() const;
    const string GetHeure() const;
    const string GetMinute() const;
    const string GetSeconde() const;
    const string GetCible() const;
    const string GetCibleType() const;
    const string GetVersionHTTP() const;
    const string GetCodeHTTP() const;
    const string GetQtDonnees() const;
    const string GetRef() const;
    const string GetRefType() const;
    const string GetClient() const;
    // ---- --- ---- //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Requete(string str);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Requete();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string ip;
    string logName;
    string authenticatedUser;
    string date;
    string heure;
    string minute;
    string seconde;
    string fuseau;
    string type;
    string cible;
    string cibleType;
    string versionHTTP;
    string codeHTTP;
    string qtDonnees;
    string ref;
    string refType;
    string client;
};

//-------------------------------- Autres définitions dépendantes de <Requete>

#endif // REQUETE_H