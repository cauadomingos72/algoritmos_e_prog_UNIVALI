/** 
  Já implementado:
  -> Matriz transposta
  -> Seletor da matriz gabarito

  O que falta:
    -> Criar a matriz invertida por linha
    -> Criar a matriz invertida por coluna

*/

#include <iostream>
#include <locale.h>
#include <time.h>
#define TAM 4

using namespace std;

int main() {
  srand(time(NULL));
  int matP[TAM][TAM] {1,4,5,2,7,2,8,7,3,6,1,4,6,5,3,8},matT[TAM][TAM]{1,7,3,6,4,2,6,5,5,8,1,3,2,7,4,8},matIL[TAM][TAM] {6,5,3,8,3,6,1,4,7,2,8,7,1,4,5,2},matIC[TAM][TAM] {2,5,4,1,7,8,2,7,4,1,6,3,8,3,5,6},matJ[TAM][TAM]{},lin,col,k,numero_rand, rodadas=24,val1=0, val2=0;

  numero_rand = rand()%4+1; //Gerar um numero aleatorio que será usado para estabelecer qual será a matriz gabarito 
  cout<< numero_rand<<endl;
  cout << endl;
  
  switch(numero_rand) {//Será selecionado qual será a matriz gabarito de acordo com o numero gerado aleatoriamente

  case 1:  //No caso 1, a matriz gabarito será uma copia da matriz principal
    
    for (lin=0;lin<TAM;lin++) {    
      for (col=0;col<TAM;col++){
        cout << matJ[lin][col] << "\t";
      }
    
      cout << endl;
    
    } 

    cout << endl;

    cout << "Digite a posição da linha e da coluna, respectivamente, do primeiro valor" << endl;
    cin >> lin >> col;
    val1=matP[lin-1][col-1];
    lin=0;
    col=0;

    cout<< endl;
    
    cout << "Digite a posição da linha e da coluna, respectivamente, do segundo valor" << endl;
    cin >> lin >> col;
    val2=matP[lin-1][col-1];
    lin=0;
    col=0;
    
  break;

  case 2: //No caso 2, a matriz gabarito será uma matriz transposta
  // Gerando a Matriz Transposta:
    
    for (lin=0;lin<TAM;lin++) {    
      for (col=0;col<TAM;col++){
        cout << matJ[lin][col] << "\t";
      }
    
      cout << endl;
    
    } 

    cout << endl;

    cout << "Digite a posição da linha e da coluna, respectivamente, do primeiro valor" << endl;
    cin >> lin >> col;
    val1=matT[lin-1][col-1];
    lin=0;
    col=0;
    
    cout<< endl;
    
    cout << "Digite a posição da linha e da coluna, respectivamente, do segundo valor" << endl;
    cin >> lin >> col;
    val2=matT[lin-1][col-1];
    lin=0;
    col=0;
    
  break;

  case 3: //No caso 3, a matriz gabarito será uma matriz inversa por linha
    
    for (lin=0;lin<TAM;lin++) {    
      for (col=0;col<TAM;col++){
        cout << matJ[lin][col] << "\t";
      }
      
      cout << endl;
      
    } 

    cout << endl;
    
    cout << "Digite a posição da linha e da coluna, respectivamente, do primeiro valor" << endl;
    cin >> lin >> col;
    val1=matIL[lin-1][col-1];
    lin=0;
    col=0;
    
    cout<< endl;
    
    cout << "Digite a posição da linha e da coluna, respectivamente, do segundo valor" << endl;
    cin >> lin >> col;
    val2=matIL[lin-1][col-1];
    lin=0;
    col=0;

  break;

  case 4: //No caso 4, a matriz gabarito será uma matriz inversa por coluna

    for (lin=0;lin<TAM;lin++) {    
      for (col=0;col<TAM;col++){
        cout << matJ[lin][col] << "\t";
      }
      
      cout << endl;
      
    }

    cout << endl;

    cout << "Digite a posição da linha e da coluna, respectivamente, do primeiro valor" << endl;
    cin >> lin >> col;
    val1=matT[lin-1][col-1];
    lin=0;
    col=0;
    
    cout<< endl;
    
    cout << "Digite a posição da linha e da coluna, respectivamente, do segundo valor" << endl;
    cin >> lin >> col;
    val2=matT[lin-1][col-1];
    lin=0;
    col=0;
    
  break;

  }
    
}
