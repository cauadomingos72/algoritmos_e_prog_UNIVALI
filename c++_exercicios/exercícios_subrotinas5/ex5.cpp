#include <iostream>
#include <locale.h>
#include <time.h>
#define TAM 4

using namespace std;

void preen(float mat[TAM][TAM]){
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      mat[i][j]=rand()%10+1;
    }
  }
}

void leitura(float mat[][TAM]){
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
  }
}

float soma(float mat[TAM][TAM]){
  float soma=0;
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      if(i!=j && i+j != TAM-1){
       soma=soma+mat[i][j];
      }
    }
  }
  return float(soma);
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  srand(time(NULL));
  float mat[TAM][TAM];

  preen(mat);

  leitura(mat);
  
  cout<<"Soma: "<<soma(mat)<<endl;
}
