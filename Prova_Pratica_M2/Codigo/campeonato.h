#ifndef CAMPEONATO_H_INCLUDED
#define CAMPEONATO_H_INCLUDED
#include "pessoas.h"
#include "informacoes.h"
#include "jogos.h"

class Campeonato
{
  Pessoas team;
  Jogos matches;
  Informacoes info;

public:

  void setTeam(Pessoas &team);
  void getTeam(Pessoas team);

  void setMatches(Jogos &matches);
  void getMatches(Jogos matches);

  void setInfo(Informacoes info);
  void getInfo(Informacoes info);
  void imprimir();

  Campeonato();
  Campeonato(Pessoas team, Jogos matches, Informacoes info);
};

#endif
