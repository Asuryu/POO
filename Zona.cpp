#include <iostream>
#include <sstream>
#include "Ilha.h"
using namespace std;

Zona::Zona(int linha, int coluna) {
    this->linha = linha;
    this->coluna = coluna;
    this->edificio = NULL;
}
string Zona::getInfoZona() {
    ostringstream oss;
    string edf;
    if (this->edificio != NULL) {
        edf = this->edificio->getSigla();
    } else edf = "Sem edificio";
    oss << "(" << linha << ", " << coluna << ")\nZona: " << sigla << "\nEdificio: " << edf << "\nTrabalhadores: " << getSiglaTrabalhadores() << "\nNr. Trabalhadores: " << getNrTrabalhadores() << endl;
    return oss.str();
}
void Zona::setLinha(int linha) {
    this->linha = linha;
}
void Zona::setColuna(int coluna) {
    this->coluna = coluna;
}
void Zona::setSigla(string tipo) {
    this->sigla = tipo;
}
string Zona::getSigla() {
    return this->sigla;
}
int Zona::getLinha() {
    return this->linha;
}
int Zona::getColuna() {
    return this->coluna;
}
vector<Trabalhador*> Zona::getTrabalhadores(){
    return this->trabalhadores;
}
int Zona::getNrTrabalhadores() {
    return this->trabalhadores.size();
}
string Zona::getSiglaTrabalhadores() {
    string concatSigla = "";
    for (int i = 0; i < this->trabalhadores.size(); i++) {
        concatSigla += this->trabalhadores[i]->getSigla();
    }
    return concatSigla;
}
void Zona::addTrabalhador(Trabalhador* trabalhador) {
    this->trabalhadores.push_back(trabalhador);
    string nome;
    if(trabalhador->getSigla() == "O") nome = "Operário";
    else if(trabalhador->getSigla() == "M") nome = "Mineiro";
    else if(trabalhador->getSigla() == "L") nome = "Lenhador";
    cout << "Opearario do tipo " << nome << " foi CONTRATADO e colocado na zona de pasto (" << linha << ", " << coluna << ")!" << endl;
}
void Zona::removeTrabalhador(Trabalhador* trabalhador) {
    for (int i = 0; i < this->trabalhadores.size(); i++) {
        if (this->trabalhadores[i] == trabalhador) {
            this->trabalhadores.erase(this->trabalhadores.begin() + i);
        }
    }
}
string Zona::getSiglaEdificio() {
    if (this->edificio != NULL) {
        return this->edificio->getSigla();
    }
    return "";
}
void Zona::setEdificio(Edificio* edificio) {
    this->edificio = edificio;
    cout << "Edificio do tipo " << edificio->getSigla() << " CONSTRUIDO na posicao (" << linha << "," << coluna << ")!" << endl;
}
Edificio* Zona::getEdificio() {
    return this->edificio;
}
// Destrutor da classe Zona
// libertar memória
Zona::~Zona() {
    for (int i = 0; i < this->trabalhadores.size(); i++) {
        delete this->trabalhadores[i];
    }
    delete this->edificio;
}


Deserto::Deserto(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("dsr");
}
Montanha::Montanha(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("mnt");
}
Floresta::Floresta(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("flr");
}
Pastagem::Pastagem(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("pas");
}
Pantano::Pantano(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("pnt");
}
ZonaZ::ZonaZ(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("znZ");
}