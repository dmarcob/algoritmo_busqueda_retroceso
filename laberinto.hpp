//*****************************************************************
// File:   laberinto.hpp
// Author: ProgramaciÃ³n II. Diego Marco 755232
// Date:   March 27, 2019
// Coms:   Definición del tipo "Laberinto" para la práctica 3 de la asignatura
//*****************************************************************

#include <fstream>
#include <iostream>
using namespace std;

// Dimensión máxima de los laberintos
const int MAX_DIM = 120;

// Posibles valores de las posiciones del laberinto
const char LIBRE = ' ';     // (espacio en blanco), posición libre
const char MURO = '#';      // (almohadilla), posición bloqueada
const char CAMINO = '.';    // (punto), camino
const char IMPOSIBLE = 'I'; // posiciÃ³n ya visitada que no llevÃ³ a soluciÃ³n

// Retraso en microsegundos tras mostrar el laberinto
const int RETRASO_MOSTRAR = 75000;

struct Laberinto{
    // Altura en char (nÃºmero de filas) del laberinto
    int alto;
    // Anchura en char (nÃºmero de columnas) del laberinto
    int ancho;
    // Matriz del laberinto
    // Cada posiciÃ³n puede tomar el valor LIBRE, MURO, CAMINO o IMPOSIBLE
    char mapa[MAX_DIM][MAX_DIM];
};

bool busqueda(Laberinto& lab, int x, int y);
//*************************************************************************
// Encontrar un camino en el laberinto
//*************************************************************************

// Pre:   * "lab" es un laberinto correcto y limpio
//        * las casillas (1,1) y (lab.alto-2,lab.ancho-2) contienen LIBRE
// Post:  "encontrado" si, y solo si, se cumplen las condiciones siguientes:
//         * en "lab" se ha marcado con CAMINO las casillas de un camino
//           que une las casillas (1,1) y (lab.alto-2,lab.ancho-2)
//         * las casillas visitadas que no llevaban a la salida quedan marcadas
//           como IMPOSIBLE
//         * el resto de casillas no se han modificado
void buscarCamino(Laberinto& lab, bool &encontrado);

//*************************************************************************
// Generar el laberinto
//*************************************************************************

// Pre:   "nombFichero" es el nombre de un fichero que contiene un laberinto
//        almacenado, correcto
// Post:  "lab" contiene el laberinto del fichero, almacenado de acuerdo a la
//        especificaciÃ³n dada para el tipo
void cargarLaberinto(const char nombFichero[], Laberinto& lab);

//Pre:  * 3<=lab.alto, lab.ancho, fila, col <=MAX_DIM
//      * 0 <= densidad <= 1
//Post: "lab" queda inicializado con un laberinto aleatorio con "nFils" filas
//      y "nCols" columnas, correcto
void generarLaberinto(Laberinto& lab, const double densidad, const int nFils, const int nCols);

//*************************************************************************
// Visualizar el camino encontrado
//*************************************************************************

// Pre:   "lab" es un laberinto correcto
// Post:  Se ha mostrado el laberinto por la salida estÃ¡ndar
// Coms:  VersiÃ³n iterativa
void mostrarLaberinto(const Laberinto& lab);

// Pre:  "lab" es un laberinto correcto
// Post:  Se ha mostrado el laberinto por la salida estÃ¡ndar
// Coms:  VersiÃ³n recursiva
void mostrarLaberintoR(const Laberinto& lab);


// Set Attribute Mode  <ESC>[{attr1};...;{attrn}m
// Sets multiple display attribute settings. The following lists standard attributes:
// 0   Reset all attributes

// 1   Bright
// 2   Dim
// 4   Underscore
// 5   Blink
// 7   Reverse
// 8   Hidden

//     Foreground Colours
// 30  Black
// 31  Red
// 32  Green
// 33  Yellow
// 34  Blue
// 35  Magenta
// 36  Cyan
// 37  White

//     Background Colours
// 40  Black
// 41  Red
// 42  Green
// 43  Yellow
// 44  Blue
// 45  Magenta
// 46  Cyan
// 47  White
