#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void leitura (float &i)
{
  do
  {
  fflush(stdin);
  cout<<"Digite um valor de N (maior ou igual a 1):"<<endl;
  cin>>i;
  system("clear");
  } while (i <= 0);
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         0 - NÃO"<<endl;
  fflush(stdin);
  cin>>op;
  system("clear");
}

float soma (float i, float j, float k)
{
  if((i-j) == 1)
    return 0;
  return float ((k / (i - j)) + soma(i,j+1,k+1));
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  float i, j=0, k=1; 
  int op;

  do
  {
    leitura(i);
    cout<<"Resultado: "<<soma(i,j,k)<<endl;
    fim(op);
  } while (op != 0);
 
}
