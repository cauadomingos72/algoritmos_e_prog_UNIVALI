/*
Faça uma função recursiva que calcule o M.D.C. pelo algoritmo de Euclides. Por exemplo,
divide-se a por b e obtêm-se o quociente q e o resto r. Se r for zero, b é o m.d.c; se não for,
divide-se b por r e assim sucessivamente até encontrar um resto zero. O último divisor é o M.D.C.
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void leitura (int &div1, int &div2)
{
  cout<<"Digite dois valores para o cálculo do MDC:"<<endl;
  fflush(stdin);
  cin>>div1>>div2;
  system("clear");
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         0 - NÃO"<<endl;
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
    cout<<"O MDC entre "<<div1<<" e "<<div2<<" é: "<<mdc(div1,div2)<<endl;
    cout<<endl;
    fim(op); 
  } while (op!=0);
}
