// Faça um programa que exiba na tela os números inteiros de 50 até 200

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int numC;

  for (numC = 50; numC <= 200; numC++) {

    cout << numC << endl;
    
  }

  return 0;
  
}
