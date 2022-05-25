#include <iostream>

using namespace std;

int main() {
  int num1;

  cout << "Insira um número inteiro" << endl;
  cin >> num1;

  if (num1 %2 ==0) {
    cout << "O número " << num1 << " é par" << endl;
    return 0;
  } else {
    cout << "O número " << num1 << " é impar" << endl;
    return 0;
  }
}
