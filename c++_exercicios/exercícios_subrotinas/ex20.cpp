/**
Declare um vetor de 10 inteiros, leia um valor para cada posição. Crie uma função que
mostre os elementos deste vetor em posição inversa ao que foram atribuídos.
*/
#include <iostream>
#include <locale.h>
#define TAM 10

using namespace std;

void inv(int vet[TAM]){
  for(int i=TAM-1;i>=0;i--){
    cout<<vet[i]<<"\t";
  }
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  srand(time(NULL));
  
  int vet[TAM];

  for(int i=0;i<TAM;i++){
    vet[i]=rand()%10+1;
    cout<<vet[i]<<"\t";
  }

  cout<<endl;
  cout<<endl;
  
  inv(vet);

  return 0;  
}
