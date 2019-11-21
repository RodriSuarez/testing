#include "windows.h"
#include "libarboles.h"
#include "stdio.h"

stnodoArbolCancion* inicArbol()
{
    return NULL;
}

stnodoArbolCancion* crearNodoA (stCancion cancion)
{
    stnodoArbolCancion* aux= (stnodoArbolCancion*) malloc (sizeof(stnodoArbolCancion));

    aux->c.idCancion= cancion.idCancion;
    aux->c.tipo= cancion.tipo;

    fflush(stdin);
    strcpy(aux->c.titulo, cancion.titulo);
    fflush(stdin);
    strcpy(aux->c.artista, cancion.artista);
    fflush(stdin);
    strcpy(aux->c.album, cancion.album);
    strcpy(aux->c.genero, cancion.genero);
    strcpy(aux->c.comentario, cancion.comentario);

    aux->c.duracion= cancion.duracion;
    aux->c.anio= cancion.anio;

    return aux;
}

stnodoArbolCancion* agregarA (stnodoArbolCancion* A, stnodoArbolCancion* NN) ///por ID
{
    if (A==NULL)
        A=NN;
    else if (NN->c.idCancion < A->c.idCancion)
    {
        A->izq= agregarA(A->izq, NN);
    }
    else
    {
        A->der=agregarA(A->der, NN);
    }

    return A;
}

void mostrarINorderA(stnodoArbolCancion* A)
{
    if (A!=NULL)
    {
        mostrarINorderA(A->izq);
        muestraUnaCancion(A->c);
        mostrarINorderA(A->der);
    }
}

void mostrarPREorderA(stnodoArbolCancion* A)
{
    if (A!=NULL)
    {
        muestraUnaCancion(A->c);
        mostrarINorderA(A->izq);
        mostrarINorderA(A->der);
    }
}

void mostrarPOSTorderA(stnodoArbolCancion* A)
{
    if (A!=NULL)
    {
        mostrarINorderA(A->izq);
        mostrarINorderA(A->der);
        muestraUnaCancion(A->c);
    }
}

stnodoArbolCancion* buscarNodoXtitulo (stnodoArbolCancion* A, char titulo[])
{
    stnodoArbolCancion* respuesta= NULL;
    if (A!=NULL)
    {
        if (strcmpi(A->c.titulo, titulo)== 0)
        {
            respuesta= A;
        }
        else if (strcmpi(A->c.titulo, titulo) > 0)
        {
            respuesta=buscarNodoXtitulo(A->izq, titulo);
        }
        else if (strcmpi(A->c.titulo, titulo) < 0)
        {
            respuesta=buscarNodoXtitulo(A->der, titulo);
        }
    }

    return respuesta;
}

stnodoArbolCancion* buscarNodoXartista (stnodoArbolCancion* A, char artista[])
{
    stnodoArbolCancion* respuesta= NULL;
    if (A!=NULL)
    {  if (strcmpi(A->c.artista, artista)== 0)
        {
            respuesta= A;
        }
        else if (respuesta == NULL)
        {
            respuesta=buscarNodoXartista(A->izq, artista);
        }
        else if (respuesta == NULL)
        {
            respuesta=buscarNodoXartista(A->der, artista);
        }
    }
    return respuesta;
}

stnodoArbolCancion* nodoMasDerecho(stnodoArbolCancion * arbol)
{
    stnodoArbolCancion * aux;
    if(arbol->der==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecho(arbol->der);
    }
    return aux;
}

stnodoArbolCancion* nodoMasIzquierdo(stnodoArbolCancion* arbol)
{
    stnodoArbolCancion* aux;
    if(arbol->izq==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierdo(arbol->izq);
    }
    return aux;
}

stnodoArbolCancion* borrarUnNodo(stnodoArbolCancion* arbol, int idCancion) //por ID
{
    if(arbol!=NULL)
    {
        if(idCancion> arbol->c.idCancion)
        {
            arbol->der=borrarUnNodo(arbol->der, idCancion);
        }
        else if (idCancion < arbol->c.idCancion)
        {
            arbol->izq=borrarUnNodo(arbol->izq, idCancion);
        }
        else
        {
            if(arbol->izq!=NULL)
            {
                arbol->c= (nodoMasDerecho(arbol->izq))->c; // not sure whether it is c or c.idCancion
                arbol->izq=borrarUnNodo(arbol->izq, arbol->c.idCancion);
            }
            else if(arbol->der!=NULL)
            {
                arbol->c=(nodoMasIzquierdo(arbol->der))->c; // not sure whether it is c or c.idCancion
                arbol->der=borrarUnNodo(arbol->der, arbol->c.idCancion);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
    }
    return arbol;
}

int cuentaElementos(stnodoArbolCancion* A)
{
        int suma=0;

    if (A!=NULL)
    {
        suma= suma+ cuentaElementos(A->izq) + cuentaElementos(A->der) + 1;
    }

    return suma;
}

int cuentaHojas (stnodoArbolCancion* A)
{
    int suma=0;
    if (A!= NULL)
    {
        suma=suma+ EShojaA(A)+ cuentaHojas(A->izq) + cuentaHojas(A->der);
    }
}

int cuentaNiveles (stnodoArbolCancion* A)
{
    int sumaIzq=0, sumaDer=0, rta=0;

    if (A!= NULL)
    {
       sumaIzq= sumaIzq + 1 + cuentaNiveles(A->izq);
       sumaDer= sumaDer + 1 + cuentaNiveles(A->der);
    }

    if (sumaIzq>sumaDer)
    {
        rta= sumaIzq;
    }
    else rta= sumaDer;


    return rta;
}

int EShojaA (stnodoArbolCancion* A)
{
    int rta=0;
    if ((A->izq==NULL) && (A->der==NULL))
    {
        rta= 1;
    }
    return rta;
}

int sumarA (stnodoArbolCancion* A)
{
    int rta=0;

    if (A!=NULL)
    {
        rta=rta+sumarA(A->izq)+ sumarA(A->der)+A->c.idCancion;
    }
    return rta;
}
