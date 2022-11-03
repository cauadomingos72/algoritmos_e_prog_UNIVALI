#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

void info(float &med, string &aluno)
{
  cout<<"Informe o nome do aluno:"<<endl;
  fflush(stdin);
  getline(cin, aluno);
  cout<<"Informe sua média:"<<endl;
  cin>>med;
  system("clear");
}

void suce(int &op)
{
  cout<<"Dado inserido com sucesso!"<<endl;
  cout<<endl;
  cout<<"Deseja abrir o arquivo?"<<endl;
  cout<<"0 - SIM         1 - NÃO"<<endl;
  cin>>op;
  system("clear");
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  float med;
  string aluno;
  int op, op2=1;

  info(med, aluno);
  ofstream escreve;
  escreve.open("notas.txt");
  escreve<<aluno<<endl;
  escreve<<med<<endl;
  escreve<<endl;
  escreve.close();
  fflush(stdin);
  suce(op);
  
  if(op==0)
  {
    ifstream leitura;
    leitura.open("notas.txt");
    cout<<"Aluno: "<<aluno<<endl;
    cout<<"Média: "<<med<<endl;
    leitura.close();
  } else {
    cout<<"Encerrando o programa...";
    op2 = 0; 
  }
}
