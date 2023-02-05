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

const void Requete::printRequete() const{
    cout << "IP : " << ip << endl;
    cout << "logName : " << logName << endl;
    cout << "authenticatedUser : " << authenticatedUser << endl;
    cout << "date : " << date << endl;
    cout << "heure : " << heure << endl;
    cout << "fuseau : " << fuseau << endl;
    cout << "type : " << type << endl;
    cout << "cible : " << cible << endl;
    cout << "versionHTTP : " << versionHTTP << endl;
    cout << "codeHTTP : " << codeHTTP << endl;
    cout << "qtDonnees : " << qtDonnees << endl;
    cout << "ref : " << ref << endl;
    cout << "client : " << client << endl;
}

const string Requete::GetIp() const{
    return ip;
}

const string Requete::GetLogName() const{
    return logName;
}

const string Requete::GetAuthenticatedUser() const {
    return authenticatedUser;
}

const string Requete::GetDate() const{
    return date;
}

const string Requete::GetHeure() const{
    return heure;
}

const string Requete::GetFuseau() const {
    return fuseau;
}

const string Requete::GetType() const {
    return type;
}

const string Requete::GetCible() const{
    return cible;
}

const string Requete::GetVersionHTTP() const{
    return versionHTTP;
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




void Requete::SetIp(string chaine){
    ip = chaine;
}

void Requete::SetLogName(string chaine){
    logName = chaine;
}

void Requete::SetAuthenticatedUser(string chaine){
    authenticatedUser = chaine;
}

void Requete::SetDate(string chaine){
    date = chaine;
}

void Requete::SetHeure(string chaine){
    heure = chaine;
}

void Requete::SetFuseau(string chaine){
    fuseau = chaine;
}

void Requete::SetType(string chaine){
    type = chaine;
}

void Requete::SetCible(string chaine){
    cible = chaine;
}

void Requete::SetVersionHTTP(string chaine){
    versionHTTP = chaine;
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
    logName = "";
    authenticatedUser = "";
    date = "";
    heure = "";
    fuseau = "";
    type = "";
    cible = "";
    versionHTTP = "";
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

