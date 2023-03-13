#include <iostream>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "baralho.h"

using namespace std;

void menu (int &op)
{
  cout<<"1 - Insere Fim"<<endl;
  cout<<"2 - Remove Fim"<<endl;
  cout<<"3 - Mostrar Baralho"<<endl;
  cout<<"4 - Encerrar"<<endl;
  cin>>op;
} 

int main() {
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  Baralho mesa, dealer, jogadores[4];
  int op;


  inicializa_baralho(mesa);
  monta_baralho(mesa);
  inicializa_baralho(dealer);
  monta_baralho(dealer);
  for(int i=0;i<4;i++)
  {
    inicializa_baralho(jogadores[i]);
    monta_baralho(jogadores[i]);
  }

  do
  {
    menu(op);
    switch(op)
    {
      case 2:
        insere_fim(Baralho &d, Carta c)
      break;
      case 4:
      break;
      case 6:
        system("clear");
        imprime_baralho(mesa);
        sleep(3);
      break;
      case 8:
      break;
    }
  }while(op != 4);  
}
