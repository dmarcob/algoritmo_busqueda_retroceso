//*****************************************************************
// File:   mainLab.cpp
// Author: Diego Marco
// Date:   March 27, 2019
// Coms:   Modulo principal laberinto
//*****************************************************************
//#include <iostream>         <---tosearch
//#include <fstream>
#include  <stdlib.h>
#include "laberinto.hpp"

int main(int argc,char* argv[]) {
  if (argc != 2 && argc != 4) {
      //caso nº parámetros INCORRECTOS
      cout << "Usos(dos formas):" << endl;
      cout << "Primera forma: ./mainLab pathFichero" << endl;
      cout << "Segunda forma: ./mainLab alto ancho densidad" << endl;
      return 85;
  }
  Laberinto lab;
  bool encontrado = false; //Inicialmente camino NO encontrado
  switch (argc) {
    case 2:
      //caso ./mainLab pathFichero
      cargarLaberinto(argv[1],lab);
      buscarCamino(lab,encontrado);
      break;
    case 4:
      //caso ./mainLab alto ancho densidad
      generarLaberinto(lab,atof(argv[3]),atoi(argv[1]),atoi(argv[2]));
      buscarCamino(lab,encontrado);
  }
  if (! encontrado) { cerr << "\033[1;31;47m" << "Camino no encontrado" << endl;}
  return 0;
}
