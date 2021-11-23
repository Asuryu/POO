// ISEC - Trabalho Prático de POO 2021/2022
// Tomás Gomes Silva - 2020143845
// Tomás da Cunha Pinto - 2020144067

#ifndef ENGINE
#define ENGINE

#include <sstream>
#include <vector>
using namespace std;


class Zona {

    private:
        string zona;
        string edificio;
        string trabalhadores;
        int nrTrabalhadores = 0;
        int linha, coluna;

    public:
        void setLinha(int l);
        void setColuna(int c);
        int getLinha() const;
        int getColuna() const;
        string getZona() const;
        void setZona(string z);
        string getEdificio() const;
        void setEdificio(string e);
        string getTrabalhadores() const;
        string getInfo() const;
        int getNrTrabalhadores() const;
        void setNrTrabalhadores(int t);
        void cons(string tipo, int linhaX, int colunaX);
        void cont(string tipo);

};

void menu(int &linhas, int &colunas);

void initIlha(vector< vector<Zona> > &matriz, int linhasTab, int colunasTab);

void mostraIlha(vector< vector<Zona> > matriz, int linhas, int colunas);

void mostraInfoTotal(vector< vector<Zona> > &matriz, int linhasTab, int colunasTab);

void mostraASCII();

bool isNumber(string s);

bool validaComando(vector< vector<Zona> > &matriz, istringstream &iss, int linhasTab, int colunasTab);

#endif //ENGINE