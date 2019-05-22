#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "instrumento.h"
#define TEXT_SIZE 50
#define cuerdas 1
#define viento_madera 2
#define viento_metal 3
#define percusion 4

static int generateID(void);

/** \brief  Esta funcion para indicar que todas las posiciones del array estan vacias, pone el flag isEmpty en 1.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \return int (-1) si da Error [Tamaño invalido o puntero NULL] - (0) si esta Ok
*
*/
int instrumento_Inicializar(Instrumento *pInstrumento, int size)
{
    int retorno=-1;
    if(pInstrumento!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            pInstrumento[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca el primer espacio vacio en el array Instrumento.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \param Puntero a la posicion del pInstrumento donde se encuentra el valor buscado
* \return  (-1) si no encuentra un apellido vacio o Error [Tamaño invalido o puntero NULL] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento *pInstrumento, int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(pInstrumento!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en el array Instrumento y devuelve la posicion en que se encuentra.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \param Puntero a la posicion del array Instrumento donde se encuentra el valor buscado
* \return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pInstrumento!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else if(pInstrumento[i].idInstrumento==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en el array Instrumento y devuelve la posicion en que se encuentra.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \param Puntero a la posicion del array Instrumento donde se encuentra el valor buscado
* \return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarIDnuevo(Instrumento *pInstrumento, int size, char* valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pInstrumento!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else if(pInstrumento[i].nombreInstrumento==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en el array Instrumento y devuelve la posicion en que se encuentra
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \param valorBuscado El int encontrado.
* \param  Posicion Puntero a la posicion del pInstrumento donde se encuentra el valor buscado.
* \return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarInt(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion)
{


    int retorno=-1;
    int i;
    if(pInstrumento!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else if(pInstrumento[i].instrumento==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en el array Instrumento.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \param posicion Puntero a la posicion del pInstrumento donde se encuentra el valor buscado
* \return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarString(Instrumento *pInstrumento, int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(pInstrumento!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else if(strcmp(pInstrumento[i].nombreInstrumento,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Solicita los datos para completar la primer posicion vacia del array Instrumento.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \param contadorID  Puntero al ID unico que se va a asignar al nuevo elemento
* \return (-1) si Error [largo no valido o puntero NULL o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento *pInstrumento, int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    generateID();
    if(pInstrumento!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(pInstrumento,size,&posicion)==-1)
        {
            printf("\nNo hay espacios vacios");
        }
        else
        {
            (*contadorID)++;
            pInstrumento[posicion].idInstrumento=*contadorID;
            pInstrumento[posicion].isEmpty=0;
            utn_getName("\nIngrese nombre del Instrumento:\n ","\nError",1,TEXT_SIZE,1,pInstrumento[posicion].nombreInstrumento);
            utn_getUnsignedInt("\nIngrese tipo de Instrumento \n 1) Cuerdas \n 2) Viento-madera \n 3) viento-Metal \n 4) Percusion \n:","\nError",1,sizeof(int),1,4,1,&pInstrumento[posicion].instrumento);
            printf("\n ID: %d\n Nombre del Instrumento: %s\n Su Instrumento es de tipo: %d",
                   pInstrumento[posicion].idInstrumento,pInstrumento[posicion].nombreInstrumento,pInstrumento[posicion].instrumento);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array instrumento por ID.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \return  (-1) si Error [largo no valido o puntero NULL o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_baja(Instrumento *pInstrumento, int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(pInstrumento!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID de Instrumento a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(instrumento_buscarID(pInstrumento,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            pInstrumento[posicion].isEmpty=1;
            pInstrumento[posicion].idInstrumento=0;
            pInstrumento[posicion].instrumento=0;
            strcpy(pInstrumento[posicion].nombreInstrumento,"");
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Borra todos los elemento del array Instrumento que contengan el valor buscado repetido.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \param valorBuscado  Valor a buscar en el array instrumento.
* \return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int instrumento_bajaValorRepetidoInt(Instrumento *pInstrumento, int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(pInstrumento!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(pInstrumento[i].idInstrumento==valorBuscado)
            {
                pInstrumento[i].isEmpty=1;
                pInstrumento[i].idInstrumento=0;
                pInstrumento[i].instrumento=0;
                strcpy(pInstrumento[i].nombreInstrumento,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordena por campo XXXXX los elementos del array instrumento.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int instrumento_ordenarPorString(Instrumento *pInstrumento,int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    int bufferInt;

    if(pInstrumento!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,pInstrumento[i].nombreInstrumento);
            bufferId=pInstrumento[i].idInstrumento;
            bufferIsEmpty=pInstrumento[i].isEmpty;
            bufferInt=pInstrumento[i].instrumento;
            j = i - 1;
            while ((j >= 0) && strcmp(bufferString,pInstrumento[j].nombreInstrumento)<0)
            {
                strcpy(pInstrumento[j + 1].nombreInstrumento,pInstrumento[j].nombreInstrumento);
                pInstrumento[j + 1].idInstrumento=pInstrumento[j].idInstrumento;
                pInstrumento[j + 1].isEmpty=pInstrumento[j].isEmpty;
                pInstrumento[j + 1].instrumento=pInstrumento[j].instrumento;
                j--;
            }
            strcpy(pInstrumento[j + 1].nombreInstrumento,bufferString);
            pInstrumento[j + 1].idInstrumento=bufferId;
            pInstrumento[j + 1].isEmpty=bufferIsEmpty;

            pInstrumento[j + 1].instrumento=bufferInt;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Lista los elementos del array Instrumento.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento.
* \param CANT_INSTRUMENTO Tamaño del array.
* \return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento *pInstrumento, int CANT_INSTRUMENTO)
{
    int retorno=-1;

    char bufferCuerda[TEXT_SIZE]="Instrumento de Cuerdas";
    char bufferVientoMadera[TEXT_SIZE]="Instrumento de Viento Madera";
    char bufferVientoMetal[TEXT_SIZE]="Instrumento de Viento Metal";
    char bufferPercusion[TEXT_SIZE]="Instrumento de percusion";
    int i;
    if(pInstrumento!=NULL && CANT_INSTRUMENTO>=0)
    {
        for(i=0;i<CANT_INSTRUMENTO;i++)
        {
            if(pInstrumento[i].isEmpty==1)
                continue;
            else
                {
                  switch(pInstrumento[i].instrumento)
                  {
                      case cuerdas:
                      printf("\nTipo de instrumento: %s\n",bufferCuerda);
                      break;

                      case viento_madera:
                      printf("\nTipo de instrumento: %s\n",bufferVientoMadera);
                      break;

                      case viento_metal:
                      printf("\nTipo de instrumento: %s\n",bufferVientoMetal);
                      break;

                      case percusion:
                      printf("\nTipo de instrumento: %s\n",bufferPercusion);
                      break;
                      default:
                        printf("No hay instrumento");
                        break;

                  }
                  printf("\nEl ID del instrumento es : %d\nEl nombre del instrumento es: %s\n",pInstrumento[i].idInstrumento,
                                                                                                pInstrumento[i].nombreInstrumento);
                  }
                }
        }
    retorno=0;
    return retorno;
}
/** \brief Genera un ID para el instrumento.
 *

 * \return Retorna el ID del instrumento autoincrementado.
 *
 */

static int generateID(void)
{
    static int idMus = 0;
    return idMus++;
}

