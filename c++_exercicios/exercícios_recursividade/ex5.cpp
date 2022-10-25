/*
Faça uma função recursiva que recebe um vetor preenchido e a quantidade de posições deste
vetor, e retorna a soma de todos os elementos do vetor.
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM 3

using namespace std;

void preen(int vet[])
{
  for(int i=0;i<TAM;i++)
  {
    vet[i] = rand() % (TAM*TAM) + 1;
    cout<<vet[i]<<"\t";
  }
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         0 - NÃO"<<endl;
  fflush(stdin);
  cin>>op;
  system("clear");
}

int soma(int vet[], int pos)
{
  if(pos<0)
    return 0;
  else
    return vet[pos] + soma(vet, pos-1);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));
  int vet[TAM], pos=TAM-1, op;

  do
  {
    preen(vet);
    cout<<endl;
    cout<<"A soma do vetor acima é igual a: "<<soma(vet,pos)<<endl;
    cout<<endl;
    fim(op);
  } while (op!=0);
}
