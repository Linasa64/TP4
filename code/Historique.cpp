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
void Historique::Top10()
{
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

void Historique::AjoutRequete(Requete * rq)
{
    int changed = 0;
    if( mapClesCible.find(rq->GetCible()) == mapClesCible.end() ){
        mapClesCible.insert( make_pair(rq->GetCible(), mapClesCible.size()) );
    }
    if( mapClesCible.find(rq->GetRef()) == mapClesCible.end() ){
        mapClesCible.insert( make_pair(rq->GetRef(), mapClesCible.size()) );
    }
    for (auto itr = mapComplete.begin(); itr != mapComplete.end(); itr++) {
        if (itr -> first == rq->GetCible()){
            mapComplete[itr->first].first +=1;
            int innerChange = 0;
            for (auto itr2 = itr->second.second.begin(); itr2 != itr->second.second.end(); itr2++) {
                if(itr2->first == rq->GetRef()){
                    mapComplete[itr->first].second.at(itr2->first) = itr2->second+1;
                    innerChange = 1;
                    break;
                }
            }
            if(innerChange==0){
                mapComplete[itr->first].second.insert(make_pair(rq->GetRef(), 1));
            }
            changed = 1;
            break;
        }
    }  
    if(changed ==0){
        map<string, int> innerMap;
        innerMap.insert(make_pair(rq->GetRef(), 1));
        pair<int, map<string, int>> innerPair = make_pair(1, innerMap);
        mapComplete.emplace(make_pair(rq->GetCible(), innerPair));
    }else{
        changed = 1;
    }
}

map<string, pair<int, map<string, int>>> Historique::GetMapComplete ()
{
    return mapComplete;
}

map<string, int> Historique::GetMapClesCible ()
{
    return mapClesCible;
}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Historique::Historique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Historique>" << endl;
#endif
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

