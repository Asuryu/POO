// ISEC - Trabalho Prático de POO 2021/2022
// Tomás Gomes Silva - 2020143845
// Tomás da Cunha Pinto - 2020144067

#include "engine.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <regex>
#include <algorithm>
#include <fstream>

using namespace std;

string Zona::getInfo() const{
    ostringstream oss;
    oss << "(" << linha << ", " << coluna << ")\nZona: " << zona << "\nEdificio: " << edificio << "\nTrabalhadores: " << trabalhadores << "\nNr. Trabalhadores: " << nrTrabalhadores << endl;
    return oss.str();
}
void Zona::setLinha(int l){ linha = l; }
void Zona::setColuna(int c){ coluna = c; }
void Zona::setZona(string z){ zona = z; }
string Zona::getZona() const { return zona; }
string Zona::getEdificio() const { return edificio; }
string Zona::getTrabalhadores() const { return trabalhadores; }
void Zona::setNrTrabalhadores(int n) { nrTrabalhadores = n; }
int Zona::getNrTrabalhadores() const { return nrTrabalhadores; }
void Zona::cons(string tipo, int linhaX, int colunaX){
    this->edificio = tipo;
    cout << "Edificio do tipo " << edificio << " CONSTRUIDO na posicao (" << linhaX << "," << colunaX << ")!" << endl;
}
void Zona::cont(string tipo){
    if(tipo == "oper") trabalhadores.append("O");
    else if(tipo == "miner") trabalhadores.append("M");
    else if(tipo == "len") trabalhadores.append("L");
    else return;
    nrTrabalhadores++;
    cout << "Opearario do tipo " << tipo << " foi CONTRATADO e colocado na zona de pasto (" << linha << ", " << coluna << ")!" << endl;
}

void menu(int &linhas, int &colunas){
    int opcao_menu;
    string input;

    do {
        cout << "\033[2J\033[1;1H";
        mostraASCII();
        cout << "\n1 - Comecar o jogo" << endl;
        cout << "2 - Sair do jogo\n\nEscolha: ";
        getline(cin, input);
        stringstream(input) >> opcao_menu;
        if(opcao_menu == 1 || opcao_menu == 2) break;
    } while (1);
    if(opcao_menu == 2) exit(0);

    do {
        cout << "\033[2J\033[1;1H";
        mostraASCII();
        cout << "Introduza o numero de linhas: ";
        getline(cin, input);
        stringstream(input) >> linhas;
    } while (linhas < 3 || linhas > 8);
    do {
        cout << "Introduza o numero de colunas: ";
        getline(cin, input);
        stringstream(input) >> colunas;
    } while (colunas < 3 || colunas > 16);
    cout << "\033[2J\033[1;1H";
    mostraASCII();
}

void initIlha(vector< vector<Zona> > &matriz, int linhas, int colunas){
    Zona z;
    vector<Zona> tmp;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            tmp.push_back(z);
        }
        matriz.push_back(tmp);
    }

    vector<string> zonas;
    string zonasExistentes[6] = {"mnt", "dsr", "pas", "flr", "pnt", "znZ"};
    int celulas = linhas * colunas;
    int repeticoes = celulas / 6;
    int randIndex;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < repeticoes; j++){
            zonas.push_back(zonasExistentes[i]);
        }
    }
    random_shuffle(zonas.begin(), zonas.end());
    int count = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j].setLinha(i);
            matriz[i][j].setColuna(j);
            matriz[i][j].setNrTrabalhadores(0);
            if(count < (6 * repeticoes)) matriz[i][j].setZona(zonas[count]);
            else{
                randIndex = rand()%(6);
                matriz[i][j].setZona(zonas[randIndex]);
            }
            count++;
        }
    }


}


