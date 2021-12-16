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
        int nrTrabalhadores;
        int linha, coluna;

    public:
        void setLinha(int l);
        void setColuna(int c);
        string getZona() const;
        void setZona(string z);
        string getEdificio() const;
        string getTrabalhadores() const;
        string getInfo() const;
        void setNrTrabalhadores(int n);
        int getNrTrabalhadores() const;
        void cons(string tipo, int linhaX, int colunaX);
        void cont(string tipo);
};

void menu(int &linhas, int &colunas);

void initIlha(Zona **matriz, int linhasTab, int colunasTab);

void mostraIlha(Zona **matriz, int linhas, int colunas);

void mostraInfoTotal(Zona **matriz, int linhasTab, int colunasTab);

void mostraASCII();

bool isNumber(string s);

bool validaComando(Zona **matriz, istringstream &iss, int linhasTab, int colunasTab);

#endif //ENGINE