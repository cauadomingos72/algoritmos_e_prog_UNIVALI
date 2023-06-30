#ifndef INCLUDED_ARVBINEXP_H
#define INCLUDED_ARVBINEXP_H
#include <iostream>
#include <string.h>
using namespace std;

struct TNo
{
  char VxO;
  int chave;
  TNo *esquerda, *direita;
};

struct TArv
{
  TNo *raiz;
};

void inserirDireita(TNo *no, int &prior, char exp);

void Prioridade(char C, int &prior)
{
  if(C == '(')
    prior *= 10;
  if(C == ')')
    prior /= 10;
  if(C=='+' || C=='-')
    prior *= 2;
  if(C=='/' || C=='*')
    prior *= 4;
  else
    prior *= 6;
}

void inserirEsquerda(TNo *no, int &prior, char exp)
{
  if(no->esquerda == NULL)
  {
    TNo *novo = new TNo;
    novo->VxO =  exp;
    novo->chave = prior;
    novo->esquerda = NULL;
    novo->direita = NULL;
    no->esquerda = novo;
  }
  else
  {
    if(prior < no->esquerda->chave)
      inserirEsquerda(no->esquerda, prior, exp);
    if(prior > no->esquerda->chave)
      inserirDireita(no->esquerda, prior, exp);
  }
}

void inserirDireita(TNo *no, int &prior, char exp)
{
  if(no->direita == NULL)
  {
    TNo *novo = new TNo;
    novo->VxO =  exp;
    novo->chave = prior;
    novo->esquerda = NULL;
    novo->direita = NULL;
    no->direita = novo;
  }
  else
  {
    if(prior > no->direita->chave)
      inserirDireita(no->direita, prior, exp);
    if(prior < no->direita->chave)
      inserirEsquerda(no->direita, prior, exp);
  }
}

void inserir(TArv *arv, int &prior, char exp)
{
  if(arv->raiz == NULL)
  {
    TNo *novo = new TNo;
    novo->VxO =  exp;
    novo->chave = prior;
    novo->esquerda = NULL;
    novo->direita = NULL;
    arv->raiz = novo;
  }
  else
  {
    Prioridade(exp, prior);
    if(prior < arv->raiz->chave)
      inserirEsquerda(arv->raiz, prior, exp);
    if(prior > arv->raiz->chave)
      inserirDireita(arv->raiz, prior, exp);
  }
}

bool VerificaNumero(char N)
{
  if((N >= '0')&&(N <= '9'))
    return true;
  else 
    return false;
}

bool VerificaOperador(char O)
{
  if((O == '+') || (O == '-') || (O == '*') || (O == '/'))
    return true;
  else 
    return false;
}

void MontaArvore(TArv *arv, int &prior, string exp)
{
  for(int i = exp.size(); i >= 0; i--)
  {
    inserir(arv, prior, exp[i]);
  }
}

int Calculo(TNo *no)
{
  int A, B;

  if(no != NULL)
  {
    if(VerificaNumero(no->VxO))
      return no->VxO-'0';
    if((no->esquerda == NULL) && (no->direita))
      return 0;
    else
    {
      A = Calculo(no->esquerda);
      B = Calculo(no->direita);

      switch(no->VxO)
      {
        case '+':
          return (A+B);
        case '-':
          return (A-B);
        case '*':
          return (A*B);
        case '/':
          return (A/B);
      }
    }
  }
  return 0;
}

void imprimir(TNo *raiz)
{
  if(raiz != NULL)
  {
    imprimir(raiz->esquerda);
    cout<<raiz->VxO<<endl;
    imprimir(raiz->direita);
  }
}

void imprimirResultado(TArv *arv)
{
  cout<<"Resultado: "<<Calculo(arv->raiz);
}

#endif

//strlen (string x) -- x.size() -- x[i]
