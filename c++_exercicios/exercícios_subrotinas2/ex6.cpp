/**
Faça uma função que gere e mostre os dez primeiros primos acima de 100. 
*/
#include <iostream>
#include <locale.h>

using namespace std;

int primo(){
  int static num=100;
  int pr=0, res=0;
  for(int i=1;i<=num;i++){
    if(num%i==0){
      pr++;
    }
    if(pr==2 && i==num){
      res=num;
    }
  }
  num++;
  return res;
}

int main() {
  setlocale (LC_ALL,"Portuguese");
  for(int i=0;i<10;i++){
    if(primo()==0){
      cout<<primo()<<endl;
    } else {
      i--;
    }
  }
  return 0;
}
