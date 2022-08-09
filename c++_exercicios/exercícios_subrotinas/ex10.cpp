/**
Faça uma função/procedimento que solicita o peso de 25 pessoas e atribui o maior e o menor peso dentre os digitados. Exiba o maior e o menor peso no programa principal.
*/
#include <iostream>
#include <locale.h>

using namespace std;

int maior=0,menor=0;

void pes(int &peso){
  cout<<"Digite o peso da pessoa:"<<endl;
  cin>>peso;  
}

int verfMai(int peso){
  if(peso>maior){
    maior=peso;
  }
  return maior;
}
int verfMen(int peso){
  if(menor==0){
    menor=peso;
  }
  if (peso<menor){
    menor=peso;
  }
  return menor;
}

int main() {
  setlocale (LC_ALL,"Portuguese");

  int peso, maior, menor;
  for(int i=25;i>0;i--){
    pes(peso);
    maior=verfMai(peso);
    menor=verfMen(peso);
  }
  cout<<"Maior: "<<maior<<"  Menor: "<<menor<<endl;
}
