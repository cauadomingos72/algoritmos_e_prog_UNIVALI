#include <iostream>

using namespace std;

int main() {
  char letraD;
  
  cout << "Digite uma Letra" << endl;
  cin >> letraD;

  if (letraD == 'a' || letraD == 'e' || letraD == 'i' || letraD == 'o' || letraD == 'u') {
    
    cout << "É uma vogal" << endl;
    
    } else {
      cout << "Não é uma vogal" << endl;
    return 0;
    }
  }
