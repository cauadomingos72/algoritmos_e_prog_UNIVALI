#ifndef TORCEDOR_H_INCLUDED
#define TORCEDOR_H_INCLUDED

struct Torcedor
{
  int nome;
  int tempo;
  bool socio;
};

int contTempo(Torcedor a)
{
  return a.tempo++;
}

bool setSocio(Torcedor a)
{
  return a.socio = true;
}

#endif // TORCEDOR_H_INCLUDED
