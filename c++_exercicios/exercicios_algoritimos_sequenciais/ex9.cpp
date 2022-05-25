#include <iostream>

using namespace std;

int main() {
  float sa1, conA, conB, resulF;

  cout << "Digite o Valor do seu Salário" << endl;
  cin >> sa1;

  cout << "Digite os Valores das suas Contas" << endl;
  cin >> conA >> conB;
  
  conA = conA + 0.02 * conA;
  conB = conB + 0.02 * conB;
  sa1 = sa1 - (conA + conB);

  cout << "Você possuí R$" << sa1 << "restantes do seu salário" << endl;
  return 0;
}
