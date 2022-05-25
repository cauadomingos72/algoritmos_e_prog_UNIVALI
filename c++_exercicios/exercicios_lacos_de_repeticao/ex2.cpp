// Faça um programa que exiba na tela a tabuada do número 5 no seguinte formato: 5X1=5; 5X2=10; 5X3=15; ... ; 5X10=50

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int numM, resT;

  numM = 1;

  cout << "--------------------------------------" << endl;
  cout << "TABUADA DO 5" << endl;
  cout << "--------------------------------------" << endl;

  while (numM <= 10) {

    resT = 5 * numM;

    cout << "5 X " << numM << " = " << resT << endl;

    numM = numM + 1;
    
  }

  return 0;
  
}
