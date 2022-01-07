#include "Trabalhador.h"
using namespace std;

Trabalhador::Trabalhador(int custo, int diaContrato) {
    this->custo = custo;
    nTrabalhador = nTrabalhadorGlobal++;
    idTrabalhador = to_string(nTrabalhador) + "." + to_string(diaContrato);
}
string Trabalhador::getIdTrabalhador() {
    return idTrabalhador;
}
int Trabalhador::getCusto() {
    return custo;
}
int Trabalhador::getDiaContrato() {
    return diaContrato;
}
string Trabalhador::getSigla() {
    return sigla;
}
void Trabalhador::setSigla(string sigla) {
    this->sigla = sigla;
}
int Trabalhador::nTrabalhadorGlobal = 0;


Operario::Operario(int custo, int diaContrato) : Trabalhador(custo, diaContrato) {
    setSigla("O");
}


Mineiro::Mineiro(int custo, int diaContrato) : Trabalhador(custo, diaContrato) {
    setSigla("M");
}


Lenhador::Lenhador(int custo, int diaContrato) : Trabalhador(custo, diaContrato) {
    setSigla("L");
}