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
        int saldo, nrVigasMadeira = 100, vigasMadeiraUsar, flag = 0;
        int custoMinaf = 100, custoMinac = 100, custoBateria = 10, custoFundicao = 10, custoCentral = 15, custoOper = 15, custoLen = 20, custoMiner = 10, custoVigasMadeira = 10;
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
        void amanhacer();
        void anoitecer();

        // Comandos possiveis
};