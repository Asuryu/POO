#include "Edificio.h"
#include <string>

Edificio::Edificio(string sigla) {
    this->sigla = sigla;
    this->ligado = 0;
}
void Edificio::ligar() {
    this->ligado = 1;
}
void Edificio::desligar() {
    this->ligado = 0;
}
int Edificio::getLigado() {
    return this->ligado;
}
string Edificio::getSigla() {
    return this->sigla;
}


MinaFerro::MinaFerro(string sigla, int vigasMadeira) : Edificio(sigla) {
    this->vigasMadeira = vigasMadeira;
    this->nivel = 1;
    this->producao = 0;
    this->armazenamento = 0;
}
int MinaFerro::getNivel() const {
    return this->nivel;
}
void MinaFerro::setNivel(int nivel) {
    this->nivel = nivel;
}
int MinaFerro::getProducao() const {
    return this->producao;
}
void MinaFerro::setProducao(int producao) {
    this->producao = producao;
}
int MinaFerro::getArmazenamento() const {
    return this->armazenamento;
}
void MinaFerro::setArmazenamento(int armazenamento) {
    this->armazenamento = armazenamento;
}


MinaCarvao::MinaCarvao(string sigla, int vigasMadeira) : Edificio(sigla) {
    this->vigasMadeira = vigasMadeira;
    this->nivel = 1;
    this->producao = 0;
    this->armazenamento = 0;
}
int MinaCarvao::getNivel() const {
    return this->nivel;
}
void MinaCarvao::setNivel(int nivel) {
    this->nivel = nivel;
}
int MinaCarvao::getProducao() const {
    return this->producao;
}
void MinaCarvao::setProducao(int producao) {
    this->producao = producao;
}
int MinaCarvao::getArmazenamento() const {
    return this->armazenamento;
}
void MinaCarvao::setArmazenamento(int armazenamento) {
    this->armazenamento = armazenamento;
}


Central::Central(string sigla, int custo) : Edificio(sigla) {
    this->custo = custo;
    this->armazenamento = 0;
}
int Central::getArmazenamento() const {
    return this->armazenamento;
}
void Central::setArmazenamento(int armazenamento) {
    this->armazenamento = armazenamento;
}


Bateria::Bateria(string sigla, int vigasMadeira, int custo) : Edificio(sigla) {
    this->vigasMadeira = vigasMadeira;
    this->custo = custo;
    this->nivel = 1;
    this->capacidade = 0;
}
int Bateria::getNivel() const {
    return this->nivel;
}
void Bateria::setNivel(int nivel) {
    this->nivel = nivel;
}
int Bateria::getCapacidade() const {
    return this->capacidade;
}
void Bateria::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}


Fundicao::Fundicao(string sigla, int custo) : Edificio(sigla) {
    this->custo = custo;
}


EdificioX::EdificioX(string sigla, int custo) : Edificio(sigla) {}