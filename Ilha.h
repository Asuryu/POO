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
        int nrVigasMadeira, nrFerro, nrBarraDeAco, nrCarvao, nrMadeira, nrEletricidade;
        int vigasMadeiraUsar, flag;
        int custoMinaf, custoMinac, custoBateria, custoFundicao, custoCentral, custoRestaurante, custoOper, custoLen, custoMiner, custoVigasMadeira;
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