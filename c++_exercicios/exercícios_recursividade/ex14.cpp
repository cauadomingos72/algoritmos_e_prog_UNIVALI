#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void leitura (float &n)
{
  cout<<"Digite um valor N maior que 0:"<<endl;
  fflush(stdin);
  cin>>n;
  system("clear");
  while(n==0)
  {
    cout<<"Digite um valor maior que 0!"<<endl;
    cin>>n;
    system("clear");
  }
}

void fim (int &op)
{
  fflush(stdin);
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         0 - NÃO"<<endl;
  cin>>op;
  system("clear");
}

float soma(float max, float a)
{
  if(a==max)
    return 0;
  return float((1+ a*a) / a) + soma(max, a+1);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int op; 
  float n, a=1;
  do
  {
    leitura(n);
    cout<<"Resultado: "<<soma(n, a)<<endl;
    fim(op);
  } while (op != 0);
}
