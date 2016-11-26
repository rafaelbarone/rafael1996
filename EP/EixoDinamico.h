#ifndef EIXODINAMICO_H_INCLUDED
#define EIXODINAMICO_H_INCLUDED
#include <string>
#include "Serie.h"
#include "Eixo.h"

class EixoDinamico : public Eixo{
public:
  EixoDinamico(Serie* serie, string unidade, int numeroDeDivisoes, double escalaMinimaInicial, double escalaMaximaInicial);
  virtual ~EixoDinamico();
  double getEscalaMinima();
  double getEscalaMaxima();

private:
  Serie* serie;
};

#endif // EIXODINAMICO_H_INCLUDED
