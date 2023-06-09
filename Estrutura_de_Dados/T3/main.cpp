// Alunos:

#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

using namespace std;

void menu(int &op)
{
  cout<<"-----------------------------------\t\t";
  cout<<"\n\nÁrvore Binária de Expressão\t\t";
  cout<<"-----------------------------------\t";
  cout<<"1 - Inserir Expressão"<<endl;
  cout<<"2 - Imprimir Árvore"<<endl;
  cout<<"3 - Resultado"<<endl;
  cout<<"4 - Encerrar"<<endl;
  cin>>op;
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int op, run = 1;

  do
  {
    menu(op);
  } while (run == 1);
}