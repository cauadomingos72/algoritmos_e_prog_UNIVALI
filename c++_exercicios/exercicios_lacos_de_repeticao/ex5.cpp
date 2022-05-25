// Faça um programa que exiba na tela a soma dos números inteiros do intervalo [100, 200].
// Exemplo: soma = 100 + 101 +102 + ... + 200

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  long int cont, resT, numC;

  numC = 100;
  resT = 0;
  cont = 0;

  while (cont <= 100) {

    resT = resT + numC;
    numC++;
    cont++;
    
  }

  cout << "Resultado: " << resT << endl;

  return 0;
  
}
