/**
Faça uma função que recebe um número inteiro por parâmetro, calcule e retorne o fatorial deste número.
*/
#include <iostream>
#include <locale.h>

using namespace std;

int fat(int a){
  int res=1;
  for (int i=1;i<=a;i++){
    res=res*i;
  }
  return res;
}

int main() {
  setlocale (LC_ALL, "Portuguese");

  int num;

  cout<<"Digite um número inteiro:"<<endl;
  cin>>num;

  cout<<"O Fatorial do número "<<num<<" é "<<fat(num)<<endl;

  return 0;
  
}
