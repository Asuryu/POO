#pragma once

#include "Ilha.h"
#include "Trabalhador.h"
#include "Edificio.h"
using namespace std;
class Ilha;

class Zona {
    private:
        int linha, coluna;
        string sigla;
        vector<Trabalhador*> trabalhadores;
        Edificio* edificio;
    public:
        Zona(int linha, int linhas);
        string getInfoZona();
        void setLinha(int linha);
        void setColuna(int coluna);
        void setSigla(string tipo);
        string getSigla();
        int getLinha();
        int getColuna();
        string getSiglaTrabalhadores();
        Trabalhador* getTrabalhadorById(string id);
        vector<Trabalhador*> getTrabalhadoresBySigla(string sigla);
        vector<Trabalhador*> getTrabalhadores();
        int getNrTrabalhadores();
        void addTrabalhador(Trabalhador* trabalhador);
        void removeTrabalhador(Trabalhador* trabalhador);
        string getSiglaEdificio();
        void setEdificio(Edificio* edificio);
        void removeEdificio();
        Edificio* getEdificio();       
        ~Zona(); 
};

class Deserto : public Zona {
    private:
        
    public:
        Deserto(int linha, int coluna);
};
class Montanha : public Zona {
    private:

    public:
        Montanha(int linha, int coluna);
};
class Floresta : public Zona {
    private:

    public:
        Floresta(int linha, int coluna);
};
class Pastagem : public Zona {
    private:

    public:
        Pastagem(int linha, int coluna);
};
class Pantano : public Zona {
    private:

    public:
        Pantano(int linha, int coluna);
};
class ZonaZ : public Zona {
    private:

    public:
        ZonaZ(int linha, int coluna);
};