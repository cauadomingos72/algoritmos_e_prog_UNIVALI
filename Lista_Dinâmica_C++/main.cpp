///Integrantes: Cauã Domingos, Paulo Hermans e Vinicius Ribeiro.
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
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
  cout<<"Insira os dados do produto"<<endl;
  cout<<"Nome: "<<endl;
  fflush(stdin);
  getline(cin, p.nome);
  cout<<endl;
  do {
    cout<<"Código:"<<endl;
    cin>>p.codigo;
  } while (false);
  cout<<endl;
  cout<<"Preço:"<<endl;
  cin>>p.preco;
  system("cls");
}


void exibir_dados(Produto *p)
{
  if(prodvazio(p))
    cout<<"Nenhum item adicionado"<<endl;
  else {
    while (p != NULL)
    {
      cout<<p->nome<<endl;
      cout<<p->codigo<<endl;
      cout<<p->preco<<endl;
      p = p->proximo;
    }
  }
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  ListaE lista;
  ofstream listasalva;
  listasalva.open("data.txt");
  inicializa_lista(lista);
  Produto *item = NULL;
  Produto *itemF = NULL;
  Produto val;
  int op=0;

  do{
    system("cls");
    menu(op);

    switch (op)
    {
      case 1:
        extrai_dados(val);
        insere_elemento_lista(item, itemF, val);
        system("pause");
      break;

      case 2:
      remover_lista(item, itemF);
      system("cls");
      break;

      case 3:
      consulta_lista(item, itemF);
      system("pause");
      break;

      case 4:
      exibir_dados(item);
      system("pause");
      break;

      default:
      break;

    }
  } while (op!=5);
  listasalva << item->codigo <<endl;
  listasalva << item->nome<<endl;
  listasalva << item->preco<<endl;
  listasalva << itemF->codigo<<endl;
  listasalva << itemF->nome<<endl;
  listasalva << itemF->preco<<endl;
  listasalva.close();
  return 0;
}
