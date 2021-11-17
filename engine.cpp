#include "engine.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
using namespace std;

string Zona::getInfo(){
    ostringstream oss;
    oss << "(" << linha << ", " << coluna << ")\nZona: " << zona << "\nEdifício: " << edificio << "\nTrabalhadores: " << trabalhadores << "\nNr. Trabalhadores: " << nrTrabalhadores << endl;
    return oss.str();
}
void Zona::setLinha(int l){ linha = l; }
void Zona::setColuna(int c){ coluna = c; }
int Zona::getLinha(){ return linha; }
int Zona::getColuna(){ return coluna; }
string Zona::getZona(){ return zona; }
string Zona::getEdificio(){ return edificio; }
string Zona::getTrabalhadores(){ return trabalhadores; }
int Zona::getNrTrabalhadores(){ return nrTrabalhadores; }
void Zona::cons(string tipo, int linhaX, int colunaX){
    this->edificio = tipo;
    cout << "Edifício do tipo " << edificio << " CONSTRUÍDO na posição (" << linhaX << "," << colunaX << ")!" << endl;
}
void Zona::cont(string tipo){
    if(tipo == "oper" || tipo == "len" || tipo == "miner"){
        cout << "Opearário do tipo " << tipo << " foi CONTRATADO e colocado na zona de pasto (" << linha << ", " << coluna << ")!" << endl;
    } else cout << "[ERRO] Esse tipo de operário não existe" << endl;
}

void mostraASCII(){
    cout << " ___ _ _       __       " << endl;
    cout << "|_ _| | |__   /_/ _   _ " << endl;
    cout << " | || | '_ \\ / _ \\ | | |" << endl;
    cout << " | || | | | |  __/ |_| |" << endl;
    cout << "|___|_|_| |_|\\___|\\__,_|" << endl << endl;
}

bool isNumber(string x){
    regex e ("-{0,1}\\d+");
    return (regex_match (x,e));
}

