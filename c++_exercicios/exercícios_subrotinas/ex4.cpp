#include <iostream>
#include <locale.h>

using namespace std;

void esc(int a){
  if (a==0){
    cout<<"Ele é igual a zero"<<endl;
  } else if (a>0){
    cout<<"Ele é positivo"<<endl;
  } else {
    cout<<"Ele é negativo"<<endl;
  }
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  
  int num;

  cout<<"Digite um número inteiro:"<<endl;
  cin>>num;

  esc(num);

  return 0;
}
