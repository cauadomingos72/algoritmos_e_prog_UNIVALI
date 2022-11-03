#include <iostream>
#include <locale.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define TAM 10

using namespace std;

void info(string nome[])
{
  for(int i=0;i<TAM;i++)
  {
    cout<<"Digite o nome da pessoa "<<i+1<<":"<<endl;
    fflush(stdin);
    getline(cin,nome[i]);
  }
}

void leit(string nome[])
{
  for(int i=0;i<TAM;i++)
  {
    cout<<nome[i]<<endl;
  }
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  string nome[TAM];
  
  ofstream escreve;
  escreve.open("nomes.dat", ofstream::binary);
  info(nome);
  escreve.close();

  system("clear");

  ifstream leitura;
  leitura.open("nomes.dat", ofstream::binary);
  leit(nome);
  leitura.close();

  return 0;
}