bool validaComando(vector< vector<Zona> > &matriz, istringstream &iss, int linhasTab, int colunasTab){

    vector<string> args;
    while (iss){
        string subs;
        iss >> subs;
        args.push_back(subs);
    }
    args.pop_back();
    
    if (args[0] == "exec" && args.size() == 2){

    }
    else if (args[0] == "cons" && args.size() == 4){
        int linhaX, colunaX;
        if(isNumber(args[2])){
            linhaX = stoi(args[2]);
        }
        else{
            cout << "[ERRO] Introduza um número para a linha" << endl;
            return false;
        }
        if(isNumber(args[3])){
            colunaX = stoi(args[3]);
        }
        else{
            cout << "[ERRO] Introduza um número para a coluna" << endl;
            return false;
        }

        if(args[1] == "minaf" || args[1] == "minac" || args[1] == "central" || args[1] == "bat" || args[1] == "fund" || args[1] == "edx"){
            if(linhaX < linhasTab && linhaX > 0){
                if(colunaX < colunasTab && colunaX > 0){
                    matriz[linhaX][colunaX].cons(args[1], linhaX, colunaX);
                } else cout << "[ERRO] Coluna inválida" << endl;
            } else cout << "[ERRO] Linha inválida" << endl;
        } else cout << "[ERRO] Tipo de edifício inválido" << endl;
    }
    else if (args[0] == "liga" && args.size() == 3){
        int l = stoi(args[1]);
        int c = stoi(args[2]);
        // Implementar a validação do edifício
        if(l >= 3 && l <= 8){
            if(c >= 3 && c <= 16){
                cout << "Edifício LIGADO na posição (" << l << "," << c << ")!" << endl;
                return true;
            } else return false;
        } else return false;
    }
    else if (args[0] == "des" && args.size() == 3){
        int l = stoi(args[1]);
        int c = stoi(args[2]);
        // Implementar a validação do edifício
        if(l >= 3 && l <= 8){
            if(c >= 3 && c <= 16){
                cout << "Edifício DESLIGADO na posição (" << l << "," << c << ")!" << endl;
                return true;
            } else return false;
        } else return false;
    }
    else if (args[0] == "move" && args.size() == 4){
        int id = stoi(args[1]);
        int l = stoi(args[2]);
        int c = stoi(args[3]);
        // Implementar a validação do ID
        if(l >= 3 && l <= 8){
            if(c >= 3 && c <= 16){
                cout << "Edifício com o ID " << id << "MOVIDO para a posição (" << l << "," << c << ")!" << endl;
                return true;
            } else return false;
        } else return false;
    }
    else if (args[0] == "vende" && args.size() == 3){
        int quant = stoi(args[2]);
        if(args[1] == "ferro" || args[1] == "aco" || args[1] == "carvao" || args[1] == "mad" || args[1] == "viga" || args[1] == "eletr"){
            if(quant > 0){
                cout << "Material " << args[1] << " x" << quant << "foi VENDIDO!" << endl;
                return true;
            }
            else return false;
        } else return false;
    }
    else if (args[0] == "cont" && args.size() == 2){
        vector<Zona> pastos;
        for(int i = 0; i < linhasTab; i++){
            for(int j = 0; j < colunasTab; j++){
                if(matriz[i][j].getZona() == "pas"){
                    pastos.push_back(matriz[i][j]);
                }
            }
        }
        if(pastos.size()){
            int randomIntger = rand()%(pastos.size() - 0) + 0;
            pastos[randomIntger].cont(args[1]);
            return true;
        } else return false;

    }
    else if (args[0] == "list" && args.size() >= 1){
        if(args.size() == 1){
            for(int i = 0; i < linhasTab; i++){
                for(int j = 0; j < colunasTab; j++){
                    cout << matriz[i][j].getInfo() << endl;
                }
            }
            return true;
        } else if(args.size() == 3) {
            int linhaX, colunaX;
            if(isNumber(args[1])) linhaX = stoi(args[1]);
            else return false;
            if(isNumber(args[2])) colunaX = stoi(args[2]);
            else return false;
            cout << matriz[linhaX][colunaX].getInfo() << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "next" && args.size() == 1){
        // Implementar o resto do comando
        cout << "Fase de recolha TERMINADA!" << endl;
        return true;
    }
    else if (args[0] == "save" && args.size() == 2){
        // Implementar o resto do comando
        if(args[1].empty()){
            cout << "Savegame " << args[1] << " GUARDADO!" << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "load" && args.size() == 2){
        // Implementar o resto do comando
        if(args[1].empty()){
            cout << "Savegame " << args[1] << " CARREGADO!" << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "apaga" && args.size() == 2){
        // Implementar o resto do comando
        if(args[1].empty()){
            cout << "Savegame " << args[1] << " APAGADO!" << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "config" && args.size() == 2){
        // Implementar o resto do comando
        if(args[1].empty()){
            cout << "Ficheiro de configuração " << args[1] << " LIDO!" << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "debcash" && args.size() == 2){
        // Implementar o resto do comando
        int valor = stoi(args[1]);
        if(valor != 0){
            cout << "[DEBUG] Foram ADICIONADOS " << args[1] << "€ à sua conta!" << endl;
            return true;
        }
        else return false;
    } 
    else if (args[0] == "debed" && args.size() == 4){
        int l = stoi(args[2]);
        int c = stoi(args[3]);
        if(args[1] == "minaf" || args[1] == "minac" || args[1] == "central" || args[1] == "bat" || args[1] == "fund" || args[1] == "edx"){
            if(l >= 3 && l <= 8){
                if(c >= 3 && c <= 16){
                    cout << "[DEBUG] Edifício do tipo " << args[1] << " CONSTRUÍDO na posição (" << l << "," << c << ")!" << endl;
                    return true;
                } else return false;
            } else return false;
        } else return false;
    }
    else if (args[0] == "debkill" && args.size() == 2){
        int id = stoi(args[1]);
        // Implementar a verificação do ID
        cout << "[DEBUG] Trabalhador com ID " << id << " REMOVIDO do seu posto!" << endl;
        return true;
    }
    else if (args[0] == "exit" && args.size() == 1){
        exit(0);
    }
    else return false;
    return false;
}
