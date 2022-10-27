#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void leitura (float &nA,float &nB, float &tA, float &tB)
{
  cout<<""<<endl;
  fflush(stdin);
  cout<<"Insira o número da população atual do país A e B respectivamente:"<<endl;
  cin>>nA>>nB;
  fflush(stdin);
  cout<<"Insira a taxa de crescimento do país A e B:"<<endl;
  cin>>tA>>tB;
  system("clear");
}

void fim (int &op)
{
  cout<<"Deseja calcular novamente?"<<endl;
  cout<<"1 - SIM         0 - NÃO"<<endl;
  fflush(stdin);
  cin>>op;
  system("clear");
}

int calcA(int nA,int nB, int tA, int tB)
{
  if(nA>nB)
    return 0;
  return 1 + calcA(nA + nA*(tA/100), nB + nB*(tB/100), tA, tB);
}

int calcB(float nA,float nB, float tA, float tB)
{
  if(nB>nA)
    return 0;
  return 1 + calcB(nA + nA*(tA/100), nB + nB*(tB/100), tA, tB);
}

int main() {
  setlocale(LC_ALL,"Portuguese");
  int op;
  float nA,nB,tA,tB;

  do
  {
    leitura(nA,nB,tA,tB);
    if(nA<nB && tA>tB)
      cout<<"Anos: "<<calcA(nA,nB,tA,tB)<<endl;
    else if (nB<nA && tB>tA)
    {
      calcB(nA,nB,tA,tB);
      cout<<"Anos: "<<calcB(nA,nB,tA,tB)<<endl;
    }
    else
    {
      if(nA<nB)
        cout<<"O País A não conseguirá ultrapassar o B."<<endl;
      else
        cout<<"O País B não conseguirá ultrapassar o A."<<endl;
    }
    fim(op);
  } while (op!=0); 
}
