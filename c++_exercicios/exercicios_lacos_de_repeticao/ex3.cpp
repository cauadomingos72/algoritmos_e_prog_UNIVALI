// Faça um programa que exiba na tela os números inteiros de 100 até 1

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int numC;

  numC = 100;

  while (numC >= 1) {

    cout << numC << endl;

    numC = numC - 1;
    
  }

  return 0;
  
}
