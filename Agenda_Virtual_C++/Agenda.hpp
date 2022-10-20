///Membros: Cauã Domingos, Paulo Hermans e Vinicius Ribeiro.
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

struct Pessoal ///Struct contendo dados para agenda pessoal.
{
    int ID;
    long long int CPF;
    string nome;
    long long int  celular;
};

bool operator<(const Pessoal &p1, const Pessoal &p2) ///Sobrecarga para comparação de strings da agenda pessoal (p1 menor que p2).
{
    return p1.nome < p2.nome;
}

bool operator>(const Pessoal &p1, const Pessoal &p2) ///Sobrecarga para comparação de strings da agenda pessoal (p1 maior que p2).
{
    return p1.nome > p2.nome;
}

bool operator==(const Pessoal &p1, const Pessoal &p2) ///Sobrecarga para verificação de igualdade entre os dados da agenda pessoal.
{
    if (p1.ID != p2.ID || p1.CPF != p2.CPF || p1.nome != p2.nome || p1.celular != p2.celular)
        return false;
    return true;
}

bool operator!=(const Pessoal &p1, const Pessoal &p2) ///Sobrecarga para verificação de diferença entre os dados da agenda pessoal.
{
    return !(p1 == p2);
}

struct Comercial ///Struct contendo dados para agenda comercial.
{
    int  ID;
    long long int  CNPJ;
    string nome;
    long long int  telefone;
};

bool operator<(const Comercial &c1, const Comercial &c2) ///Sobrecarga para comparação de strings da agenda comercial (c1 menor que c2).
{
    return c1.nome < c2.nome;
}

bool operator>(const Comercial &c1, const Comercial &c2) ///Sobrecarga para comparação de strings da agenda comercial (c1 maior que c2).
{
    return c1.nome > c2.nome;
}

bool operator==(const Comercial &p1, const Comercial &p2) ///Sobrecarga para verificação de igualdade entre os dados da agenda comercial.
{
    if (p1.ID != p2.ID || p1.CNPJ != p2.CNPJ || p1.nome != p2.nome || p1.telefone != p2.telefone)
        return false;
    return true;
}

bool operator!=(const Comercial &p1, const Comercial &p2) ///Sobrecarga para verificação de diferença entre os dados da agenda comercial.
{
    return !(p1 == p2);
}

template <typename TIPO, int MAX>
struct Agenda                     ///Determina a quantidade de itens e o tipo de uma agenda.
{
    TIPO itens[MAX];
    int quantidade;
};

template <typename TIPO, int MAX>
bool inicializa_agenda(Agenda <TIPO,MAX> &ag) ///Inicializa a variável de espaço ocupado em uma agenda.
{
    ag.quantidade = 0;
    return true;
}

template <typename TIPO, int MAX>
bool insere(Agenda <TIPO,MAX> &ag, TIPO dado) ///Verifica capacidade total da agenda e insere um novo dado.
{
    if (ag.quantidade < MAX){
        ag.itens[ag.quantidade++] = dado;
        return true;
    }

    return false;
}

template <typename TIPO, int MAX>
bool remova(Agenda <TIPO,MAX> &ag, TIPO dado) ///Remove um dado de uma agenda e libera um espaço.
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
