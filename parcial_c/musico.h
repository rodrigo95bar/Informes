#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#define TEXT_SIZE 50

typedef struct
{
    int idMusico;
    int isEmpty;
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int edad;
    int suOrquesta;
    int suInstrumento;

}Musico;



int musico_Inicializar(Musico *pMusico, int size);
int musico_buscarEmpty(Musico *pMusico, int size, int* posicion);
int musico_buscarID(Musico *pMusico, int size, int valorBuscado, int* posicion);
int musico_buscarIdOrquesta(Musico *pMusico, int size, int valorBuscado, int* posicion);
int musico_alta(Musico* pMusico, Orquesta* pOrquesta, Instrumento* pInstrumento , int size, int* contadorID);
int musico_buscarInt(Musico *pMusico, int size, int valorBuscado, int* posicion);
int musico_buscarString(Musico *pMusico, int size, char* valorBuscado, int* indice);
int musico_baja(Musico *pMusico, int sizeArray);
int musico_bajaPorOrquesta(Musico *pMusico, int sizeArray, int idOrquesta);
int musico_bajaValorRepetidoInt(Musico *pMusico, int sizeArray, int valorBuscado);
int musico_modificar(Musico *pMusico,Orquesta *pOrquesta, int sizeArray);
int musico_ordenarPorString(Musico *pMusico,int size);
int musico_listar(Musico *pMusico, int size);

#endif // MUSICO_H_INCLUDED

