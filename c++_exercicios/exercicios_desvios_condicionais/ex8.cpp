#include <iostream>

using namespace std;

int main() {
  
  int numA, numB, numC;

  cout << "Digite três números reais:" << endl;
  cin >> numA >> numB >> numC;

  if ((numA < numB) && (numA < numC)) {

    cout << "O menor número é " << numA << endl;
    
  } else if ((numB < numA) && (numB < numC)) {

    cout << "O menor número é " << numB << endl;
    
  } else {

    cout << "O menor número é " << numC << endl;
    
  } 

  return 0;
  
}
