#include <iostream>
#include <stdio.h>
#include <locale.h>
#define TAM 3

using namespace std;

struct Cadastro 
{
  int codigo;
  string nome;
  float notas[TAM];
};

float media(float nota[TAM])
{
  float soma;
  for(int i=0;i<TAM;i++)
  {
    soma+=nota[i];
  }
  return float (soma/TAM);
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  Cadastro aluno;

  cout<<"Insira o CÓDIGO do Aluno:"<<endl;
  cin>>aluno.codigo;
  fflush(stdin);
  cout<<endl;
  cout<<"Insira o NOME do Aluno"<<endl;
  cin>>aluno.nome;
  cout<<endl;
  for(int i=0;i<TAM;i++)
  {
    cout<<"Insira a "<<i+1<<"° nota do aluno:"<<endl;
    cin>>aluno.notas[i];
    cout<<endl;
  }

  cout<<"_______________________________________________"<<endl;

  cout<<"Código do Aluno: "<<aluno.codigo<<endl;
  cout<<"Nome do Aluno: "<<aluno.nome<<endl;
  cout<<"Média do Aluno: "<<media(aluno.notas)<<endl;
}
