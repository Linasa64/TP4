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
    for (auto itr = mapComplete.begin(); itr != mapComplete.end(); ++itr) {
        mpTop10.insert(pair<int, string>(itr->second.first, itr->first));
    }
    int cpt = 0;
    for (auto itr = mpTop10.rbegin(); itr != mpTop10.rend(); ++itr) {
        cpt++;
        cout << itr->second<< " (" << itr->first << " hits)" << endl;
        if(cpt==10){
            break;
        }
    }
}

map<string, pair<int, map<string, int>>> Historique::GetMapComplete (){
    return mapComplete;
}


//------------------------------------------------- Surcharge d'opérateurs


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

    for(Requete * r : l){
        int changed = 0;
        for (auto itr = mapComplete.begin(); itr != mapComplete.end(); itr++) {
            if (itr -> first == r->GetCible()){
                mapComplete[itr->first].first +=1;
                for (auto itr2 = itr->second.second.begin(); itr2 != itr->second.second.end(); itr2++) {
                    if(itr2->first == r->GetRef()){
                        mapComplete[itr->first].second.at(itr2->first) = itr2->second+1;
                    }
                    else{
                        mapComplete[itr->first].second.insert(make_pair(r->GetRef(), 1));
                    }
                }
                changed = 1;
                break;
            }
        }  
        if(changed ==0){
            map<string, int> innerMap;
            innerMap.insert(make_pair(r->GetRef(), 1));
            pair<int, map<string, int>> innerPair = make_pair(1, innerMap);
            mapComplete.emplace(make_pair(r->GetCible(), innerPair));
        }else{
            changed = 1;
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

