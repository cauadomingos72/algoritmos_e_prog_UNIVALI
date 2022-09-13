#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#define TAM 5

using namespace std;

struct Lista
{
  long int codigo;
  string nome;
  int cadastrado;
};

int main() {
  setlocale(LC_ALL,"Portuguese");

  Lista produtos[TAM]{};
  long int pesquisa;
  int run=0;
  char finalizar;

  cout<<"Deseja cadastrar um novo produto ou pesquisar um determinado produto?"<<endl;
  cout<<"[c] Cadastrar \t\t\t\t [p] Pesquisar"<<endl;
  cin>>finalizar;
  if(finalizar=='c' || finalizar=='C')
  {
    do
    {
      system("clear");
      for(int i=0;i<TAM;i++)
      {
        if(produtos[i].cadastrado==1)
        {
          system("clear");
          i++;
        }
        
        cout<<"CADASTRO DE PRODUTOS"<<endl;
        cout<<endl;
        
        cout<<"Insira o NOME e o CÓDIGO"<<endl;
        cin>>produtos[i].nome>>produtos[i].codigo;
        system("clear");
        
        cout<<"Deseja cadastrar outro produto?"<<endl;
        cout<<"[s] SIM\t\t\t\t[n] Não"<<endl;
        cin>>finalizar;
        
        if(finalizar=='n' || finalizar=='N'){
          system("clear");
          run=0;
          i=TAM;
        }
        system("clear");
      }
    } while (run==1);
  }
  system("clear");
    
  cout<<"Digite o código do produto:"<<endl;
  cin>>pesquisa;
  cout<<endl;
    
  for(int i=0;i<TAM;i++)
  {
    if(pesquisa==produtos[i].codigo)
    {
      cout<<"O produto de código "<<pesquisa<<" é: "<<produtos[i].nome;
      break;
    }
  }
}
