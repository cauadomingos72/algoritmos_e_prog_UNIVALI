///////////////////////////////////////////////////////////////////////////////////////////////////
// Faça um programa que solicita ao usuário 25 valores reais e armazene em uma matriz 5x5. A seguir troque todos os elementos da matriz que sejam maiores do que 100 pelo valor zero. Exiba a matriz original e alterada.
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <locale.h>
#define TAM 5

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int mat[TAM][TAM], lin, col;

  cout << "Digite 25 valores inteiros:" << endl;
  for (lin = 1; lin <= TAM; lin++) {
    for (col = 1; col <= TAM; col++) {
      cin >> mat[lin][col];
    }
  }
  for (lin = 1; lin <= TAM; lin++) {
    for (col = 1; col <= TAM; col++) {
      if (mat[lin][col] > 100) {
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
