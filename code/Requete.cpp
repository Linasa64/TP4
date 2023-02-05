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




void Requete::SetIp(string &chaine){
    string tip = chaine;
    this->ip.assign(tip);
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


Requete::Requete (string & str)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif

    string s = str;
    smatch m;

    // IP
	regex re("([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3})(.+)");
	if(regex_match(s, m, re)){
        string ip = m[1];
        this->ip = ip;
        s= m[2];
    }
    else{
        cout << "IP non trouvee" << endl;
    }

    //logName
    regex re2("\\s([^\\s]+)\\s(.+)");
    if(regex_match(s, m, re2)){
        string logname = m[1];
        this->logName = logName;
        s= m[2];
    }
    else{
        cout << "logname non trouve" << endl;
    }

    //authenticatedUser
    regex re3("([^\\s]+)\\s(.+)");
    if(regex_match(s, m, re3)){
        string authenticatedUser = m[1];
        this->authenticatedUser = authenticatedUser;
        s= m[2];
    }
    else{
        cout << "authenticatedUser non trouve" << endl;
    }

    //date
    regex re4("^\\[([^\\:]+)(.+)");
    if(regex_match(s, m, re4)){
        string date = m[1];
        this->date = date;
        s= m[2];
    }
    else{
        cout << "date non trouvee" << endl;
    }

    //heure
    regex re5("^:([^\\s]+)(.+)");
    if(regex_match(s, m, re5)){
        string heure = m[1];
        this->heure = heure;
        s= m[2];
    }
    else{
        cout << "heure non trouvee" << endl;
    }

    //fuseau
    regex re6("\\s\\+([^\\s]+)\\](.+)");
    if(regex_match(s, m, re6)){
        string fuseau = m[1];
        this->fuseau = fuseau;
        s= m[2];
    }
    else{
        cout << "fuseau non trouve" << endl;
    }

    //type
    regex re7("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re7)){
        string type = m[1];
        type.erase(0,1);
        this->type = type;
        s= m[2];
    }
    else{
        cout << "type non trouve" << endl;
    }
    
    //cible
    regex re8("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re8)){
        string cible = m[1];
        this->cible = cible;
        s= m[2];
    }
    else{
        cout << "cible non trouvee" << endl;
    }

    //Version HTTP
    regex re9("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re9)){
        string version = m[1];
        this->versionHTTP = version;
        s= m[2];
    }
    else{
        cout << "version http non trouvee" << endl;
    }

    //code http
    regex re10("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re10)){
        string code = m[1];
        this->codeHTTP = code;
        s= m[2];
    }
    else{
        cout << "code http non trouve" << endl;
    }

    //taille octet réponse
    regex re11("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re11)){
        string qtData = m[1];
        this->qtDonnees = qtData;
        s= m[2];
    }
    else{
        cout << "qt donnees http non trouvee" << endl;
    }

    //referer
    regex re12("\\s\"([^\\s\"]+)(.+)");
    if(regex_match(s, m, re12)){
        string ref = m[1];
        this->ref = ref;
        s= m[2];
        s.erase(0,1);
    }
    else{
        cout << "ref non trouve" << endl;
    }

    //id client navigateur
    regex re13("\\s\"([^\"]+)(.+)");
    if(regex_match(s, m, re13)){
        string client = m[1];
        this->client = client;
        s= m[2];
    }
    else{
        cout << "client non trouve" << endl;
    }

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

