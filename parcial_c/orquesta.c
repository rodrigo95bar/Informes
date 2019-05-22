#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"

static int generateID(void);

/** \brief  Esta funcion para indicar que todas las posiciones del array estan vacias, pone el flag isEmpty en 1.
* \param Orquesta pOrquesta Puntero a la estructura Orquesta
* \param size Tamaño del array.
* \return  (-1)Si es error [Tamaño invalido o puntero NULL] - (0) si esta Ok
*
*/
int orquesta_Inicializar(Orquesta *pOrquesta, int size)
{
    int retorno=-1;
    if(pOrquesta!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            pOrquesta[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca el primer lugar vacio en el array de Orquesta.
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param size Tamaño del array.
* \param posicion Puntero a la posicion del pOrquesta donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Tamaño invalido o puntero NULL] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta *pOrquesta, int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(pOrquesta!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pOrquesta[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en el Array de Orquesta y devuelve la posicion en que se encuentra.
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param size Tamaño del array.
* \param posicion Puntero a la posicion del array Orquesta donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pOrquesta!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pOrquesta[i].isEmpty==1)
                continue;
            else if(pOrquesta[i].idOrquesta==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un int en el array de Orquesta y devuelve la posicion en que se encuentra
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param size Tamaño del array.
* \param posicion Puntero a la posicion del array Orquesta donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta *pOrquesta, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pOrquesta!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pOrquesta[i].isEmpty==1)
                continue;
            else if(pOrquesta[i].tipoOrquesta==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en el array de Orquesta.
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param size Tamaño del array.
* \param posicion Puntero a la posicion del array Orquesta donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta *pOrquesta, int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(pOrquesta!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pOrquesta[i].isEmpty==1)
                continue;
            else if(strcmp(pOrquesta[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Solicita los datos para completar la primer posicion vacia del array Orquesta.
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param size Tamaño del array.
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o puntero NULL o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta* pOrquesta, int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    generateID();
    if(pOrquesta!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(pOrquesta,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            pOrquesta[posicion].idOrquesta=*contadorID;
            pOrquesta[posicion].isEmpty=0;
            utn_getName("Ingrese nombre de orquesta\n: ","\nError",1,TEXT_SIZE,1,pOrquesta[posicion].nombre);
            utn_getTexto("Ingrese lugar\n: ","\nError",1,TEXT_SIZE,1,pOrquesta[posicion].lugar);
            utn_getUnsignedInt("Ingrese tipo de Orquesta: \n 1) Sinfonica \n 2) Filarmonica \n 3) Camara","\nError",1,sizeof(int),1,3,1,&pOrquesta[posicion].tipoOrquesta);
            utn_getUnsignedInt("Ingrese tipo de Instrumento: \n 1) Cuerdas \n 2) Viento-madera \n 3) viento-Metal \n 4) Percusion","\nError",1,sizeof(int),1,4,1,&pOrquesta[posicion].tipoInstrumento);

            printf("\n Posicion: %d\n ID: %d\n \n nombre: %s\n lugar: %s \n Tipo de orquesta: %d \n Tipo de Instrumento: %d",
                   posicion, pOrquesta[posicion].idOrquesta,pOrquesta[posicion].nombre,pOrquesta[posicion].lugar,pOrquesta[posicion].tipoOrquesta,pOrquesta[posicion].tipoInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array Orquesta por ID
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param size Tamaño del array.
* \return int Return (-1) si Error [largo no valido o puntero NULL o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente.
*
*/
int orquesta_baja(Orquesta* pOrquesta, int sizeArray)
{
    int posicion;
    int id;
    if(pOrquesta!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID de Orquesta a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(orquesta_buscarID(pOrquesta,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            pOrquesta[posicion].isEmpty=1;
            pOrquesta[posicion].idOrquesta=0;
            pOrquesta[posicion].tipoOrquesta=0;
            strcpy(pOrquesta[posicion].nombre,"");
            strcpy(pOrquesta[posicion].lugar,"");
        }
    }
    return id;
}

/** \brief Borra todos los elemento del array Orquesta que contengan el valor buscado
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param sizeArray Tamaño del array.
* \param valorBuscado  Valor a buscar en el array de Orquesta.
* \return int Return (-1) si Error [largo no valido o puntero NULL o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente.
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta *pOrquesta, int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(pOrquesta!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(pOrquesta[i].idOrquesta==valorBuscado)
            {
                pOrquesta[i].isEmpty=1;
                pOrquesta[i].idOrquesta=0;
                pOrquesta[i].tipoOrquesta=0;
                strcpy(pOrquesta[i].nombre,"");
                strcpy(pOrquesta[i].lugar,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordena por campo XXXXX los elementos del array Orquesta.
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param size Tamaño del array.
* \return int Return (-1) si Error [largo no valido o puntero NULL] - (0) si se ordena exitosamente
*
*/
int orquesta_ordenarPorString(Orquesta *pOrquesta,int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    int bufferInt;
    char bufferLongString[TEXT_SIZE];

    if(pOrquesta!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,pOrquesta[i].nombre);
            bufferId=pOrquesta[i].idOrquesta;
            bufferIsEmpty=pOrquesta[i].isEmpty;
            bufferInt=pOrquesta[i].tipoOrquesta;
            strcpy(bufferLongString,pOrquesta[i].lugar);
            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,pOrquesta[j].nombre)<0)
            {
                strcpy(pOrquesta[j + 1].nombre,pOrquesta[j].nombre);
                pOrquesta[j + 1].idOrquesta=pOrquesta[j].idOrquesta;
                pOrquesta[j + 1].isEmpty=pOrquesta[j].isEmpty;
                pOrquesta[j + 1].tipoOrquesta=pOrquesta[j].tipoOrquesta;
                strcpy(pOrquesta[j + 1].lugar,pOrquesta[j].lugar);

                j--;
            }
            strcpy(pOrquesta[j + 1].nombre,bufferString);
            pOrquesta[j + 1].idOrquesta=bufferId;
            pOrquesta[j + 1].isEmpty=bufferIsEmpty;
            pOrquesta[j + 1].tipoOrquesta=bufferInt;
            strcpy(pOrquesta[j + 1].lugar,bufferLongString);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Lista los elementos del array Orquesta.
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param CANT_ORQUESTA Tamaño del array.
* \return int Return (-1) si Error [largo no valido o puntero NULL] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta *pOrquesta, int CANT_ORQUESTA)
{
    int retorno=-1;
    int i;
    if(pOrquesta!=NULL && CANT_ORQUESTA>=0)
    {
        for(i=0;i<CANT_ORQUESTA;i++)
        {
            if(pOrquesta[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n tipoOrquesta: %d\n nombre: %s\n lugar: %s",
                       pOrquesta[i].idOrquesta,pOrquesta[i].tipoOrquesta,pOrquesta[i].nombre,pOrquesta[i].lugar);
        }
        retorno=0;
    }
    return retorno;
}

static int generateID(void)
{
    static int idOrq = 0;
    return idOrq++;
}
