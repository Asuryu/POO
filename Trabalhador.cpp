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
int Trabalhador::getDiasTrabalhados() {
    return 0;
}
void Trabalhador::getDiasTrabalhados(int diasTrabalhados) {
}
bool Trabalhador::getOperacional() {
    return false;
}
void Trabalhador::setOperacional(bool operacional) {
}

int Trabalhador::nTrabalhadorGlobal = 0;


Operario::Operario(int custo, int diaContrato) : Trabalhador(custo, diaContrato) {
    setSigla("O");
}


Mineiro::Mineiro(int custo, int diaContrato) : Trabalhador(custo, diaContrato) {
    setSigla("M");
}


Lenhador::Lenhador(int custo, int diaContrato) : Trabalhador(custo, diaContrato) {
    this->diasTrabalhados = 0;
    this->operacional = true;
    setSigla("L");
}
int Lenhador::getDiasTrabalhados() {
    return diasTrabalhados;
}
void Lenhador::getDiasTrabalhados(int diasTrabalhados) {
    this->diasTrabalhados = diasTrabalhados;
}
bool Lenhador::getOperacional() {
    return operacional;
}
void Lenhador::setOperacional(bool operacional) {
    this->operacional = operacional;
}