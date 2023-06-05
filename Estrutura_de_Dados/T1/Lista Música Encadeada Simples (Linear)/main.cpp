#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "musica.h"

using namespace std;

void menu(int &op)
{
  cout<<"Adicionar Música"<<endl;
  cout<<"Remover Música"<<endl;
  cout<<"Mostrar Playlist"<<endl;
  cout<<"Encerrar"<<endl;
  fflush(stdin);
  cin>>op;
  fflush(stdin);
}

int main() 
{ 
  setlocale(LC_ALL, "Portuguese");
  Lista conj;
  Info dado;
  int op;
  
  inicializa_lista_enc(conj);
  do{
    menu(op);
    switch (op)
    {
      case 1:
        cout<<"Nome: "<<endl;
        getline(cin, dado.det.nome);
        fflush(stdin);
        cout<<"Artista: "<<endl;
        getline(cin, dado.det.artista);
        fflush(stdin);
        insere_final(conj, dado);
      break;
      case 2:
        remove_final(conj);
      break;
      case 3:
        imprimir();
      break;
      case 4:
      break;
    }
  } while (op < 4 && op > 0);
}
