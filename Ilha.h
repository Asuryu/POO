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
        float saldo;
        int nrVigasMadeira = 200, nrFerro = 10, nrBarraDeAco = 10, nrCarvao = 10, nrMadeira = 10, nrEletricidade = 5;
        int vigasMadeiraUsar, flag = 0;
        int custoMinaf = 100, custoMinac = 100, custoBateria = 10, custoFundicao = 10, custoCentral = 15, custoRestaurante = 30, custoOper = 15, custoLen = 20, custoMiner = 10, custoVigasMadeira = 10;
        vector< vector<Zona*> > zonas;
    public:
        Ilha();
        void initIlha();
        void mostraIlha();
        void addSaldo(float saldo);
        float getSaldo();
        string getInfoZona();
        string getInfoZona(int linha, int coluna);
        int getNrTrabalhadores();
        void addZona(Zona *zona);
        void jogar();
        bool validaComando(istringstream &comando);
        void amanhacer();
        void anoitecer();
};