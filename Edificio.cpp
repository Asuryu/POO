#include "Edificio.h"
#include <iostream>
#include <string>
using namespace std;

Edificio::Edificio(string sigla, int diaConstrucao) {
    this->sigla = sigla;
    this->diaConstrucao = diaConstrucao;
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
int Edificio::getDiaConstrucao() {
    return this->diaConstrucao;
}
int Edificio::getCusto() {
    return 0;
}
int Edificio::getNivel() {
    return 0;
}
int Edificio::addNivel() {
    return 0;
}
int Edificio::getArmazenamento() const {
    return 0;
};
int Edificio::getArmazenamentoMax() const {
    return 0;
};
int Edificio::addArmazenamento(int armazenamento) {
    return 0;
};
Edificio::~Edificio() {
}


MinaFerro::MinaFerro(string sigla, int custoFabrico, int diaConstrucao) : Edificio(sigla, diaConstrucao) {
    this->custoFabrico = custoFabrico;
    this->nivel = 1;
    this->producao = 0;
    this->armazenamento = 0;
    this->armazenamentoMax = 100;
}
int MinaFerro::getNivel() {
    return this->nivel;
}
int MinaFerro::addNivel(){
    nivel++;
    armazenamentoMax += 10;
    return nivel;
};
int MinaFerro::getProducao() const {
    return this->producao;
}
void MinaFerro::setProducao(int producao) {
    this->producao = producao;
}
int MinaFerro::getArmazenamento() const {
    return this->armazenamento;
}
int MinaFerro::getArmazenamentoMax() const {
    return this->armazenamentoMax;
}
int MinaFerro::addArmazenamento(int armazenamento) {
    return this->armazenamento += armazenamento;
}
int MinaFerro::getCusto() {
    return this->custoFabrico;
}


MinaCarvao::MinaCarvao(string sigla, int custoFabrico, int diaConstrucao) : Edificio(sigla, diaConstrucao) {
    this->custoFabrico = custoFabrico;
    this->nivel = 1;
    this->producao = 0;
    this->armazenamento = 0;
    this->armazenamentoMax = 100;
}
int MinaCarvao::getNivel() {
    return this->nivel;
}
int MinaCarvao::addNivel(){
    nivel++;
    armazenamentoMax += 10;
    return nivel;
};
int MinaCarvao::getProducao() const {
    return this->producao;
}
void MinaCarvao::setProducao(int producao) {
    this->producao = producao;
}
int MinaCarvao::getArmazenamento() const {
    return this->armazenamento;
}
int MinaCarvao::getArmazenamentoMax() const {
    return this->armazenamentoMax;
}
int MinaCarvao::addArmazenamento(int armazenamento) {
    return this->armazenamento += armazenamento;
}
int MinaCarvao::getCusto() {
    return this->custoFabrico;
}


Central::Central(string sigla, int custoFabrico, int diaConstrucao) : Edificio(sigla, diaConstrucao) {
    this->custoFabrico = custoFabrico;
    this->armazenamento = 0;
}
int Central::getArmazenamento() const {
    return this->armazenamento;
}
int Central::addArmazenamento(int armazenamento) {
    if(this->armazenamento + armazenamento < 101)
        return this->armazenamento += armazenamento;
    else return 0;
}
int Central::getCusto() {
    return this->custoFabrico;
}


Bateria::Bateria(string sigla, int custoFabrico, int diaConstrucao) : Edificio(sigla, diaConstrucao) {
    this->custoFabrico = custoFabrico;
    this->nivel = 1;
    this->capacidade = 0;
}
int Bateria::getNivel() {
    return this->nivel;
}
int Bateria::addNivel(){
    nivel++;
    capacidade += 10;
    return nivel;
};
int Bateria::getCapacidade() const {
    return this->capacidade;
}
void Bateria::setCapacidade(int capacidade) {
    this->capacidade = capacidade;
}
int Bateria::getCusto() {
    return this->custoFabrico;
}


Fundicao::Fundicao(string sigla, int custoFabrico, int diaConstrucao) : Edificio(sigla, diaConstrucao) {
    this->custoFabrico = custoFabrico;
}
int Fundicao::getCusto() {
    return this->custoFabrico;
}


Purgatorio::Purgatorio(string sigla, int custoFabrico, int diaConstrucao) : Edificio(sigla, diaConstrucao) {
    this->custoFabrico = custoFabrico;
}
int Purgatorio::getCusto() {
    return this->custoFabrico;
}