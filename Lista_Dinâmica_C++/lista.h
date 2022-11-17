#include <iostream>

using namespace std;

//estrutura do produto
struct Produto
{
 int Codigo;
 string Nome;
 float Preco;
 Produto *proximo;
};

//estrutura da lista
struct ListaE
{
 Produto * inicio;
};

//inicializa lista
bool inicializa_lista (TListaE &lista)
{
 lista.inicio = NULL;
}

//Protótipo da inserção
bool insere_elemento_lista(TListaE &lista, Produto prod);
