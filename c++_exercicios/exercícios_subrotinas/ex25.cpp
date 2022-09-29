/**
Faça um programa que leia dois vetores A e B, de tamanho 8. Em uma função realize a troca
dos elementos destes vetores; ou seja, após a execução da função o vetor B deverá conter os
valores fornecidos para o vetor A, e vice-versa.
*/
#include <iostream>
#include <locale.h>
#define TAM 8

using namespace std;

void inv(int vetA[],int vetB[]){
  int vetT[TAM];

  //PREENCHENDO VETOR AUXILIAR COM O VETOR A
  for(int i=0;i<TAM;i++){
    vetT[i]=vetA[i];
  }
  //PREENCHENDO VETOR A COM O VETOR B
  for(int i=0;i<TAM;i++){
    vetA[i]=vetB[i];
  }
  //PREENCHENDO VETOR B COM O VETOR AUXILIAR 
  for(int i=0;i<TAM;i++){
    vetB[i]=vetT[i];
  }
}

int main() {
  setlocale (LC_ALL,"Portuguese");
  srand(time(NULL));
  
  int vetA[TAM], vetB[TAM];

  //VETOR A NORMAL
  cout<<"Vetor A"<<endl;
  for(int i=0;i<TAM;i++){
    vetA[i]=rand()%10+1;
    cout<<vetA[i]<<"\t";
  }

  cout<<endl;

  //VETOR B NORMAL
  cout<<"Vetor B"<<endl;
  for(int i=0;i<TAM;i++){
    vetB[i]=rand()%10+1;
    cout<<vetB[i]<<"\t";
  }

  cout<<endl;

  inv(vetA,vetB);

  cout<<endl;

  //VETOR A COM OS VALORES DO VETOR B
  cout<<"Vetor A atual:"<<endl;
  for(int i=0;i<TAM;i++){
    cout<<vetA[i]<<"\t";
  }

  cout<<endl;

  //VETOR B COM OS VALORES DO VETOR A
  cout<<"Vetor B atual:"<<endl;
  for(int i=0;i<TAM;i++){
    cout<<vetB[i]<<"\t";
  }
  
}
