#include "Tempo.h"
#include <iostream>

using namespace std;

Tempo::Tempo(int tamanhoDaFaixa) : Serie("Tempo"){
    this->tamanhoDaFaixa = tamanhoDaFaixa;
}

Tempo::~Tempo(){
    //dtor
}

void Tempo::incrementar(){
    if(tamanho == 0){
        serie[0] = 1;
    }
    else{
        if (tamanho < tamanhoDaFaixa){
            serie[tamanho - 1] = serie[tamanho - 2] + 1;
        } else {
            for (int i = 0; i < tamanho; i++){
                serie [i] = serie[i+1];
            }
            serie[tamanho - 1] = serie[tamanho - 2] + 1;
        }
    }
}

bool Tempo::estaVazia(){
    if(tamanho == 0){
        return true;
    }
    return false;
}

int Tempo::getTamanho(){
    return tamanho;
}

double Tempo::getValor(int posicao){
    if (posicao < tamanho){
        return serie[posicao]
    }
}

double Tempo::getMaximo(){
    return serie[tamanho - 1];
}

double Tempo::getMinimo(){
    return serie[0];
}

string Tempo::getNome(){
  return nome;
}
