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
int Edificio::getCusto() {
    return 0;
}
int Edificio::getNivel() {
    return 0;
}
Edificio::~Edificio() {
}


MinaFerro::MinaFerro(string sigla, int custoFabrico) : Edificio(sigla) {
    this->custoFabrico = custoFabrico;
    this->nivel = 1;
    this->producao = 0;
    this->armazenamento = 0;
}
int MinaFerro::getNivel() {
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
int MinaFerro::getCusto() {
    return this->custoFabrico;
}


MinaCarvao::MinaCarvao(string sigla, int custoFabrico) : Edificio(sigla) {
    this->custoFabrico = custoFabrico;
    this->nivel = 1;
    this->producao = 0;
    this->armazenamento = 0;
}
int MinaCarvao::getNivel() {
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
int MinaCarvao::getCusto() {
    return this->custoFabrico;
}


Central::Central(string sigla, int custoFabrico) : Edificio(sigla) {
    this->custoFabrico = custoFabrico;
    this->armazenamento = 0;
}
int Central::getArmazenamento() const {
    return this->armazenamento;
}
void Central::setArmazenamento(int armazenamento) {
    this->armazenamento = armazenamento;
}
int Central::getCusto() {
    return this->custoFabrico;
}


Bateria::Bateria(string sigla, int custoFabrico) : Edificio(sigla) {
    this->custoFabrico = custoFabrico;
    this->nivel = 1;
    this->capacidade = 0;
}
int Bateria::getNivel() {
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
int Bateria::getCusto() {
    return this->custoFabrico;
}


Fundicao::Fundicao(string sigla, int custoFabrico) : Edificio(sigla) {
    this->custoFabrico = custoFabrico;
}
int Fundicao::getCusto() {
    return this->custoFabrico;
}


Restaurante::Restaurante(string sigla, int custoFabrico) : Edificio(sigla) {
    this->custoFabrico = custoFabrico;
}
int Restaurante::getCusto() {
    return this->custoFabrico;
}