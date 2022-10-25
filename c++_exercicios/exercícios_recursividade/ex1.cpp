/*
Faça uma função recursiva para elevar um valor base a potência do valor expoente.
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void leitura (int &bas, int &exp)
{
  cout<<"Digite um valor para a BASE e para o EXPOENTE, respectivamente:"<<endl;
  fflush(stdin);
  cin>>bas>>exp;
  system("clear");
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         2 - NÃO"<<endl;
  cin>>op;
  system("clear");
}

int potencia(int bas, int exp)
{
  if(exp<=0)
    return 1;
  return (bas * potencia(bas,exp-1));
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  int bas, exp, op;

  do
  {
    leitura(bas,exp);
    cout<<"A potência de "<<bas<<"^("<<exp<<") é: "<<potencia(bas, exp)<<endl;
    cout<<endl;
    fim(op);
  } while (op!=0);
  
}
