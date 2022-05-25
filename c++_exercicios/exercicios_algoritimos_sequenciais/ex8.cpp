#include <iostream>

using namespace std;

int main() {
  float not1, not2, not3, medF;

  cout << "Digite a nota da sua Prova 1" << endl;
  cin >> not1;

  cout << "Agora digite a nota da sua Prova 2" << endl;
  cin >> not2;

  cout << "Por fim digite a nota da sua Prova 3" << endl;
  cin >> not3;

  not1 = not1 * 2;
  not2 = not2 * 4;
  not3 = not3 * 6;
  medF = (not1 + not2 + not3)/12;

  if (medF >= 7) {
    cout << "Parabéns, você está Aprovado" << endl;
    cout << "Sua média foi de: " << medF << endl;
    return 0;
  }
  if (medF < 7) {
    cout << "Infelizmente você está reprovado" << endl;
    cout << "Sua média foi de: " << medF << endl;
    return 0;
  }
}
