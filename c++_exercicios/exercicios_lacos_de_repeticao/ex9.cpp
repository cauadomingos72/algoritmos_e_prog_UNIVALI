// Faça um programa para uma calculadora simples que solicita ao usuário dois operandos como entrada, seleciona uma das opções da lista (1- soma, 2- produto, 3- divisão, 4- potência) e exibe o resultado. O algoritmo deve executar repetidamente até que os dois operandos informados sejam iguais a zero. Utilize uma variável do tipo real para exibir o resultado;

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  float num1, num2, resu;
  int oper, cont;

  cont = 1;

  do {
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "                 Calculadora Simples" << endl;
    cout << "   1 - SOMA  2 - PRODUTO  3 - DIVISÃO  4 - POTÊNCIA" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
    cout << "Digite a operação desejada:" << endl;
    cin >> oper;
    cout << endl;
    do {
      if (oper <= 0 || oper > 4) {

        cout << "Digite uma operação válida" << endl;
        cin >> oper;
        cout << endl;

      } 
    } while (oper <= 0 || oper > 4);
    cout << "Digite o valor do primeiro número:" << endl;
    cin >> num1;
    cout << endl;
    cout << "Digite o valor do segundo número:" << endl;
    cin >> num2;
    cout << endl;
    
    switch (oper) {
    case 1:
        
      resu = num1 + num2;
      break;
      
    case 2:

      resu = num1 * num2;
      break;

    case 3:

      resu = num1 / num2;
      break;

    case 4:

      resu = num1;
      if (num2 == 0) {

        resu = 0;
        
      } else {

        while (cont < num2) {

          resu = resu * num1;
          cont++;
          
        }
      }
      break;
    }

    cout << "O resultado é: " << resu << endl;
    
  } while (num1 != 0 && num2 != 0);
} 
