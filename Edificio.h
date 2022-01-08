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
        string getSigla();
};

class MinaFerro : public Edificio {
    private:
        int vigasMadeira;
        int custoFabrico;
        int nivel;
        int producao;
        int armazenamento;
    public:
        MinaFerro(string sigla, int vigasMadeira);
        int getNivel() const;
        void setNivel(int nivel);
        int getProducao() const;
        void setProducao(int producao);
        int getArmazenamento() const;
        void setArmazenamento(int armazenamento);
};

class MinaCarvao : public Edificio {
    private:
        int vigasMadeira;
        int nivel;
        int producao;
        int armazenamento;
    public:
        MinaCarvao(string sigla, int vigasMadeira);
        int getNivel() const;
        void setNivel(int nivel);
        int getProducao() const;
        void setProducao(int producao);
        int getArmazenamento() const;
        void setArmazenamento(int armazenamento);
};

class Central : public Edificio {
    private:
        int armazenamento;
        int custo;
    public:
        Central(string sigla, int custo);
        int getArmazenamento() const;
        void setArmazenamento(int armazenamento);
};

class Bateria : public Edificio {
    private:
        int vigasMadeira;
        int custo;
        int nivel;
        int capacidade;
    public:
        Bateria(string sigla, int vigasMadeira, int custo);
        int getNivel() const;
        void setNivel(int nivel);
        int getCapacidade() const;
        void setCapacidade(int capacidade);

};

class Fundicao : public Edificio {
    private:
        int custo;
    public:
        Fundicao(string sigla, int custo);
};

class EdificioX : public Edificio {
    private:

    public:
        EdificioX(string sigla, int custo);
};