//***************************************************************************
// File:   laberinto.cpp
// Author: Diego Marco
// Date:   March 27, 2019
// Coms:   Implementación del tipo "Laberinto" para la práctica 3 de la asignatura
//***************************************************************************

#include <unistd.h> // para "usleep"
#include <fstream> //trabajo con ficheros
#include <ctime> //para "time"
#include <cstdlib> //para "srand" "rand"
#include "laberinto.hpp"

// ARREGLAR->   GenerarLaberinto1
// COMPLETAR -> mostrarLaberintoR
//*************************************************************************
// AUX1:Encontrar un camino en el laberinto
//*************************************************************************
bool busqueda(Laberinto& lab, int y, int x) {
  if (y == lab.alto - 2 && x == lab.ancho - 2) {
      //caso posición actual es la salida
      lab.mapa[y][x]='.';
      mostrarLaberinto(lab);
      return true;
  }

  else if (lab.mapa[y][x] == '#' || lab.mapa[y][x] == '.') {
      //caso posición actual es un MURO o se visitó antes
      return false;
  }
  else {
      lab.mapa[y][x]='.';
      mostrarLaberinto(lab);
      if (lab.mapa[y][x + 1] == ' ' && busqueda(lab,y,x + 1)) {
          return true;
      }
      if (lab.mapa[y][x - 1] == ' ' && busqueda(lab,y,x - 1)) {
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
// AUX1:Generar el laberinto1
//*************************************************************************
void cargarLaberinto(ifstream& f, Laberinto& lab, const int y, const int x, const int columnas) {
     char casilla = f.get();
     if (!f.eof()) {
        //caso no ha terminado de leer el fichero
        if (casilla != '\n') {
            //caso no se ha leido un salto de linea
            lab.mapa[y][x] = casilla;
            if (y == 0) {
                //caso primera fila
                cargarLaberinto(f,lab,y,x + 1,columnas + 1);
            }
            else {cargarLaberinto(f,lab,y,x + 1,columnas);}
        }
        else{
            //caso se ha leido un salto de línea
            if (x == columnas) {
              //caso es una línea correcta
              cargarLaberinto(f,lab,y + 1,0,columnas);
            }
            else {
              //caso es una línea incorrecta
              cargarLaberinto(f,lab,y,0,columnas);
            }
        }
     }
     else {
       lab.alto = y;
       lab.ancho = columnas;
     }
}
//*************************************************************************
// Generar el laberinto1
//*************************************************************************

void cargarLaberinto(const char nombreFichero[], Laberinto& lab) {
    ifstream f (nombreFichero);
    if (f.is_open()) {
        //Uso inmersión mediante reforzamiento de la precondición
        cargarLaberinto(f,lab,0,0,0);
      //  cout << lab.alto << endl;
      //  cout << lab.ancho << endl;
        f.close();
    }
    else { cerr << "Fichero " << nombreFichero << "no se puede abrir" << endl;}
}

//*************************************************************************
// Generar el laberinto2
//*************************************************************************
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
// Visualizar el camino encontrado: ITERATIVO
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


//*************************************************************************
// Visualizar el camino encontrado: RECURSIVO
//*************************************************************************

void mostrarLaberintoR(const Laberinto& lab){

    // COMPLETAR
}
