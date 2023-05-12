#ifndef PESSOAS_H_INCLUDED
#define PESSOAS_H_INCLUDED
#include <iostream>

class Pessoas
{
  std::string nome;
  int cpf;

public:

  std::string addNome(std::string nome);
  void printNome(std::string nome);
  int addCPF(int cpf);
  void printCPF(int cpf);

  Pessoas (std::string nome, int cpf);

  
};

class Funcionarios : public Pessoas
{
  std::string funcao;
  int salario;

public:

  std::string addFuncao(std::string);
  void printFuncao(std::string);
  int addSalario(int salario);
  void printSalario(int salario);

  Funcionarios(std::string funcao, int salario);
};

class Cliente : public Pessoas
{
  int numCadastro;

public:

  int addNumCad(int numCadastro);
  void printNumCad(int numCadastro);

  Cliente(int numCadastro);
};

#endif
