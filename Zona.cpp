#include <iostream>
#include <sstream>
#include "Ilha.h"
using namespace std;

Zona::Zona(int linha, int coluna) : linha(linha), coluna(coluna), edificio(NULL) {}
string Zona::getInfoZona() {
    ostringstream oss;
    string edf, zonaNome;
    if (this->edificio != NULL) {
        edf = this->edificio->getSigla();
        if(edf == "minaf") edf = "Mina de Ferro";
        else if(edf == "minac") edf = "Mina de Carvao";
        else if(edf == "central") edf = "Central Eletrica";        
        else if(edf == "bat") edf = "Bateria"; 
        else if(edf == "fund") edf = "Fundicao";
        else if(edf == "rest") edf = "Restaurante"; 
    } else edf = "Sem edificio";


    if (this->sigla == "pas") zonaNome = "Pastagem";
    else if (this->sigla == "dsr")  zonaNome = "Deserto";
    else if (this->sigla == "mnt")  zonaNome = "Montanha";      
    else if (this->sigla == "flr")  zonaNome = "Floresta";
    else if (this->sigla == "pnt")  zonaNome = "Pantano";
    else if (this->sigla == "vul")  zonaNome = "Vulcão"; 

    oss << "(" << linha << ", " << coluna << ")\nZona: " << zonaNome << "\nEdificio: " << edf << "\nTrabalhadores: " << getSiglaTrabalhadores() << "\nNr. Trabalhadores: " << getNrTrabalhadores() << endl;
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
    for (unsigned int i = 0; i < this->trabalhadores.size(); i++) {
        concatSigla += this->trabalhadores[i]->getSigla();
    }
    return concatSigla;
}
Trabalhador* Zona::getTrabalhadorById(string id){
    for (unsigned int i = 0; i < this->trabalhadores.size(); i++) {
        if (this->trabalhadores[i]->getIdTrabalhador() == id) return this->trabalhadores[i];
    }
    return NULL;
}
vector<Trabalhador*> Zona::getTrabalhadoresBySigla(string sigla){
    vector<Trabalhador*> trabalhadoresBySigla;
    for (unsigned int i = 0; i < this->trabalhadores.size(); i++) {
        if (this->trabalhadores[i]->getSigla() == sigla) trabalhadoresBySigla.push_back(this->trabalhadores[i]);
    }
    return trabalhadoresBySigla;
}
void Zona::addTrabalhador(Trabalhador* trabalhador) {
    this->trabalhadores.push_back(trabalhador);
    string nome;
    if(trabalhador->getSigla() == "O") nome = "Operário";
    else if(trabalhador->getSigla() == "M") nome = "Mineiro";
    else if(trabalhador->getSigla() == "L") nome = "Lenhador";
}
void Zona::removeTrabalhador(Trabalhador* trabalhador) {
    for (unsigned int i = 0; i < this->trabalhadores.size(); i++) {
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
void Zona::removeEdificio() {
    this->edificio = NULL;
}
Edificio* Zona::getEdificio() {
    return this->edificio;
}
int Zona::getArmazenamento() {
    return 0;
}
void Zona::addArmazenamento(int armazenamento) {}
int Zona::getArvores() {
    return 0;
}
int Zona::addArvores(int arvores) {}
// Destrutor da classe Zona
// libertar memória
Zona::~Zona() {
    for (unsigned int i = 0; i < this->trabalhadores.size(); i++) {
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
int Montanha::getArmazenamento(){
    return this->armazenamento;
}
void Montanha::addArmazenamento(int armazenamento){
    this->armazenamento += armazenamento;
}
Floresta::Floresta(int linha, int coluna, int arvores) : Zona(linha, coluna) {
    setSigla("flr");
    this->armazenamento = 0;
    this->arvores = arvores;
}
int Floresta::getArmazenamento(){
    return this->armazenamento;
}
void Floresta::addArmazenamento(int armazenamento){
    this->armazenamento += armazenamento;
}
int Floresta::getArvores(){
    return this->arvores;
}
int Floresta::addArvores(int arvores){
    this->arvores += arvores;
}
Pastagem::Pastagem(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("pas");
}
Pantano::Pantano(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("pnt");
}
Vulcao::Vulcao(int linha, int coluna) : Zona(linha, coluna) {
    setSigla("vul");
}