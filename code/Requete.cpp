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

const void Requete::printRequete() const
// Algorithme :
//
{
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
} //----- Fin de Méthode

// ---- Get ---- //

const string Requete::GetIp() const
{
    return ip;
} //----- Fin de Méthode

const string Requete::GetLogName() const
{
    return logName;
} //----- Fin de Méthode

const string Requete::GetAuthenticatedUser() const
{
    return authenticatedUser;
} //----- Fin de Méthode

const string Requete::GetDate() const
{
    return date;
} //----- Fin de Méthode

const string Requete::GetHeure() const
{
    return heure;
} //----- Fin de Méthode

const string Requete::GetMinute() const{
    return heure;
} //----- Fin de Méthode

const string Requete::GetSeconde() const{
    return heure;
} //----- Fin de Méthode

const string Requete::GetFuseau() const {
    return fuseau;
} //----- Fin de Méthode

const string Requete::GetType() const
{
    return type;
} //----- Fin de Méthode

const string Requete::GetCible() const
{
    return cible;
} //----- Fin de Méthode

const string Requete::GetCibleType() const
{
    return cibleType;
} //----- Fin de Méthode

const string Requete::GetVersionHTTP() const
{
    return versionHTTP;
} //----- Fin de Méthode

const string Requete::GetCodeHTTP() const
{
    return codeHTTP;
} //----- Fin de Méthode

const string Requete::GetQtDonnees() const
{
    return qtDonnees;
} //----- Fin de Méthode

const string Requete::GetRef() const
{
    return ref;
} //----- Fin de Méthode

const string Requete::GetRefType() const
{
    return refType;
} //----- Fin de Méthode

