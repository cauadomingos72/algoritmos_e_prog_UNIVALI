#include <iostream>

using namespace std;

int main() {

  int dia1, mes1, ano1, dia2, mes2, ano2, mesF, idadeA;

  cout << "Digite sua data de nascimento, na ordem dia, mês e ano:" << endl;
  cin >> dia1 >> mes1 >> ano1;

  cout << "Digite a data atual, na ordem dia, mês e ano:" << endl;
  cin >> dia2 >> mes2 >> ano2;

  if(mes1 < mes2 || mes1 == mes2 && dia1 <= dia2){

    idadeA = ano2 - ano1;
    cout << "Você tem " << idadeA << " anos" << endl;
    
    } else {

      idadeA = ano2 - ano1 - 1;
      cout << "Você tem " << idadeA << " anos" << endl;
    
    }
	return 0;
} 
