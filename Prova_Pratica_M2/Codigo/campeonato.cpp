#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include "pessoas.h"
#include "informacoes.h"
#include "jogos.h"

using namespace std;

void setTeam(Pessoas &team)
{
  int idade;
  string nome, pais;
  team.setIdade(idade);
  team.setNome(nome);
  team.setPais(pais);
}

void getTeam(Pessoas team)
{
  
}
