/**
Crie uma função para fazer a leitura das notas de 10 alunos e adicioná-las no vetor. Crie
uma função para calcular a média das notas de 10 alunos de uma disciplina e em outra função
verifique o número de alunos que tiveram nota superior à média calculada. Exiba a quantidade
de alunos com nota superior à média no main.
*/
#include <iostream>
#include <locale.h>
#define TAM 10

using namespace std;

float med(float nt[TAM]){
  float soma=0;
  for(int i=0;i<TAM;i++){
    soma=soma+nt[i];
  }
  return soma/TAM;
}

float sup(float med, float nt[TAM]){
  int cont=0;
  for(int i=0;i<TAM;i++){
    if(nt[i]>med){
      cont++;
    }
  }
  return cont;
}

int main() {
  setlocale (LC_ALL, "Portuguese");
  float nt[TAM],media;

  for(int i=0;i<TAM;i++){
    cout<<"Insira a nota do "<<i+1<<"° aluno:"<<endl;
    cin>>nt[i];
  }

  media=med(nt);
  cout<<"Média dos alunos é de: "<<media<<endl;
  cout<<"A quantidade de alunos acima da média é de: "<<sup(media,nt)<<endl;
}
