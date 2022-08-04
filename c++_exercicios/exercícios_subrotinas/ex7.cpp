/**
Faça um procedimento que gere e exiba os 20 primeiros termos da série de Fibonacci (Os dois primeiros termos da série são 1 e 1, os termos subsequentes são a soma dos dois últimos. Observe o exemplo: 1,1,2,3,5,8,13,21,..)
*/
#include <iostream>
#include <locale.h>

using namespace std;

void serie(){
  int val1=1, soma=0,res, i;
  cout<<"1"<<endl;
  for(i=0;i<19;i++){
    res= val1 + soma;
    soma=val1;
    val1=res;
    cout<<res<<endl;
  }
}

int main() {
  setlocale (LC_ALL, "Portuguese");

  serie();

  return 0;
}
