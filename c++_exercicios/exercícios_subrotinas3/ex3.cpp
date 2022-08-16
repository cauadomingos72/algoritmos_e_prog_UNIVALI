/**
Declare um vetor de 5 inteiros, leia um valor para cada posição. Crie uma função que
verifique quantos elementos possuem valor maior, menor e igual ao primeiro elemento do
vetor. Mostre a quantidade de valores maiores, menores e iguais no main.
*/
#include <iostream>
#include <locale.h>
#define TAM 5

using namespace std;

int maior(int vet[TAM]){
  int cont=0;
  for(int i=0;i<TAM;i++){
    if(vet[0]<vet[i]){
      cont++;
    }
  }
  return cont;
}

int menor(int vet[TAM]){
  int cont=0;
  for(int i=0;i<TAM;i++){
    if(vet[0]>vet[i]){
      cont++;
    }
  }
  return cont;
}

int igual(int vet[TAM]){
  int cont=0;
  for(int i=0;i<TAM;i++){
    if(vet[0]==vet[i]){
      cont++;
    }
  }
  return cont;
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  srand(time(NULL));
  int vet[TAM];

  for(int i=0;i<TAM;i++){
    vet[i]=rand()%6+1;
    cout<<vet[i]<<"\t";
  }

  cout<<endl;
  cout<<"Quantidade de números maiores que "<<vet[0]<<" é de: "<<maior(vet)<<endl;
  cout<<"Quantidade de números menores que "<<vet[0]<<" é de: "<<menor(vet)<<endl;
  cout<<"Quantidade de números iguais a "<<vet[0]<<" é de: "<<igual(vet)<<endl;
  
}
