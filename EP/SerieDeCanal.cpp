#include "SerieDeCanal.h"
#include <iostream>

using namespace std;

SerieDeCanal::SerieDeCanal(string nome, int quantidadeMaxima) : Serie(nome){
    this->quantidadeMaxima = quantidadeMaxima;
}

SerieDeCanal::~SerieDeCanal(){
    //dtor
}

void SerieDeCanal::adicionar(double valor){
    if (tamanho < quantidadeMaxima){
        serie[tamanho - 1] = valor;
    } else {
        for (int i=0; i < tamanho; i++){
            serie[i] = serie[i + 1];
        }
        serie[tamanho - 1] = valor;
    }
}

bool SerieDeCanal::estaVazia(){
    if (tamanho == 0){
        return true;
    }
    return false;
}

int SerieDeCanal::getTamanho(){
    return tamanho;
}

double SerieDeCanal::getValor(int posicao){
    if (posicao < tamanho){
        return serie[posicao];
    }
}

double SerieDeCanal::getMaximo(){
    if(tamanho != 0){
        double maximo = serie[0];
        for(int i = 1; i < tamanho; i++){
            if (serie[i] > maximo){
                maximo = serie[i];
            }
        }
        return maximo;
    }
}

double SerieDeCanal::getMinimo(){
    if(tamanho != 0){
        double minimo = serie[0];
        for(int i = 1; i < tamanho; i++){
            if(serie[i] < minimo){
                minimo = serie[i]
            }
        }
        return minimo;
    }
}

string SerieDeCanal::getNome(){
  return nome;
}
