#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include "campeonato.h"

using namespace std;

void menu(int &op)
{
  system("clear");
  fflush(stdin);
  cout<<"-----------------------------------------\n\n";
  cout<<"1 - Cadastro"<<endl; 
  cout<<"2 - Remover"<<endl; 
  cout<<"3 - Exibir"<<endl; 
  cout<<"4 - Alterar"<<endl; 
  cout<<"5 - Encerrar"<<endl; 
  cout<<"-----------------------------------------\n";
  cin>>op;
}

void menuC(int op)
{
  system("clear");
  fflush(stdin);
  cout<<"-----------------------------------------\n\n";
  cout<<"1 - Cadastro Informações"<<endl; 
  cout<<"2 - Cadastro Jogador"<<endl; 
  cout<<"3 - Cadastro Time"<<endl; 
  cout<<"4 - Cadastro Jogo"<<endl; 
  cout<<"5 - Voltar"<<endl; 
  cout<<"-----------------------------------------\n";
  cin>>op;
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  int run=1, op;
  Campeonato *camp;
  Pessoas p;
  Jogos j;
  Informacoes i;

  do
  {
    menu(op);

    switch(op)
    {
      case 1:
        menuC(op);
        if(op == 1)
        {
          camp->setInfo(i);
        }
      break;

      case 2:
      break;

      case 3:
      break;

      case 4:
      break;

      case 5:
        run = 0;
      break;
    }
  } 
  while(run == 1);

}
