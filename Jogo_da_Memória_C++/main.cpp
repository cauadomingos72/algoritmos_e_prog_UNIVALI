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
  int matP[TAM][TAM] {1,4,5,2,7,2,8,7,3,6,1,4,6,5,3,8} , matT[TAM][TAM]{}, matIL[TAM][TAM] {}, matIC[TAM][TAM] {}, lin, col;

    for(lin=0;lin<TAM;lin++) {
      for(col=0;col<TAM;col++) {
        matT[lin][col] = matP[col][lin];
      }
    }
    
    for (lin=0;lin<TAM;lin++){      // Exibindo a matriz principal [remover no final]
        for (col=0;col<TAM;col++){
            cout << matP[lin][col] << "\t";
        }
        cout << endl;
    }

    cout<<endl;

    for (lin=0;lin<TAM;lin++){      // Exibindo a matriz transposta [remover no final]
        for (col=0;col<TAM;col++){
            cout << matT[lin][col] << "\t";
        }
        cout << endl;
    }
}
