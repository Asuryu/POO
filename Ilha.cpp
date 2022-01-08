#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <regex>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <random>
#include "Ilha.h"
#include "engine.h"
using namespace std;

void Ilha::initIlha(){
    mostraASCII();
    string input;
    do {
        cout << "Introduza o numero de linhas: ";
        getline(cin, input);
        stringstream(input) >> linhas;
    } while (linhas < 3 || linhas > 8);
    do {
        cout << "Introduza o numero de colunas: ";
        getline(cin, input);
        stringstream(input) >> colunas;
    } while (colunas < 3 || colunas > 16);

    vector<string> zonasAux;
    string zonasExistentes[6] = {"mnt", "dsr", "pas", "flr", "pnt", "znZ"};

    int celulas = linhas * colunas;
    int repeticoes = celulas / 6;
    int resto = celulas % 6;
    int randIndex;

    random_shuffle(zonasExistentes, zonasExistentes + 6);

    for(int i = 0; i < repeticoes; i++){
        for(int j = 0; j < 6; j++){
            zonasAux.push_back(zonasExistentes[j]);
        }
    }
    for(int i = 0; i < resto; i++){
        zonasAux.push_back(zonasExistentes[i]);
    }

    //Add zonas to vector zonas
    for(int i = 0; i < linhas; i++){
        vector<Zona*> zonasLinha;
        for(int j = 0; j < colunas; j++){
            randIndex = rand() % zonasAux.size();
            if(zonasAux[randIndex] == "mnt"){
                zonasLinha.push_back(new Montanha(i, j));
            }
            else if(zonasAux[randIndex] == "dsr"){
                zonasLinha.push_back(new Deserto(i, j));
            }
            else if(zonasAux[randIndex] == "pas"){
                zonasLinha.push_back(new Pastagem(i, j));
            }
            else if(zonasAux[randIndex] == "flr"){
                zonasLinha.push_back(new Floresta(i, j));
            }
            else if(zonasAux[randIndex] == "pnt"){
                zonasLinha.push_back(new Pantano(i, j));
            }
            else if(zonasAux[randIndex] == "znZ"){
                zonasLinha.push_back(new ZonaZ(i, j));
            }
            zonasAux.erase(zonasAux.begin() + randIndex);
        }
        zonas.push_back(zonasLinha);
    }
    
    mostraIlha();
}

Ilha::Ilha(){
    dia = 1;
    saldo = 0;
    initIlha();
    jogar();
}

void Ilha::mostraIlha() {
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            cout << "*-------";
            if(j == (colunas - 1)){
                cout <<  "*";
            }
        }
        cout << endl;
        for(int z = 0; z < 4; z++){
            for(int k = 0; k < colunas; k++){
                if(z == 0) cout << "|" << left << setfill(' ') << setw(7) << zonas[i][k]->getSigla();
                else if(z == 1){
                    cout << "|" << left << setfill(' ') << setw(7) << zonas[i][k]->getSiglaEdificio();
                }

                else if(z == 2) cout << "|" << left << setfill(' ') << setw(7) << zonas[i][k]->getSiglaTrabalhadores().substr(0, 6);
                else if(z == 3) cout << "|" << left << setfill(' ') << setw(7) << zonas[i][k]->getNrTrabalhadores();
                else cout << "|       ";
                if(k == (colunas - 1)){
                    cout <<  "|";
                }
            }
            cout << endl;
        }
    }
    for(int j = 0; j < colunas; j++){
        cout << "*-------";
        if(j == (colunas - 1)){
            cout <<  "*";
        }
    }

    cout << endl;
    cout << "[DIA " << dia << "]" << endl;
    cout << "Saldo: " << saldo << "€" << endl;
    cout << "Número de Trabalhadores: " << getNrTrabalhadores() << endl << endl;

}

void Ilha::addSaldo(int saldo){
    this->saldo += saldo;
}
int Ilha::getSaldo(){
    return saldo;
}

// Função para adicionar uma zona ao vector de zonas
void Ilha::addZona(Zona *zona) {
    zonas.push_back(vector<Zona*>());
    for(int i = 0; i < colunas; i++){
        zonas[zonas.size() - 1].push_back(zona);
    }
}


int Ilha::getNrTrabalhadores() {
    int nrTrabalhadores = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            nrTrabalhadores += zonas[i][j]->getNrTrabalhadores();
        }
    }
    return nrTrabalhadores;
}

