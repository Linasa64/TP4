/*************************************************************************
                           Requete  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include <iostream>

//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Requete::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

const string Requete::GetIp() const{
    return ip;
}

const string Requete::GetDate() const{
    return date;
}

const string Requete::GetHeure() const{
    return heure;
}

const string Requete::GetCible() const{
    return cible;
}

const string Requete::GetCodeHTTP() const{
    return codeHTTP;
}

const string Requete::GetQtDonnees() const{
    return qtDonnees;
}

const string Requete::GetRef() const{
    return ref;
}

const string Requete::GetClient() const{
    return client;
}

const string Requete::GetLogName() const{
    return logName;
}

const string Requete::GetAuthenticatedUser() const{
    return authenticatedUser;
}



void Requete::SetIp(string chaine){
    ip = chaine;
}

void Requete::SetDate(string chaine){
    date = chaine;
}

void Requete::SetHeure(string chaine){
    heure = chaine;
}

void Requete::SetCible(string chaine){
    cible = chaine;
}

void Requete::SetCodeHTTP(string chaine){
    codeHTTP = chaine;
}

void Requete::SetQtDonnees(string chaine){
    qtDonnees = chaine;
}

void Requete::SetRef(string chaine){
    ref = chaine;
}

void Requete::SetClient(string chaine){
    client = chaine;
}

void Requete::SetLogName(string chaine){
    logName = chaine;
}

void Requete::SetAuthenticatedUser(string chaine){
    authenticatedUser = chaine;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Requete::Requete ( const Requete & unRequete )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif

} //----- Fin de Requete (constructeur de copie)


Requete::Requete ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif

    ip = "";
    date = "";
    heure = "";
    cible = "";
    codeHTTP = "";
    qtDonnees = "";
    ref = "";
    client = "";

} //----- Fin de Requete


Requete::~Requete ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif

} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

