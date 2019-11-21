#ifndef LIBARBOLES_H_INCLUDED
#define LIBARBOLES_H_INCLUDED
#include "libCanciones.h"

typedef struct stnodoArbolCancion
{
    stCancion c;
    struct stnodoArbolCancion * izq;
    struct stnodoArbolCancion * der;
} stnodoArbolCancion;


///**FUNCIONES ARBOL///
stnodoArbolCancion* inicArbol();
stnodoArbolCancion* crearNodoA (stCancion cancion);
stnodoArbolCancion* agregarA (stnodoArbolCancion* A, stnodoArbolCancion* NN); ///por ID

void mostrarINorderA(stnodoArbolCancion* A);
void mostrarPREorderA(stnodoArbolCancion* A);
void mostrarPOSTorderA(stnodoArbolCancion* A);

stnodoArbolCancion* buscarNodoXtitulo (stnodoArbolCancion* A, char titulo[]);
stnodoArbolCancion* buscarNodoXartista (stnodoArbolCancion* A, char artista[]);

stnodoArbolCancion* nodoMasDerecho(stnodoArbolCancion * arbol);
stnodoArbolCancion* nodoMasIzquierdo(stnodoArbolCancion* arbol);
stnodoArbolCancion* borrarUnNodo(stnodoArbolCancion* arbol, int idCancion); //por ID

int cuentaElementos(stnodoArbolCancion* A);
int cuentaHojas (stnodoArbolCancion* A);
int cuentaNiveles (stnodoArbolCancion* A);
int EShojaA (stnodoArbolCancion* A);
int sumarA (stnodoArbolCancion* A);

#endif // LIBARBOLES_H_INCLUDED
