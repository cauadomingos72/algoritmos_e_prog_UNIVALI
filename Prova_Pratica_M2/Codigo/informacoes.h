#ifndef INFORMACOES_H_INCLUDED
#define INFORMACOES_H_INCLUDED
#include <iostream>
using namespace std;

struct Local
{
  string pais;
  string estado;
  string cidade;
};

struct Data
{
  int dia;
  int mes;
  int ano;
};

class Informacoes
{
  Local location;
  Data date;

public:

  void setLocal(Local &location);
  void getLocal(Local location);

  void setData(Data &date);
  void getData(Data date);

  void imprime();

  Informacoes();
  Informacoes(Local location, Data date);
};


#endif
