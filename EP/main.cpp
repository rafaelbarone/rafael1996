#include <iostream>
#include "Eixo.h"
#include "Serie.h"
#include "Grafico.h"
#include "Tela.h"
#include "IHC.h"
#include "InterfaceSerial.h"
#include <string>
#include "EixoDinamico.h"
#include "SerieDeCanal.h"
#include "Tempo.h"

#define LARGURA_UTIL 61
#define ALTURA_UTIL 16

#define DIVISAO_ABSCISSA 10
#define DIVISAO_ORDENADA 5

using namespace std;

int main()
{
    bool isTempo = false;
    int opX, opY, quantidadeMaximaX, quantidadeMaximaY, numeroDeDivisoesX, numeroDeDivisoesY;
    string tipoEixoX, tipoEixoY, unidadeX, unidadeY, tituloX, tituloY;
    double escalaMinimaX, escalaMaximaX, escalaMinimaY, escalaMaximaY;
    InterfaceSerial *is = new InterfaceSerial();
    is->inicializar("COMM");
    Tela *tela = new Tela;
    numeroDeDivisoesX = LARGURA_UTIL/DIVISAO_ABSCISSA;
    numeroDeDivisoesY = ALTURA_UTIL/DIVISAO_ORDENADA;

    //Criando eixo e serie para as abscissas abaixo
    cout << "Aperte o botao reset da placa" << endl;
    cout << "Escolha uma serie para o eixo X:" <<endl;
    cout << "0) Tempo" << endl;
    cout << "1) ACCX" << endl;
    cout << "2) ACCY" << endl;
    cout << "3) ACCZ" << endl;
    cout << "4) MAGX" << endl;
    cout << "5) MAGY" << endl;
    cout << "6) MAGZ" << endl;
    cin >> opX;
    cout << "Informe a quantidade maxima de valores: " << endl;
    cin >> quantidadeMaximaX;
    cout << "O eixo deve ser (e)statico ou (d)inamico: " << endl;
    cin >> tipoEixoX;
    if(opX != 0){
      cout << "Informe o titulo: " << endl;
      cin >> tituloX;
    }
    cout << "Informe a unidade do eixo: " << endl;
    cin >> unidadeX;
    if (tipoEixoX == "d"){
      cout << "Informe a escala minima inicial: " << endl;
      cin >> escalaMinimaX;
      cout << "Informe a escala maxima inicial" << endl;
      cin >> escalaMaximaX;
    } else {
      cout << "Informe a escala minima: " << endl;
      cin >> escalaMinimaX;
      cout << "Informe a escala maxima: " << endl;
      cin >> escalaMaximaX;
    }
    if(opX == 0){
      isTempo = true;
      Tempo* serieX = new Tempo(quantidadeMaximaX);
    } else {
      isTempo = false;
      SerieDeCanal* serieX = new SerieDeCanal(tituloX, quantidadeMaximaX);
    }
    if(tipoEixoX == "d"){
      EixoDinamico* eixoX = new EixoDinamico(serieX, unidadeX, numeroDeDivisoesX, escalaMinimaX, escalaMaximaX);
    } else {
      Eixo* eixoX = new Eixo(tituloX, unidadeX, numeroDeDivisoesX, escalaMinimaX, escalaMaximaX);
    }

    //Eixo e serie das abscissas prontos
    //Criando eixo e serie para as ordenadas abaixo

    cout << "Aperte o botao reset da placa" << endl;
    cout << "Escolha uma serie para o eixo Y:" <<endl;
    cout << "0) ACCX" << endl;
    cout << "1) ACCY" << endl;
    cout << "2) ACCZ" << endl;
    cout << "3) MAGX" << endl;
    cout << "4) MAGY" << endl;
    cout << "5) MAGZ" << endl;
    cin >> opY;
    cout << "Informe a quantidade maxima de valores: " << endl;
    cin >> quantidadeMaximaY;
    cout << "O eixo deve ser (e)statico ou (d)inamico: " << endl;
    cin >> tipoEixoY;
    cout << "Informe o titulo: " << endl;
    cin >> tituloY;
    cout << "Informe a unidade do eixo: " << endl;
    cin >> unidadeY;
    if (tipoEixoY == "d"){
      cout << "Informe a escala minima inicial: " << endl;
      cin >> escalaMinimaY;
      cout << "Informe a escala maxima inicial" << endl;
      cin >> escalaMaximaY;
    } else {
      cout << "Informe a escala minima: " << endl;
      cin >> escalaMinimaY;
      cout << "Informe a escala maxima: " << endl;
      cin >> escalaMaximaY;
    }
    SerieDeCanal* serieY = new SerieDeCanal(tituloY, quantidadeMaximaY);
    if(tipoEixoX == "d"){
      EixoDinamico* eixoY = new EixoDinamico(serieY, unidadeY, numeroDeDivisoesY, escalaMinimaY, escalaMaximaY);
    } else {
      Eixo* eixoX = new Eixo(tituloY, unidadeY, numeroDeDivisoesY, escalaMinimaY, escalaMaximaY);
    }

    //Eixo e serie das abscissas pronto
    //Podemos fazer grafico

    Grafico* g = new Grafico(tela, serieX, serieY, eixoX, eixoY);
    while(!IHC::escFoiPressionado()){
      if(isTempo){
        serieX->incrementar();
      }
      is->atualizar();
      g->desenhar();
      IHC::sleep();
    }
}
