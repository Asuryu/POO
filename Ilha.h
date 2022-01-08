#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "Zona.h"

using namespace std;

class Ilha {
    private:
        int linhas, colunas;
        int dia; //"novoDia" é utilizada como flag para sabermos quando é que o utilizador executa o comando "next" e muda de dia.
        int saldo;
        int custoMinaf, custoBateria, custoFundicao, custoCentral, custoOper, custoLen, custoMiner;
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