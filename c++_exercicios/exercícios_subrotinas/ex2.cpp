#include <iostream>
#include <locale.h>

using namespace std;

void ver (int a){
  a = a%2;
  if (a == 0){
    cout<<"O número é par!"<<endl;
  } else {
    cout<<"O número é ímpar!"<<endl;
  }
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  int num;

  cout<<"Digite um número inteiro:"<<endl;
  cin>>num;

  ver(num);

  return 0;
}
