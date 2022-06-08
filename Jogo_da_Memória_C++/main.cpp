#include <iostream>
#include <locale.h>
#include <time.h>
#define TAM 4

using namespace std;

int main() {
  srand(time(NULL));
  int matP[TAM][TAM], matT[TAM][TAM], matIL[TAM][TAM], matIC[TAM][TAM], lin, col;

  matP[0][0]=1;
  matP[0][1]=4;
  matP[0][2]=5;
  matP[0][3]=2;
  matP[1][0]=7;
  matP[1][1]=2;
  matP[1][2]=8;
  matP[1][3]=7;
  matP[2][0]=3;
  matP[2][1]=6;
  matP[2][2]=1;
  matP[2][3]=4;
  matP[3][0]=6;
  matP[3][1]=5;
  matP[3][2]=3;
  matP[3][3]=8;

  for (lin=0;lin<TAM;lin++){
        for (col=0;col<TAM;col++){
            cout << matP[lin][col] << "\t";
        }
        cout << endl;
    }
}
