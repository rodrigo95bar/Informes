#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
#include "instrumento.h"

#define TEXT_SIZE 50
typedef struct
{
    int idOrquesta;
    int isEmpty;
    char nombre[TEXT_SIZE];
    char lugar[TEXT_SIZE];
    int tipoOrquesta;
    int tipoInstrumento;


}Orquesta;




int orquesta_Inicializar(Orquesta *pOrquesta, int size);
int orquesta_buscarEmpty(Orquesta *pOrquesta, int size, int* posicion);
int orquesta_buscarID(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion);
int orquesta_buscarTipo(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion);
int orquesta_buscarInt(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion);
int orquesta_buscarString(Orquesta *pOrquesta, int size, char* valorBuscado, int* indice);
int musico_buscarIDorquesta(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion);
int orquesta_alta(Orquesta* pOrquesta, int size, int* contadorID);
int orquesta_baja(Orquesta* pOrquesta, int sizeArray);
int orquesta_bajaValorRepetidoInt(Orquesta *pOrquesta, int sizeArray, int valorBuscado);
int orquesta_modificar(Orquesta *pOrquesta, int sizeArray);
int orquesta_ordenarPorString(Orquesta *pOrquesta,int size);
int orquesta_listar(Orquesta *pOrquesta, int size);



#endif // ORQUESTA_H_INCLUDED
