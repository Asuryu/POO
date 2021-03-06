#pragma once

#include <string>
using namespace std;

class Edificio {
    private:
        string sigla;
        int ligado;
        int diaConstrucao;
    public:
        Edificio(string sigla, int diaConstrucao);
        void ligar();
        void desligar();
        int getLigado();
        int getDiaConstrucao();
        virtual int getCusto();
        virtual int getNivel();
        virtual int addNivel();
        virtual int getArmazenamento() const;
        virtual int getArmazenamentoMax() const;
        virtual int addArmazenamento(int armazenamento);
        string getSigla();
};

class MinaFerro : public Edificio {
    private:
        int custoFabrico;
        int nivel;
        int armazenamentoMax;
        int producao;
        int armazenamento;
    public:
        MinaFerro(string sigla, int custoFabrico, int diaConstrucao);
        int getNivel();
        int addNivel();
        int getProducao() const;
        void setProducao(int producao);
        int getArmazenamento() const;
        int getArmazenamentoMax() const;
        int addArmazenamento(int armazenamento);
        int getCusto();
};

class MinaCarvao : public Edificio {
    private:
        int custoFabrico;
        int nivel;
        int armazenamentoMax;
        int producao;
        int armazenamento;
    public:
        MinaCarvao(string sigla, int custoFabrico, int diaConstrucao);
        int getNivel();
        int addNivel();
        int getProducao() const;
        void setProducao(int producao);
        int getArmazenamento() const;
        int getArmazenamentoMax() const;
        int addArmazenamento(int armazenamento);
        int getCusto();
};

class Central : public Edificio {
    private:
        int armazenamento;
        int custoFabrico;
    public:
        Central(string sigla, int custoFabrico, int diaConstrucao);
        int getArmazenamento() const;
        int addArmazenamento(int armazenamento);
        int getCusto();
};

class Bateria : public Edificio {
    private:
        int custoFabrico;
        int nivel;
        int capacidade;
    public:
        Bateria(string sigla, int custoFabrico, int diaConstrucao);
        int getNivel();
        int addNivel();
        int getCapacidade() const;
        void setCapacidade(int capacidade);
        int getCusto();
};

class Fundicao : public Edificio {
    private:
        int custoFabrico;
    public:
        Fundicao(string sigla, int custoFabrico, int diaConstrucao);
        int getCusto();
};

class Purgatorio : public Edificio {
    private:
        int custoFabrico;
    public:
        Purgatorio(string sigla, int custoFabrico, int diaConstrucao);
        int getCusto();
};