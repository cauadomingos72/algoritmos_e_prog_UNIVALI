#ifndef PESSOAS_H_INCLUDED
#define PESSOAS_H_INCLUDED
#include <iostream>
using namespace std;

class Pessoas
{
  string nome;
  int idade;
  string pais;

public:

  void setNome(string &nome);
  void getNome(string nome);

  int setIdade(int &idade);
  void getIdade(int idade);

  void setPais(string &pais);
  void getPais(string pais);

  virtual void imprime(string nome, int idade, string pais);

  Pessoas();
  Pessoas(string nome, int idade, string pais);
};

class Jogadores: public Pessoas
{
  int numero;
  string posicao;

public: 

  int setNumero(int &numero);
  void getNumero(int numero);

  void setPosicao(string &posicao);
  void getPosicao(string posicao);

  void imprime();

  Jogadores();
  Jogadores(int numero, string posicao);
};

#endif
