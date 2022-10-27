#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void leitura (int &num1, int &num2)
{
  cout<<"Digite dois valores inteiros:"<<endl;
  fflush(stdin);
  cin>>num1>>num2;
  system("clear");
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         0 - NÃO"<<endl;
  fflush(stdin);
  cin>>op;
  system("clear");
}

int mult (int num1, int num2)
{
  if(num2==0)
    return 0;
  else
    return num1 + mult(num1,num2-1);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int num1, num2, op;

  do
  {
    leitura(num1,num2);
    cout<<num1<<" X "<<num2<<" = "<<mult(num1,num2)<<endl;
    cout<<endl;
    fim(op);
  } while (op!=0);
}
