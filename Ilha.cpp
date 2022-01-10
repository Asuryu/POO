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
#include <cstdlib>
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
    string zonasExistentes[6] = {"mnt", "dsr", "pas", "flr", "pnt", "vul"};

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
                // Gerar número aleatório entre 20 e 40
                int arvores = rand() % 20 + 20;
                zonasLinha.push_back(new Floresta(i, j, arvores));
            }
            else if(zonasAux[randIndex] == "pnt"){
                zonasLinha.push_back(new Pantano(i, j));
            }
            else if(zonasAux[randIndex] == "vul"){
                zonasLinha.push_back(new Vulcao(i, j));
            }
            zonasAux.erase(zonasAux.begin() + randIndex);
        }
        zonas.push_back(zonasLinha);
    }
    
    mostraIlha();
}

Ilha::Ilha() :  nrVigasMadeira(200), nrFerro(10), nrBarraDeAco(10), nrCarvao(10), nrMadeira(10), nrEletricidade(5), vigasMadeiraUsar(0), flag(0),
                custoMinaf(100), custoMinac(100), custoBateria(10), custoFundicao(10), custoCentral(15), custoRestaurante(30), custoOper(15), custoLen(20),
                custoMiner(10), custoVigasMadeira(10){
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
    cout << "Saldo: " << saldo << " euros" << endl;
    cout << "Numero de Trabalhadores: " << getNrTrabalhadores() << endl << endl;
    cout << "Recursos: " << endl;
    cout << "Vigas de Madeira: " << nrVigasMadeira << endl;
    cout << "Ferro: " << nrFerro << endl; 
    cout << "Barras de Aco: " << nrBarraDeAco << endl; 
    cout << "Carvao: " << nrCarvao << endl; 
    cout << "Madeira: " << nrMadeira << endl; 
    cout << "Eletricidade: " << nrEletricidade << endl << endl; 
}

void Ilha::addSaldo(float saldo){
    if(saldo > 0) cout << "Foram ADICIONADOS " << saldo << " euros a sua conta!" << endl;
    else if(saldo < 0) cout << "Foram DEBITADOS " << abs(saldo) << " euros da sua conta." << endl;
    this->saldo += saldo;
}
float Ilha::getSaldo(){
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
    ostringstream oss;
    string state, tipo;

    Zona *zona = zonas[linha][coluna];

    oss << zona->getInfoZona() << endl;
    if(zona->getEdificio() != nullptr){
        if(zona->getEdificio()->getLigado()) state = "LIGADO";
        else state = "DESLIGADO";
        oss << "Edificio encontra-se " << state << " e está a nivel " << zona->getEdificio()->getNivel() << endl;
    }
    if(zona->getTrabalhadores().size() > 0){
        oss << "Trabalhadores: " << endl;
        for(int i = 0; i < zona->getTrabalhadores().size(); i++){
            if(zona->getTrabalhadores()[i]->getSigla() == "O") tipo = "Operário";
            else if(zona->getTrabalhadores()[i]->getSigla() == "M") tipo = "Mineiro";
            else if(zona->getTrabalhadores()[i]->getSigla() == "L") tipo = "Lenhador";
            oss << tipo << "(" << zona->getTrabalhadores()[i]->getIdTrabalhador() << ")" << endl;
        }
    }
    return oss.str();
}

