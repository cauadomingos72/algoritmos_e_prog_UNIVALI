/**
Faça uma função que recebe três números reais por parâmetro e retorne o menor deles. 
*/
#include <iostream>
#include <locale.h>

using namespace std;

float verf(float a){
  float num, menor=0;
  for(int i=0;i<3;i++){
    cout<<"Digite um valor qualquer:"<<endl;
    cin>>num;
    if(menor==0){
      menor=num;
    }
    if(menor>num){
      menor=num;
    }
  }
  return menor;
}

int main() {
  setlocale (LC_ALL,"Portuguese");

  float num,res;

  res = verf(num);
  
  cout<<"O menor número digitado é: "<<res<<endl;
}
