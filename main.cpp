#include "engine.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int contador = 0;

class Zona {

    private:
        int zona;

    public:
        Zona() : zona(++contador){
            cout << "Criado objeto #" << zona << endl;
        }
};

int main(){

    // string input;
    // cout << "Introduza um comando: ";
    // getline(cin, input);

    // istringstream comando(input);

    // validaComando(comando);
    
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

    cout << "\033[2J\033[1;1H";
    Zona matriz[3][3];

    return 0;
}