void Ilha::jogar(){
    bool state = false;
    string input;
    do { // Ciclo de jogo
        fflush(stdin);
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
        if(args[1] == "minaf" || args[1] == "minac" || args[1] == "central" || args[1] == "bat" || args[1] == "fund" || args[1] == "rest"){
            if(linhaX < linhas && linhaX >= 0){
                if(colunaX < colunas && colunaX >= 0){
                    if(zonas[linhaX][colunaX]->getEdificio() == nullptr){
                        if(args[1] == "minaf"){
                            if(flag == 1){
                                do{
                                    cout << "Introduza o numero de vigas de madeira que pretende usar na construcao deste Edificio: " << endl;
                                    cin >> vigasMadeiraUsar;                                 
                                    if(nrVigasMadeira - vigasMadeiraUsar < 0) cout << "Nao tem vigas de madeira suficientes." << endl;
                                }while((vigasMadeiraUsar < 0 || vigasMadeiraUsar > 10) || (nrVigasMadeira - vigasMadeiraUsar < 0));
                                if (saldo - (custoMinaf * 10 - vigasMadeiraUsar * custoMinaf) < 0){
                                    cout << "Nao tem dinheiro suficiente. Faltam " << (custoMinaf * 10 - vigasMadeiraUsar * custoMinaf) << " euros!" << endl;
                                    return false;
                                };                           
                                nrVigasMadeira -= vigasMadeiraUsar;
                                addSaldo(-(custoMinaf * 10 - vigasMadeiraUsar * custoMinaf));
                                zonas[linhaX][colunaX]->setEdificio(new MinaFerro("minaf", (custoMinaf * 10 - vigasMadeiraUsar * custoMinaf)));
                            }
                            else{
                                do{
                                    cout << "Introduza o numero de vigas de madeira que pretende usar na construcao deste Edificio: ";
                                    cin >> vigasMadeiraUsar;
                                    if(vigasMadeiraUsar < 0 || vigasMadeiraUsar > 10) cout << "Introduza um valor entre 0 e 10" << endl;         
                                    else if(nrVigasMadeira - vigasMadeiraUsar < 0) cout << "Nao tem vigas de madeira suficientes." << endl;
                                } while((vigasMadeiraUsar < 0 || vigasMadeiraUsar > 10) || (nrVigasMadeira - vigasMadeiraUsar < 0));
                                if(saldo - (100 - vigasMadeiraUsar * custoVigasMadeira) < 0){
                                    cout << "Nao tem dinheiro suficiente. Faltam " << (100 - vigasMadeiraUsar * custoVigasMadeira) << " euros!" << endl;
                                    return false;
                                };
                                nrVigasMadeira -= vigasMadeiraUsar;
                                addSaldo(-(100 - vigasMadeiraUsar * custoVigasMadeira));
                                zonas[linhaX][colunaX]->setEdificio(new MinaFerro("minaf", (100 - vigasMadeiraUsar * custoVigasMadeira)));
                            }
                        }
                        else if(args[1] == "minac"){
                            if(flag == 1){
                                do{
                                    cout << "Introduza o numero de vigas de madeira que pretende usar na construcao deste Edificio: " << endl;
                                    cin >> vigasMadeiraUsar;                                 
                                    if(nrVigasMadeira - vigasMadeiraUsar < 0) cout << "Nao tem vigas de madeira suficientes." << endl;
                                }while((vigasMadeiraUsar < 0 || vigasMadeiraUsar > 10) || (nrVigasMadeira - vigasMadeiraUsar < 0));
                                if (saldo - (custoMinac * 10 - vigasMadeiraUsar * custoMinac) < 0){
                                    cout << "Nao tem dinheiro suficiente. Faltam " << (custoMinac * 10 - vigasMadeiraUsar * custoMinac) << " euros!" << endl;
                                    return false;
                                };                           
                                nrVigasMadeira -= vigasMadeiraUsar;
                                addSaldo(-(custoMinac * 10 - vigasMadeiraUsar * custoMinac));
                                zonas[linhaX][colunaX]->setEdificio(new MinaFerro("minaf", (custoMinac * 10 - vigasMadeiraUsar * custoMinac)));    
                            }
                            else{
                                do{
                                    cout << "Introduza o numero de vigas de madeira que pretende usar na construcao deste Edificio: " << endl;
                                    cin >> vigasMadeiraUsar;                                
                                    if(nrVigasMadeira - vigasMadeiraUsar < 0) cout << "Não tem vigas de madeira suficientes." << endl;
                                }while((vigasMadeiraUsar < 0 || vigasMadeiraUsar > 10) || (nrVigasMadeira - vigasMadeiraUsar < 0));
                                if (saldo - (100 - vigasMadeiraUsar * custoVigasMadeira) < 0){
                                    cout << "Nao tem dinheiro suficiente. Faltam " << (100 - vigasMadeiraUsar * custoVigasMadeira) << " euros!" << endl;
                                    return false;
                                };                           
                                nrVigasMadeira -= vigasMadeiraUsar;
                                addSaldo(-(100 - vigasMadeiraUsar * custoVigasMadeira));
                                zonas[linhaX][colunaX]->setEdificio(new MinaCarvao("minac", (100 - vigasMadeiraUsar * custoVigasMadeira)));
                            }                
                        }
                        else if(args[1] == "central"){
                            if(saldo - custoCentral < 0){
                                cout << "Nao tem dinheiro suficiente. Faltam " << -(saldo - custoCentral) << " euros!" << endl;
                                return false;
                            };
                            addSaldo(-custoCentral); //Custo da construção da Central
                            zonas[linhaX][colunaX]->setEdificio(new Central("central", custoCentral));
                        }
                        else if(args[1] == "bat"){
                            if(nrVigasMadeira - 10 < 0){
                              cout << "Nao tem vigas de madeira suficientes. Faltam " << -(nrVigasMadeira - 10) << " vigas de madeira!" << endl;
                              return false;
                            }
                            if(saldo - custoBateria < 0){
                              cout << "Nao tem dinheiro suficiente. Faltam " << -(saldo - custoBateria) << " euros!" << endl;
                              return false;
                            }
                            addSaldo(-custoBateria); //Custo da construção da Bateria é "10€ + 10 Vigas". (Falta retirar as Vigas de Madeira adicionadas)
                            zonas[linhaX][colunaX]->setEdificio(new Bateria("bat", custoBateria));
                        }
                        else if(args[1] == "fund"){
                            if(saldo - custoFundicao < 0){
                                cout << "Nao tem dinheiro suficiente. Faltam " << -(saldo - custoFundicao) << " euros!" << endl;
                                return false;
                            };
                            addSaldo(-custoFundicao); //Custo da construção da Fundição.
                            zonas[linhaX][colunaX]->setEdificio(new Fundicao("fund", custoFundicao));
                        }
                        else if(args[1] == "rest"){
                            if(saldo - custoRestaurante < 0){
                                cout << "Nao tem dinheiro suficiente. Faltam " << -(saldo - custoRestaurante) << " euros!" << endl;
                                return false;
                            };
                            addSaldo(-custoRestaurante); //Ainda temos de decidir o que fazer neste edificio e o seu respetivo preço.
                            zonas[linhaX][colunaX]->setEdificio(new Restaurante("rest", custoRestaurante));
                        }
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
                    if(saldo - custoOper < 0){
                        cout << "Nao tem dinheiro suficiente. Faltam " << -(saldo - custoOper) << " euros!" << endl;
                        return false;
                    };
                    addSaldo(-custoOper);
                    (*pastos[randomIntger]).addTrabalhador(new Operario(custoOper, dia));                   
                    cout << "Trabalhador do tipo Operario foi CONTRATADO e colocado na zona de pasto (" << (*pastos[randomIntger]).getLinha() << ", " << (*pastos[randomIntger]).getColuna() << ")!" << endl;
                    return true;
                }
                else if(args[1] == "len"){
                    if(saldo - custoLen < 0){
                        cout << "Nao tem dinheiro suficiente. Faltam " << -(saldo - custoLen) << " euros!" << endl;
                        return false;
                    };
                    addSaldo(-custoLen);
                    (*pastos[randomIntger]).addTrabalhador(new Lenhador(custoLen, dia));
                    cout << "Trabalhador do tipo Lenhador foi CONTRATADO e colocado na zona de pasto (" << (*pastos[randomIntger]).getLinha() << ", " << (*pastos[randomIntger]).getColuna() << ")!" << endl;
                    return true;
                }
                else if(args[1] == "miner"){
                    if(saldo - custoMiner < 0){
                        cout << "Nao tem dinheiro suficiente. Faltam " << -(saldo - custoMiner) << " euros!" << endl;
                        return false;
                    };
                    (*pastos[randomIntger]).addTrabalhador(new Mineiro(custoMiner, dia));
                    addSaldo(-custoMiner);
                    cout << "Trabalhador do tipo Mineiro foi CONTRATADO e colocado na zona de pasto (" << (*pastos[randomIntger]).getLinha() << ", " << (*pastos[randomIntger]).getColuna() << ")!" << endl;
                    return true;
                }
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
                        cout << "Edificio LIGADO na posicao (" << l << "," << c << ")!" << endl;
                        return true;
                    } else {
                        cout << "[ERRO] Edificio ja esta ligado" << endl;
                        return false;
                    }
                } else { 
                    cout << "[ERRO] Nao existe edificio nessa zona" << endl;
                    return false;
                }
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
            vector<string> cfgArgs;
            while (getline(input_file, line)) {
                istringstream lineFich(line);            
                while (lineFich){
                    string subs;
                    lineFich >> subs;
                    cfgArgs.push_back(subs);
                }
                cfgArgs.pop_back();
                if (cfgArgs[0] == "minaf" && cfgArgs.size() == 2){
                    // Verificações
                    cout << "Preco de compra da Mina de Ferro alterado de " << custoMinaf << " para ";
                    custoMinaf = stoi(cfgArgs[1]);
                    cout << custoMinaf << endl;
                }
                else if (cfgArgs[0] == "minac" && cfgArgs.size() == 2){
                    // Verificações
                    cout << "Preco de compra da Mina de Carvao alterado de " << custoMinac << " para ";
                    custoMinac = stoi(cfgArgs[1]);
                    cout << custoMinac << endl;
                }
                else if (cfgArgs[0] == "bat" && cfgArgs.size() == 2){
                    cout << "Preco de compra da Bateria alterado de " << custoBateria << " para ";
                    custoBateria = stoi(cfgArgs[1]);
                    cout << custoBateria << endl;
                }
                else if (cfgArgs[0] == "fund" && cfgArgs.size() == 2){
                    cout << "Preco de compra da Fundicao alterado de " << custoFundicao << " para ";
                    custoFundicao = stoi(cfgArgs[1]);
                    cout << custoFundicao << endl;
                }
                else if (cfgArgs[0] == "central" && cfgArgs.size() == 2){
                    cout << "Preco de compra da Central alterado de " << custoCentral << " para ";
                    custoCentral = stoi(cfgArgs[1]);
                    cout << custoCentral << endl;
                }
                else if (cfgArgs[0] == "rest" && cfgArgs.size() == 2){
                    cout << "Preco de compra do Restaurante alterado de " << custoCentral << " para ";
                    custoCentral = stoi(cfgArgs[1]);
                    cout << custoCentral << endl;
                }
                else if (cfgArgs[0] == "oper" && cfgArgs.size() == 2){
                    cout << "Preco de contratacao de um Operario alterado de " << custoOper << " para ";
                    custoOper = stoi(cfgArgs[1]);
                    cout << custoOper << endl;
                }
                else if (cfgArgs[0] == "len" && cfgArgs.size() == 2){
                    cout << "Preco de contratacao de uma Lenhador alterado de " << custoLen << " para ";
                    custoLen = stoi(cfgArgs[1]);
                    cout << custoLen << endl;
                }
                else if (cfgArgs[0] == "miner" && cfgArgs.size() == 2){
                    cout << "Preco de contratacao de um Mineiro alterado de " << custoMiner << " para ";
                    custoMiner = stoi(cfgArgs[1]);
                    cout << custoMiner << endl;
                }
                else {
                    cout << "\n[ERRO] Comando " << line << " desconhecido" << endl;
                }
                cfgArgs.clear();
            }
            
            flag = 1;    

            input_file.close();
            cout << "Ficheiro de configuracao " << args[1] << " LIDO!" << endl;
            return true;
        }
    }
    else if (args[0] == "move" && args.size() == 4){
        Zona *zona;
        int linhaX, colunaX;
        string id = "", tipo = "";
        int index;
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                for(unsigned int l = 0; l < zonas[i][j]->getTrabalhadores().size(); l++){
                    if(zonas[i][j]->getTrabalhadores()[l]->getIdTrabalhador() == args[1]){
                        zona = zonas[i][j];
                        id = zonas[i][j]->getTrabalhadores()[l]->getIdTrabalhador();
                        index = l;
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
                if(zona->getTrabalhadores()[index]->getSigla() == "O") tipo = "Operario";
                else if(zona->getTrabalhadores()[index]->getSigla() == "L") tipo = "Lenhador";
                else if(zona->getTrabalhadores()[index]->getSigla() == "M") tipo = "Mineiro";
                
                zonas[linhaX][colunaX]->addTrabalhador(zona->getTrabalhadores()[index]);
                zona->removeTrabalhador(zona->getTrabalhadores()[index]);
                
                cout << "Trabalhador do tipo " << tipo << " com o ID " << id << " foi MOVIDO para a zona (" << linhaX << ", " << colunaX << ")!" << endl;
                return true;
            } else cout << "[ERRO] Coluna invalida" << endl;
        } else cout << "[ERRO] Linha invalida" << endl;
    }
    else if (args[0] == "vende" && args.size() == 3){
        if(args[1] == "ferro" || args[1] == "aco" || args[1] == "carvao" || args[1] == "mad" || args[1] == "viga" || args[1] == "eletr"){       
            if(args[1] == "ferro"){
                if(nrFerro - stoi(args[2]) < 0){
                    cout << "Nao tem Kg suficientes do recurso ferro!\nFaltam " << -(nrFerro - stoi(args[2])) << " Kg." << endl;
                    return false;
                }
                nrFerro = nrFerro - stoi(args[2]);
                cout << "Foram vendidos " << stoi(args[2]) << " Kg de ferro!" << endl;
                addSaldo(stoi(args[2])); //Vendido a 1 euro o Kg.
                return true; 
            }
            else if(args[1] == "aco"){
                if(nrBarraDeAco - stoi(args[2]) < 0){
                    cout << "Nao tem Kg suficientes do recurso Barras de Aco!\nFaltam " << -(nrBarraDeAco - stoi(args[2])) << " Kg." << endl;
                    return false;
                }
                nrBarraDeAco = nrBarraDeAco - stoi(args[2]);
                cout << "Foram vendidos " << stoi(args[2]) << " Kg de Barras de Aco!" << endl;
                addSaldo(2 * stoi(args[2])); //Vendido a 2 euro o Kg.
                return true;                
            }
            else if(args[1] == "carvao"){
                if(nrCarvao - stoi(args[2]) < 0){
                    cout << "Nao tem Kg suficientes do recurso Carvao!\nFaltam " << -(nrCarvao - stoi(args[2])) << " Kg." << endl;
                    return false;
                }
                nrCarvao = nrCarvao - stoi(args[2]);
                cout << "Foram vendidos " << stoi(args[2]) << " Kg de Carvao!" << endl;
                addSaldo(stoi(args[2])); //Vendido a 1 euro o Kg.
                return true;     
            }
            else if(args[1] == "mad"){
                if(nrMadeira - stoi(args[2]) < 0){
                    cout << "Nao tem Kg suficientes do recurso Madeira!\nFaltam " << -(nrMadeira - stoi(args[2])) << " Kg." << endl;
                    return false;
                }
                nrMadeira = nrMadeira - stoi(args[2]);
                cout << "Foram vendidos " << stoi(args[2]) << " Kg de Madeira!" << endl;
                addSaldo(stoi(args[2])); //Vendido a 1 euro o Kg.
                return true;     
            }
            else if(args[1] == "viga"){
                if(nrVigasMadeira - stoi(args[2]) < 0){
                    cout << "Nao tem Kgs suficientes do recurso Vigas de Madeira!\nFaltam " << -(nrVigasMadeira - stoi(args[2])) << " Kg." << endl;
                    return false;
                }
                nrVigasMadeira = nrVigasMadeira - stoi(args[2]);
                cout << "Foram vendidos " << stoi(args[2]) << " Kg de Vigas de Madeira!" << endl;
                addSaldo(2 * stoi(args[2])); //Vendido a 2 euro o Kg.
                return true;     
            }
            else if(args[1] == "eletr"){
                if(nrEletricidade - stoi(args[2]) < 0){
                    cout << "Nao tem KWh suficientes do recurso Eletricidade!\nFaltam " << -(nrEletricidade - stoi(args[2])) << " KWh." << endl;
                    return false;
                }
                nrEletricidade = nrEletricidade - stoi(args[2]);
                cout << "Foram vendidos " << stoi(args[2]) << " KWhs de Eletricidade!" << endl;
                addSaldo(1.5 * stoi(args[2])); //Vendido a 1,5 euro o KWh.
                return true;     
            }
        }
        else{
            // Vender edificio
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
                    if(zonas[linhaX][colunaX]->getEdificio() != nullptr){
                        cout << "Edificio na zona " << "(" << linhaX << "," << colunaX << ") VENDIDO" << endl;
                        addSaldo(zonas[linhaX][colunaX]->getEdificio()->getCusto());
                        zonas[linhaX][colunaX]->removeEdificio();
                        return true;
                    } else cout << "[ERRO] Nao existe um edificio nessa zona" << endl;
                } else cout << "[ERRO] Coluna invalida" << endl;
            } else cout << "[ERRO] Linha invalida" << endl;
            return false;
        }
    }
    else if (args[0] == "debcash" && args.size() == 2){
        // Implementar o resto do comando
        int valor;
        if(isNumber(args[1])) valor = stoi(args[1]);
        else{
            cout << "[ERRO] Introduza um numero valido para o valor" << endl;
            return false;
        }
        if(valor > 0){
            cout << "[DEBUG] ";
            addSaldo(valor);
            return true;
        } else if(valor < 0){
            cout << "[DEBUG] ";
            addSaldo(valor);
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

        if(args[1] == "minaf" || args[1] == "minac" || args[1] == "central" || args[1] == "bat" || args[1] == "fund" || args[1] == "rest"){
            if(linhaX < linhas && linhaX >= 0){
                if(colunaX < colunas && colunaX >= 0){
                    if(zonas[linhaX][colunaX]->getEdificio() == nullptr){
                        cout << "[DEBUG] ";
                        if(args[1] == "minaf")
                            zonas[linhaX][colunaX]->setEdificio(new MinaFerro("minaf", 0));
                        else if(args[1] == "minac")
                            zonas[linhaX][colunaX]->setEdificio(new MinaCarvao("minac", 0));
                        else if(args[1] == "central")
                            zonas[linhaX][colunaX]->setEdificio(new Central("central", 0));
                        else if(args[1] == "bat")
                            zonas[linhaX][colunaX]->setEdificio(new Bateria("bat", 0));
                        else if(args[1] == "fund")
                            zonas[linhaX][colunaX]->setEdificio(new Fundicao("fund", 0));
                        else if(args[1] == "rest")
                            zonas[linhaX][colunaX]->setEdificio(new Restaurante("rest", 0));
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
                for(unsigned int l = 0; l < zonas[i][j]->getTrabalhadores().size(); l++){
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
    else if (args[0] == "next" && args.size() == 1){
        dia++;
        cout << "[Dia " <<  dia << "]" << endl;
        anoitecer();          
        return true;          
    }
    else if (args[0] == "exit" && args.size() == 1){
        cout << "A sair do jogo" << endl;
        exit(0);
    }
    else return false;
    return false;
}

 void Ilha::anoitecer(){
    cout << "Verificar se trabalhador está na sua zona de produção" << endl;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){    
            Zona* zonaAux = zonas[i][j];  
            if(zonaAux->getSigla() == "pas"){ 
                vector<Trabalhador*> oper = zonaAux->getTrabalhadoresBySigla("O"); //Guarda no vetor os operarios dessa zona
                vector<Trabalhador*> len = zonaAux->getTrabalhadoresBySigla("L"); //Guarda no vetor os lenhadores dessa zona
                vector<Trabalhador*> miner = zonaAux->getTrabalhadoresBySigla("M"); //Guarda no vetor os mineiros dessa zona
                if(zonaAux->getSiglaEdificio() == "minaf" && miner.size() > 0){
                   nrFerro += zonaAux->getEdificio()->addArmazenamento(2 + zonaAux->getEdificio()->getNivel()- 1);
                }
                else if(zonaAux->getSiglaEdificio() == "minac" && miner.size() > 0){
                    nrFerro += zonaAux->getEdificio()->addArmazenamento(2 + zonaAux->getEdificio()->getNivel()- 1);
                }
                else if(zonaAux->getSiglaEdificio() == "central" && oper.size() > 0){
                    // Obter o armazenamento das zonas diretamente ao lado da zonaAux
                    Zona* zonaAux2 = zonas[i-1][j];
                    Zona* zonaAux3 = zonas[i+1][j];
                    Zona* zonaAux4 = zonas[i][j-1];
                    Zona* zonaAux5 = zonas[i][j+1];
                    if(zonaAux2 != nullptr){
                        if(zonaAux2->getSiglaEdificio() == "minaf" && miner.size() > 0){
                            nrFerro += zonaAux2->getEdificio()->addArmazenamento(2 + zonaAux2->getEdificio()->getNivel()- 1);
                        }
                        else if(zonaAux2->getSiglaEdificio() == "minac" && miner.size() > 0){
                            nrFerro += zonaAux2->getEdificio()->addArmazenamento(2 + zonaAux2->getEdificio()->getNivel()- 1);
                        }
                    }
                    if(zonaAux3 != nullptr){
                        if(zonaAux3->getSiglaEdificio() == "minaf" && miner.size() > 0){
                            nrFerro += zonaAux3->getEdificio()->addArmazenamento(2 + zonaAux3->getEdificio()->getNivel()- 1);
                        }
                        else if(zonaAux3->getSiglaEdificio() == "minac" && miner.size() > 0){
                            nrFerro += zonaAux3->getEdificio()->addArmazenamento(2 + zonaAux3->getEdificio()->getNivel()- 1);
                        }
                    }
                    if(zonaAux4 != nullptr){
                        if(zonaAux4->getSiglaEdificio() == "minaf" && miner.size() > 0){
                            nrFerro += zonaAux4->getEdificio()->addArmazenamento(2 + zonaAux4->getEdificio()->getNivel()- 1);
                        }
                        else if(zonaAux4->getSiglaEdificio() == "minac" && miner.size() > 0){
                            nrFerro += zonaAux4->getEdificio()->addArmazenamento(2 + zonaAux4->getEdificio()->getNivel()- 1);
                        }
                    }
                    if(zonaAux5 != nullptr){
                        if(zonaAux5->getSiglaEdificio() == "minaf" && miner.size() > 0){
                            nrFerro += zonaAux5->getEdificio()->addArmazenamento(2 + zonaAux5->getEdificio()->getNivel()- 1);
                        }
                        else if(zonaAux5->getSiglaEdificio() == "minac" && miner.size() > 0){
                            nrFerro += zonaAux5->getEdificio()->addArmazenamento(2 + zonaAux5->getEdificio()->getNivel()- 1);
                        }
                    }
                    //carvaoAux = zonaAux->getEdificio()->addArmazenamento(2 + zonas[i][j]->getEdificio()->getNivel()- 1);
                    //eletricidadeAux = zonaAux->getEdificio()->addArmazenamento(1);        
                    // if(zonas[i-1][j]->getSiglaEdificio() == "bat") eletricidadeAux += zonaAux->getEdificio()->getArmazenamento();
                    // else if(zonas[i][j-1]->getSiglaEdificio() == "bat") eletricidadeAux += zonaAux->getEdificio()->getArmazenamento();
                    // else if(zonas[i+1][j]->getSiglaEdificio() == "bat") eletricidadeAux += zonaAux->getEdificio()->getArmazenamento();
                    // else if(zonas[i][j+1]->getSiglaEdificio() == "bat") eletricidadeAux += zonaAux->getEdificio()->getArmazenamento();                      
                }  
            }           
        }
    }
};

