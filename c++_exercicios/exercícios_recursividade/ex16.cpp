#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void leitura (int &x, int &y)
{
  fflush(stdin);
  cout<<"Digite um valor para X e Y, respectivamente:"<<endl;
  cin>>x>>y;
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

int Div (int x, int y)
{
  if(x>y)
    return 1 + Div(x-y,y);
  else
    return 0;
  if(x==y)
    return 1;
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int x, y, op;

  do
  {
    leitura(x,y);
    cout<<Div(x,y)<<endl;
    fim(op);
  }
}
