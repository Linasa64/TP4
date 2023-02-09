#include "Requete.h"
#include "GestionFlux.h"
#include "Historique.h"
#include "Graphe.h"
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <map>

using namespace std;


void ajoutOptionE( const list<Requete *> l, Historique * h) ;
void ajoutOptionT( const list<Requete *> l, Historique * h, int heure) ;
void ajoutOptionET( const list<Requete *> l, Historique * h, int heure) ;
void creerGraphe(Historique * h, string nomFicDot) ;

int main(int argc, char const *argv[])
{
   string nomFic = argv[argc-1];
		// options -g -e -t
	int arg [3] = {0, 0, 0};
	int heure = 0;
   string nomFicDot = "";
	int i = 1;
	
	for (i = 1; i<argc; i++){
		if(!strcmp(argv[i], "-g")){
			arg[0] = 1;
         nomFicDot = argv[i+1];
      }else if(!strcmp(argv[i], "-e")){
			arg[1] = 1;
      }else if(!strcmp(argv[i], "-t"))
		{
			arg[2] = 1;
			heure = stoi(argv[i+1]);
		} 
   }
   GestionFlux* gf =  new GestionFlux(nomFic);
   const list<Requete *> l = gf->GetlistRq();
   delete gf;
   Historique * h = new Historique();
      
   if(arg[1] == 1){
      if(heure < 0 || heure > 23){
         cerr << "Horaire invalide" << endl;
      }
      int heure2 = heure + 1;
      if( heure == 23){
         heure2 = 0;
      }
      cout << "Warning : only hits between " << heure << "h and " << heure2 << "h have been taken into account" << endl;
      if(arg[2] == 1){
         ajoutOptionET(l, h, heure);
      }else{
         ajoutOptionE(l, h);
      }
   }
   else if(arg[2] == 1){
      ajoutOptionT(l, h, heure);
   }else{
      for(Requete * rq : l){
         h->AjoutRequete(rq);
      }
   }

   h->Top10();

   if(arg[0] == 1){
      creerGraphe(h, nomFicDot);
   }

   for(Requete * r : l){
      delete r;
   }

   delete h;
}


void ajoutOptionE( const list<Requete *> l , Historique * h){
   set<string> * extension = new set<string>();
   extension->insert(".css");
   extension->insert(".js");
   extension->insert(".png");
   extension->insert(".jpg");
   extension->insert(".svg");
   extension->insert(".jpeg");
   extension->insert(".gif");
   extension->insert(".ico");

   for(Requete * rq : l){
      if(extension->find(rq->GetCibleType()) == extension->end()){
         h->AjoutRequete(rq);
      }
   }
   //delete extension;
}
   
void ajoutOptionT( const list<Requete *> l , Historique * h, int heure){
   for(Requete * rq : l){
      if(stoi(rq->GetHeure()) == heure){
         h->AjoutRequete(rq);
      }
   }
}

void ajoutOptionET( const list<Requete *> l , Historique * h, int heure){
   set<string> * extension = new set<string>();
   extension->insert(".css");
   extension->insert(".js");
   extension->insert(".png");
   extension->insert(".jpg");
   extension->insert(".svg");
   extension->insert(".jpeg");
   extension->insert(".gif");
   extension->insert(".ico");
   for(Requete * rq : l){
      if(extension->find(rq->GetCibleType()) == extension->end() && stoi(rq->GetHeure()) == heure){
         h->AjoutRequete(rq);
      }
   }
}

void creerGraphe(Historique * h, string nomFicDot){
   if(nomFicDot.compare(nomFicDot.length() - 4, 4, ".dot") != 0){
      cerr << "Erreur dans le nom du fichier .dot" << endl;
      return;
   }
   map<string, pair<int, map<string, int>>> m = h->GetMapComplete();
   map<string, int> mapCles = h->GetMapClesCible();
   Graphe *g = new Graphe(m, mapCles, nomFicDot);
   cout << "Dot-file " << nomFicDot << " generated" << endl;
   delete g;
}