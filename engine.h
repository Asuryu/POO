#ifndef ENGINE
#define ENGINE

#include <sstream>
#include <vector>
#include <tuple>
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
        int getLinha();
        int getColuna();
        string getZona();
        string getEdificio();
        string getTrabalhadores();
        string getInfo();
        int getNrTrabalhadores();
        void cons(string tipo, int linhaX, int colunaX);
        void cont(string tipo);

};

void mostraASCII();

bool validaComando(vector< vector<Zona> > &matriz, istringstream &iss, int linhasTab, int colunasTab);

#endif //ENGINE