// ISEC - Trabalho Prático de POO 2021/2022
// Tomás Gomes Silva - 2020143845
// Tomás da Cunha Pinto - 2020144067

#ifndef ENGINE
#define ENGINE

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class Ilha {
    private:

    // A ILHA VAI TER ZONAS, RECURSOS e TRABALHADORES, os TRABALHADORES vão ter TIPOS (MINEIRO, LENHADOR, OPERÁRIO).

};


class Zona : public Ilha{

    private:
        string zona;
        string edificio;
        string trabalhadores;
        int nrTrabalhadores;
        int linha, coluna;
    public:
        void setLinha(int l);
        void setColuna(int c);
        string getZona() const;
        void setZona(string z);
        string getEdificio() const;
        string getTrabalhadores() const;
        string getInfo() const;
        void setNrTrabalhadores(int n);
        int getNrTrabalhadores() const;
        void cons(string tipo, int linhaX, int colunaX);
        void cont(string tipo);
};

class Recursos : public Ilha{
    private:

};
class Ferro : public Recursos{
    private:
};
class BarraAco : public Recursos{
    private:
};
class Carvao : public Recursos{
    private:
};
class Madeira : public Recursos{
    private:
};
class VigasMadeira : public Recursos{
    private:
};
class Eletricidade : public Recursos{
    private:
};

class Edificios : public Zona{
    private:

};

class MinaFerro : public Edificios{
    private:
};
class MinaCarvao : public Edificios{
    private:
};
class CentralEletrica : public Edificios{
    private:
};
class Bateria : public Edificios{
    private:
};
class Fundicao : public Edificios{
    private:
};
class EdificioX : public Edificios{
    private:
};

class Trabalhador : public Zona{
    private:
        int cost;    
        int tired;   //Gerar um nr random de 0 a 99, criar uma condição "if(cancaço < 5)" --> Tem 5% de probabilidade de se cansar e demitir-se.   
    public:          //Ou usar um bool na variavel cansaço e verificar se o trabalhador se demitiu ou não.
    Trabalhador(int custo, int cansaco) : cost(custo), tired(cansaco){}
        int getcusto() {return cost; }
        int getcansaco() {return tired; }
};

class Mineiro : public Trabalhador{
    private:
             
    public:          
        Mineiro(int custo, int cansaco): Trabalhador(custo, cansaco){
        //Mineiro x(10, 20);
        //cout << "\nA contratacaoo do Mineiro custou " << x.getcusto() << "Cansaco: " << x.getcansaco() << endl;

        }        
    //Criar Verificações --> Apenas pode ser contratado para os Edificios "Mina de ferro" e "Mina de carvão". 

};
class Lenhador : public Trabalhador{
    private:
    //Criar Verificações --> Apenas pode ser contratado para a zona "Floresta".

};
class Operario : public Trabalhador{
    private:
    //Criar Verificações --> Apenas pode ser contratado para os Edificios "Central Elétrica" e "Fundição".

};

void menu(int &linhas, int &colunas);

void initIlha(Zona **matriz, int linhasTab, int colunasTab);

void mostraIlha(Zona **matriz, int linhas, int colunas);

void mostraInfoTotal(Zona **matriz, int linhasTab, int colunasTab);

void mostraASCII();

bool isNumber(string s);

bool validaComando(Zona **matriz, istringstream &iss, int linhasTab, int colunasTab);

#endif //ENGINE