#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <regex.h>

using namespace std;

int main (){

    regex_t regV;
    regex_t regF;
    string patronV = "^v (.*) (.*) (.*)";
    string patronF = "^f (.*)/.* (.*)/.* (.*)/.*";
    regmatch_t matches [5];
    string linea, s;
    std::vector <int> v;
    std::vector <int> f;

    ifstream ficheroObj ("imagen.obj");

    // Compila la expresion regular
    regcomp (&regV, patronV.c_str (), REG_EXTENDED | REG_ICASE);
    regcomp (&regF, patronF.c_str (), REG_EXTENDED | REG_ICASE);

    while (!ficheroObj.eof ()){

        getline (ficheroObj, linea);
        cout << linea << endl;

        if (regexec (&regV, linea.c_str (), 5, matches, 0) == 0){

            v.push_back (atoi (linea.substr (matches [1].rm_so, matches [1].rm_eo - matches [1].rm_so).c_str ()));
            v.push_back (atoi (linea.substr (matches [2].rm_so, matches [2].rm_eo - matches [2].rm_so).c_str ()));
            v.push_back (atoi (linea.substr (matches [3].rm_so, matches [3].rm_eo - matches [3].rm_so).c_str ()));

        }else if (regexec (&regF, linea.c_str (), 5, matches, 0) == 0){

            f.push_back (atoi (linea.substr (matches [1].rm_so, matches [1].rm_eo - matches [1].rm_so).c_str ()));
            f.push_back (atoi (linea.substr (matches [2].rm_so, matches [2].rm_eo - matches [2].rm_so).c_str ()));
            f.push_back (atoi (linea.substr (matches [3].rm_so, matches [3].rm_eo - matches [3].rm_so).c_str ()));

        }else{

            cout << "Match not found";
            cout << endl;

        }
    }

    cout << "Vertices: " << endl;
    
    for (int i = 0; i < v.size (); i++){

        cout << "Coord ";
        cout << i;
        cout << ": ";
        cout << v [i];
        cout << endl;

    }

    cout << "Caras:" << endl;

    for (int i = 0; i < f.size (); i++){

        cout << "Coord ";
        cout << i;
        cout << ": ";
        cout << f [i];
        cout << endl;

    }

    regfree (&regV);
    regfree (&regF);

    return 0;

}
