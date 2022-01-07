#pragma once

#include <string>
using namespace std;

class Trabalhador {
    private:
        int custo;
        string sigla;
        static int nTrabalhadorGlobal;
        int nTrabalhador;
        int diaContrato;
        string idTrabalhador;
    public:
        Trabalhador(int custo, int diaContrato);
        string getIdTrabalhador();
        int getCusto();
        int getDiaContrato();
        string getSigla();
        void setSigla(string sigla);
};

class Operario : public Trabalhador {
    private:

    public:
        Operario(int custo, int diaContrato);
};

class Mineiro : public Trabalhador {
    private:

    public:
        Mineiro(int custo, int diaContrato);
};

class Lenhador : public Trabalhador {
    private:

    public:
        Lenhador(int custo, int diaContrato);
};