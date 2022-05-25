// Faça um programa que solicita ao usuário um número real positivo. Verifique se o número é realmente positivo, e em caso contrário solicite ao usuário digitar novamente (este processo pode se repetir inúmeras vezes e é chamado de consistência, pois garante que o número será válido após a entrada de dados). Saídas:
// Pedido ao usuário = “Digite um número real positivo”;
// Caso número valido = “O número digitado é valido”;
// Caso número invalido = “Número invalido, tente novamente”.

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  float numV;

  cout << "Digite um valor qualquer positivo:" << endl;
  cin >> numV;

  if (numV < 0) {
    while (numV < 0) {

      cout << "Número inválido, tente novamente" << endl;
      cin >> numV;

    }
  } if (numV > 0) {

    cout << "O número digitado é valido" << endl;
    
  }

  return 0;
  
}
