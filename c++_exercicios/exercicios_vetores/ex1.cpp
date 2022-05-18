#include <locale.h>

#define TAM 10

using namespace std;

int main() {
  setlocale (LC_ALL, "Portuguese");

  int vetN[TAM], i=0, soma=0, resulM, resulMa;
  int maior, menor;

  do {
    cout << "Informe o " << i  << "° valor inteiro"<< endl;
    cin >> vetN[i];
    
    maior = vetN[i];
    menor = vetN[i];

    i++;

    cout << " " << endl;
  } while (i <10);
  
  for (i = 0; i <= 10; i++) {
      
      if (vetN[i] > maior) {
        vetN[i] = maior;
      }
    }
    
    for (i = 0; i <= 10; i++) {
      
      if (menor > vetN[i]) {
        menor = vetN[i];
      }
    }
  ///MÉDIA
  i=0;
  while (i < 10) {
    soma = soma + vetN[i];
    i++;
  }
  
  resulM = (float) soma/TAM;
  cout << "A média desses valores é: " << resulM << endl;
  
  ///MAIOR VALOR
  cout << "O maior valor é: " << maior << endl;
  
  ///MENOR VALOR
  cout << "O menor valor é: " << menor << endl;

  return 0;
}
