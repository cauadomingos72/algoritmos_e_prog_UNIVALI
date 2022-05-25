#include <iostream>

using namespace std;

int main() {

  int horas, min;

  cout << "Entre com um número para horas:" << endl;
  cin >> horas;

  cout << "Entre com um número para minutos" << endl;
  cin >> min;

  if ((0 <= horas <= 24) && (0 <= min <= 59)) {

    cout << "A hora é válida" << endl;

  } else {

    cout << "A hora é inválida" << endl;
    
  } 
}
