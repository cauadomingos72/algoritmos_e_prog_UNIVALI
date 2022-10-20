///Membros: Cauã Domingos, Paulo Hermans e Vinicius Ribeiro.
#include <iostream>
#include <string>
#include <cstdio>
#include <bits/stdc++.h>
#include "windows.h"
#include "Agenda.hpp"

#define TAM 100

using namespace std;

ostream& operator<<(ostream &out, const Pessoal &p) ///Sobrecarga do operador <<, mostrando as variáveis internas da struct na função cout.
{
    out<<"ID: "<<p.ID<<endl;
    out<<"Nome: "<<p.nome<<endl;
    out<<"CPF: "<<p.CPF<<endl;
    out<<"Celular: "<<p.celular<<endl;

    return out;
}

ostream& operator<<(ostream &out, const Comercial &p) ///Sobrecarga do operador <<, mostrando as variáveis internas da struct na função cout.
{
    out<<"ID: "<<p.ID<<endl;
    out<<"Nome: "<<p.nome<<endl;
    out<<"CNPJ: "<<p.CNPJ<<endl;
    out<<"Telefone: "<<p.telefone<<endl;

    return out;
}

int menu() ///Função de exibição e seleção de opções.
{
    int op;
    do
    {
        system("cls");
        cout<<"1. inserir um novo item na agenda"<<endl;
        cout<<"2. remover um item da agenda (pelo ID)"<<endl;
        cout<<"3. pesquisar um item na agenda (por ID)"<<endl;
        cout<<"4. ordenar todos os itens "<<endl;
        cout<<"5. mostrar todos os itens "<<endl;
        cout<<"6. encerrar o programa"<<endl;
        fflush(stdin);
        cin>>op;
        system("cls");
    } while (op < 1 || op > 7);

    system("cls");
    return op;
}

bool verificaNome(string nome) ///Função que verifica se um nome inserido pelo usuário contém apanas letras e espaços.
{
    const int tamanhoString = nome.length(); ///Constante que contém o tamanho da string.

    for (int i=0; i<tamanhoString; i++){
        if (!((nome[i]  >= 97 && nome[i] <= 122) || (nome[i]  >= 65 && nome[i] <= 90) || nome[i] == 32)) ///Lógica baseada em ASCII para comparação dos valores dos caracteres.
            return false;
    }

    return true;
}

void registra_dados_pessoais(const char *frase, Pessoal &dados) ///Função para preenchimento de dados de uma variável do tipo struct pessoal.
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
    } while(!verificaNome(dados.nome)); ///Chamada da função de verificação de caracteres.
    cout<<endl;

    cout<<"CPF: ";
    fflush(stdin);
    cin>>dados.CPF;
    cout<<endl;

    cout<<"Celular: ";
    fflush(stdin);
    cin>>dados.celular;
}

void registra_dados_comerciais(const char *frase, Comercial &dados) ///Função para preenchimento de dados de uma variável do tipo struct comercial.
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
    } while(!verificaNome(dados.nome)); ///Chamada da função de verificação de caracteres.
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
int procura_dados(const char *frase, const Agenda<T,MAX> &ag) ///Função de procura de dados baseada em igualdade de ID.
{
    int ID_produrado;
    cout<<frase<<endl;
    fflush(stdin);
    cin>>ID_produrado;

    for (int i=0; i<MAX; i++)
    {
        if (ag.itens[i].ID == ID_produrado)
            return i;                         ///Retorna a posição de um dado semelhante encontrado.
    }

    return -1;                             ///Retorno caso um dado semelhante não seja encontrado.
}

void selecao(int &opcao)           ///Função de seleção entre tipos de agendas.
{
    cout<<"1 - Pessoal"<<endl;
    cout<<"2 - Comercial"<<endl;
    fflush(stdin);
    cin>>opcao;
}

void selecao2(int &opcao, int posicao) ///Função de verificação de resultados de procura de dados.
{
    if (posicao < 0){
        cout<<"Dado nao encontrado"<<endl;
        cout<<"Tentar novamente? (1 = sim ou qualquer numero = nao)"<<endl;
    }else{
        cout<<"Dado encontrado"<<endl;
        cout<<"Procurar novamente? (1 = sim ou qualquer numero = nao)"<<endl;
    }
        fflush(stdin);
        cin>>opcao;
}

template <typename TIPO>
void bubblesort(Agenda<TIPO,TAM> &ag) ///Função de ordenação por nome.
{
    int i, j, cond = 1;
    TIPO temp;

    for (i=ag.quantidade-1; (i >= 1) && (cond == 1); i--) {
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
void printItens(Agenda<TIPO,TAM> &ag) ///Função que imprime, de forma ordenada, os dados de uma agenda na tela.
{
    bubblesort(ag);
    for (int i=0; i<ag.quantidade; i++){
        cout<<ag.itens[i]<<endl;
    }
    system("pause");
}

template <typename TIPO>
void printItens2(Agenda<TIPO,TAM> &ag) ///Função que imprime os dados de uma agenda na tela.
{
    for (int i=0; i<ag.quantidade; i++){
        cout<<ag.itens[i]<<endl;
    }
    system("pause");
}

int main()
{
    Agenda<Pessoal,TAM> agp;
    inicializa_agenda(agp); ///Inicializa a agenda pessoal com seu determinado tamanho.
    Agenda<Comercial,TAM> agc;
    inicializa_agenda(agc); ///Inicializa a agenda comercial com seu determinado tamanho.
    Pessoal pessoa;
    Comercial comercio;

    int op;
    do
    {
        op = menu(); ///Chamada da função menu e atribuição de valor à variável op, que servirá para seleção de todas as opções.
        int opcao, posicao;
        switch (op) ///De acordo com o valor atribuído na função menu, irá executar uma atividade determinada para tal valor.
        {
            case 1: ///Insere um novo item na agenda.
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

            case 2: ///Remove um item da agenda.
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

            case 3: ///Procura um item da agenda.
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

            case 4: ///Ordena os itens da agenda.
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

            case 5: ///Exibe os itens da agenda.
                selecao(opcao);


                if (opcao==1)
                {
                    printItens2(agp);
                }
                if (opcao==2)
                {
                    printItens2(agc);
                }
            break;

        }
    } while (op != 6); ///Caso o valor atribuído no menu seja 6, o programa é encerrado.

    return 0;
}
