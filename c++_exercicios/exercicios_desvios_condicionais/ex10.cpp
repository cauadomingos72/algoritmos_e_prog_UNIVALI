#include <iostream>

using namespace std;

int main() {

  float ladA, ladB, ladC, equI, isoS, escA;

  cout << "Digite os valores dos lados do triângulo" << endl;
  cin >> ladA >> ladB >> ladC;

  if (ladA == ladB && ladA == ladC && ladB == ladC) {

    cout << "O triângulo é equilátero" << endl;
    
  } else if (ladA == ladB && ladA != ladC || ladA == ladC && ladA != ladB || ladB == ladC & ladB != ladA){

    cout << "O triângulo é isósceles" << endl;
    
  } else {

    cout << "O triângulo é escaleno" << endl;
    
  }
  
  return 0;
  
}
