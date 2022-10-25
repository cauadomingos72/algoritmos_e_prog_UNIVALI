/*
Faça uma função recursiva que calcule o M.D.C. (máximo divisor comum) entre dois valores fornecidos pelo usuário.
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void leitura (int &div1, int &div2)
{
  cout<<"Digite dois valores para o cálculo do MDC:"<<endl;
  cin>>div1>>div2;
  system("clear");
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         2 - NÃO"<<endl;
  cin>>op;
  system("clear");
}

int mdc (int div1, int div2)
{
  if(div2 == 0)
    return div1;
  else
    return mdc(div2, div1 % div2);
}

int main() 
{
  setlocale(LC_ALL,"Portuguese");
  int div1, div2, op;

  do
  {
    leitura(div1,div2);
    cout<<"O MMD entre "<<div1<<" e "<<div2<<" é: "<<mdc(div1,div2)<<endl;
    cout<<endl;
    fim(op); 
  } while (op!=0);
}
