#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLUDED
#include "pessoas.h"
#include "produtos.h"

class Loja
{
  Pessoas client;
  Pessoas funcio;
  Produto item;

public:

  Pessoas addClient(Pessoas client);
  void printClient(Pessoas client);
  Pessoas addFuncio(Pessoas funcio);
  Pessoas printFuncio(Pessoas funcio);
  Produto addProd(Produto item);
  Produto printProd(Produto item);
  
};

#endif
