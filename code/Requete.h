/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( REQUETE_H )
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <string>

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
    // Mode d'emploi :
    //
    // Contrat :
    //
    const string GetIp() const;
    const string GetDate() const;
    const string GetHeure() const;
    const string GetCible() const;
    const string GetCodeHTTP() const;
    const string GetQtDonnees() const;
    const string GetRef() const;
    const string GetClient() const;
    const string GetLogName() const;
    const string GetAuthenticatedUser() const;

    void SetIp(string chaine);
    void SetDate(string chaine);
    void SetHeure(string chaine);
    void SetCible(string chaine);
    void SetCodeHTTP(string chaine);
    void SetQtDonnees(string chaine);
    void SetRef(string chaine);
    void SetClient(string chaine);
    void SetLogName(string chaine);
    void SetAuthenticatedUser(string chaine);


//------------------------------------------------- Surcharge d'opérateurs
    Requete & operator = ( const Requete & unRequete );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Requete ( const Requete & unRequete );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Requete ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Requete ( );
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
    string cible;
    string codeHTTP;
    string qtDonnees;
    string ref;
    string client;


};

//-------------------------------- Autres définitions dépendantes de <Requete>

#endif // REQUETE_H

