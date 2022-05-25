////////////////////////////////////////////////////////////////////////////////////////////////
// Faça um programa que preencha uma matriz de 5X5 com o elemento um em todas as posições em que o índice de linha tem valor maior que o da coluna.
////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <locale.h>
#define TAM 5

using namespace std;

int main() {
  setlocale (LC_ALL,"Portuguese");

  int mat[TAM][TAM], lin, col;

  for (lin = 1; lin <= TAM; lin++) {
    for (col = 1; col <= TAM; col++) {
      if (lin > col) {
        mat[lin][col] = 1;
      } else {
        mat[lin][col] = 0;
      }
    }
  }
  for (lin = 1; lin <= TAM; lin++) {
    for (col = 1; col <= TAM; col++) {
      cout << mat[lin][col] << "\t";
    }
    cout << endl;
  }
  return 0;
}