string Ilha::getInfoZona(){
    ostringstream oss;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            oss << zonas[i][j]->getInfoZona() << endl;
        }
    }
    return oss.str();
}
string Ilha::getInfoZona(int linha, int coluna){
    return zonas[linha][coluna]->getInfoZona();
}

void Ilha::jogar(){
    bool state = false;
    string input;
    do { // Ciclo de jogo
        if(state == true){
            cout << ">>> Prima ENTER para continuar <<< ";
            getchar();
            cout << "\033[2J\033[1;1H";
            mostraASCII();
            mostraIlha();
        }
        fflush(stdin);
        cout << "Introduza um comando: ";
        getline(cin, input);
        istringstream comando(input);
        state = validaComando(comando);
    } while (true);
}

bool Ilha::validaComando(istringstream &comando){
    vector<string> args;
    while (comando){
        string subs;
        comando >> subs;
        args.push_back(subs);
    }
    args.pop_back();

    if (args[0] == "exec" && args.size() == 2){
        string line;
        ifstream input_file(args[1]); //declarar e abrir o ficheiro
        if (!input_file) {
            cout << "Ocorreu um erro ao abrir o ficheiro" << endl;
            return false;  //ocorreu um erro
        }

        while (getline(input_file, line)) {
            istringstream lineFich(line);
            validaComando(lineFich);
        }

        // Close the file
        input_file.close();
        return true;

    }
    else if (args[0] == "cons" && args.size() == 4){
        int linhaX, colunaX;
        if(isNumber(args[2])) linhaX = stoi(args[2]);
        else{
            cout << "[ERRO] Introduza um numero para a linha" << endl;
            return false;
        }
        if(isNumber(args[3])) colunaX = stoi(args[3]);
        else{
            cout << "[ERRO] Introduza um numero para a coluna" << endl;
            return false;
        }

        if(args[1] == "minaf" || args[1] == "minac" || args[1] == "central" || args[1] == "bat" || args[1] == "fund" || args[1] == "edx"){
            if(linhaX < linhas && linhaX >= 0){
                if(colunaX < colunas && colunaX >= 0){
                    if(zonas[linhaX][colunaX]->getEdificio() == nullptr){
                        if(args[1] == "minaf")
                            zonas[linhaX][colunaX]->setEdificio(new MinaFerro("minaf", 10));
                        else if(args[1] == "minac")
                            zonas[linhaX][colunaX]->setEdificio(new MinaCarvao("minac", 10));
                        else if(args[1] == "central")
                            zonas[linhaX][colunaX]->setEdificio(new Central("central", 15));
                        else if(args[1] == "bat")
                            zonas[linhaX][colunaX]->setEdificio(new Bateria("bat", 10, 10));
                        else if(args[1] == "fund")
                            zonas[linhaX][colunaX]->setEdificio(new Fundicao("fund", 10));
                        else if(args[1] == "edx")
                            zonas[linhaX][colunaX]->setEdificio(new EdificioX("edx", 0));
                        else{
                            cout << "[ERRO] Edificio invalido" << endl;
                            return false;
                        }
                    return true;
                    } else cout << "[ERRO] Esta zona ja tem um edificio" << endl;
                } else cout << "[ERRO] Coluna invalida" << endl;
            } else cout << "[ERRO] Linha invalida" << endl;
        } else cout << "[ERRO] Tipo de edificio invalido" << endl;
    }
    else if (args[0] == "cont" && args.size() == 2){
        if(args[1] == "oper" || args[1] == "len" || args[1] == "miner"){
            
            vector<Zona*> pastos;
            for(int i = 0; i < linhas; i++){
                for(int j = 0; j < colunas; j++){
                    if(zonas[i][j]->getSigla() == "pas"){
                        pastos.push_back(zonas[i][j]);
                    }
                }
            }

            if(pastos.size()){
                int randomIntger = rand()%(pastos.size() - 0) + 0;
                if(args[1] == "oper"){
                    (*pastos[randomIntger]).addTrabalhador(new Operario(15, dia));
                }
                else if(args[1] == "len"){
                    (*pastos[randomIntger]).addTrabalhador(new Lenhador(20, dia));
                }
                else if(args[1] == "miner"){
                    (*pastos[randomIntger]).addTrabalhador(new Mineiro(10, dia));
                }
                return true;
            } else {
                cout << "[ERRO] Nao existem zonas de pasto disponiveis" << endl;
                return false;
            }
        } else {
            cout << "[ERRO] Esse tipo de operario nao existe" << endl;
            return false;
        }
    }
    else if (args[0] == "liga" && args.size() == 3){
        int l, c;
        if(isNumber(args[1])) l = stoi(args[1]);
        else{
            cout << "[ERRO] Introduza um numero para a linha" << endl;
            return false;
        }
        if(isNumber(args[2])) c = stoi(args[2]);
        else{
            cout << "[ERRO] Introduza um numero para a coluna" << endl;
            return false;
        }
        // Implementar a validaço do edifício
        if(l < linhas && l >= 0){
            if(c < colunas && c >= 0){
                if(zonas[l][c]->getEdificio() != nullptr){
                    if(zonas[l][c]->getEdificio()->getLigado() == 0){
                        zonas[l][c]->getEdificio()->ligar();
                        cout << "Edificio DESLIGADO na posicao (" << l << "," << c << ")!" << endl;
                        return true;
                    } else {
                        cout << "[ERRO] Edificio ja esta ligado" << endl;
                        return false;
                    }
                } else { 
                    cout << "[ERRO] Nao existe edificio nessa zona" << endl;
                    return false;
                }
                cout << "Edificio LIGADO na posicao (" << l << "," << c << ")!" << endl;
                return true;
            } else cout << "[ERRO] Coluna invalida" << endl;
        } else cout << "[ERRO] Linha invalida" << endl;
    }
    else if (args[0] == "des" && args.size() == 3){
        int l, c;
        if(isNumber(args[1])) l = stoi(args[1]);
        else{
            cout << "[ERRO] Introduza um numero para a linha" << endl;
            return false;
        }
        if(isNumber(args[2])) c = stoi(args[2]);
        else{
            cout << "[ERRO] Introduza um numero para a coluna" << endl;
            return false;
        }
        // Implementar a validação do edifício
        if(l < linhas && l >= 0){
            if(c < colunas && c >= 0){
                if(zonas[l][c]->getEdificio() != nullptr){
                    if(zonas[l][c]->getEdificio()->getLigado() == 1){
                        zonas[l][c]->getEdificio()->desligar();
                        cout << "Edificio DESLIGADO na posicao (" << l << "," << c << ")!" << endl;
                        return true;
                    } else {
                        cout << "[ERRO] Edificio ja esta desligado" << endl;
                        return false;
                    }
                } else { 
                    cout << "[ERRO] Nao existe edificio nessa zona" << endl;
                    return false;
                }
                cout << "Edificio DESLIGADO na posicao (" << l << "," << c << ")!" << endl;
                return true;
            } else cout << "[ERRO] Coluna invalida" << endl;
        } else cout << "[ERRO] Linha invalida" << endl;
    }
    else if (args[0] == "list" && args.size() >= 1){
        if(args.size() == 1){
            cout << getInfoZona() << endl;
            return true;
        } else if(args.size() == 3) {
            int linhaX, colunaX;
            if(isNumber(args[1])) linhaX = stoi(args[1]);
            else{
                cout << "[ERRO] Introduza um numero para a linha" << endl;
                return false;
            }
            if(isNumber(args[2])) colunaX = stoi(args[2]);
            else{
                cout << "[ERRO] Introduza um numero para a coluna" << endl;
                return false;
            }

            if(linhaX < linhas && linhaX >= 0){
                if(colunaX < colunas && colunaX >= 0){
                    cout << getInfoZona(linhaX, colunaX) << endl;
                    return true;
                } else cout << "[ERRO] Coluna invalida" << endl;
            } else cout << "[ERRO] Linha invalida" << endl;
        }
    }
    else if (args[0] == "config" && args.size() == 2){
        // Implementar o resto do comando
        if(!args[1].empty()){
            string line;
            ifstream input_file(args[1]); //declarar e abrir o ficheiro
            if (!input_file) {
                cout << "Ocorreu um erro ao abrir o ficheiro" << endl;
                return false;  //ocorreu um erro
            }

            while (getline(input_file, line)) {
                istringstream lineFich(line);
                cout << line << endl;
            }

            // Close the file
            input_file.close();
            cout << "Ficheiro de configuracao " << args[1] << " LIDO!" << endl;
            return true;
        }
    }
    else if (args[0] == "move" && args.size() == 4){
        Zona *zona;
        int linhaX, colunaX;
        string id = "";
        int l = 0;
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                for(l = 0; l < zonas[i][j]->getTrabalhadores().size(); l++){
                    if(zonas[i][j]->getTrabalhadores()[l]->getIdTrabalhador() == args[1]){
                        zona = zonas[i][j];
                        id = zonas[i][j]->getTrabalhadores()[l]->getIdTrabalhador();
                    }
                }
            }
        }
        if(id == ""){
            cout << "[DEBUG] Não existe nenhum trabalhador com o id " << args[1] << endl;
            return false;
        }
        if(isNumber(args[2])) linhaX = stoi(args[2]);
        else{
            cout << "[ERRO] Introduza um numero para a linha" << endl;
            return false;
        }
        if(isNumber(args[3])) colunaX = stoi(args[3]);
        else{
            cout << "[ERRO] Introduza um numero para a coluna" << endl;
            return false;
        }

        if(linhaX < linhas && linhaX >= 0){
            if(colunaX < colunas && colunaX >= 0){
                zonas[linhaX][colunaX]->addTrabalhador(zona->getTrabalhadores()[l]);
                zona->removeTrabalhador(zona->getTrabalhadores()[l]);
                return true;
            } else cout << "[ERRO] Coluna invalida" << endl;
        } else cout << "[ERRO] Linha invalida" << endl;
    }
    else if (args[0] == "debcash" && args.size() == 2){
        // Implementar o resto do comando
        int valor;
        if(isNumber(args[1])) valor = stoi(args[1]);
        else{
            cout << "[ERRO] Introduza um numero valido para o valor" << endl;
            return false;
        }
        cout << args[1] << endl;
        cout << valor << endl;
        if(valor > 0){
            addSaldo(valor);
            cout << "[DEBUG] Foram ADICIONADOS " << valor << "€ a sua conta!" << endl;
            return true;
        } else if(valor < 0){
            addSaldo(valor);
            cout << "[DEBUG] Foram REMOVIDOS " << valor << "€ da sua conta." << endl;
            return true;
        } else {
            cout << "[ERRO] Introduza um numero valido para o valor" << endl;
            return false;
        }
    } 
    else if (args[0] == "debed" && args.size() == 4){
        int linhaX, colunaX;
        if(isNumber(args[2])) linhaX = stoi(args[2]);
        else{
            cout << "[ERRO] Introduza um numero para a linha" << endl;
            return false;
        }
        if(isNumber(args[3])) colunaX = stoi(args[3]);
        else{
            cout << "[ERRO] Introduza um numero para a coluna" << endl;
            return false;
        }

        if(args[1] == "minaf" || args[1] == "minac" || args[1] == "central" || args[1] == "bat" || args[1] == "fund" || args[1] == "edx"){
            if(linhaX < linhas && linhaX >= 0){
                if(colunaX < colunas && colunaX >= 0){
                    if(zonas[linhaX][colunaX]->getEdificio() == nullptr){
                        cout << "[DEBUG] ";
                        if(args[1] == "minaf")
                            zonas[linhaX][colunaX]->setEdificio(new MinaFerro("minaf", 10));
                        else if(args[1] == "minac")
                            zonas[linhaX][colunaX]->setEdificio(new MinaCarvao("minac", 10));
                        else if(args[1] == "central")
                            zonas[linhaX][colunaX]->setEdificio(new Central("central", 15));
                        else if(args[1] == "bat")
                            zonas[linhaX][colunaX]->setEdificio(new Bateria("bat", 10, 10));
                        else if(args[1] == "fund")
                            zonas[linhaX][colunaX]->setEdificio(new Fundicao("fund", 10));
                        else if(args[1] == "edx")
                            zonas[linhaX][colunaX]->setEdificio(new EdificioX("edx", 0));
                        else{
                            cout << "[ERRO] Edificio invalido" << endl;
                            return false;
                        }
                    return true;
                    } else cout << "[ERRO] Esta zona ja tem um edificio" << endl;
                } else cout << "[ERRO] Coluna invalida" << endl;
            } else cout << "[ERRO] Linha invalida" << endl;
        } else cout << "[ERRO] Tipo de edificio invalido" << endl;
    }
    else if (args[0] == "debkill" && args.size() == 2){
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                for(int l = 0; l < zonas[i][j]->getTrabalhadores().size(); l++){
                    if(zonas[i][j]->getTrabalhadores()[l]->getIdTrabalhador() == args[1]){
                        zonas[i][j]->removeTrabalhador(zonas[i][j]->getTrabalhadores()[l]);
                        cout << "[DEBUG] Trabalhador com ID " << args[1] << " REMOVIDO do seu posto!" << endl;
                        return true;
                    }
                }
            }
        }
        cout << "[DEBUG] Não existe nenhum trabalhador com o id " << args[1] << endl;
        return false;
    }
    else if (args[0] == "exit" && args.size() == 1){
        cout << "A sair do jogo" << endl;
        exit(0);
    }
    else return false;
    return false;
}