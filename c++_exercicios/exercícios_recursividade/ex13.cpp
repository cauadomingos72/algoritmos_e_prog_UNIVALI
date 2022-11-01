/*
Faça um programa de busca binária recursivo. Crie um vetor de 15 posições e preencha-o
utilizando rand, e cuidando para não haver valores repetidos. A seguir ordene-o (tanto o
preenchimento quanto a ordenação não precisam ser recursivos) e solicite ao usuário que entre
com o valor que deseja procurar no vetor. Esse valor será levado a uma função de busca binária
recursiva, que irá retornar verdadeiro se o elemento existir no vetor e falso se não existir. Exiba
esta mensagem na tela.
*/
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM 15

using namespace std;

void leitura (int &num)
{
  cout<<"Digite um número para pesquisar:"<<endl;
  fflush(stdin);
  cin>>num;
  system("clear");
}

void fim (int &op)
{
  cout<<"Deseja procurar novamente?"<<endl;
  cout<<"1 - SIM         0 - NÃO"<<endl;
  cin>>op;
  system("clear");
}

bool verif(int vet[], int temp)
{
  for(int i=0; i<TAM; i++)
  {
    if(temp == vet[i])
      return true;
  }
  return false;
}

void preenchimento(int vet[])
{
  int temp;
  for(int i=0; i<TAM; i++)
  {
    temp = rand() % (TAM*TAM) + 1;
    while(verif(vet, temp))
      temp = rand() % (TAM*TAM) + 1;
    vet[i] = temp;
  }  
}

void bubblesort(int vet[])
{
  int i, j, cond, temp;
  cond = 1;
  for (i=TAM-1; (i >= 1) && (cond == 1); i--) {
    cond = 0;
    for (j=0; j < i ;j++) {
      if (vet[j+1] < vet[j]) {
        temp = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = temp;
        cond = 1;
      }
    }
  }
}

void exibir(int vet[])
{
  for(int i=0;i<TAM;i++)
    cout<<vet[i]<<"\t";
  cout<<endl;
}

int pesquisa(int vet[], int a, int i)
{
  if(vet[i] == a)
    return a;
  if(i == TAM)
    return 0;
  return pesquisa(vet, a, i+1);
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  int vet[TAM]{}, op, num, i=0;

  do
  {
    leitura(num);
    preenchimento(vet);
    bubblesort(vet);
    exibir(vet);
    cout<< endl;
    if(pesquisa(vet, num, i) == num)
      cout<<"O valor foi encontrado!"<<endl;
    else
      cout<<"O valor não foi encontrado!"<<endl;
    fim(op);
  } while (op != 0);
}
