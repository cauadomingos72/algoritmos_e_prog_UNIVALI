#include <iostream>
#include <locale.h>

using namespace std;

int idade(int a, int b, int c, int x, int y, int z) {
  int idade;
  if ((a==x&&b==y)||(y>b)||(x>a&&y==b)||(x>a&&y>b)){
    idade = z - c;
    return (idade);
  } else {
    idade = (z - c) - 1;
    return (idade);
  }
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  int dia, mes, ano, diaA, mesA, anoA;

  cout<<"Digite sua data de nascimento (DD/MM/AAAA)"<<endl;
  cin>>dia>>mes>>ano;

  cout<<"Digite a data atual (DD/MM/AAAA)"<<endl;
  cin>>diaA>>mesA>>anoA;

  cout<<"Sua idade atual é: "<<idade(dia,mes,ano,diaA,mesA,anoA)<<" anos"<< endl;
}
