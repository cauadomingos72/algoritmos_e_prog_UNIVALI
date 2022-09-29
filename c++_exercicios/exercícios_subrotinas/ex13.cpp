/**
Faça o programa principal que solicita ao usuário um número inteiro N e após faça a chamada de um procedimento com o nome de “castigo”, passando N como parâmetro por valor. O procedimento deve imprimir N vezes a frase “Não vou colar na Prova”.
*/
#include <iostream>
#include <locale.h>

using namespace std;

void castigo(int n){
  for(int i=0;i<n;i++){
    cout<<"Não vou colar na Prova"<<endl;
  }
}

int main() {
  setlocale (LC_ALL,"Portuguese");
  
  int n;
  
  cout<<"Digite um valor inteiro e positivo: "<<endl;
  cin>>n;

  castigo(n);
}
