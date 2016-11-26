#include "EixoDinamico.h"

EixoDinamico::EixoDinamico(Serie* serie, string unidade, int numeroDeDivisoes, double escalaMinimaInicial,
  double escalaMaximaInicial) : Eixo(serie->getNome(), unidade, numeroDeDivisoes, escalaMinimaInicial, escalaMaximaInicial){
  this->serie = serie;
}

EixoDinamico::~EixoDinamico(){
  //dtor
}

double EixoDinamico::getEscalaMinima(){
  if(serie->getTamanho() <= 2){
    return escalaMinima;
  } else {
    escalaMinima = serie->getMinimo();
    return escalaMinima;
  }
}

double EixoDinamico::getEscalaMaxima(){
  if(serie->getTamanho() <= 2){
    return escalaMaxima;
  } else {
    escalaMaxima = serie->getMaximo();
    return escalaMaxima;
  }
}
