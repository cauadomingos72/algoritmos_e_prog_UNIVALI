#include <iostream>
#define MAX 52

using namespace std;

struct Carta
{
  int num;
  int nip;
};

struct Baralho
{
  int qtd;
  Carta deck[MAX];
};

bool inicializa_baralho(Baralho &d)
{
  d.qtd = 0;
  return true;
}

bool insere_fim(Baralho &d, Carta c)
{
  if(d.qtd < MAX)
  {
    d.deck[d.qtd] = c;
    return true;
  }
  else
  {
    return false;
  }
}

bool remove_fim(Baralho &d)
{
  if(d.qtd > 0)
  {
    d.qtd--;
    return true;
  }
  else
  {
    return false;
  }
}

void monta_baralho(Baralho &d)
{
  Carta temp;
  for(int i=1; i < 5; i++)
  {
    for(int j = 1; j < 14; j++)
    {
      temp.nip = i;
      temp.num = j;
      insere_fim(d, temp);   
    }
  }
}

void distribuir_cartas();

void ordenar_cartas();

void imprime_baralho(Baralho d)
{
  for(int i = 0; i < d.qtd; i++)
  {
    cout<<"NUM: "<<d.deck[i].num<<"\tNIPE: "<<d.deck[i].nip;
  }
}
