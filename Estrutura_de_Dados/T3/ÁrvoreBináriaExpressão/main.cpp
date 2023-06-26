#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ArvBinExp.h"

using namespace std;

void menu(int &op)
{
  cout<<endl;
  cout<<endl;
  fflush(stdin);
  cout<<"\t\tÁRVORE BINÁRIA DE EXPRESSÃO"<<endl;
  cout<<"-----------------------------------------"<<endl;
  cout<<"1 - Inserir Expressão"<<endl;
  cout<<"2 - Exibir Expressão"<<endl;
  cout<<"3 - Exibir Resultado"<<endl;
  cout<<"4 - Exibir em Forma de Grafo"<<endl;
  cout<<"5 - Encerrar"<<endl;
  cout<<"-----------------------------------------"<<endl;
  cin>>op;
}

int main() 
{
  int op, prioridade=0;
  string expressao;
  TArv<string> arvore = {};
  
  do
  {
    menu(op);
    switch(op)
    {
      case 1:
        system("clear");
        fflush(stdin);
        cout<<"Digite uma expressão:"<<endl;
        cin>>expressao;
        fflush(stdin);
        inserir(&arvore, valor, item);
        system("clear");
      break;
      case 2:
        system("clear");
        imprimir(arvore.raiz);
      break;
      case 3:
      break;
      case 4:
      break;
      case 5:
      break;
      default:
        cout<<"Opção Inválida";
    }
  } while(op != 6);
}
