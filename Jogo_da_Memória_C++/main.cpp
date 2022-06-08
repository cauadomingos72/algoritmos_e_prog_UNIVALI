/** 
  Já implementado:

  O que falta:
    -> Criar a matriz transposta
    -> Criar a matriz invertida por linha
    -> Criar a matriz invertida por coluna
    -> Criar um seletor da matriz gabarito
    ->

*/

#include <iostream>
#include <locale.h>
#include <time.h>
#define TAM 4

using namespace std;

int main() {
  srand(time(NULL));
  int matP[TAM][TAM] {1,4,5,2,7,2,8,7,3,6,1,4,6,5,3,8} , matT[TAM][TAM]{}, matIL[TAM][TAM] {}, matIC[TAM][TAM] {}, lin, col, numero_rand;

  numero_rand = rand()%3+1; //Gerar um numero aleatorio que será usado para estabelecer qual será a matriz gabarito 
  cout<< numero_rand<<endl;
  cout << endl;
  
  switch(numero_rand) //Será selecionado qual será a matriz gabarito de acordo com o numero gerado aleatoriamente

  case 1:  //No caso 1, a matriz gabarito será uma copia da matriz principal
  matP[TAM][TAM];
  break;

  case 2: //No caso 2, a matriz gabarito será uma matriz transposta
  matT[TAM][TAM];
  break;

  case 3: //No caso 3, a matriz gabarito será uma matriz inversa por linha
  matIL[TAM][TAM];
  break;

  case 4: //No caso 4, a matriz gabarito será uma matriz inversa por coluna
  matIC[TAM][TAM];
  break;

    // Gerando a Matriz Transposta:
    for(lin=0;lin<TAM;lin++) {    
      for(col=0;col<TAM;col++) {
        matT[lin][col] = matP[col][lin];
      }
    }

    // Gerando a Matriz Invertida por Linha:
    for(lin=0;lin<TAM;lin++) {    
      for(col=0;col<TAM;col++) {
        matIL[lin][col] = matP[lin][col];
      }
    }

    
    for (lin=0;lin<TAM;lin++) {    // Exibindo a matriz principal [remover no final]
        for (col=0;col<TAM;col++){
            cout << matP[lin][col] << "\t";
        }
        cout << endl;
    }

    cout<<endl;

    for (lin=0;lin<TAM;lin++) {   // Exibindo a matriz transposta [remover no final]
        for (col=0;col<TAM;col++){
            cout << matT[lin][col] << "\t";
        }
        cout << endl;
    }

    cout << endl;

   for (lin=0;lin<TAM;lin++) {    // Exibindo a matriz invertida por linha [remover no final]
        for (col=0;col<TAM;col++){
            cout << matIL[lin][col] << "\t";
        }
        cout << endl;
    } 
}
