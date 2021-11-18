#ifndef ENGINE
#define ENGINE

#include <sstream>
#include <vector>
#include <tuple>
using namespace std;


class Zona {

    private:
        string zona = "pas";
        string edificio;
        string trabalhadores;
        int nrTrabalhadores = 0;
        int linha, coluna;

    public:
        Zona();
        void setLinha(int l);
        void setColuna(int c);
        int getLinha() const;
        int getColuna() const;
        string getZona() const;
        void setZona(string z);
        string getEdificio() const;
        string getTrabalhadores() const;
        string getInfo() const;
        int getNrTrabalhadores() const;
        void cons(string tipo, int linhaX, int colunaX);
        void cont(string tipo);

};

void mostraASCII();

bool isNumber(string s);

bool validaComando(vector< vector<Zona> > &matriz, istringstream &iss, int linhasTab, int colunasTab);

#endif //ENGINE