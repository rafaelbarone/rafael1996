#ifndef SERIEDECANAL_H_INCLUDED
#define SERIEDECANAL_H_INCLUDED

#include "Serie.h"

#define MAX 100

class SerieDeCanal : public Serie{
public:
    SerieDeCanal(string nome, int quantidadeMaxima);
    virtual ~SerieDeCanal();
    virtual void adicionar (double valor);

private:
    int tamanho = 0;
    double serie[MAX];
    int quantidadeMaxima;
};

#endif // SERIEDECANAL_H_INCLUDED
