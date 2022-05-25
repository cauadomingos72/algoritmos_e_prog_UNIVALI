#include <iostream>

using namespace std;

int main() {
  float nC, nF, resultado;
  
  nF = 4;

  cout << "Digite a Quantidade de Cavalos:" << endl;
  cin >> nC;

  resultado = nC * nF;

  cout << "Você irá precisar de " << resultado << " ferraduras" << endl;
  return 0;
}
