/*************************************************************************
                           GestionFlux  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <GestionFlux> (fichier GestionFlux.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <regex>
#include <cstdlib>

//------------------------------------------------------ Include personnel
#include "GestionFlux.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GestionFlux::Méthode ( forward_liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


forward_list<Requete> GestionFlux::LectureFichier(){

    forward_list<Requete> reqforward_list;
    
// Lecture du fichier
    string line;

    while(!fic.eof())
    {
        Requete * rq = new Requete;
        getline(fic, line);
        fwlistRq.push_front(*rq);
        LineParsing(line);
    }

    return fwlistRq;            
}

const forward_list<Requete> GestionFlux::GetFwlistRq() const{
    return fwlistRq;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
GestionFlux::GestionFlux ( const GestionFlux & unGestionFlux )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionFlux>" << endl;
#endif
} //----- Fin de GestionFlux (constructeur de copie)


GestionFlux::GestionFlux ( string nomFic )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GestionFlux>" << endl;
#endif
    fic.open(nomFic, ios_base::in);
    if((nomFic.substr(nomFic.size() - 3) != "txt") && (nomFic.substr(nomFic.size() - 3) != "log")){
        cerr << "____ EXTENSION INCONNUE ____"  << endl;
        exit (EXIT_FAILURE);
    }
    if (!fic){
        cerr << "____ FICHIER INEXISTANT ____"  << endl;
        exit (EXIT_FAILURE);
    } 
    
    ifstream fic;
    fic.open(nomFic, ios_base::in);
} //----- Fin de GestionFlux


GestionFlux::~GestionFlux ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionFlux>" << endl;
#endif
    fic.close();
} //----- Fin de ~GestionFlux


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void GestionFlux::LineParsing(string & s){
    
    smatch m;

    // IP
	regex re("([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3})(.+)");
	if(regex_match(s, m, re)){
        string ip = m[1];
        fwlistRq.front().SetIp(ip);
        s= m[2];
    }
    else{
        cout << "IP non trouvee" << endl;
    }

    //logName
    regex re2("\\s([^\\s]+)\\s(.+)");
    if(regex_match(s, m, re2)){
        string logname = m[1];
        fwlistRq.front().SetLogName(logname);
        s= m[2];
    }
    else{
        cout << "logname non trouve" << endl;
    }

    //authenticatedUser
    regex re3("([^\\s]+)\\s(.+)");
    if(regex_match(s, m, re3)){
        string authenticatedUser = m[1];
        fwlistRq.front().SetAuthenticatedUser(authenticatedUser);
        s= m[2];
    }
    else{
        cout << "authenticatedUser non trouve" << endl;
    }

    //date
    regex re4("^\\[([^\\:]+)(.+)");
    if(regex_match(s, m, re4)){
        string date = m[1];
        fwlistRq.front().SetDate(date);
        s= m[2];
    }
    else{
        cout << "date non trouvee" << endl;
    }

    //heure
    regex re5("^:([^\\s]+)(.+)");
    if(regex_match(s, m, re5)){
        string heure = m[1];
        fwlistRq.front().SetHeure(heure);
        s= m[2];
    }
    else{
        cout << "heure non trouvee" << endl;
    }

    //fuseau
    regex re6("\\s\\+([^\\s]+)\\](.+)");
    if(regex_match(s, m, re6)){
        string fuseau = m[1];
        fwlistRq.front().SetFuseau(fuseau);
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
        fwlistRq.front().SetType(type);
        s= m[2];
    }
    else{
        cout << "type non trouve" << endl;
    }
    
    //cible
    regex re8("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re8)){
        string cible = m[1];
        fwlistRq.front().SetCible(cible);
        s= m[2];
    }
    else{
        cout << "cible non trouvee" << endl;
    }

    //Version HTTP
    regex re9("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re9)){
        string version = m[1];
        fwlistRq.front().SetVersionHTTP(version);
        s= m[2];
    }
    else{
        cout << "version http non trouvee" << endl;
    }

    //code http
    regex re10("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re10)){
        string code = m[1];
        fwlistRq.front().SetCodeHTTP(code);
        s= m[2];
    }
    else{
        cout << "code http non trouve" << endl;
    }

    //taille octet réponse
    regex re11("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re11)){
        string qtData = m[1];
        fwlistRq.front().SetQtDonnees(qtData);
        s= m[2];
    }
    else{
        cout << "qt donnees http non trouvee" << endl;
    }

    //referer
    regex re12("\\s\"([^\\s\"]+)(.+)");
    if(regex_match(s, m, re12)){
        string ref = m[1];
        fwlistRq.front().SetRef(ref);
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
        fwlistRq.front().SetClient(client);
        s= m[2];
    }
    else{
        cout << "client non trouve" << endl;
    }
}
