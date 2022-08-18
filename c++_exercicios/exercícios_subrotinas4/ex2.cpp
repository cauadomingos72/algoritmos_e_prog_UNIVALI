/**
Construa um algoritmo que solicite 5 valores inteiros ao usuário e os armazene em um
vetor. Na sequência, faça uma função que inverta os valores do vetor utilizando um segundo
vetor.
*/
#include <iostream>
#include <locale.h>
#define TAM 5

using namespace std;

void inv(int vetA[TAM]){
  int vetB[TAM], j=TAM-1;
  for(int i=0;i<TAM;i++){
    vetB[j]=vetA[i];
    j--;
  }
  
  j=TAM-1;
  
  for(int i=0;i<TAM;i++){
    vetA[i]=vetB[i];
  }
}

int main() {
  setlocale (LC_ALL,"Portuguese");
  int vetA[TAM];

  for(int i=0;i<TAM;i++){
    cout<<"Insira um "<<i+1<<"° valor inteiro:\t";
    cin>>vetA[i];
  }

  inv(vetA);

  cout<<endl;
  
  for(int i=0;i<TAM;i++){
    cout<<vetA[i]<<"\t";
  }
  
}
