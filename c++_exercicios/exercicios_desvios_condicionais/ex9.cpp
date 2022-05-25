#include <iostream>

using namespace std;

int main() {
  
  string nome;
  float notA, notB, notC, medF;

  cout << "Digite seu nome:" << endl;
  cin >> nome;

  cout << "Digite as notas a seguir:" << endl;
  cin >> notA >> notB >> notC;

  medF = (notA + notB + notC)/3;

  if (medF >= 6) {

    cout << "Parabéns " << nome << " você foi APROVADO" << endl;
    cout << "Sua média foi de: " << medF << endl;
    
  } else {

    cout << "Infelizmente você foi reprovado " << nome << endl;
    cout << "Sua média foi de: " << medF << endl;
    
  }

  return 0;
  
}
