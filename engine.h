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

    public:
        string getZona();
        string getEdificio();
        string getTrabalhadores();
        int getNrTrabalhadores();
        void cons(string tipo, int linhaX, int colunaX);
        void cont(string tipo);

};

bool validaComando(vector< vector<Zona> > matriz, istringstream &iss);

#endif //ENGINE