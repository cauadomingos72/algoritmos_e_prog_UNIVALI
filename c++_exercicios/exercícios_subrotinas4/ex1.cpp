/**
Declare um vetor de 10 inteiros, leia um valor para cada posição. Calcule o fatorial do maior
e do menor valor contidos no vetor usando função.
*/
#include <iostream>
#include <locale.h>
#define TAM 10

using namespace std;

void leitura(int vet[TAM], int &mai, int &men){
  for(int i=0;i<TAM;i++){
    vet[i]=rand()%10+1;
    cout<<vet[i]<<"\t";
    if(i==0){
      mai=vet[i];
      men=vet[i];
    }
    if(mai<vet[i]){
      mai=vet[i];
    }
    if(men>vet[i]){
      men=vet[i];
    }
  }
}

int fatMa(int mai){
  int antV=1,fat=0;
  for(int i=mai;i>0;i--){
    antV= i * antV; 
  }
  return antV;
}

int fatMe(int men){
  int antV=1,fat=0;
  for(int i=men;i>0;i--){
    antV= i * antV; 
  }
  return antV;
}

int main() {
  setlocale (LC_ALL,"Portuguese");
  srand(time(NULL));
  int vet[TAM], mai=0, men=0;

  leitura(vet, mai, men);

  cout<<endl;

  cout<<"Fatorial do Maior ("<<mai<<"): "<<fatMa(mai)<<endl;
  cout<<"Fatorial do Menor ("<<men<<"): "<<fatMe(men)<<endl;
}
