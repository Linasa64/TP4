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

void Historique::Top10()
// Algorithme :
// Affiche le Top10 des cibles les plus visitées
//
{
    // Remplissage du multimap top10 qui associe un nbre de visites à des cibles
    for (auto itr = mapComplete.begin(); itr != mapComplete.end(); ++itr)
    {
        mpTop10.insert(pair<int, string>(itr->second.first, itr->first));
    }
    int cpt = 0;
    // Affiche les 10 premières cibles de la map avec le nb le plus important (usage de rbegin et rend)
    for (auto itr = mpTop10.rbegin(); itr != mpTop10.rend(); ++itr)
    {
        cpt++;
        cout << itr->second << " (" << itr->first << " hits)" << endl;
        if (cpt == 10)
        {
            break;
        }
    }
} //----- Fin de Méthode

void Historique::AjoutRequete(Requete *rq)
// Algorithme :
// Attribue un id à chaque adresse (cible ou referer) à la map mapClesCibles
// Ajoute une requête à l'historique mapComplete, avec les informations additionnelles (nbre de visites, referers et nbre de visites par referer)
//
{
    int changed = 0;
    // Si nouvelle adresse (cible) alors on ajoute à mapClesCible
    if (mapClesCible.find(rq->GetCible()) == mapClesCible.end())
    {
        mapClesCible.insert(make_pair(rq->GetCible(), mapClesCible.size()));
    }
    // Si nouvelle adresse (referer) alors on ajoute à mapClesCible
    if (mapClesCible.find(rq->GetRef()) == mapClesCible.end())
    {
        mapClesCible.insert(make_pair(rq->GetRef(), mapClesCible.size()));
    }

    for (auto itr = mapComplete.begin(); itr != mapComplete.end(); itr++)
    {
        // Si la cible existe dans la map, on incrémente son nbre de visites de 1
        if (itr->first == rq->GetCible())
        {
            mapComplete[itr->first].first += 1;
            int innerChange = 0;
            for (auto itr2 = itr->second.second.begin(); itr2 != itr->second.second.end(); itr2++)
            {
                // Si le referer de la cible existe dans la map, on incrémente son nombre de visites de 1
                if (itr2->first == rq->GetRef())
                {
                    mapComplete[itr->first].second.at(itr2->first) = itr2->second + 1;
                    innerChange = 1;
                    break;
                }
            }
            // Si le referer de la cible n'existe pas dans la map alors on l'ajoute
            if (innerChange == 0)
            {
                mapComplete[itr->first].second.insert(make_pair(rq->GetRef(), 1));
            }
            changed = 1;
            break;
        }
    }
    // Si la cible n'existe pas dans la map alors on l'ajoute
    if (changed == 0)
    {
        map<string, int> innerMap;
        innerMap.insert(make_pair(rq->GetRef(), 1));
        pair<int, map<string, int>> innerPair = make_pair(1, innerMap);
        mapComplete.emplace(make_pair(rq->GetCible(), innerPair));
    }
    else
    {
        changed = 1;
    }
} //----- Fin de Méthode

map<string, pair<int, map<string, int>>> Historique::GetMapComplete()
// Algorithme :
//
{
    return mapComplete;
} //----- Fin de Méthode

map<string, int> Historique::GetMapClesCible()
// Algorithme :
//
{
    return mapClesCible;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Historique::Historique()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Historique>" << endl;
#endif
} //----- Fin de Historique

Historique::~Historique()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Historique>" << endl;
#endif
} //----- Fin de ~Historique

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
