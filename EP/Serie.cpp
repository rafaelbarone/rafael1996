#include "Serie.h"
#include <iostream>

using namespace std;

Serie::Serie(string nome){
    this->nome = nome;
}

Serie::~Serie(){
    //dtor
}

string Serie::getNome(){
    return nome;
}
