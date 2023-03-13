#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "dados.h"

using namespace std;

void menu (int &op)
{
  cout<<"Menu"<<endl;
  cout<<"2 - Inserir Fim"<<endl;
  cout<<"4 - Remover Fim"<<endl;
  cout<<"6 - Quantidade da Lista"<<endl;
  cout<<"8 - Imprimir Lista"<<endl;
  cout<<"10 - Ordenar"<<endl;
  cout<<"12 - Encerrar"<<endl;
  cin>>op;
}

int main() 
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  Lista<int> list;
  Item<int> it;
  int op;

  inicializar(list);
  
  do
  {
    system("clear");
    menu(op);

    switch(op)
    {
      case 2:
        insere_fim(list, it); 
      break;
      case 4:
        remove_fim(list);
      break;
      case 6:
        system("clear");
        qtd_lista(list);
        sleep(3);
      break;
      case 8:
        system("clear");
        imprime_lista(list);
        sleep(4);
      break;
      case 10:
        bubblesort(list);
      break;
      case 12:
      break;
    }
  } while (op < 12);
  
}
