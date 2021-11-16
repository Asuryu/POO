#include "engine.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    string input;
    cout << "Introduza um comando: ";
    getline(cin, input);

    istringstream comando(input);

    validaComando(comando);
    

    return 0;
}