#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <typename tipo>
struct fracao
{
  tipo numerador, denominador;
};

template <typename tipo>
void leitura (fracao<tipo> &num1, fracao<tipo> &num2)
{
  cout<<"Insira um valor para o numerador e denominador [1]:"<<endl;
  cin>>num1.numerador;
  cin>>num1.denominador;
  cout<<endl;
  
  cout<<"Insira um valor para o numerador e denominador [2]:"<<endl;
  cin>>num2.numerador;
  cin>>num2.denominador;
  cout<<endl;
}

template <typename tipo>
void resultado (fracao<tipo> res)
{
  cout<< res.numerador << endl;
  cout<< "--" << endl;
  cout<< res.denominador << endl;
}

template <typename tipo>
fracao<tipo> operator+ (fracao<tipo> num1, fracao<tipo> num2)
{
  fracao<tipo> res;
  if(num1.denominador == num2.denominador)
  {
    num1.numerador+=num2.numerador;
    res.numerador = num1.numerador;
    res.denominador = num1.denominador;
    return res;
  } 
  else
  {
    int temp;
    num1.numerador *= num2.denominador;
    num2.numerador *= num1.denominador;
    num1.denominador *= num2.denominador;
    num1.numerador+=num2.numerador;
    res.numerador = num1.numerador;
    res.denominador = num1.denominador;
    return res;
  }
}

template <typename tipo>
fracao<tipo> operator- (fracao<tipo> num1, fracao<tipo> num2)
{
  fracao<tipo> res;
  if(num1.denominador == num2.denominador)
  {
    num1.numerador-=num2.numerador;
    res.numerador = num1.numerador;
    res.denominador = num1.denominador;
    return res;
  } 
  else
  {
    int temp;
    num1.numerador *= num2.denominador;
    num2.numerador *= num1.denominador;
    temp = num1.denominador;
    num1.denominador *= num2.denominador;
    num2.denominador *= temp;
    num1.numerador-=num2.numerador;
    res.numerador = num1.numerador;
    res.denominador = num1.denominador;
    return res;
  }
}

template<typename tipo>
fracao<tipo> operator* (fracao<tipo> num1, fracao<tipo> num2)
{
  fracao<tipo> res;
  num1.numerador *= num2.numerador;
  num1.denominador *= num2.denominador;
  res.numerador = num1.numerador;
  res.denominador = num1.denominador;
  return res;
}

template<typename tipo>
fracao<tipo> operator/ (fracao<tipo> num1, fracao<tipo> num2)
{
  fracao<tipo> res;
  num1.numerador *= num2.denominador;
  num1.denominador *= num2.numerador;
  res.numerador = num1.numerador;
  res.denominador = num1.denominador;
  return res;
}

int rod(int &rodar)
{
  cout<<"Deseja rodar novamente?"<<endl;
  cout<<"[1] Sim\t\t[2] Não"<<endl;
  cin>>rodar;
  return rodar;
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  fracao<int> num1,num2, res;
  int opc, rodar=1;

  do{
    fflush(stdin);
    cout<<"Calculadora de Frações"<<endl;
    cout<<"[1] Soma [2] Subtração [3] Multiplicação [4] Divisão"<<endl;
    cin>>opc;
    fflush(stdin);
    system("clear");
    switch (opc)
    {
      case 1:
      leitura(num1,num2);
      system("clear");
      res = num1 + num2;
      resultado(res);
      rod(rodar);
      break;

      case 2:
      leitura(num1,num2);
      system("clear");
      res = num1 - num2;
      resultado(res);
      rod(rodar);  
      break;

      case 3:
      leitura(num1,num2);
      system("clear");
      res = num1 * num2;
      resultado(res);
      rod(rodar);
      break;

      case 4:
      leitura(num1,num2);
      system("clear");
      res = num1 / num2;
      resultado(res);
      rod(rodar);
      break;

      default:
      system("clear");
      break;
      
    }
    
    system("clear");
    
  } while (rodar==1);

  return 0;
}
