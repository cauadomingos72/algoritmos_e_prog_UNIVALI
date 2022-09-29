/**
Faça uma função que preencha uma matriz de 5X5 com o elemento um em todas as posições. Crie também uma função para exibir a matriz.
*/
#include <iostream>
#include <locale.h>
#define TAM 5

using namespace std;

void preen(int mat[TAM][TAM]){
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      mat[i][j]=1;
    }
  }
}

void leitura(int mat [TAM][TAM]){
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
  }
}

int main() {
  setlocale (LC_ALL,"Portuguese");
  int mat[TAM][TAM];

  preen(mat);

  leitura(mat);
}
