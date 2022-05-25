///////////////////////////////////////////////////////////////////////////////////////
// Faça um programa que leia uma matriz 4 x 4 e que logo em seguida realize o somatório de todos elementos contidos na diagonal principal. Exiba o resultado.
///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <locale.h>
#define TAM 4

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  srand (time(NULL));
  int mat[TAM][TAM], lin, col, soma=0;

  for (lin = 1; lin <= TAM; lin++) {
    for (col = 1; col <= TAM; col++) {
      mat[lin][col] = rand () % (TAM*TAM) + 1;
    }
  }
  
  for (lin = 1; lin <= TAM; lin++) {
    for (col = 1; col <= TAM; col++) {
      cout << mat[lin][col] << "\t";
    }
    cout << endl;
  }
  
  cout << endl;
  
  for (lin = 1; lin <= TAM; lin++) {
    for (col = 1; col <= TAM; col++) {
      if (lin == col) {
        soma = mat[lin][col] + soma;
      }
    }
  }

  cout << "A soma da diagonal principal é igual a: " << soma << endl;
}
