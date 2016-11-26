#include "Eixo.h"
#include <iostream>

using namespace std;

Eixo::Eixo(string titulo, string unidade, int numeroDeDivisoes, double escalaMinima, double escalaMaxima){
    this->titulo = titulo;
    this->unidade = unidade;
    this->numeroDeDivisoes = numeroDeDivisoes;
    this->escalaMinima = escalaMinima;
    this->escalaMaxima = escalaMaxima;
}

Eixo::~Eixo(){
    //dtor
}

string Eixo::getTitulo(){
    return titulo;
}

string Eixo::getUnidade(){
    return unidade;
}

int Eixo::getNumeroDeDivisoes(){
    return numeroDeDivisoes;
}

double Eixo::getIncrementoDaDivisao(){
    double i;
    i = (escalaMaxima - escalaMinima)/numeroDeDivisoes;
    return i;
}

double Eixo::getEscalaMinima(){
    return escalaMinima;
}

double Eixo::getEscalaMaxima(){
    return escalaMaxima;
}
