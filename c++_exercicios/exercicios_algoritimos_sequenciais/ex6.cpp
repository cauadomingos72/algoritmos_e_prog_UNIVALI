#include <iostream>

using namespace std;

int main() {
  float num1, num2, numX;

  cout << "Digite um Valor para A" << endl;
  cin >> num1;

  cout << "Digite um Valor para B" << endl;
  cin >> num2;

  numX = num1;
  num1 = num2;
  num2 = numX;

  cout << "O Valor de A agora é: " << num1 << endl;

  cout << endl;

  cout << "O Valor de B agora é: " << num2 << endl;
  return 0;
}
