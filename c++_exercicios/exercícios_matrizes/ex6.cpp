////////////////////////////////////////////////////////////////////////////////////
// Faça um programa que solicita ao usuário 16 valores reais e armazene em uma matriz 4x4. O programa deve somar os elementos de cada uma das linhas armazenando o resultado da soma em um vetor. A seguir, deve multiplicar cada elemento da matriz pela soma da sua respectiva linha. Exiba na tela a matriz resultante.
////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <locale.h>
#define TAM 4

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int mat[TAM][TAM], vet[TAM], lin, col, soma=0, resulX=1;;

  cout << "Digite 16 valores:" << endl;
  for (lin = 0; lin < TAM; lin++) {
    for (col = 0; col < TAM; col++) {
      cin >> mat[lin][col];
    }
  }
  cout << endl;

  for (lin = 0; lin < TAM; lin++) {
    for (col = 0; col < TAM; col++) {
      cout << mat[lin][col] << "\t";
    }
    cout << endl;
  }
  
  cout << endl;
  
  for (lin = 0; lin < TAM; lin++) {
    for (col = 0; col < TAM; col++) {
      soma = mat[lin][col] + soma;
    }
    vet[lin] = soma;
    soma = 0;
  }

  for (lin = 0; lin < TAM; lin++) {
    cout << vet[lin] << "\t\n";
  }
  
  cout << endl;
  
  for (lin = 0; lin < TAM; lin++) {
    resulX = vet[lin] * resulX;
  }

  cout << "A Multiplicação das Somas das linhas é: " << resulX << endl;
}
