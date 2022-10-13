#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

struct Pessoal
{
    string ID;
    string CPF;
    string nome;
    string celular;
};

bool operator==(const Pessoal &p1, const Pessoal &p2)
{
    if (p1.ID != p2.ID || p1.CPF != p2.CPF || p1.nome != p2.nome || p1.celular != p2.celular)
        return false;
    return true;
}

bool operator!=(const Pessoal &p1, const Pessoal &p2)
{
    return !(p1 == p2);
}

struct Comercial
{
    string ID;
    string CNPJ;
    string nome;
    string telefone;
};

bool operator==(const Comercial &p1, const Comercial &p2)
{
    if (p1.ID != p2.ID || p1.CNPJ != p2.CNPJ || p1.nome != p2.nome || p1.telefone != p2.telefone)
        return false;
    return true;
}

bool operator!=(const Comercial &p1, const Comercial &p2)
{
    return !(p1 == p2);
}

template <typename TIPO, int MAX>
struct Agenda
{
    TIPO itens[MAX];
    int quantidade;
};

template <typename TIPO, int MAX>
bool inicializa_agenda(Agenda <TIPO,MAX> &ag)
{
    ag.quantidade = 0;
    return true;
}

template <typename TIPO, int MAX>
bool insere(Agenda <TIPO,MAX> &ag, TIPO dado)
{
    if (ag.quantidade < MAX){
        ag.itens[ag.quantidade++] = dado;
        return true;
    }

    return false;
}

template <typename TIPO, int MAX>
bool remova(Agenda <TIPO,MAX> &ag, TIPO dado)
{
    bool deletado = false;
    TIPO dadoVazio;
    for (int i=0; i<MAX; i++){
        if (ag.itens[i] == dado){
            for (int j=i; j<MAX-1; j++){
                ag.itens[j] = ag.itens[j+1];
                ag.itens[j+1] = dadoVazio;
            }
           
            deletado = true;
            ag.quantidade--;
        }
    }

    return deletado;
}

///Codigo que converte um objeto string e retorna um long long int (porque botei o cpf, celular... em forma de string)
long long int convercao(string objeto)
{
    int length = objeto.length();
    int *numeroPtr = new int[length];
    int k = 0;
   
    for (int i=0; i<length; i++){
        if (isdigit(objeto[i])){
            numeroPtr[k] = (objeto[i] - '0');
            k++;
        }
    }

    long long int numero = 0;
    for (int i=0; i<k; i++){
        numero += numeroPtr[i]*(pow(10, k - 1 - i));
    }

    return numero;
}
///Codigo que converte um objeto string e retorna um long long int
