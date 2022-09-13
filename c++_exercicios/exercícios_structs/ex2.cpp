#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 3

using namespace std;

struct Dados
{
  string nome;
  float altura, peso;
  long int cpf;
};

void imc(long int pesquisar, Dados pessoa[TAM])
{
  float imc;
  for(int i=0;i<TAM;i++)
  {
    if(pessoa[i].cpf==pesquisar)
      imc=pessoa[i].peso/(pessoa[i].altura*pessoa[i].altura);
  }
  
  cout<<"O IMC do CPF "<<pesquisar<<" é de:"<<endl;
  cout<<imc;
}

int main() 
{
  setlocale(LC_ALL,"Portuguese");

  Dados pessoa[TAM]; 
  long int pesquisar;

  for(int i=0;i<TAM;i++)
  {
    cout<<"Insira o nome da pessoa:"<<endl;
    cin>>pessoa[i].nome;
    
    cout<<"Insira a altura e peso:"<<endl;
    cin>>pessoa[i].altura>>pessoa[i].peso;
    
    cout<<"Digite o CPF:"<<endl;
    cin>>pessoa[i].cpf;
    
    cout<<endl;
  }
  
  cout<<"Insira o CPF da pessoa desejada:"<<endl;
  cin>>pesquisar;
  cout<<endl;

  system("clear");
  
  imc(pesquisar, pessoa);
}
