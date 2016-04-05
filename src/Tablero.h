  /*
      Nombre: Tablero.h
      Autor: Juan David Narváez & Santiago Vargas Hoyos
      Clase: Tablero
      Responsabilidad:
      Crear las variables y metodos que se usaran en los archivos .cpp
      Colaboracion:  Tablero.cpp
  */

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

class Tablero {
private:
    char** casillas;
    int dimension;
public:
    Tablero();
    Tablero(int n);
    ~Tablero();
    char getCasilla(int x, int y);
    void setCasilla(int x, int y, char value);
    int getDimension();
};

#endif /* SRC_TABLERO_H_ */
