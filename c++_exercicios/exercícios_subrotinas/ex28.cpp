/**
Faça uma função que solicita ao usuário 25 valores reais e armazene em uma matriz 5X5. A seguir em outra função troque todos os elementos da matriz que sejam maiores que 100 pelo valor de zero. Crie também uma função para exibir a matriz. No main exiba a matriz original e alterada.
*/
#include <iostream>
#include <locale.h>
#include <time.h>
#define TAM 5

using namespace std;

void preen(float mat[TAM][TAM]){
  int cont=1;
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      cout<<"Digite o "<<cont<<"° valor:"<<endl;
      cin>>mat[i][j];
    }
  }
}

void verif(float mat[TAM][TAM]){
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      if(mat[i][j]>100){
        mat[i][j]=0;
      }
    }
  }
}

int main() {
  setlocale (LC_ALL,"Portuguese");
  srand(time(NULL));

  float mat[TAM][TAM];

  preen(mat);

  //MATRIZ ORIGINAL
  cout<<"Matriz Original:"<<endl;
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
  }

  cout<<endl;
  cout<<endl;

  verif(mat);

  //MATRIZ ALTERADA
  cout<<"Matriz Alterada:"<<endl;
  for(int i=0;i<TAM;i++){
    for(int j=0;j<TAM;j++){
      cout<<mat[i][j]<<"\t";
    }
    cout<<endl;
  }

  return 0;
}
