#include <iostream>
#include <string>
#include <cstdio>
#include<bits/stdc++.h>
#include "windows.h"
#include "Agenda.hpp"

#define TAM 100

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
    do
    {
        cout<<"1. inserir um novo item na agenda"<<endl;
        cout<<"2. remover um item da agenda (pelo ID ou nome)"<<endl;
        cout<<"3. pesquisar um item na agenda (por ID ou nome)"<<endl;
        cout<<"4. mostrar todos os itens "<<endl;
        cout<<"5. encerrar o programa"<<endl;
        fflush(stdin);
        cin>>op;
        system("cls");
    } while (op < 1 || op > 6);

    system("cls");
    return op;
}

bool verificaNome(string nome)
{
    const int tamanhoString = nome.length();

    for (int i=0; i<tamanhoString; i++){
        if (!((nome[i]  >= 97 && nome[i] <= 122) || (nome[i]  >= 65 && nome[i] <= 90) || nome[i] == 32))
            return false;
    }

    return true;
}

void registra_dados_pessoais(const char *frase, Pessoal &dados)
{
    cout<<frase<<endl;

    cout<<"ID: ";
    fflush(stdin);
    cin>>dados.ID;
    cout<<endl;

    do {
        cout<<"Nome: ";
        fflush(stdin);
        getline(cin, dados.nome);
    } while(!verificaNome(dados.nome));
    cout<<endl;

    cout<<"CPF: ";
    fflush(stdin);
    cin>>dados.CPF;
    cout<<endl;

    cout<<"Celular: ";
    fflush(stdin);
    cin>>dados.celular;
}

void registra_dados_comerciais(const char *frase, Comercial &dados)
{
    cout<<frase<<endl;

    cout<<"ID: ";
    fflush(stdin);
    cin>>dados.ID;
    cout<<endl;

    do {
        cout<<"Nome: ";
        fflush(stdin);
        getline(cin, dados.nome);
    } while(!verificaNome(dados.nome));
    cout<<endl;

    cout<<"CNPJ: ";
    fflush(stdin);
    cin>>dados.CNPJ;
    cout<<endl;

    cout<<"Telefone: ";
    fflush(stdin);
    cin>>dados.telefone;
}

template <typename T, int MAX>
int procura_dados(const char *frase, const Agenda<T,MAX> &ag)
{
    int ID_produrado;
    cout<<frase<<endl;
    fflush(stdin);
    cin>>ID_produrado;

    for (int i=0; i<MAX; i++)
    {
        if (ag.itens[i].ID == ID_produrado)
            return i;
    }

    return -1;
}

void selecao(int &opcao) {
    cout<<"1 - Pessoal"<<endl;
    cout<<"2 - Comercial"<<endl;
    fflush(stdin);
    cin>>opcao;
}

void selecao2(int &opcao, int posicao) {
    if (posicao < 0){
        cout<<"Dado nao encontrado"<<endl;
    }
        cout<<"Tentar novamente? (1 = sim ou qualquer numero = nao)"<<endl;
        fflush(stdin);
        cin>>opcao;
}

template <typename TIPO>
void bubblesort(Agenda<TIPO,TAM> &ag)
{
    int i, j, cond = 1;
    TIPO temp;

    for (i=TAM-1; (i >= 1) && (cond == 1); i--) {
        cond = 0;
        for (j=0; j < i ;j++) {
            if (ag.itens[j+1] < ag.itens[j]) {
                temp = ag.itens[j];
                ag.itens[j] = ag.itens[j+1];
                ag.itens[j+1] = temp;
                cond = 1;
            }
        }
    }
}

template <typename TIPO>
void printItens(Agenda<TIPO,TAM> &ag)
{
    bubblesort(ag);
    for (int i=0; i<ag.quantidade; i++){
        cout<<ag.itens[i]<<endl;
    }

}

int main()
{
    Agenda<Pessoal,TAM> agp;
    inicializa_agenda(agp);
    Agenda<Comercial,TAM> agc;
    inicializa_agenda(agc);
    Pessoal pessoa;
    Comercial comercio;

    int op;
    do
    {
        op = menu();
        int opcao, posicao;
        switch (op)
        {
            case 1:
                selecao(opcao);
                if (opcao == 1)
                {
                    registra_dados_pessoais("Insira seu ID, nome, CPF e numero de celular respectivamente.", pessoa);
                    insere(agp, pessoa);
                }
                else
                {
                    registra_dados_comerciais("Insira seu ID, nome, CNPJ e numero de telefone respectivamente.", comercio);
                    insere(agc, comercio);
                }
            break;

            case 2:
                do
                {
                    selecao(opcao);

                    if (opcao == 1)
                    {
                        posicao = procura_dados("Insira o dado que deseja remover da agenda pessoal (ID):", agp);
                        if (posicao >= 0)
                            remova(agp, agp.itens[posicao]);
                    }
                    if (opcao == 2)
                    {
                        posicao = procura_dados("Insira o dado que deseja remover da agenda comercial (ID):", agc);
                        if (posicao >= 0)
                            remova(agc, agc.itens[posicao]);
                    }
                    selecao2(opcao, posicao);
                } while (opcao == 1);
            break;

            case 3:
                do
                {
                    selecao(opcao);

                    if (opcao == 1)
                    {
                        posicao = procura_dados("Insira o dado que deseja procurar na agenda pessoal:", agp);
                        if (posicao >= 0)
                            cout<<agp.itens[posicao]<<endl;
                    }
                    if (opcao == 2)
                    {
                        posicao = procura_dados("Insira o dado que deseja procurar na agenda comercial:", agc);
                        if (posicao >= 0)
                            cout<<agc.itens[posicao]<<endl;
                    }
                    selecao2(opcao, posicao);
                } while (opcao == 1);
            break;

            case 4:
                selecao(opcao);


                if (opcao==1)
                {
                    printItens(agp);
                }
                if (opcao==2)
                {
                    printItens(agc);
                }
            break;

        }
    } while (op != 5);

    return 0;
}
