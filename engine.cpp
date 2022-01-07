#include <iostream>
#include <sstream>
#include <regex>
#include "engine.h"
using namespace std;

void mostraASCII(){
    cout << "\033[2J\033[1;1H";
    cout << " ___ _ _       __       " << endl;
    cout << "|_ _| | |__   /_/ _   _ " << endl;
    cout << " | || | '_ \\ / _ \\ | | |" << endl;
    cout << " | || | | | |  __/ |_| |" << endl;
    cout << "|___|_|_| |_|\\___|\\__,_|" << endl << endl;
}

void menu(){
    int opcao_menu;
    string input;
    do {
        mostraASCII();
        cout << "\n1 - Comecar o jogo" << endl;
        cout << "2 - Sair do jogo\n\nEscolha: ";
        getline(cin, input);
        if(input.length() != 1) opcao_menu = -1;
        else stringstream(input) >> opcao_menu;
        if(opcao_menu == 1 || opcao_menu == 2) break;
    } while (1);
    if(opcao_menu == 2) exit(0);
}

bool isNumber(string x){
    regex e ("-{0,1}\\d+");
    return (regex_match (x,e));
}