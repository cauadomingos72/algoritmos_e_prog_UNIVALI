#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

using namespace std;

int menu()
{
  system("clear");
  fflush(stdin);
  int op;
  cout<<"-----------------------------------------\n";
  cout<<"\t\t\tLoja de Música\n";
  cout<<"-----------------------------------------\n\n";
  cout<<"1 - Cadastro"<<endl; //Cadastra: Clientes/Funcionários e Produtos
  cout<<"2 - Remover"<<endl; //Remove: Clientes/Funcionários e Produtos
  cout<<"3 - Exibir"<<endl; //Exibe: Clientes/Funcionários e Produtos
  cout<<"4 - Pesquisar"<<endl; //Pesquisa: Clientes/Funcionários e Produtos
  cout<<"5 - Serviços"<<endl; //Lista os serviços e atribui um contrato para um cliente
  cout<<"-----------------------------------------\n";
  cin>>op;
  return op;
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int op;

  do
  {
    op = menu();
  } 
  while(1);
  
}
