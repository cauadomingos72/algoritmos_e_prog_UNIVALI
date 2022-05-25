///////////////////////////////////////////////////////////////////
// Faça um programa que preencha uma matriz de 5X5 com o elemento um em todas as posições.
///////////////////////////////////////////////////////////////////
#include <iostream>
#include <locale.h>

#define TAM 5

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  srand(time(NULL));
  int mat[TAM][TAM], lin, col;

  for (lin = 0; lin < TAM; lin++) {
    for (col = 0; col < TAM; col++) {
      mat[lin][col] = rand() % (TAM*TAM) +1;
    }
  }
  for (lin = 0; lin < TAM; lin++) {
    for (col = 0; col < TAM; col++) {
      cout << mat[lin][col] << "\t";
    }
    cout << endl;
  }
  return 0;
}
