#ifndef INTERFACESERIAL_H_INCLUDED
#define INTERFACESERIAL_H_INCLUDED

#include "Serie.h"
#include "SerieDeCanal.h"
#include <string>
#include <windows.h>

using namespace std;

/**
 * Faz a interface com a placa, usando a porta serial
 *
 * Os dados sao lidos seguindo o seguinte formato:
 * T: NOME1, NOME2, NOME3,... // para os titulos
 * A: VALOR1, VALOR2, VALOR3,... // para os valores
 *
 * Baseado em http://playground.arduino.cc/Interfacing/CPPWindows
 * Obs: essa classe esta simplificada para este EP.
 * @Version EP1
 */
class InterfaceSerial {
public:
  /**
   * Inicializa a comunicacao usando uma porta.
   */
  void inicializar(string porta);

  /**
   * Registra a serie especifica a um canal.
   */
  void registrar(string canal, SerieDeCanal* serie);

  /**
   * Atualiza as series registradas com o canal.
   *
   * Em caso de problema de leitura, retorna false. Caso
   * contrario, retorna true.
   */
  bool atualizar();

private:
  // Metodos internos, de apoio
  void conectar();
  void desconectar();
  int ler(char *buffer, unsigned int numeroDeCaracteres);
  int encontraHeader(char* buffer, int inicio, int tamanho);
/*
  string* canaisRegistrados;
  Serie** registradas;
  int quantidadeDeSeriesRegistradas;
  string* canais;
  int quantidadeDeCanais;
  string porta;
  bool conectado = false;
*/

  SerieDeCanal* s1 = NULL;
  SerieDeCanal* s2 = NULL;
  int numeroDeChamadas = 0;
  // Variaveis para comunicacao em baixo nivel - Windows
  HANDLE serial;
  COMSTAT status;
  DWORD errors;
};

#endif // INTERFACESERIAL_H_INCLUDED
