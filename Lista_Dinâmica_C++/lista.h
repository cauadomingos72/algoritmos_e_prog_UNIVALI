///Integrantes: Cauã Domingos, Paulo Hermans e Vinicius Ribeiro.
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

bool prodvazio (Produto *p) //Verifica se a lista está vazia
{
  if (p == NULL)
    return true;
  else
    return false;
}

void insere_primeiro_elemento (Produto *&item, Produto *&itemF, Produto val) //Caso a lista esteja vazia é inserido um primeiros valores digitados pelo usuário.
{
  Produto *temp = new Produto;
  temp->codigo = val.codigo;
  temp->nome = val.nome;
  temp->preco = val.preco;
  temp->proximo = NULL;
  item = temp;
  itemF = temp;
}

void insere_elemento_lista(Produto *&item, Produto *&itemF, Produto val)
{
  if (prodvazio(item)) {
    insere_primeiro_elemento (item, itemF, val);
  } else {
    Produto *temp = new Produto;
    temp->codigo = val.codigo;
    temp->nome = val.nome;
    temp->preco = val.preco;
    temp->proximo = NULL;
    itemF->proximo = temp;
    itemF = temp;
  }
}

void remover_lista (Produto *&item, Produto *&itemF) //Remove uma lista de acordo com o código digitado pelo usuário
{
  int cod;
  cout<<"Digite o código da lista que deseja deletar:"<<endl;
  cin>>cod;

  if (cod == item->codigo)
    delete item;
  else if (cod == itemF->codigo)
    delete itemF;
}

void consulta_lista (Produto *&item, Produto *&itemF) //Consulta e exibe uma lista de acordo com o código digitado pelo usuário
{
  int cod;
  cout<<"Digite o código da lista que deseja mostrar :"<<endl;
  cin>>cod;

  if (cod == item->codigo)
  {
    cout<<item->nome<<endl;
    cout<<item->codigo<<endl;
    cout<<item->preco<<endl;
  }
  else if (cod == itemF->codigo)
  {
    cout<<itemF->nome<<endl;
    cout<<itemF->codigo<<endl;
    cout<<itemF->preco<<endl;
  }
}
