#include <iostream>
#include <string>
#include <cstdio>
#include "windows.h"
#include "Agenda.hpp"

using namespace std;

ostream& operator<<(ostream &out, const Pessoal &p)
{
    out<<"ID: "<<p.ID<<endl;
    out<<"Nome: "<<p.nome<<endl;
    out<<"CPF: "<<p.CPF<<endl;
    out<<"Celular: "<<p.celular<<endl;

    return out;
}

ostream& operator<<(ostream &out, const Comercial &p)
{
    out<<"ID: "<<p.ID<<endl;
    out<<"Nome: "<<p.nome<<endl;
    out<<"CNPJ: "<<p.CNPJ<<endl;
    out<<"Telefone: "<<p.telefone<<endl;

    return out;
}

int menu()
{
    int op;
    do {
        cout<<"1. inserir um novo item na agenda (sempre no final)"<<endl;
        cout<<"2. remover um item da agenda (pelo ID ou nome)"<<endl;
        cout<<"3. pesquisar um item na agenda (por ID ou nome)"<<endl;
        cout<<"4. ordenar a agenda por nome"<<endl;
        cout<<"5. mostrar todos os itens "<<endl;
        cout<<"6. encerrar o programa"<<endl;
        fflush(stdin);
        cin>>op;
        system("cls");
    } while (op < 1 || op > 6);

    system("cls");
    return op;
}

void registra_dados_pessoais(const char *frase, Pessoal &dados)
{
    cout<<frase<<endl;
    cin>>dados.ID>>dados.nome>>dados.CPF>>dados.celular;
}

void registra_dados_comerciais(const char *frase, Comercial &dados)
{
    cout<<frase<<endl;
    cin>>dados.ID>>dados.nome>>dados.CNPJ>>dados.telefone;
}

template <typename T, int MAX>
int procura_dados(const char *frase, const Agenda<T,MAX> &ag)
{
    int ID_produrado;
    cout<<frase<<endl;
    cin>>ID_produrado;

    for (int i=0; i<MAX; i++){
        if (ag.itens[i].ID == ID_produrado)
            return i;
    }
    
    return -1;
}

void selecao(int &opcao) {
    cout<<"1 - Pessoal"<<endl;
    cout<<"2 - Comercial"<<endl;
    cin>>opcao;
}

void selecao2(int &opcao, int posicao) {
    if (posicao >= 0){
        cout<<"Dado nao encontrado"<<endl;
        cout<<"Tentar novamente? (1 = sim ou qualquer numero = nao)"<<endl;
        cin>>opcao;
    }
}

int main()
{   
    Agenda<Pessoal,100> agp;
    Agenda<Comercial,100> agc;
    Pessoal pessoa;
    Comercial comercio;

    int op;
    do {
        op = menu();

        switch (op){
            case 1:
                int opcao;
                selecao(opcao);
                if (opcao == 1){
                    registra_dados_pessoais("Insira seu ID, nome, CPF e numero de celular respectivamente.", pessoa);
                    insere(agp, pessoa);
                }
                else{
                    registra_dados_comerciais("Insira seu ID, nome, CNPJ e numero de telefone respectivamente.", comercio);
                    insere(agc, comercio);
                }
            break;

            case 2:
                int opcao, posicao;
                do {
                    selecao(opcao);
                    
                    if (opcao == 1){
                        posicao = procura_dados("Insira o dado que deseja remover da agenda pessoal (ID):", agp);
                        if (posicao >= 0)
                            remova(agp, agp.itens[posicao])
                    }
                    if (opcao == 2){
                        posicao = procura_dados("Insira o dado que deseja remover da agenda comercial (ID):", agc);
                        if (posicao >= 0)
                            remova(agc, agc.itens[posicao])
                    }
                    selecao2(opcao, posicao);
                } while (opcao == 1);
            break;

            case 3:
                int opcao, posicao;
                do {
                    selecao(opcao);
                    
                    if (opcao == 1){
                        posicao = procura_dados("Insira o dado que deseja procurar na agenda pessoal:", agp);
                        if (posicao >= 0)
                            cout<<agp.itens[posicao]<<endl;
                    }
                    if (opcao == 2){
                        posicao = procura_dados("Insira o dado que deseja procurar na agenda comercial:", agc);
                        if (posicao >= 0)
                            cout<<agc.itens[posicao]<<endl;
                    }
                    selecao2(opcao, posicao);
                } while (opcao == 1);
            break;

            case 4:
            break;

            case 5:
            break;
        }
    } while (op != 6);

    return 0;
}
