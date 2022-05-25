#include <iostream>

using namespace std;

int main() {
  cout << "Loja Friboi Online" << endl;

  float kgQ, kgV, valorPago;
  
  kgV = 6.5;

  cout << "Digite a Quantidade em KG que Deseja:" << endl;
  cin >> kgQ;

  valorPago = kgQ * kgV;

  cout << "O Valor a ser pago será: R$" << valorPago << endl;

  return 0;
}
