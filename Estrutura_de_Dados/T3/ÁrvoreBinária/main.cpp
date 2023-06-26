#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ArvBin.h"

using namespace std;

void menu(int &op)
{
  cout<<endl;
  cout<<endl;
  fflush(stdin);
  cout<<"\t\tÁRVORE BINÁRIA DE BUSCA"<<endl;
  cout<<"-----------------------------------------"<<endl;
  cout<<"1 - Inserir"<<endl;
  cout<<"2 - Remover"<<endl;
  cout<<"3 - Pesquisar"<<endl;
  cout<<"4 - Imprimir"<<endl;
  cout<<"5 - Tamanho Total da Árvore"<<endl;
  cout<<"6 - Encerrar"<<endl;
  cout<<"-----------------------------------------"<<endl;
  cin>>op;
}

int main() 
{
  int op, item=0, valor=0;
  TArv<int> arvore = {};
  
  do
  {
    menu(op);
    switch(op)
    {
      case 1:
        system("clear");
        fflush(stdin);
        cout<<"Digite uma chave:"<<endl;
        cin>>valor;
        fflush(stdin);
        cout<<"Digite um valor:"<<endl;
        cin>>item;
        inserir(&arvore, valor, item);
        system("clear");
      break;
      case 2:
      break;
      case 3:
        system("clear");
        cout<<"Qual chave você deseja buscar?"<<endl;
        cin>>valor;
        busca(&arvore, valor);
      break;
      case 4:
        system("clear");
        imprimir(arvore.raiz);
      break;
      case 5:
        cout<<"Tamanho Total: "<<arvore.tamanho<<endl;
      break;
      case 6:
      break;
      default:
        cout<<"Opção Inválida";
    }
  } while(op != 6);
}
