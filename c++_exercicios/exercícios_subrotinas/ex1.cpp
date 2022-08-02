#include <iostream>
#include <locale.h>

using namespace std;

void leitura(int a) {
  if (a == 1) {
    cout<<"O valor é positivo!"<<endl;
  } else { 
    cout<<"O valor é negativo!"<<endl;
  }
}


int numero(int a) {
  if (a>=0) {
    a = 1;
    return (a);
  } else if (a<0) {
    a = 0;
    return (a);
  }
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  int num, ver;

  cout<<"Digite um número inteiro qualquer:" << endl;
  cin>>num;

  ver = numero(num);

  leitura(ver);
  return 0;
}
