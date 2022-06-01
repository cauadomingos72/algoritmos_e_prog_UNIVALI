//////////////////////////////////////////////////////////////////////////////////
// Faça um programa que preenche duas matrizes, uma M (4X6) e outra N (6X4). A seguir o programa deverá criar uma nova matriz que seja o produto matricial de M por N.
//////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <locale.h>
#include <time.h>
#define TAMB 4
#define TAMA 6


using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  srand (time(NULL));
  int matM[TAMB][TAMA], matN[TAMA][TAMB], matX[TAMA][TAMA]={}, lin, col, k;

  // PREENCHENDO A MATRIZ M
  for (lin = 0; lin < TAMB; lin++) {
    for (col = 0; col < TAMA; col++) {
      matM[lin][col] = rand() % (TAMB * TAMB) + 1;
    }
  }
  
  // PREENCHENDO A MATRIZ N
  for (lin = 0; lin < TAMA; lin++) {
    for (col = 0; col < TAMB; col++) {
      matN[lin][col] = rand() % (TAMB * TAMB) + 1;
    }
  }

  // EXIBINDO A MATRIZ M
  for (lin = 0; lin < TAMB; lin++) {
    for (col = 0; col < TAMA; col++) {
      cout << matM[lin][col] << "\t";
    }
    cout << endl;
  }
  
  cout << endl;
  
  // EXIBINDO A MATRIZ N
  for (lin = 0; lin < TAMA; lin++) {
    for (col = 0; col < TAMB; col++) {
      cout << matN[lin][col] << "\t";
    }
    cout << endl;
  }

  cout << endl;

  // REALIZANDO O PRODUTO MATRICIAL ENTRE O "M" E O "N"
  for (lin = 0; lin < TAMB; lin++) {
    for (col = 0; col < TAMB; col++) {
      for (k = 0; k < TAMA; k++) {
        matX[lin][col] += matM[lin][k] * matN[k][col];
      }
    }
  }

  for (lin = 0; lin < TAMB; lin++) {
    for (col = 0; col < TAMB; col++) {
      cout << matX[lin][col] << "\t";
    }
    cout << endl;
  }
  
}
