//*****************************************************************
// File:   mainLab.cpp
// Author: Programación II. Diego Marco 755232
// Date:   March 27, 2019
// Coms:   Modulo principal laberinto
//*****************************************************************
#include <iostream>
#include <fstream>
#include "laberinto.hpp"
int main(int argc,char* argv[]) { cout << argc << endl;
  if (argc != 2 && argc != 4) {
    //caso nº parámetros incorrectos
    cout << "Usos(dos formas):" << endl;
    cout << "Primera forma: ./mainLab pathFichero" << endl;
    cout << "Segunda forma: ./mainLab alto ancho densidad" << endl;
    return 1;
  }
  else {
    //caso nº parámetros correctos
    Laberinto lab;
    int y = 1;
    int x = 1;
    if (argc == 2) {
      //caso ./mainLab pathFichero
      cargarLaberinto(argv[1],lab);
      busqueda(lab,y,x);
    }
    else {
      //caso ./mainLab alto ancho densidad
      generarLaberinto(lab,0.2,25,30);
      busqueda(lab,y,x);
    }
  }
  return 0;
}
