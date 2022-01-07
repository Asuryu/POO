#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "Zona.h"

using namespace std;

class Ilha {
    private:
        int linhas, colunas;
        int dia;
        int saldo;
        vector< vector<Zona*> > zonas;
    public:
        Ilha();
        void initIlha();
        void mostraIlha();
        void addSaldo(int saldo);
        int getSaldo();
        string getInfoZona();
        string getInfoZona(int linha, int coluna);
        int getNrTrabalhadores();
        void addZona(Zona *zona);
        void jogar();
        bool validaComando(istringstream &comando);

        // Comandos possiveis
};