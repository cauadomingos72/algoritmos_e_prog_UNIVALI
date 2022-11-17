#include <iostream>

using namespace std;

struct Produto 
{
  int codigo;
  string nome;
  float preco;
  Produto *proximo;
};

//estrutura da lista
struct ListaE
{
 Produto *inicio;
};

//inicializa lista
void inicializa_lista (ListaE &lista)
{
 lista.inicio = NULL;
}

//Protótipo da inserção
void insere_elemento_lista(ListaE &lista, Produto prod)
{
  lista.inicio->codigo = prod.codigo;
  lista.inicio->nome = prod.nome;
  lista.inicio->preco = prod.preco;
  lista.inicio->proximo = lista.inicio;
}

/*Produto* acha_ultimo_elemento(Produto *p)
{
  if (p->proximo == NULL)
    return p;
}*/
