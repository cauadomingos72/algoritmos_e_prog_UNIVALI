/**
Leia 30 valores em um vetor e em uma função jogue os pares em um vetor e os ímpares em
outro. Após a distribuição faça uma função para calcular o somatório dos dois vetores. Exiba o
vetor de maior valor no main.
*/
#include <iostream>
#include <locale.h>
#define TAM 30

using namespace std;

int soma(int vetP[TAM], int vetI[TAM]){
  int res, soP=0,soI=0;
  //SOMA DOS PARES
  for(int i=0;i<TAM;i++){
    soP=soP+vetP[i];
  }
  //SOMA DOS IMPARES
  for(int i=0;i<TAM;i++){
    soI=soI+vetI[i];
  }

  if(soP>soI){
    return 1;
  } else {
    return 0;
  }
}

int main() {
  setlocale (LC_ALL,"Portuguese");
  srand(time(NULL));

  int vetA[TAM], vetP[TAM], vetI[TAM], res;

  for(int i=0;i<TAM;i++){
    vetA[i]=rand()%10+1;
    cout<<vetA[i]<<"\t";
    if(vetA[i]%2==0){
      vetP[i]=vetA[i];
      vetI[i]=0;
    } else {
      vetI[i]=vetA[i];
      vetP[i]=0; 
    }
  }

  cout<<endl;
  cout<<endl;

  res=soma(vetP,vetI);

  if(res==1){
    cout<<"O Vetor de Maior Valor é o Par"<<endl;
    cout<<endl;
    for(int i=0;i<TAM;i++){
      cout<<vetP[i]<<"\t";
    } 
  } else {
    cout<<"O Vetor de Maior Valor é o Ímpar"<<endl;
    cout<<endl;
    for(int i=0;i<TAM;i++){
      cout<<vetI[i]<<"\t";
    } 
  }
}
