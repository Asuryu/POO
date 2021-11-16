#include "engine.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool validaComando(istringstream &iss){
    // string comando, valida;
    // cout << "Introduza o comando: ";
    // getline(cin, comando);
    // istringstream iss(comando);
    // iss >> valida;

    vector<string> args;
    while (iss){
        string subs;
        iss >> subs;
        args.push_back(subs);
    }
    args.pop_back();
    
    if (args[0] == "cons"){
        int l = stoi(args[2]);
        int c = stoi(args[3]);
        if(args[1] == "minaf" || args[1] == "minac" || args[1] == "central" || args[1] == "bat" || args[1] == "fund" || args[1] == "edx"){
            if(l >= 3 && l <= 8){
                if(c >= 3 && c <= 16){
                    cout << "Edifício do tipo " << args[1] << " CONSTRUÍDO na posição (" << l << "," << c << ")!" << endl;
                    return true;
                } else return false;
            } else return false;
        } else return false;
    }
    else if (args[0] == "liga"){
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
    else if (args[0] == "des"){
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
    else if (args[0] == "move"){
        int id = stoi(args[2]);
        int l = stoi(args[3]);
        int c = stoi(args[4]);
        // Implementar a validação do ID
        if(l >= 3 && l <= 8){
            if(c >= 3 && c <= 16){
                cout << "Edifício com o ID " << id << "MOVIDO para a posição (" << l << "," << c << ")!" << endl;
                return true;
            } else return false;
        } else return false;
    }
    else if (args[0] == "vende"){
        int quant = stoi(args[2]);
        if(args[1] == "ferro" || args[1] == "aco" || args[1] == "carvao" || args[1] == "mad" || args[1] == "viga" || args[1] == "eletr"){
            if(quant > 0){
                cout << "Material " << args[1] << " x" << quant << "foi VENDIDO!" << endl;
                return true;
            }
            else return false;
        } else return false;
    }
    else if (args[0] == "cont"){
        if(args[1] == "oper" || args[1] == "len" || args[1] == "miner"){
            cout << "Opearário do tipo " << args[1] << " foi CONTRATADO!" << endl;
            return true;
        } else return false;
    }
    else if (args[0] == "list"){
        // Implementar a validação do edifício
        // Mostrar a informação detalhada
        cout << "ZONA XYZ" << endl;
        return true;
    }
    else if (args[0] == "next"){
        // Implementar o resto do comando
        cout << "Fase de recolha TERMINADA!" << endl;
        return true;
    }
    else if (args[0] == "save"){
        // Implementar o resto do comando
        if(args[1].empty()){
            cout << "Savegame " << args[1] << " GUARDADO!" << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "load"){
        // Implementar o resto do comando
        if(args[1].empty()){
            cout << "Savegame " << args[1] << " CARREGADO!" << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "apaga"){
        // Implementar o resto do comando
        if(args[1].empty()){
            cout << "Savegame " << args[1] << " APAGADO!" << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "config"){
        // Implementar o resto do comando
        if(args[1].empty()){
            cout << "Ficheiro de configuração " << args[1] << " LIDO!" << endl;
            return true;
        }
        else return false;
    }
    else if (args[0] == "debcash"){
        // Implementar o resto do comando
        int valor = stoi(args[1]);
        if(valor != 0){
            cout << "[DEBUG] Foram ADICIONADOS " << args[1] << "€ à sua conta!" << endl;
            return true;
        }
        else return false;
    } 
    else if (args[0] == "debed"){
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
    else if (args[0] == "debkill"){
        int id = stoi(args[1]);
        // Implementar a verificação do ID
        cout << "[DEBUG] Trabalhador com ID " << id << " REMOVIDO do seu posto!" << endl;
        return true;
    }
    else return false;
}