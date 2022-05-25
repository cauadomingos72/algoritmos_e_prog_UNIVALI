// Faça um programa que solicita a idade de 10 pessoas e exiba a quantidade de pessoas que possui idade maior ou igual a 18 anos.

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale(LC_ALL, "Portuguese");

  int pesI, qtd, numP;

  qtd = 0;

  for (numP = 1; numP <= 10; numP++) {

    cout << "Digite a idade da " << numP << "° pessoa:" << endl;
    cin >> pesI;

    if (pesI >= 18)
      qtd++;
    
  }

  cout << "O número de pessoas maiores ou iguais a 18 é igual a: " << endl;
  cout << qtd << endl;

  return 0;
}
