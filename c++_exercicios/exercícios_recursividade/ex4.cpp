/*
 Faça um programa que receba um valor n, e imprima a contagem regressiva a partir deste
valor. Por exemplo, se o usuário digitar 5, o programa irá imprimir 5, 4, 3, 2, 1, 0.
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

void leitura (int &num)
{
  cout<<"Digite um valor inicial para a contagem:"<<endl;
  fflush(stdin);
  cin>>num;
  system("clear");
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         2 - NÃO"<<endl;
  cin>>op;
  system("clear");
}

int contagem (int num)
{
  if(num < 0)
    return 1;
  cout<<num<<endl;
  sleep(1);
  return contagem(num-1);
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  int num, op;

  do
  {
    leitura(num);
    contagem(num);
    cout<<endl;
    fim(op);
  } while (op!=0);
}
