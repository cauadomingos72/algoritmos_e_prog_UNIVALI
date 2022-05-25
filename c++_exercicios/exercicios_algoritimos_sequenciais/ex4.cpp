#include <iostream>

using namespace std;

int main() {
  cout << "Bem-vindo ao Importados SC" << endl;

  float valorP, resultado;

  cout << "Digite o Valor do Produto:" << endl;
  cin >> valorP;

  resultado = valorP * 1.15;

  cout << "O Valor a ser Pago é: R$" << resultado << endl;

  return 0;
}
