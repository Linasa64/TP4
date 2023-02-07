#include "Requete.h"
#include "GestionFlux.h"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;
void Historique();
bool cmp(pair<string, int>& a, pair<string, int>& b);
vector<pair<string, int> > sort(map<string, int>& m);


int main(int argc, char const *argv[])
{
   /*
         // options -g -e -t heure
      int arg [4] = {0, 0, 0, 0};
      int i = 1;
      for (i, i<argc, i++){
         if(strcmp(argv[i], "-g")
            arg[0] = 1;
         else if(strcmp(argv[i], "-e")
            arg[1] = 1;
         else if(strcmp(argv[i], "-t")
            arg[2] = 1;
            arg[3] = argv[i+1];
         } 
      }
   */
   Historique();

}

void Historique(){
    GestionFlux* gf =  new GestionFlux("../ressources/petit.log");
    const list<Requete *> l = gf->GetlistRq();
    //l.front()->printRequete();
    //cout << "main : " << gf->GetlistRq().size() << gf->GetlistRq().back()->GetIp() << endl;
    
   vector<pair<string, int> > vec;
   map<string, int> m;

    for(Requete * r : l){
        if (m.find(r->GetCible()) == m.end()){
            m.insert({r->GetCible(), 1});
        }
        else {
            m[r->GetCible()] += 1;
        }
    }


   vec = sort(m);
   int cpt=0;
   for (auto& it : vec) {
      cout << it.first<< " (" << it.second << " hits)" << endl;
      cpt++;
      if(cpt==10){
         break;
      }
   }
}

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

vector<pair<string, int> > sort(map<string, int>& m)
{
   vector<pair<string, int> > A;
   for (auto itr = m.begin(); itr != m.end(); ++itr) {
      pair<string, int> p = {itr->first, itr->second};
      A.push_back(p);
   }
   sort(A.begin(), A.end(), cmp);
   return A;
}


/*

*/