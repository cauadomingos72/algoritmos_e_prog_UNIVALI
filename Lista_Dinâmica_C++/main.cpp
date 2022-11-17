#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "lista.h"

using namespace std;

void menu (int &op)
{
  cout<<"Menu:"<<endl;
  cout<<"Adicionar (1)"<<endl;
  cout<<"Remover - Código (2)"<<endl;
  cout<<"Consulta - Código (3)"<<endl;
  cout<<"Exibir (4)"<<endl;
  cout<<"Encerrar (5)"<<endl;
  cin>>op;
}

void extrai_dados(Produto &p)
{
  cout<<"Inira os dados do produto"<<endl;
  cout<<"Nome: "<<endl;
  fflush(stdin);
  cin.ignore();
  getline(cin, p.nome);
  cout<<endl;
  do {
    cout<<"Código:"<<endl;
    cin>>p.codigo;
  } while (false);
  cout<<endl;
  cout<<"Preço:"<<endl;
  cin>>p.preco;
  /*system("clear");*/
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  ListaE lista;
  inicializa_lista(lista);
  Produto item;
  int op;

  menu(op);

  switch (op)
  {
    case 1:
      extrai_dados(item);
      insere_elemento_lista(lista, item);      
    break;
    
    case 2:
    break;
  
    case 3:
    break;

    case 4:
    break;

    default:
    break;
  }
  return 0;
}
