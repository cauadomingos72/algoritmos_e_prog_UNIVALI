#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

using namespace std;

void menu(int op)
{
  system("clear");
  fflush(stdin);
  cout<<"\n\t\tLoja de Música\n\n";
  cout<<"1 - Cadastro"<<endl; //Cadastra: Clientes/Funcionários e Produtos
  cout<<"2 - Remover"<<endl; //Remove: Clientes/Funcionários e Produtos
  cout<<"3 - Exibir"<<endl; //Exibe: Clientes/Funcionários e Produtos
  cout<<"4 - Pesquisar"<<endl; //Pesquisa: Clientes/Funcionários e Produtos
  cout<<"5 - Serviços"<<endl; //Lista os serviços e atribui um contrato para um cliente
  cin>>op;  
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int op;

  do
  {
    menu(op);
  } 
  while(1);
  
}
