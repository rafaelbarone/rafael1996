#include "Grafico.h"
#include "math.h"
#include <iostream>

using namespace std;

Grafico::Grafico(Tela* tela, Serie* x, Serie* y, Eixo* abscissas, Eixo* ordenadas){
    this->tela = tela;
    serieNasAbscissas = x;
    serieNasOrdenadas = y;
    eixoNasAbscissas = abscissas;
    eixoNasOrdenadas = ordenadas;
}

Grafico::~Grafico(){
    //dtor
}

void Grafico::desenhar(){
    tela->setEixoDasAbscissas(eixoNasAbscissas);
    tela->setEixoDasOrdenadas(eixoNasOrdenadas);
    double xmax = eixoNasAbscissas->getEscalaMaxima();
    double xmin = eixoNasAbscissas->getEscalaMinima();
    double ymax = eixoNasOrdenadas->getEscalaMaxima();
    double ymin = eixoNasOrdenadas->getEscalaMinima();
    double hx = (xmax - xmin)/LARGURA_UTIL;
    double hy = (ymax - ymin)/ALTURA_UTIL;
    for(int i=0; i<serieNasOrdenadas->getTamanho(); i++){
        double x = serieNasAbscissas->getValor(i);
        double y = serieNasOrdenadas->getValor(i);
        //cout << y << endl;
        if((x < xmax)&&(x > xmin)&&(y < ymax)&&(y > ymin)){
            x = trunc((x-xmin)/hx);
            y = trunc((y-ymin)/hy);
            //cout << y << endl;
            tela->adicionarPontoEm(x,y);
        };
        if((x > xmax)&&(y < ymax)&&(y > ymin)){
            y = trunc(y/hy);
            tela->adicionarForaDoLimiteDasAbscissasEm(y, Limite::SUPERIOR);
        };
        if((x < xmin)&&(y < ymax)&&(y > ymin)){
            y = trunc(y/hy);
            tela->adicionarForaDoLimiteDasAbscissasEm(y, Limite::INFERIOR);
        };
        if((x < xmax)&&(x > xmin)&&(y > ymax)){
            x = trunc(x/hx);
            tela->adicionarForaDoLimiteDasOrdenadasEm(x, Limite::SUPERIOR);
        };
        if((x < xmax)&&(x > xmin)&&(y < ymin)){
            x = trunc(x/hx);
            tela->adicionarForaDoLimiteDasOrdenadasEm(x, Limite::INFERIOR);
        };
        if((x > xmax)&&(y > ymax)){
            tela->adicionarForaDoLimiteEm(Limite::SUPERIOR, Limite::SUPERIOR);
        };
        if((x > xmax)&&(y < ymin)){
            tela->adicionarForaDoLimiteEm(Limite::SUPERIOR, Limite::INFERIOR);
        };
        if((x < xmin)&&(y < ymin)){
            tela->adicionarForaDoLimiteEm(Limite::INFERIOR, Limite::INFERIOR);
        };
        if((x < xmin)&&(y > ymax)){
            tela->adicionarForaDoLimiteEm(Limite::INFERIOR, Limite::SUPERIOR);
        };
    };
    tela->desenhar();
}

void Grafico::reset(){
    tela->apagar();
}

Serie* Grafico::getSerieNasAbscissas(){
    return serieNasAbscissas;
}

Serie* Grafico::getSerieNasOrdenadas(){
    return serieNasOrdenadas;
}

Eixo* Grafico::getEixoDasAbscissas(){
    return eixoNasAbscissas;
}

Eixo* Grafico::getEixoDasOrdenadas(){
    return eixoNasOrdenadas;
}
