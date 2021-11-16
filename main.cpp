#include "engine.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    
    int opcao_menu = 0;
    cout << " ___ _ _       __       " << endl;
    cout << "|_ _| | |__   /_/ _   _ " << endl;
    cout << " | || | '_ \\ / _ \\ | | |" << endl;
    cout << " | || | | | |  __/ |_| |" << endl;
    cout << "|___|_|_| |_|\\___|\\__,_|" << endl;
    cout << "\n\n1 - Começar o jogo" << endl;
    cout << "0 - Sair do jogo\n\nEscolha: ";
    cin >> opcao_menu;

    if(opcao_menu == 0) return 0;

    // cout << "\033[2J\033[1;1H"; // Clear na consola
    vector< vector<Zona> > matriz; 
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "*------";
        }
        for(int z = 0; z < 3; z++){
            cout << endl <<  "|      |      |      |      |";
        }
    }

    // do {
    //     string input;
    //     fflush(stdin);
    //     cout << "Introduza um comando: ";
    //     getline(cin, input);
    //     istringstream comando(input);
    //     validaComando(matriz, comando);
    // } while (true);

    return 0;
}