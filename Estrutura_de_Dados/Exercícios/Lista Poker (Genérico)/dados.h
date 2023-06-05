#include <iostream>
#define MAX 52
using namespace std;

template <typename TIPO>
struct Item
{
  TIPO num;
  TIPO nip;
};

template <typename TIPO>
struct Lista
{
  Item <TIPO> dados[MAX];

  int qtd;
};


template <typename TIPO>
bool inicializar(Lista <TIPO> &list)
{
  list.qtd = NULL;
  return true;
}

template <typename TIPO>
void qtd_lista (Lista <TIPO> x)
{
  cout<<"Quantidade de Cartas: "<<x.qtd<<endl;
}

template <typename TIPO>
bool insere_fim(Lista <TIPO> &x, Item <TIPO> &i)
{
  if(x.qtd < MAX)
  {
    x.qtd++;
    x.dados[x.qtd] = i;
    return true;
  }
  else
  {
    return false;
  }
}

template <typename TIPO>
bool remove_fim(Lista <TIPO> &x)
{
  if(x.qtd > 0)
  {
    x.qtd--;
    return true;
  }
  else
  {
    return false;
  }
}

template <typename TIPO>
bool insere_posicao (Lista <TIPO> &x, TIPO num, TIPO nip, int pos)
{
  if(x.qtd >= MAX || pos > x.qtd)
  {
    return false;
  }
  else
  {
    for (int i = x.qtd -1; i+1>pos; i--)
        x.dados[i] = x.dados[i - 1];
    Item <TIPO> item;
    item.num = num;
    item.nip = nip;
    x.dados[pos] = item;
    x.qtd++;
    return true;
  }
}

template <typename TIPO>
void imprime_lista(Lista <TIPO> x)
{
  for(int i = 0; i < x.qtd; i++)
  {
    cout<<"NUM: "<<x.dados[i].num<<"\tNIPE: "<<x.dados[i].nip;
    cout<<endl;
  }
}

template <typename TIPO>
void bubblesort(Lista <TIPO> &x)
{
  TIPO tmp1, tmp2;
  int cond=1;
  for(int i = x.qtd; i >= 1 && cond == 1; i--)
    {
      cond = 0;
      for(int j = 0; j < i; j++)
      {
        if(x.dados[j+1].num < x.dados[j].num && x.dados[j+1].nip < x.dados[j].nip)
        {
          tmp1 = x.dados[j].num;
          tmp2 = x.dados[j].nip;
          x.dados[j].num = x.dados[j+1].num;
          tmp2 = x.dados[j].nip = x.dados[j+1].nip;
          x.dados[j+1].num = tmp1;
          x.dados[j+1].nip = tmp2;
          cond = 1;
        }
      }
    }
}

template <typename TIPO>
bool operator < (TIPO a, TIPO b)
{
  return a.nip*10+a.num < b.nip*10+b.num;
}
