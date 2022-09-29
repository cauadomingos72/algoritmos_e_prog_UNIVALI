/**
Faça uma função que recebe, por parâmetro, a altura e o sexo de uma pessoa e retorna o seu peso ideal. Para os homens, calcular o peso ideal usando a fórmula PI = 72,7 * altura – 58, e para as mulheres PI = 62,1 * altura – 44,7. 
*/
#include <iostream>
#include <locale.h>

using namespace std;

float pesM(float alt){
  return 72.7 * alt - 58;
}

float pesF(float alt){
  return 62.1 * alt - 44.7;
}

int main() {
  setlocale (LC_ALL,"Portuguese");

  float alt;
  char id;

  cout<<"Digite sua altura e seu sexo (M - MASCULINO // F - FEMININO), respectivamente:"<<endl;
  cin>>alt>>id;

  if(id=='m'||id=='M'){
    cout<<"O seu peso ideial é de: "<<pesM(alt)<<endl;
  } else if (id=='f'||id=='F'){
    cout<<"O seu peso ideial é de: "<<pesF(alt)<<endl;
  } else {
    cout<<"Digite um sexo válido"<<endl;
  }
}
