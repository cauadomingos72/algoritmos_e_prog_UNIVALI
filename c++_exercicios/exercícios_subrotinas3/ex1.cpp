/**
Declare um vetor de 10 inteiros no main, crie uma função para fazer a leitura do vetor. Na sequência faça outras três funções para calcular a média, o menor e o maior valor contidos no vetor. Exiba os valores da média, menor e maior no main.
*/
#include <iostream>
#include <locale.h>
#define TAM 10

using namespace std;

void leitura(int vet[TAM]){
  for (int i=0;i<TAM;i++){
    cout<<vet[i]<<"\t";
  }
}

float media(int vet[TAM]){
  int soma=0;
  for(int i=0;i<TAM;i++){
    soma=soma+vet[i];
  }
  return (float) soma/TAM;
}

int maior(int vet[TAM]){
  int maior;
  for(int i=0;i<TAM;i++){
    if(i==0){
      maior=vet[i];
    }
    if(vet[i]>maior){
      maior=vet[i];
    }
  }
  return maior;
}

int menor(int vet[TAM]){
  int menor;
  for(int i=0;i<TAM;i++){
    if(i==0){
      menor=vet[i];
    }
    if(vet[i]<menor){
      menor=vet[i];
    }
  }
  return menor;
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  srand(time(NULL));
  int vet[TAM];

  for (int i=0;i<TAM;i++){
    vet[i]=rand()%10+1;
  }

  leitura(vet);

  cout<<endl;
  cout<<"Maior Valor: "<<maior(vet)<<endl;
  cout<<"Menor Valor: "<<menor(vet)<<endl;
  cout<<"Média: "<<media(vet)<<endl;
}
