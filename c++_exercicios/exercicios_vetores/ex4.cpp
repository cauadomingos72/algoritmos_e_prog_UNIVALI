////////////////////////////////////////////////////////////////////
// Declare um vetor de 10 inteiros, leia um valor para cada posição e no final mostre os elementos deste vetor em posição inversa ao que foram atribuídos.
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <locale.h>

#define TAM 10

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int num[TAM];
  int i;

  cout << "---------------------------------------------" << endl;
  
  for (i=0; i < TAM; i++) {
    cout << "Digite um valor:" << endl;
    cin >> num[i];
  }
  
  cout << "---------------------------------------------" << endl;
  
  for (i=9; i > -1; i--) {
    cout << num[i] << endl;
  }

  return 0;
  
}
