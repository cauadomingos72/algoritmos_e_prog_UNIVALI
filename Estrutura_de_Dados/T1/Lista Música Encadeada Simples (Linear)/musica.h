#include <iostream>

using namespace std;

struct Musica
{
  string nome;
  string artista;
};

struct Info 
{
  Musica det;
  int qtd;
  Info *proximo;
};

struct Lista
{
  Info *inicio;
};

bool inicializa_lista_enc(Lista &x)
{
  x.inicio = NULL;
  return true;
}

bool insere_final (Lista &x, Info y)
{
  
}

bool remove_final(Lista &x)
{
  if(x.inicio == NULL)
  {
    return false;
  }
  else
  {
    Info *pes = x.inicio;
    if(pes->proximo == NULL)
    {
      x.inicio = pes->proximo;
      delete pes;
      return true;
    }
    else
    {
      Info *rot = x.inicio->proximo;
      while(rot->proximo != NULL)
      {
        pes = pes->proximo;
        rot = rot->proximo;
      }
      pes->proximo = NULL;
      delete rot;
      return true;
    }
  }
}

void imprimir();
