// Faça um programa que solicita ao usuário o valor de N e calcule o valor de S na série S = 1/1 + 1/2 + 1/3 + ... + 1/N. Ao fim exiba o número real resultante da série.

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  float cont, valN, resul, div1;

  div1 = 1;
  cont = 1;

  cout << "Digite um valor:" << endl;
  cin >> valN;

  while (cont <= valN) {

    resul = resul + 1 / div1;
    div1 = div1 + 1;
    cont++;
    
  }
  
  cout << "O Resultado da Operação é: " << resul << endl;

  return 0;
  
}
