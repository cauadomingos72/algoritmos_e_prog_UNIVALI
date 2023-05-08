#ifndef TORCEDOR_H_INCLUDED
#define TORCEDOR_H_INCLUDED

struct Torcedor
{
  int qtd;
  int tempo;
  bool socio;
};

int addQtd(Torcedor a)
{
  return a.qtd++;
}

int contTempo(Torcedor a)
{
  return a.tempo++;
}

bool setSocio(Torcedor a)
{
  return a.socio = true;
}

#endif // TORCEDOR_H_INCLUDED
