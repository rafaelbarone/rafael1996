#ifndef SERIE_H_INCLUDED
#define SERIE_H_INCLUDED

#include <string>

using namespace std;

/**
 * Representa uma serie. Series representam um conjunto de valores
 * sequenciais. Por exemplo, pode-se ter uma serie 1, 2, 3, 5, 7, 11, 13.
 *
 * Existem pelo menos dois tipos de serie: tempo ou serie de canal. Por
 * isso esta eh uma classe abstrata.
 *
 * Note que nao ha mais uma restricao da quantidade de valores: essa
 * restricao depende da implementacao usada.
 *
 * @Version EP2
 */
class Serie {
public:
  Serie(string nome);
  virtual ~Serie();
  string getNome();

  /**
   * Informa se a serie esta vazia.
   */
  virtual bool estaVazia() = 0;

  /**
   * Informa o numero de valores que a serie possui.
   */
  virtual int getTamanho() = 0;

  /**
   * Obtem o valor que esta na posicao definida da serie. A contagem de
   * valores comeca em 0.
   *
   * Em caso de posicoes invalidas, retorne 0.
   *
   * Por exemplo, considere a serie: 1, 2, 3, 5, 7, 11, 13. O metodo
   * getValor(0) deve retornar 1; getValor(6) deve retornar 13.
   */
  virtual double getValor(int posicao) = 0;

  /**
   * Obtem o maior valor da serie. Caso esteja vazia, retorna 0.
   */
  virtual double getMaximo() = 0;

  /**
   * Obtem o menor valor da serie. Caso esteja vazia, retorna 0.
   */
  virtual double getMinimo() = 0;
protected:
  string nome;
};

#endif // SERIE_H_INCLUDED
