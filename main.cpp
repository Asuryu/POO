// ISEC - Trabalho Prático de POO 2021/2022
// Tomás Gomes Silva - 2020143845
// Tomás da Cunha Pinto - 2020144067

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
    bool state = false;
    int linhas, colunas;
    menu(linhas, colunas);
    vector< vector<Zona> > matriz;
    initIlha(matriz, linhas, colunas);
    
    // for(int i = 0; i < linhas; i++){
    //     for(int j = 0; j < colunas; j++){
    //         cout << "*------";
    //     }
    //     for(int z = 0; z < 3; z++){
    //         cout << endl <<  "|      |      |      |      |";
    //     }
    // }

    do { // Ciclo de jogo
        string input;
        if(state == true){
            cout << ">>> Prima ENTER para continuar <<< ";
            getchar();
            cout << "\033[2J\033[1;1H";
            mostraASCII();
            mostraInfoTotal(matriz, linhas, colunas); // Alterar para uma função que mostre a ilha visualmente
        }
        fflush(stdin);
        cout << "Introduza um comando: ";
        getline(cin, input);
        istringstream comando(input);
        state = validaComando(matriz, comando, linhas, colunas);
    } while (true);

    return 0;
}