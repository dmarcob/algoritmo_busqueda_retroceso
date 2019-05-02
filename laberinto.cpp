//***************************************************************************
// File:   laberinto.cpp
// Author: Programación II. Diego Marco 755232
// Date:   March 27, 2019
// Coms:   Implementación del tipo "Laberinto" para la práctica 3 de la asignatura
//***************************************************************************

#include "laberinto.hpp"
#include <unistd.h> // para "usleep"
#include <fstream> //trabajo con ficheros
#include <ctime> //para "time"
#include <cstdlib> //para "srand" "rand"
bool busqueda(Laberinto& lab, int y, int x) {
  if (y == lab.alto - 2 && x == lab.ancho - 2) {
    //caso posición actual es la salida
    return true;
  }

  else if (lab.mapa[y][x] == '#' || lab.mapa[y][x] == '.') {
    //caso posición actual es un MURO o se visitó antes
    return false;
  }
  else {
    lab.mapa[y][x]='.';
    mostrarLaberinto(lab);
    if (lab.mapa[y][x - 1] == ' ' && busqueda(lab,y,x - 1)) {
      return true;
    }
    if (lab.mapa[y][x + 1] == ' ' && busqueda(lab,y,x + 1)) {
      return true;
    }
    if (lab.mapa[y - 1][x] == ' ' && busqueda(lab,y - 1,x)) {
      return true;
    }
    if (lab.mapa[y + 1][x] == ' ' && busqueda(lab,y + 1,x)) {
      return true;
    }
    //no hay camino desde la posición actual
    lab.mapa[y][x] = 'I';
    mostrarLaberinto(lab);
    return false;

  }
}


//*************************************************************************
// Encontrar un camino en el laberinto
//*************************************************************************
void buscarCamino(Laberinto& lab, bool& encontrado) {
      int y = 1; //fila origen
      int x = 1; //columna origen
      //busqueda del camino correcto desde las coordenadas x e y
      encontrado = busqueda(lab,y,x);
}

//*************************************************************************
// Generar el laberinto
//*************************************************************************

void cargarLaberinto(const char nombreFichero[], Laberinto& lab) {
  ifstream f;
  f.open(nombreFichero);
  if (f.is_open()) {
    //-------------VARIABLES------------------------------------------------
    int columnas = 0; //nº columnas matriz leida
    int filas = 0;// nº filas matriz leida
    int y = 0; //Coordenada y de la Matriz
    int x = 0; //Coordenada x de la matriz
    bool primFila = true; //true si está leyendo la primera fila
    //------------LECTURA MATRIZ--------------------------------------------
    //Intento leer la primera casilla
    char casilla = f.get();
    while (!f.eof()) {
      //caso he conseguido leer la casilla
      if (casilla != '\n') {
        //caso <<casilla>> no es un salto de línea
        lab.mapa[y][x] = casilla;
        x++; //avanzo una columna;
        if (primFila) {
          //caso estoy leyendo la primera fila
          columnas++; //número de columnas que tiene la matriz
        }
      }
      else {
        //caso <<casilla>> es un salto de línea
        y++; //avanzo una fila
        x = 0; //reinicio las columnas
        primFila = false; //ya no estoy leyendo primera fila
        filas++; //numero de filas que tiene la matriz
      }
      //Intento leer siguiente casilla
      casilla = f.get();
    }
    //fin de fichero alcanzado
    lab.ancho = columnas;
    lab.alto = filas;
    f.close(); //cierro fichero
  }
  else {cerr << "Fichero " << nombreFichero << " no existe" << endl;}
}


void generarLaberinto(Laberinto &lab, double densidad, int nFils, int nCols) {
  srand(time(nullptr)); //genero semilla
  lab.alto = nFils;
  lab.ancho = nCols;

  for (int i = 0; i < nFils; i++) {
    for (int j = 0; j < nCols; j++) {
        if(i == 0 || i == nFils - 1) {
          //caso primera fila o última fila
          lab.mapa[i][j] = '#';
        }
        else if (j == 0 || j == nCols - 1) {
          //caso primera columna o últia columna
          lab.mapa[i][j] = '#';
        }
        else if ((i == 1 && j == 1) || (i == nFils - 2 && j == nCols - 2)) {
          //caso inicio o final laberinto
          lab.mapa[i][j] = ' ';
        }
        else {
          //caso casillas interiores de la matriz
          double random = (rand()%100)/100.0;
          if (random <= densidad) {
            lab.mapa[i][j] = '#';
          }
          else {lab.mapa[i][j] = ' ';}
        }
    }
  }
}

//*************************************************************************
// Visualizar el camino encontrado
//*************************************************************************

// Pre:   "lab" es un laberinto correcto, segÃºn la especificaciÃ³n dada para el tipo
// Post:  Se haa mostrado el laberinto por la salida estÃ¡ndar
// Coms:  VersiÃ³n iterativa
void mostrarLaberinto(const Laberinto& lab) {
    system("clear");
    for (int i = 0; i < lab.alto; i++) {
        for (int j = 0; j < lab.ancho; j++) {
                if (lab.mapa[i][j] == CAMINO) {
                    cout << "\033[1;36;46m" << lab.mapa[i][j] << "\033[0m";
                } else if (lab.mapa[i][j] == IMPOSIBLE) {
                    cout << "\033[1;36;41m" << lab.mapa[i][j] << "\033[0m";
                }
                else {
                   cout << lab.mapa[i][j];
                }
            }
        // Al acabar una fila, se cambia de lÃ­nea
        cout << endl;
    }
    usleep(RETRASO_MOSTRAR); //microsegundos
}


// Pre:  "lab" es un laberinto correcto, segÃºn la especificaciÃ³n en el enunciado
// Post:  Se haa mostrado el laberinto por la salida estÃ¡ndar
// Coms:  VersiÃ³n recursiva

void mostrarLaberintoR(const Laberinto& lab){

    // COMPLETAR
}
