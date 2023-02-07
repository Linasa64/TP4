/*************************************************************************
                           Historique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Historique> (fichier Historique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>
//------------------------------------------------------ Include personnel
#include "Historique.h"
#include "GestionFlux.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Historique::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Historique::Top10(){
    for (auto itr = mapHisto.begin(); itr != mapHisto.end(); ++itr) {
        mpTop10.insert(pair<int, string>(itr->second, itr->first));
    }
   int cpt = 0;
   for (auto itr = mpTop10.rbegin(); itr != mpTop10.rend(); ++itr) {
        cout << itr->second<< " (" << itr->first << " hits)" << endl;
        cpt++;
        if(cpt==10){
         break;
        }
    }
}


//------------------------------------------------- Surcharge d'opérateurs
Historique & Historique::operator = ( const Historique & unHistorique )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
// Historique::Historique ( const Historique & unHistorique )
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Historique>" << endl;
// #endif
// } //----- Fin de Historique (constructeur de copie)


Historique::Historique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Historique>" << endl;
#endif

    GestionFlux* gf =  new GestionFlux("../ressources/petit.log");
    const list<Requete *> l = gf->GetlistRq();
    //l.front()->printRequete();
    //cout << "main : " << gf->GetlistRq().size() << gf->GetlistRq().back()->GetIp() << endl;

    for(Requete * r : l){
        if (mapHisto.find(r->GetCible()) == mapHisto.end()){
            mapHisto.insert({r->GetCible(), 1});
        }
        else {
            mapHisto[r->GetCible()] += 1;
        }
    }


} //----- Fin de Historique


Historique::~Historique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Historique>" << endl;
#endif
} //----- Fin de ~Historique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

