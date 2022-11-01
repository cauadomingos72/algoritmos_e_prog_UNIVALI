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

int mod (int x, int y)
{
  if (x > y)
    return mod (x-y, y);
  else
    return x;
  if (x==y)
    return -1;
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int op, x, y;
  
  do
  {
    leitura(x,y);
    cout<<"Resultado: "<<mod(x,y)<<endl;
    fim(op);
  } while (op != 0);
}
