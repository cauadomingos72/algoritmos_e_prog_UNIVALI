/*
Faça uma função recursiva que receba os valores de X e N e realize o cálculo da seguinte
progressão geométrica:
1 + x^(1) + x^(2) + x^(3) + x^(n)
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void leitura (double &bas, double &exp)
{
  cout<<"Digite um valor para a BASE e para o EXPOENTE, respectivamente:"<<endl;
  fflush(stdin);
  cin>>bas>>exp;
  system("clear");
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         0 - NÃO"<<endl;
  cin>>op;
  system("clear");
}

int mult(double b, double e)
{
  int temp;
  temp = pow (b,e);
  if (e==0)
    return 1;
  else
    return temp + mult(b, e-1);
}

int main() 
{
  setlocale(LC_ALL,"Portuguese");
  double bas, exp; 
  int op;

  do
  {
    leitura(bas, exp);
    cout<<"Resultado: "<<mult(bas,exp)<<endl;
    cout<<endl;
    fim(op);
  } while (op!=0);
}
