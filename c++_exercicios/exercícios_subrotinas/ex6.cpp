#include <iostream>
#include <locale.h>

using namespace std;

void rep(int &num, int &num1){
  do{
    cout<<"Digite um valor positivo:"<<endl;
    cin>>num>>num1;
  }while(num<0||num1<0);
}

int pot(int a, int b){
  return a * b;
}

int main() {
  setlocale (LC_ALL, "Portuguese");

  int num, num1, res=1;

  cout<<"Digite um valor inteiro positivo para a base e o expoente, respectivamente"<<endl;
  cin>>num>>num1;

  if (num<0||num1<0){
    rep(num,num1);
  }
  
  for(int i=0; i<num1; i++){
    res = pot(num, res); 
    cout<<res<<endl;
  }

  return 0;
}
