#include <iostream>
#include <string>
#include <cstdio>
#include "windows.h"
#include <cmath>

using namespace std;

struct Pessoal
{
    string ID;
    string CPF;
    string nome;
    string celular;
};

struct Comercial
{
    string ID;
    string CNPJ;
    string nome;
    string telefone;
};

template <typename TIPO, int MAX>
struct Agenda 
{
    TIPO itens[MAX];
    int quantidade;
};

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

template <typename TIPO, int MAX>
bool inicializa_agenda(Agenda <TIPO,MAX> &ag) 
{
    ag.quantidade = 0;
    return true;
}

template <typename TIPO, int MAX>
bool insere(Agenda <TIPO,MAX> &ag, TIPO dado)
{
    //ag.itens[posicao] = dado;
}

template <typename TIPO, int MAX>
bool remova(Agenda <TIPO,MAX> &ag, TIPO dado)
{

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

int main()
{
    int op;
    do {
        op = menu();

        switch (op){
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;
        }
    } while (op != 6);

    return 0;
}
