#include <iostream>
#include <locate.h>

using namespace std;

int main() {
  float numA, numB;

  cout << "Digite dois números:" << endl;
  cin >> numA >> numB;

  if (numA == numB) {

    cout << "Os números são iguais" << endl;
    
  } else if (numA > numB) {

    cout << "O número " << numA << " é o maior" << endl;
    
  } else {

    cout << "O número " << numB << " é o maior" << endl;
  }
  
  return 0;
  
}
