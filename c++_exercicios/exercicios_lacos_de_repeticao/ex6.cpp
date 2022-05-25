// Faça um programa que solicita ao usuário dois valores inteiros e positivos que serão a base e o expoente. O programa deve usar laço de repetição para calcular e escrever o resultado da base elevado ao expoente (potencia).

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int numD, numE, cont, resu;

  cont = 1;
  resu = 0;

  cout << "Digite um valor positivo e inteiro para a base e o expoente respectivamente:" << endl;
  cin >> numD >> numE;

  resu = numD;

  if (numE == 0){

    resu = 1;
      
  } else if (numD < 0 || numE < 0) {

    cout << "Você não digitou um valor negativo, digite novamente" << endl;
    return 0;
    } else {
    while (cont < numE) {

      resu = numD * resu;
      cont++;
    
    }
  }
  
  cout << "Resultado = " << resu << endl;

  return 0;
  
}
