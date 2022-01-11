#pragma once

#include <string>
using namespace std;

class Edificio {
    private:
        string sigla;
        int ligado;
    public:
        Edificio(string sigla);
        void ligar();
        void desligar();
        int getLigado();
        virtual int getCusto();
        virtual int getNivel();
        virtual int addNivel();
        virtual int getArmazenamento() const;
        virtual int addArmazenamento(int armazenamento);
        string getSigla();
        virtual ~Edificio();
};

class MinaFerro : public Edificio {
    private:
        int custoFabrico;
        int nivel;
        int producao;
        int armazenamento;
    public:
        MinaFerro(string sigla, int custoFabrico);
        int getNivel();
        int addNivel();
        int getProducao() const;
        void setProducao(int producao);
        int getArmazenamento() const;
        int addArmazenamento(int armazenamento);
        int getCusto();
};

class MinaCarvao : public Edificio {
    private:
        int custoFabrico;
        int nivel;
        int producao;
        int armazenamento;
    public:
        MinaCarvao(string sigla, int custoFabrico);
        int getNivel();
        int addNivel();
        int getProducao() const;
        void setProducao(int producao);
        int getArmazenamento() const;
        int addArmazenamento(int armazenamento);
        int getCusto();
};

class Central : public Edificio {
    private:
        int armazenamento;
        int custoFabrico;
    public:
        Central(string sigla, int custoFabrico);
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
        Bateria(string sigla, int custoFabrico);
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
        Fundicao(string sigla, int custoFabrico);
        int getCusto();
};

class Restaurante : public Edificio {
    private:
        int custoFabrico;
    public:
        Restaurante(string sigla, int custoFabrico);
        int getCusto();
};