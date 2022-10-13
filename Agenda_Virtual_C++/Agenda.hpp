#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

struct Pessoal
{
    int ID;
    long long int CPF;
    string nome;
    long long int  celular;
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
    int  ID;
    long long int  CNPJ;
    string nome;
    long long int  telefone;
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
