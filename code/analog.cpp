#include "Requete.h"
#include "GestionFlux.h"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

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

    GestionFlux* gf =  new GestionFlux("../ressources/petit.log");
    const list<Requete *> l = gf->GetlistRq();
    l.front()->printRequete();
    cout << "main : " << gf->GetlistRq().size() << gf->GetlistRq().back()->GetIp() << endl;
}


/*

*/