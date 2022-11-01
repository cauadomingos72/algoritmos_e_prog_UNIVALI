/*
Escreva uma função recursiva, int SomaSerie (int i, int j, int k), que imprime na tela a soma
de valores do intervalo [i,j], com incremento k
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void leitura (int &i, int &j, int &k)
{
  cout<<""<<endl;
  fflush(stdin);
  cout<<"Digite um intervalo de [i,j]:"<<endl;
  cin>>i>>j;
  cout<<"Incremento (Ex: De 2 em 2):"<<endl;
  cin>>k;
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

int soma (int i, int j, int k)
{
  if(i>=j)
    return 0;
  i+=k;
  return k + soma(i,j,k);
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  int i, j, k, op;

  do
  {
    leitura(i,j,k);
    cout<<"Resultado: "<<soma(i,j,k)<<endl;
    fim(op);
  } while (op!=0);
}
