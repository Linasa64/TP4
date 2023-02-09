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
    cout << "type de la cible : " << cibleType << endl;
    cout << "versionHTTP : " << versionHTTP << endl;
    cout << "codeHTTP : " << codeHTTP << endl;
    cout << "qtDonnees : " << qtDonnees << endl;
    cout << "ref : " << ref << endl;
    cout << "type du referer : " << refType << endl;
    cout << "client : " << client << endl;
}

const string Requete::GetIp() const
{
    return ip;
}

const string Requete::GetLogName() const
{
    return logName;
}

const string Requete::GetAuthenticatedUser() const
{
    return authenticatedUser;
}

const string Requete::GetDate() const
{
    return date;
}

const string Requete::GetHeure() const
{
    return heure;
}

const string Requete::GetMinute() const{
    return heure;
}

const string Requete::GetSeconde() const{
    return heure;
}

const string Requete::GetFuseau() const {
    return fuseau;
}

const string Requete::GetType() const
{
    return type;
}

const string Requete::GetCible() const
{
    return cible;
}

const string Requete::GetCibleType() const
{
    return cibleType;
}

const string Requete::GetVersionHTTP() const
{
    return versionHTTP;
}

const string Requete::GetCodeHTTP() const
{
    return codeHTTP;
}

const string Requete::GetQtDonnees() const
{
    return qtDonnees;
}

const string Requete::GetRef() const
{
    return ref;
}

const string Requete::GetRefType() const
{
    return refType;
}

const string Requete::GetClient() const
{
    return client;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Requete::Requete(string s)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
    smatch m;

    // si retour chariot alors ça ne marche plus ???????
    // solution : le faire sauter !
    if (int(s.at(s.length() - 1)) == 13)
    {
        s.pop_back();
    }

    // IP
    regex reIP("([^\\s]+)(.+)");
    if (regex_match(s, m, reIP))
    {
        string ip = m[1];
        this->ip = ip;
        s = m[2];
    }
    else{
        cerr << "Warning : IP non trouvee" << endl;
        this->ip = "";
    }

    // logName
    regex relogName("\\s([^\\s]+)\\s(.+)");
    if (regex_match(s, m, relogName))
    {
        string logname = m[1];
        this->logName = logName;
        s = m[2];
    }
    else{
        cerr << "Warning : logName non trouvé" << endl;
        this->logName = "";
    }

    // authenticatedUser
    regex reAU("([^\\s]+)\\s(.+)");
    if(regex_match(s, m, reAU)){
        authenticatedUser = m[1];
        this->authenticatedUser = authenticatedUser;
        s = m[2];
    }
    else{
        cerr << "Warning : authenticatedUser non trouvé" << endl;
        this->authenticatedUser = "";
    }

    // date
    regex reDate("^\\[([^\\:]+)(.+)");
    if (regex_match(s, m, reDate))
    {
        string date = m[1];
        this->date = date;
        s = m[2];
    }
    else{
        cerr << "Warning : date non trouvée" << endl;
        this->date = "";
    }

    //heure - minute - seconde
    regex reHeure("([^\\s]+)(.+)");
    regex reIsole("^:([^\\:]+)(.+)");
    if(regex_match(s, m, reHeure)){
        string hms = m[1];
        s= m[2];

        if(regex_match(hms, m, reIsole)){
            string heure = m[1];
            hms = m[2];
            this->heure = heure;
        }

        if(regex_match(hms, m, reIsole)){
            string minute = m[1];
            hms = m[2];
            this->minute = minute;
            regex reIsoleSeconde("^:([^\\s]+)(.+)");

            if(regex_match(hms, m, reIsoleSeconde)){
                string seconde = m[1];
                this->seconde = seconde;
            }
        }
    }
    else{
        cerr << "Warning : horaire non trouvé" << endl;
        this->heure = "";
        this->minute = "";
        this->seconde = "";
    }

    // fuseau
    regex reFuseau("\\s\\+([^\\s]+)\\](.+)");
    if (regex_match(s, m, reFuseau))
    {
        string fuseau = m[1];
        this->fuseau = fuseau;
        s = m[2];
    }
    else{
        cerr << "Warning : fuseau non trouvé" << endl;
        this->fuseau = "";
    }

    // type
    regex reType("\\s([^\\s]+)(.+)");
    if (regex_match(s, m, reType))
    {
        string type = m[1];
        type.erase(0, 1);
        this->type = type;
        s = m[2];
    }
    else{
        cerr << "Warning : type non trouvé" << endl;
        this->type = "";
    }
    
 
    //cible
    regex rePHP("(.+\\.php)(.+)");
    regex reICO("(.+\\.ico)(.+)");
    
    regex reCibleG("\\s([^\\s]+)(HTTP.+)");
    regex reCibleEspace("\\s(.+)(\\sHTTP.+)");
    if (regex_match(s, m, reCibleG) || regex_match(s, m, reCibleEspace))
    {
        string cible = m[1];
        s = m[2];
        if (regex_match(cible, m, rePHP) || regex_match(cible, m, reICO))
        {
            cible = m[1];
        }

        this->cible = cible;
    
    }else{
        cerr << "Warning : cible non trouvée" << endl;
        this->cible = "";                
    }
    else
    {
        cout << "cible non trouvee" << endl;
    }

    // type de la cible
    regex reCibleType("(.+)(\\.[a-z]{1,4}$)");
    if (regex_match(cible, m, reCibleType))
    {
        string cibleType = m[2];
        this->cibleType = cibleType;
    }
    else{
        this->cibleType = "";              
    }

    // Version HTTP
    regex reHTTP("\\s{1,2}([^\\s]+)(.+)");
    if (regex_match(s, m, reHTTP))
    {
        string version = m[1];
        this->versionHTTP = version;
        s = m[2];
    }
    else{
        cerr << "Warning : version http non trouvée" << endl;
        this->versionHTTP = "";     
    }

    // code http
    regex reCode("\\s([^\\s]+)(.+)");
    if (regex_match(s, m, reCode))
    {
        string code = m[1];
        this->codeHTTP = code;
        s = m[2];
    }
    else{
        cerr << "Warning : code http non trouvé" << endl;
        this->codeHTTP = "";     
    }

    // taille octet réponse
    regex reTaille("\\s([^\\s]+)(.+)");
    if (regex_match(s, m, reTaille))
    {
        string qtData = m[1];
        this->qtDonnees = qtData;
        s = m[2];
    }
    else{
        cerr << "Warning : quantité de données http non trouvée" << endl;
        this->qtDonnees = "";  
    }

    //referer
    regex reRefG("\\s\"([^\"\\s]+)(.+)");
    //regex reRefEspace("\\s\"(.+)(\"\\s.+)");
    if(regex_match(s, m, reRefG) /*|| regex_match(s, m, reRefEspace)*/){
        string ref = m[1];
        if (regex_match(ref, m, rePHP) || regex_match(ref, m, reICO))
        {
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
        cerr << "Warning : referer non trouvé" << endl;
        this->ref = "";  
    }

    // type du referer
    regex reRefType("(.+)(\\.[a-z]{1,4}$)");
    if (regex_match(ref, m, reRefType))
    {
        string refType = m[2];
        this->refType = refType;
    }
    else{
        this->refType = "";               
    }

    // id client navigateur
    regex reID("\\s\"([^\"]+)(.+)");
    if (regex_match(s, m, reID))
    {
        string client = m[1];
        this->client = client;
        s = m[2];
    }
    else{
        cerr << "Warning : client non trouvé" << endl;
        this->client = "";               
    }
} //----- Fin de Requete

Requete::~Requete()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif

} //----- Fin de ~Requete

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