const string Requete::GetClient() const
{
    return client;
} //----- Fin de Méthode

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

    // faire sauter le retour chariot en fin de ligne pour simplifier l'utilisation des expressions régulières
    if (int(s.at(s.length() - 1)) == 13)
    {
        s.pop_back();
    }

    // Extraire IP
    regex reIP("([^\\s]+)(.+)");
    if (regex_match(s, m, reIP))
    {
        string ip = m[1];
        this->ip = ip;
        s = m[2];
    }
    else{
        cout << "Warning : IP non trouvee" << endl;
        this->ip = "";
    }

    // Extraire logName
    regex relogName("\\s([^\\s]+)\\s(.+)");
    if (regex_match(s, m, relogName))
    {
        string logname = m[1];
        this->logName = logName;
        s = m[2];
    }
    else{
        cout << "Warning : logName non trouvé" << endl;
        this->logName = "";
    }

    // Extraire authenticatedUser
    regex reAU("([^\\s]+)\\s(.+)");
    if(regex_match(s, m, reAU)){
        authenticatedUser = m[1];
        this->authenticatedUser = authenticatedUser;
        s = m[2];
    }
    else{
        cout << "Warning : authenticatedUser non trouvé" << endl;
        this->authenticatedUser = "";
    }

    // Extraire Date
    regex reDate("^\\[([^\\:]+)(.+)");
    if (regex_match(s, m, reDate))
    {
        string date = m[1];
        this->date = date;
        s = m[2];
    }
    else{
        cout << "Warning : date non trouvée" << endl;
        this->date = "";
    }

    // Extraire heure - minute - seconde
    regex reHeure("([^\\s]+)(.+)");
    regex reIsole("^:([^\\:]+)(.+)");
    if(regex_match(s, m, reHeure)){
        string hms = m[1];
        s= m[2];

        // Extraire Heure
        if(regex_match(hms, m, reIsole)){
            string heure = m[1];
            hms = m[2];
            this->heure = heure;
        }else 
            this->heure = "";

        // Extraire Minute
        if(regex_match(hms, m, reIsole)){
            string minute = m[1];
            hms = m[2];
            this->minute = minute;
        }else
            this->minute = "";

        // Extraire Seconde
        regex reIsoleSeconde("^:([^\\s]+)(.+)");
        if(regex_match(hms, m, reIsoleSeconde)){
            string seconde = m[1];
            this->seconde = seconde;
        }else   
            this->seconde = "";
    }
    else{
        cout << "Warning : horaire non trouvé" << endl;
    }

    // Extraire Fuseau
    regex reFuseau("\\s\\+([^\\s]+)\\](.+)");
    if (regex_match(s, m, reFuseau))
    {
        string fuseau = m[1];
        this->fuseau = fuseau;
        s = m[2];
    }
    else{
        cout << "Warning : fuseau non trouvé" << endl;
        this->fuseau = "";
    }

    // Extraire Type
    regex reType("\\s([^\\s]+)(.+)");
    if (regex_match(s, m, reType))
    {
        string type = m[1];
        type.erase(0, 1);
        this->type = type;
        s = m[2];
    }
    else{
        cout << "Warning : type non trouvé" << endl;
        this->type = "";
    }
    
 
    // Extraire Cible
    regex rePHP("(.+\\.php)(.+)");
    regex reICO("(.+\\.ico)(.+)");
    
    regex reCibleG("\\s([^\\s]+)(HTTP.+)"); // Cas où il y a 1 espace devant HTTP " HTTP"
    regex reCibleEspace("\\s(.+)(\\sHTTP.+)"); // Cas où il y a 2 espaces devant HTTP "  HTTP"
    if (regex_match(s, m, reCibleG) || regex_match(s, m, reCibleEspace))
    {
        string cible = m[1];
        s = m[2];
        // Cas de php et ico qui ne finissent pas par l'extension
        if (regex_match(cible, m, rePHP) || regex_match(cible, m, reICO)) 
        {
            cible = m[1];
        }

        this->cible = cible;
    
    }else{
        cout << "Warning : cible non trouvée" << endl;
        this->cible = "";                
    }

    // Extraire Type de la cible
    regex reCibleType("(.+)(\\.[a-z]{1,4}$)");
    if (regex_match(cible, m, reCibleType))
    {
        string cibleType = m[2];
        this->cibleType = cibleType;
    }
    else{
        this->cibleType = "";              
    }

    // Extraire Version HTTP
    regex reHTTP("\\s{1,2}([^\\s]+)(.+)");
    if (regex_match(s, m, reHTTP))
    {
        string version = m[1];
        this->versionHTTP = version;
        s = m[2];
    }
    else{
        cout << "Warning : version http non trouvée" << endl;
        this->versionHTTP = "";     
    }

    // Extraire Code HTTP
    regex reCode("\\s([^\\s]+)(.+)");
    if (regex_match(s, m, reCode))
    {
        string code = m[1];
        this->codeHTTP = code;
        s = m[2];
    }
    else{
        cout << "Warning : code http non trouvé" << endl;
        this->codeHTTP = "";     
    }

    // Extraire Taille octet réponse
    regex reTaille("\\s([^\\s]+)(.+)");
    if (regex_match(s, m, reTaille))
    {
        string qtData = m[1];
        this->qtDonnees = qtData;
        s = m[2];
    }
    else{
        cout << "Warning : quantité de données http non trouvée" << endl;
        this->qtDonnees = "";  
    }

    // Extraire Referer
    regex reRefG("\\s\"([^\"\\s]+)(.+)");
    if(regex_match(s, m, reRefG)){
        string ref = m[1];
        // Cas de php et ico qui ne finissent pas par l'extension
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
        cout << "Warning : referer non trouvé" << endl;
        this->ref = "";  
    }

    // Extraire Type du referer
    regex reRefType("(.+)(\\.[a-z]{1,4}$)");
    if (regex_match(ref, m, reRefType))
    {
        string refType = m[2];
        this->refType = refType;
    }
    else{
        this->refType = "";               
    }

    // Extraire ID client navigateur
    regex reID("\\s\"([^\"]+)(.+)");
    if (regex_match(s, m, reID))
    {
        string client = m[1];
        this->client = client;
        s = m[2];
    }
    else{
        cout << "Warning : client non trouvé" << endl;
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