void mostraIlha(vector< vector<Zona> > matriz, int linhas, int colunas){
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
                if(z == 0) cout << "|" << left << setfill(' ') << setw(7) << matriz[i][k].getZona();
                else if(z == 1){
                    string edificio = matriz[i][k].getEdificio();
                    string edf;
                    if (edificio == "minaf") edf = "mnF";
                    else if (edificio == "minac") edf = "mnC";
                    else if (edificio == "central") edf = "elec";
                    else if (edificio == "bat") edf = "bat";
                    else if (edificio == "fund") edf = "fun";
                    cout << "|" << left << setfill(' ') << setw(7) << edf;
                }

                else if(z == 2) cout << "|" << left << setfill(' ') << setw(7) << (matriz[i][k].getTrabalhadores()).substr(0, 6);
                else if(z == 3) cout << "|" << left << setfill(' ') << setw(7) << matriz[i][k].getNrTrabalhadores();
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
    cout << "DIA N/A" << endl;
    cout << "Quantidade de Recursos: N/A" << endl;
    int nTrab = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            nTrab += matriz[i][j].getNrTrabalhadores();
        }
    }
    cout << "Numero de Trabalhadores: " << nTrab << endl;
    cout << endl << endl;

}


void mostraInfoTotal(vector< vector<Zona> > &matriz, int linhasTab, int colunasTab){
    for(int i = 0; i < linhasTab; i++){
        for(int j = 0; j < colunasTab; j++){
            cout << matriz[i][j].getInfo() << endl;
        }
    }
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
        string line;
        ifstream input_file(args[1]); //declarar e abrir o ficheiro
        if (!input_file) {
            cout << "Ocorreu um erro ao abrir o ficheiro" << endl;
            return false;  //ocorreu um erro
        }

        while (getline(input_file, line)) {
            istringstream lineFich(line);
            validaComando(matriz, lineFich, linhasTab, colunasTab);
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
            if(linhaX < linhasTab && linhaX >= 0){
                if(colunaX < colunasTab && colunaX >= 0){
                    matriz[linhaX][colunaX].cons(args[1], linhaX, colunaX);
                    return true;
                } else cout << "[ERRO] Coluna invalida" << endl;
            } else cout << "[ERRO] Linha invalida" << endl;
        } else cout << "[ERRO] Tipo de edificio invalido" << endl;
    }
    else if (args[0] == "liga" && args.size() == 3){
        int l = stoi(args[1]);
        int c = stoi(args[2]);
        // Implementar a validaço do edifício
        if(l >= 3 && l <= 8){
            if(c >= 3 && c <= 16){
                cout << "Edificio LIGADO na posicao (" << l << "," << c << ")!" << endl;
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
                cout << "Edificio DESLIGADO na posicao (" << l << "," << c << ")!" << endl;
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
                cout << "Edificio com o ID " << id << "MOVIDO para a posicao (" << l << "," << c << ")!" << endl;
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
        if(args[1] == "oper" || args[1] == "len" || args[1] == "miner"){
            vector<Zona*> pastos;
            for(int i = 0; i < linhasTab; i++){
                for(int j = 0; j < colunasTab; j++){
                    if(matriz[i][j].getZona() == "pas"){
                        pastos.push_back(&matriz[i][j]);
                    }
                }
            }
            if(pastos.size()){
                int randomIntger = rand()%(pastos.size() - 0) + 0;
                (*pastos[randomIntger]).cont(args[1]);
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
    else if (args[0] == "list" && args.size() >= 1){
        if(args.size() == 1){
            mostraInfoTotal(matriz, linhasTab, colunasTab);
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

            if(linhaX < linhasTab && linhaX >= 0){
                if(colunaX < colunasTab && colunaX >= 0){
                    cout << matriz[linhaX][colunaX].getInfo() << endl;
                    return true;
                } else cout << "[ERRO] Coluna invalida" << endl;
            } else cout << "[ERRO] Linha invalida" << endl;
        }
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
                    cout << "[DEBUG] Edificio do tipo " << args[1] << " CONSTRUIDO na posicao (" << l << "," << c << ")!" << endl;
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
