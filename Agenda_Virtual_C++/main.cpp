#include <iostream>
#include <string>
#include <cstdio>
#include <locale.h>
#include "windows.h"
#include <cmath>
#include "Agenda.hpp"


using namespace std;

ostream& operator<<(ostream &out, const Pessoal &p)
{
    out<<p.ID<<endl;
    out<<p.nome<<endl;
    out<<p.CPF<<endl;
    out<<p.celular<<endl;

    return out;
}

ostream& operator<<(ostream &out, const Comercial &p)
{
    out<<p.ID<<endl;
    out<<p.nome<<endl;
    out<<p.CNPJ<<endl;
    out<<p.telefone<<endl;

    return out;
}

int menu()
{
    int op;
    do {
        cout<<"1. inserir um novo item na agenda"<<endl;
        cout<<"2. remover um item da agenda"<<endl;
        cout<<"3. pesquisar um item na agenda"<<endl;
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
void procura_dados_pessoal(const char *frase, const Agenda<T,MAX> &ag)
{
    string p;

    cout<<frase<<endl;
    cin>>p;
    fflush(stdin);
    for (int i=0; i<MAX; i++)
    {
        if(ag.itens[i].ID == p || ag.itens[i].nome == p)
            cout<<ag.itens[i].ID<<" - "<<ag.itens[i].nome<<" - "<<ag.itens[i].CPF<<" - "<<ag.itens[i].celular;
    }


}

template <typename T, int MAX>
void procura_dados_comercial(const char *frase, const Agenda<T,MAX> &ag)
{
    string p;
    cout<<frase<<endl;
    cin>>p;
    for (int i=0; i<MAX; i++)
    {
        if(ag.itens[i].ID == p || ag.itens[i].nome == p || ag.itens[i].CNPJ == p || ag.itens[i].telefone == p)
            cout<<ag.itens[i].ID<<" - "<<ag.itens[i].nome<<" - "<<ag.itens[i].CNPJ<<" - "<<ag.itens[i].telefone;
    }
}



int main()
{
    setlocale(LC_ALL,"Portuguese");
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
                cout<<"1 - Pessoal"<<endl;
                cout<<"2 - Comercial"<<endl;
                cin>>opcao;

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
            break;

            case 3:
                int op;
                do
                {
                    cout<<"Escolha uma opcao de identificacao:"<<endl;
                    cout<<"1 - Pessoal"<<endl;
                    cout<<"2 - Comercial"<<endl;
                    cin>>op;
                    fflush(stdin);

                    if(op==1)
                        procura_dados_pessoal("Escreva o que você deseja buscar.", agp);
                    if(op==2)
                        procura_dados_comercial("Escreva o que você deseja buscar.", agc);
                } while (op < 1 || op > 2);

            break;

            case 4:
            break;

            case 5:
            break;
        }
    } while (op != 6);

    return 0;
}
