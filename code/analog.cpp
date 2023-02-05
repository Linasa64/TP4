#include "Requete.h"
#include <iostream>
#include <regex>
#include <fstream>

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


    ifstream fic;
    fic.open("../ressources/anonyme.log", ios_base::in);
    //string s = "192.168.5.101 - - [20/Sep/2012:11:04:27 +0200] GET /wiki/lib/exe/indexer.php?id=contacts_marches_informatiques_sav_etc&1348131867 HTTP/1.1 200 42 http://intranet-if.insa-lyon.fr:90/wiki/doku.php?id=contacts_marches_informatiques_sav_etc&do=login Mozilla/5.0 (Windows NT 6.1; rv:10.0.2) Gecko/20100101 Firefox/10.0.2";
	string s;
    getline(fic, s);
    cout << s << endl;

    
    smatch m; // string matches

    // IP
	regex re("([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3})(.+)");
	// The entiere string s must match the régular expression
	if(regex_match(s, m, re)){
        cout << "IP : " << m[1] << endl;
    }
    s= m[2];

    //logName
    regex re2("\\s([^\\s]+)\\s(.+)");
    if(regex_match(s, m, re2)){
        cout << "lLogName : " << m[1] << endl;
    }
    s= m[2];

    //authenticatedUser
    regex re3("([^\\s]+)\\s(.+)");
    if(regex_match(s, m, re3)){
        cout << "authenticatedUser : " << m[1] << endl;
    }
    s= m[2];

    //date
    regex re4("^\\[([^\\:]+)(.+)");
    if(regex_match(s, m, re4)){
        cout << "date : " << m[1] << endl;
    }
    s= m[2];

    //heure
    regex re5("^:([^\\s]+)(.+)");
    if(regex_match(s, m, re5)){
        cout << "heure : " << m[1] << endl;
    }
    s= m[2];

    //fuseau
    regex re6("\\s\\+([^\\s]+)\\](.+)");
    if(regex_match(s, m, re6)){
        cout << "fuseau : " << m[1] << endl;
    }
    s= m[2];


    //methode
    regex re7("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re7)){
        string rep7 = m[1];
        rep7.erase(0,1);
        cout << "methode : " << rep7 << endl;
    }
    s= m[2];
    
    //cible
    regex re8("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re8)){
        cout << "cible : " << m[1] << endl;
    }
    s= m[2];

    //http machin
    regex re9("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re9)){
        string rep9 = m[1];
        rep9.erase(rep9.size()-1);
        cout << "http machin : " << rep9 << endl;
    }
    s= m[2];

    //code http
    regex re10("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re10)){
        cout << "code http : " << m[1] << endl;
    }
    s= m[2];

    //taille octet réponse
    regex re11("\\s([^\\s]+)(.+)");
    if(regex_match(s, m, re11)){
        cout << "taille o rep : " << m[1] << endl;
    }
    s= m[2];

    //referer
    regex re12("\\s\"([^\\s\"]+)(.+)");
    if(regex_match(s, m, re12)){
        cout << "referer : " << m[1] << endl;
    }
    s= m[2];
    s.erase(0,1);

    //id client navigateur
    regex re13("\\s\"([^\"]+)(.+)");
    if(regex_match(s, m, re13)){
        cout << "identification du client navigateur : " << m[1] << endl;
    }
    s= m[2];

   return 0;
}


/*

*/