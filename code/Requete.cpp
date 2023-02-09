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
    // cout << "IP : " << ip << endl;
    // cout << "logName : " << logName << endl;
    // cout << "authenticatedUser : " << authenticatedUser << endl;
    // cout << "date : " << date << endl;
    // cout << "heure : " << heure << endl;
    // cout << "fuseau : " << fuseau << endl;
    // cout << "type : " << type << endl;
    cout << "cible : " << cible << endl;
    cout << "type de la cible : " << cibleType << endl;
    // cout << "versionHTTP : " << versionHTTP << endl;
    // cout << "codeHTTP : " << codeHTTP << endl;
    // cout << "qtDonnees : " << qtDonnees << endl;
    cout << "ref : " << ref << endl;
    cout << "type du referer : " << refType << endl;
    // cout << "client : " << client << endl;
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

const string Requete::GetCibleType() const{
    return cibleType;
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

const string Requete::GetRefType() const{
    return refType;
}

const string Requete::GetClient() const{
    return client;
}


/* -------------------------- */
/*           Seteur           */
/* -------------------------- */

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

void Requete::SetCibleType(string chaine){
    cibleType = chaine;
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

void Requete::SetRefType(string chaine){
    refType = chaine;
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


Requete::Requete (string s)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
    smatch m;

    //si retour chariot alors ça ne marche plus ???????
    //solution : le faire sauter !
    if(int(s.at(s.length() - 1)) == 13){
        s.pop_back();
    }    

    // IP
	regex reIP("([^\\s]+)(.+)");
	if(regex_match(s, m, reIP)){
        string ip = m[1];
        this->ip = ip;
        s= m[2];
    }
    else{
        cout << "IP non trouvee" << endl;
    }

    //logName
    regex relogName("\\s([^\\s]+)\\s(.+)");
    if(regex_match(s, m, relogName)){
        string logname = m[1];
        this->logName = logName;
        s= m[2];
    }
    else{
        cout << "logname non trouve" << endl;
    }

    //authenticatedUser
    regex reAU("([^\\s]+)\\s(.+)");
    if(regex_match(s, m, reAU)){
        string authenticatedUser = m[1];
        this->authenticatedUser = authenticatedUser;
        s= m[2];
    }
    else{
        cout << "authenticatedUser non trouve" << endl;
    }

    //date
    regex reDate("^\\[([^\\:]+)(.+)");
    if(regex_match(s, m, reDate)){
        string date = m[1];
        this->date = date;
        s= m[2];
    }
    else{
        cout << "date non trouvee" << endl;
    }

    //heure
    regex reHeure("^:([^\\s]+)(.+)");
    regex reHeureIsole("([^\\:]+)(.+)");
    if(regex_match(s, m, reHeure)){
        
        string hms = m[1];
        s= m[2];
        if(regex_match(hms, m, reHeureIsole)){
            string heure = m[1];
            this->heure = heure;
        }
    }
    else{
        cout << "heure non trouvee" << endl;
    }

    //fuseau
    regex reFuseau("\\s\\+([^\\s]+)\\](.+)");
    if(regex_match(s, m, reFuseau)){
        string fuseau = m[1];
        this->fuseau = fuseau;
        s= m[2];
    }
    else{
        cout << "fuseau non trouve" << endl;
    }

    //type
    regex reType("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, reType)){
        string type = m[1];
        type.erase(0,1);
        this->type = type;
        s= m[2];
    }
    else{
        cout << "type non trouve" << endl;
    }
    
    //cible
    regex rePHP("(.+\\.php)(.+)");
    regex reICO("(.+\\.ico)(.+)");
    
    regex reCibleG("\\s([^\\s]+)(.+)");
    regex reCibleEspace("\\s(.+)(\\sHTTP.+)");
    if(regex_match(s, m, reCibleG) || regex_match(s, m, reCibleEspace)){
        string cible = m[1];
        s= m[2];
        if(regex_match(cible, m, rePHP) || regex_match(cible, m, reICO)){
            cible = m[1];
        }

        this->cible = cible;
    
    }else{
        cout << "cible non trouvee" << endl;                 
    }
    

    //type de la cible
    regex reCibleType("(.+)(\\.[a-z]{1,4}$)");
    if(regex_match(cible, m, reCibleType)){
        string cibleType = m[2];
        this->cibleType = cibleType;
    }
    else{
        string cibleType = "";
        this->cibleType = cibleType;              
    }



    //Version HTTP
    regex reHTTP("\\s{1,2}([^\\s]+)(.+)");
    if(regex_match(s, m, reHTTP)){
        string version = m[1];
        this->versionHTTP = version;
        s= m[2];
    }
    else{
        cout << "version http non trouvee" << endl;
    }

    //code http
    regex reCode("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, reCode)){
        string code = m[1];
        this->codeHTTP = code;
        s= m[2];
    }
    else{
        cout << "code http non trouve" << endl;
    }

    //taille octet réponse
    regex reTaille("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, reTaille)){
        string qtData = m[1];
        this->qtDonnees = qtData;
        s= m[2];
    }
    else{
        cout << "qt donnees http non trouvee" << endl;
    }

    //referer
    regex reRefG("\\s\"([^\\s\"]+)(.+)");
    regex reRefEspace("\\s(.+)(\\sHTTP.+)");
    if(regex_match(s, m, reRefG) || regex_match(s, m, reRefEspace)){
        string ref = m[1];
        if(regex_match(ref, m, rePHP) || regex_match(ref, m, reICO)){
            ref = m[1];
        }
        this->ref = ref;

        string s = "http://intranet-if.insa-lyon.fr";
        string::size_type i = this->ref.find(s);

        if (i != string::npos)
        this->ref.erase(i, s.length());

        s= m[2];
        s.erase(0,1);
    }else{
        cout << "ref non trouve" << endl;
    }

    //type du referer
    regex reRefType("(.+)(\\.[a-z]{1,4}$)");
    if(regex_match(ref, m, reRefType)){
        string refType = m[2];
        this->refType = refType;
    }
    else{
        string refType = "";
        this->refType = refType;              
    }

    //id client navigateur
    regex reID("\\s\"([^\"]+)(.+)");
    if(regex_match(s, m, reID)){
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

