#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int* preencher(int TAM){
  int *temp = new int[TAM];
  for(int i=0;i<TAM; i++){
    temp[i] = rand()%(TAM*TAM)+1;
  }
  return temp;
}

float med (int *a, int TAM)
{
  float soma=0;
  for(int i=0;i<TAM;i++)
    soma+=a[i];
  
  return float (soma/TAM);
}

int maior(int *a, int TAM)
{
  int maior;
  for(int i=0;i<TAM;i++)
  {
    if(i==0)
      maior=a[i];
    if(maior<a[i])
      maior=a[i];
  }
  return maior;
}

int menor(int *a, int TAM)
{
  int menor;
  for(int i=0;i<TAM;i++)
  {
    if(i==0)
      menor=a[i];
    if(menor>a[i])
      menor=a[i];
  }
  return menor;
}

int main() {
  srand(time(NULL));
  setlocale(LC_ALL,"Portuguese");
  
  int TAM, *a; 

  cout<<"Tamanho do Vetor: ";
  fflush(stdin);
  cin>>TAM;
  fflush(stdin);
  system("clear");

  a = preencher(TAM);

  cout<<"Vetor Gerado:"<<endl;
  for(int i=0;i<TAM;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<"Média: "<<med(a, TAM)<<endl;
  cout<<"Maior: "<<maior(a,TAM)<<endl;
  cout<<"Menor: "<<menor(a,TAM)<<endl;

  delete []a;

  return 0;
}
