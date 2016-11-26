#ifndef TEMPO_H_INCLUDED
#define TEMPO_H_INCLUDED

#include "Serie.h"

#define MAX 100

class Tempo : public Serie{
public:
    Tempo(int tamanhoDaFaixa);
    virtual ~Tempo();
    virtual void incrementar();
    string getNome();
    bool estaVazia();
    int getTamanho();
    double getValor(int posicao);
    double getMaximo();
    double getMinimo();


private:
    int tamanhoDaFaixa;
    int tamanho = 0;
    double serie[MAX];
};

#endif // TEMPO_H_INCLUDED
