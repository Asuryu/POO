#include "engine.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(){

    srand(time(NULL));
    
    int linhas, colunas;
    int opcao_menu = 0;
    mostraASCII();
    cout << "\n1 - Começar o jogo" << endl;
    cout << "0 - Sair do jogo\n\nEscolha: ";
    cin >> opcao_menu;
    if(opcao_menu == 0) return 0;
    do {
        cout << "\033[2J\033[1;1H"; // Clear na consola
        mostraASCII();
        cout << "Introduza o número de linhas: ";
        cin >> linhas;
    } while (linhas < 3 || linhas > 8);
    do {
        cout << "Introduza o número de colunas: ";
        cin >> colunas;
    } while (colunas < 3 || colunas > 16);
    cout << "\033[2J\033[1;1H"; // Clear na consola
    mostraASCII();

    Zona z;
    vector< vector<Zona> > matriz;
    vector<Zona> tmp;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            tmp.push_back(z);
        }
        matriz.push_back(tmp);
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j].setLinha(i);
            matriz[i][j].setColuna(j);
        }
    }
    
    // for(int i = 0; i < linhas; i++){
    //     for(int j = 0; j < colunas; j++){
    //         cout << "*------";
    //     }
    //     for(int z = 0; z < 3; z++){
    //         cout << endl <<  "|      |      |      |      |";
    //     }
    // }
    
    do {
        string input;
        fflush(stdin);
        cout << "Introduza um comando: ";
        getline(cin, input);
        istringstream comando(input);
        validaComando(matriz, comando, linhas, colunas);
    } while (true);

    return 0;
}