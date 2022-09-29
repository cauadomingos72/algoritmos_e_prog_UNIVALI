/**
Leia dois vetores A e B com vinte elementos e declare um terceiro vetor C. Faça uma função
que calcule cada elemento de C com a subtração do elemento correspondente de A com B.
Exiba o vetor C no main.
*/
#include <iostream>
#include <locale.h>
#define TAM 20

using namespace std;

int vetorC(int vA[TAM], int vB[TAM], int i){
  return vA[i]-vB[i];
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  srand(time(NULL));
  
  int vA[TAM], vB[TAM], vC[TAM];

  //VETOR A
  for(int i=0;i<TAM;i++){
    vA[i]=rand()%10+1;
    cout<<vA[i]<<"\t";
  }
  
  cout<<endl;
  
  //VETOR B
  for(int i=0;i<TAM;i++){
    vB[i]=rand()%10+1;
    cout<<vB[i]<<"\t";
  }

  cout<<endl;

  //VETOR C
  for(int i=0;i<TAM;i++){
    cout<<vetorC(vA, vB, i)<<"\t";
  }

}
