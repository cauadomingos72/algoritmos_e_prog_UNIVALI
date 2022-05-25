#include <iostream>

using namespace std;

int main() {
  float distP, consL, preC, resulD;

  preC = 6;

  cout << "Digite a Distância na qual você irá Percorrer" << endl;
  cin >> distP;

  cout << "Agora Digite o Consumo (KM/Litro) do seu Carro" << endl;
  cin >> consL;

  resulD = preC * (distP / consL);

  cout << "O Valor que você irá gastar de Gasolina na Viagem será de: R$" << resulD << endl;

  return 0;
}
