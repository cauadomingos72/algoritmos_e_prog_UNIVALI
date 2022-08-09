/**
Faça uma função que calcule E a partir da fórmula E = X/1 + X/2 + X/3 + ... + X/X, sendo X passado por parâmetro. No programa principal calcule o somatório dos valores de E. para o seguinte intervalo de valores de X: [5,15], ou seja, para cada valor de X, calcule o valor respectivo de E. Exiba o somatório ao final.
*/
#include <iostream>
#include <locale.h>

using namespace std;

float calc(){
  int static x=5;
  float e=0;
  for(int i=1;i<=x;i++){
    e=e+x/i;
  }
  x++;
  return e;
}

int main() {
  setlocale (LC_ALL,"Portuguese");

  float resE,somE=0;

  for(int i=0;i<10;i++){
    resE=calc();
    somE=resE+somE;
  }
   cout<<"A soma de (E) no intervalo de 5 à 15 é de: "<<somE<<endl;
}
