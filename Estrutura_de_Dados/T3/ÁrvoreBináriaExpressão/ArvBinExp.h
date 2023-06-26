#ifndef INCLUDED_ARVBINEXP_H
#define INCLUDED_ARVBINEXP_H
#include <iostream>
using namespace std;

template<typename TIPO>
struct TNo
{
  TIPO item;
  int chave;
  TNo *esquerda, *direita;
};

template<typename TIPO>
struct TArv
{
  TNo<TIPO> *raiz;
};

template<typename TIPO>
void inserirEsquerda(TNo<TIPO> *no, int valor, TIPO i)
{
  if(no->esquerda == NULL)
  {
    TNo<TIPO> *novo = new TNo<TIPO>;
    novo->item =  i;
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    no->esquerda = novo;
  }
  else
  {
    if(valor < no->esquerda->chave)
      inserirEsquerda(no->esquerda, valor, i);
    if(valor > no->esquerda->chave)
      inserirDireita(no->esquerda, valor, i);
  }
}

template<typename TIPO>
void inserirDireita(TNo<TIPO> *no, int valor, TIPO i)
{
  if(no->direita == NULL)
  {
    TNo<TIPO> *novo = new TNo<TIPO>;
    novo->item =  i;
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    no->direita = novo;
  }
  else
  {
    if(valor > no->direita->chave)
      inserirDireita(no->direita, valor, i);
    if(valor < no->direita->chave)
      inserirEsquerda(no->direita, valor, i);
  }
}

template<typename TIPO>
void inserir(TArv<TIPO> *arv, int valor, TIPO i)
{
  if(arv->raiz == NULL)
  {
    TNo<TIPO> *novo = new TNo<TIPO>;
    novo->item =  i;
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    arv->raiz = novo;
  }
  else
  {
    if(valor < arv->raiz->chave)
      inserirEsquerda(arv->raiz, valor, i);
    if(valor > arv->raiz->chave)
      inserirDireita(arv->raiz, valor, i);
  }
}

template<typename TIPO>
void buscaEsquerda(TNo<TIPO> *no, int valor)
{
  if(no->chave == valor)
  {
    cout<<"Chave: "<<no->chave<<endl;
    cout<<"Item: "<<no->item<<endl;
  }
  else
  {
    if(valor < no->chave)
      buscaEsquerda(no->esquerda, valor);
    else
      buscaDireita(no->direita, valor);
  }
}

template<typename TIPO>
void buscaDireita(TNo<TIPO> *no, int valor)
{
  if(no->chave == valor)
  {
    cout<<"Chave: "<<no->chave<<endl;
    cout<<"Item: "<<no->item<<endl;
  }
  else
  {
    if(valor < no->chave)
      buscaEsquerda(no->esquerda, valor);
    else
      buscaDireita(no->direita, valor);
  }
}

template<typename TIPO>
void busca(TArv<TIPO> *arv, int valor)
{
  if(arv->raiz == NULL)
    cout<<"Árvore Vazia"<<endl;
  else
  {
    if(arv->raiz->chave == valor)
    {
      cout<<"Chave: "<<arv->raiz->chave<<endl;
      cout<<"Item: "<<arv->raiz->item<<endl;
    }
    else
    {
      if(valor < arv->raiz->chave)
        buscaEsquerda(arv->raiz->esquerda, valor);
      else
        buscaDireita(arv->raiz->direita, valor);
    }
  }
}

template<typename TIPO>
void imprimir(TNo<TIPO> *raiz)
{
  if(raiz != NULL)
  {
    imprimir(raiz->esquerda);
    cout<<"Chave: "<<raiz->chave<<endl; 
    cout<<"Item: "<<raiz->item<<endl;
    imprimir(raiz->direita);
  }
}

#endif
