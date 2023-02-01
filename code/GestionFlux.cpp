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
        LectureUser(line);
        LectureLogName(line);
        LectureAutenticatedUser(line);
        LectureCible(line);
        LectureReferer(line);
        LectureHeure(line);
        LectureCodeHTTP(line);
        LectureExtension(line);
    }

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
    ifstream fic;
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

void GestionFlux::LectureIp(string & line){
    
    string ip;
    //Sorte d'array qui va avoir en 0 la string de base, et en dans chaque case suivante les découpes.
	smatch m;
    //Regex spéciale adresse IP
	regex re("([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3})(.+)");
	
	if(regex_match(line, m, re)){
        ip = m[1];
        line = m[2];
    }
    else{
        cout << "IP non trouvee" << endl;
    }
    fwlistRq.front().SetIp(ip);
}

void GestionFlux::LectureCible(string & line){
    string cible;
    fwlistRq.front().SetCible(cible);
}

void GestionFlux::LectureReferer(string & line){
    string ref;

    fwlistRq.front().SetRef(ref);
}

void GestionFlux::LectureHeure(string & line){
    string heure;

    fwlistRq.front().SetCible(heure);
}

void GestionFlux::LectureCodeHTTP(string & line){
    string code;

    fwlistRq.front().SetCible(code);
}

void GestionFlux::LectureExtension(string & line){
    string ext;

    fwlistRq.setExtension(ext);
}