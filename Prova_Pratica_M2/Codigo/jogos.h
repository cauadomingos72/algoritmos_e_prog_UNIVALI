#ifndef JOGOS_H_INCLUDED
#define JOGOS_H_INCLUDED
#include <iostream>
using namespace std;

struct Data
{
  int dia;
  int mes;
  int ano;
};

class Times
{
  string nome;
  string pais;

public:

  void setNome(string &nome);
  void getNome (string nome);

  void setPais(string &pais);
  void getPais(string pais);

  Times();
  Times(string nome, string pais);
};

class Jogos: public Times
{
  Data date;
  Times team1;
  Times team2;

public:

  void setData(Data &date);
  void getData(Data &date);

  void setTeam1(Times &team1);
  void getTeam1(Times team1);

  void setTeam2(Times &team2);
  void getTeam2(Times team2);

  void imprime();

  Jogos();
  Jogos(Data date, Times team1, Times team2);
  
};

#endif
