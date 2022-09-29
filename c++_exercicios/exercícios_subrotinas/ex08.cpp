/**
Faça uma função que solicita a idade de 10 pessoas e retorne a quantidade de pessoas que possui idade maior ou igual a 18 anos.
*/
#include <iostream>
#include <locale.h>
#define TAM 10

using namespace std;

int maior(int id[TAM]){
  int cont=0;
  for (int i=0; i<TAM;i++){
    if(id[i]>=18){
      cont++;
    }
  }
  return cont;
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  int id[TAM];

  for(int i=0;i<TAM;i++){
    cout<<"Digite a idade:"<<endl;
    cin>>id[i];
  }
  cout<<"O número de pessoas com 18 anos ou mais é de: "<<maior(id)<<endl;
}
