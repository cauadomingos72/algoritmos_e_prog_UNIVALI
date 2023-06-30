#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>     
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
  int op, prioridade;
  string expressao;
  TArv arvore = {};
  
  do
  {
    menu(op);
    switch(op)
    {
      case 1:
        system("clear");
        fflush(stdin);
        prioridade = 1;
        cout<<"Digite uma expressão:"<<endl;
        cin>>expressao;
        fflush(stdin);
        MontaArvore(&arvore, prioridade, expressao);
        system("clear");
      break;
      case 2:
        system("clear");
        imprimir(arvore.raiz);
      break;
      case 3:
        imprimirResultado(&arvore);
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
