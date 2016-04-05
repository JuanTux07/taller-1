//============================================================================
// Name        : taller1.cpp
// Author      : Juan David Narváez & Santiago Vargas Hoyos
// Description :
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Arbitro.h"
using namespace std;


Arbitro::Arbitro() {
    juegoEnCurso = false;
    puntaje = 100.0;
    srand(time(NULL));
    filaBolita = 0;
    columnaBolita = 0;
}

Arbitro::~Arbitro() {
    // TODO Auto-generated destructor stub
}

void Arbitro::iniciarJuego() {
  int dimension = 0;
  std::cout << "Ingrese la dimension del tablero: " << std::endl;
  std::cin >> dimension;

  tablero = Tablero(dimension);
  filaBolita = rand()%dimension;//es para comprobar si la bolita esta en la fila indicada
  columnaBolita = rand()%dimension;// es para comprobar si la bolita esta en la columna indicada
  imprimirTablero();
  juegoEnCurso = true;

  while (juegoEnCurso) {
    int fila = 0;
    std::cout << "Ingrese la fila:" << std::endl;
    std::cin >> fila;
    int columna = 0;
    std::cout << "Ingrese la columna" << std::endl;
    std::cin >> columna;
    validarIntento(fila, columna);
  }
    //Debe implementar un metodo que se encargue de iniciar el juego y controlar su desarrollo
    //Este metodo debe recibir las entradas del usuario, imprimir el tablero y validar los intentos
}

void Arbitro::imprimirTablero() {
    cout << "   ";
    for (int i = 0; i < tablero.getDimension(); i ++){
        cout << i << "  ";
    }
    cout << endl;
    for (int i = 0; i < tablero.getDimension(); i++){
        cout << i << "  " ;
        for (int j= 0; j < tablero.getDimension(); j ++){
            if (tablero.getCasilla(i , j)!= 'O'){
            cout << tablero.getCasilla(i,j) << "  ";
        }else{
            cout << 'X' << "  ";
        }
    }
    cout << endl;
    //Debe implementar un metodo que imprima el tablero en pantalla
    } //Recuerde que el usuario no puede conocer la posicion de la bolita
}

int Arbitro::calcularDistancia(int fila, int columna){
    int distanciaf = fila - filaBolita;
    int distanciac = columna - columnaBolita;
    int distancia = floor(sqrt(pow(distanciaf,2) + (pow(distanciac,2))));
    return  distancia;
    //Debe implmentar un metodo que calcula la distancia entre la posicion (fila, columna)
    //Y la posicion real de la bolita
}

bool Arbitro::validarIntento(int fila, int columna){
    int n = tablero.getDimension();
    puntaje = puntaje - (puntaje/(n*n));

  if (fila == filaBolita && columna == columnaBolita){
    std::cout << "Ganastee!!!" << std::endl;
    juegoEnCurso = false;
  }else if (puntaje == 0) {
    std::cout << "Ya no tienes mas intentos, terminaste el juego" << std::endl;
    juegoEnCurso = false;
  } else {
    std::cout << "La bolita esta a una distancia de " << calcularDistancia(fila, columna) << std::endl;
    std::cout << "Su puntaje es: "<< puntaje << std::endl;
    imprimirTablero();

  }
    //Este metodo debe validar el intento del usuario, debe informarle si fue correcto o no
    //Retorna verdadero si el intento es correcto y falso si no lo es
    //En caso de no serlo debe realizar los cambios correspondientes a las variables miembro
    //Y debe informar por pantalla cual fue la distancia del fallo y el puntaje restante
}
