#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Tempo
{
  int hora, min, seg;
};

struct Resultado
{
  int hora=0, min=0, seg=0;
};

Resultado soma(Tempo h1, Tempo h2, Resultado &resu)
{
  resu.seg = h1.seg + h2.seg;
  if (resu.seg >= 60)
  {
    resu.min++;
    resu.seg = resu.seg - 60;
  }
  resu.min = h1.min + h2.min;
  if (resu.min >= 60)
  {
    resu.hora++;
    resu.min = resu.min - 60;
  }
  resu.hora = h1.hora + h2.hora;
  return resu;
}

int main() 
{
  setlocale(LC_ALL,"Portuguese");

  bool sair=false;
  char seletor;
  Tempo horario1, horario2;
  Resultado resu;

  cout<<"Somador de Horários"<<endl;
  fflush(stdin);
  cout<<"[c] Começar\t[s] Sair"<<endl;
  cin>>seletor;
  fflush(stdin);

  if(seletor=='c' || seletor== 'C')
  {
    do
    {
      system("clear");   
      cout<<"Digite o 1° horário:"<<endl;
      cin>>horario1.hora;
      cin>>horario1.min;
      cin>>horario1.seg;
      cout<<endl;
      fflush(stdin);
        
      cout<<"Digite o 2° horário:"<<endl;
      cin>>horario2.hora;
      cin>>horario2.min;
      cin>>horario2.seg;
      cout<<endl;
        
      fflush(stdin);
      system("clear");
      soma(horario1, horario2, resu);

      cout<<"Resultado: "<<resu.hora<<":"<<resu.min<<":"<<resu.seg<<endl;
      cout<<endl;
      
      cout<<"Inserir outros valores?"<<endl;
      cout<<"[s] Sim\t\t[n] Não"<<endl;
      cin>>seletor;
      fflush(stdin);
      
      if(seletor == 'n' || seletor == 'N')
        sair=true;
      
    } while (!sair);
    system("clear");
  }
}
