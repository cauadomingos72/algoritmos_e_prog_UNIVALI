/**
Faça uma função que recebe, por parâmetro, um valor N inteiro e positivo e retorna verdadeiro se N for um número perfeito e falso em caso contrário. Obs.: número perfeito é aquele que é igual a soma de seus divisores. 
*/
#include <iostream>
#include <locale.h>

using namespace std;

int verf(int a){
  int num,som=0,res;
  for (int i=1;i<=a;i++){
    if(a%i==0){
      num=i;
      som=som+i;
    }
    if(som==a){
      res=1;
      i=a;
    } else if (som!=a && i==a){
      res=0;
    }
  }
  return res;
}

int main() {
  setlocale (LC_ALL,"Portuguese");

  int num, res;

  cout<<"Digite um valor inteiro e positivo:"<<endl;
  cin>>num;

  res=verf(num);

  if(res==1){
    cout<<"O número é perfeito!"<<endl;
  } else {
    cout<<"O número não é perfeito!"<<endl;
  }
  return 0;
}
