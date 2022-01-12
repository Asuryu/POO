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
        string saveName;
        float saldo;
        int nrVigasMadeira, nrFerro, nrBarraDeAco, nrCarvao, nrMadeira, nrEletricidade;
        int vigasMadeiraUsar, flag;
        int custoMinaf, custoMinac, custoBateria, custoFundicao, custoCentral, custoRestaurante, custoOper, custoLen, custoMiner, custoVigasMadeira;
        bool validaAuxMinaf = false, validaAuxMinac = false, validaAuxCentral = false;
        vector< vector<Zona*> > zonas;
        vector<Ilha *> ilhas;
    public:
        Ilha();
        Ilha(Ilha *ilha);
        void initIlha();
        void mostraIlha();
        void addSaldo(float saldo);
        float getSaldo();
        string getInfoZona();
        string getInfoZona(int linha, int coluna);
        string getSaveName();
        int getNrTrabalhadores();
        void addZona(Zona *zona);
        void jogar();
        bool validaComando(istringstream &comando);
        void amanhacer();
        void anoitecer();
        ~Ilha();
};