// Faça um programa que gere e exiba os 20 primeiros termos da série de Fibonacci (Os dois primeiros termos da série são 1 e 1, os termos subsequentes são a soma dos dois últimos. Observe o exemplo: 1,1,2,3,5,8,13,21,..)

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int cont, digT, ultD, novD;

  ultD = 1;
  digT = 0;
  cont = 1;

  cout << "1" << endl;
  
  while (cont <= 19) {
    
    novD = ultD + digT;
    digT = ultD;
    ultD = novD;
    cout << novD << endl; 
    cont++;
    
  }

  return 0;
  
}
