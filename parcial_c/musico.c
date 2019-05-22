#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h"
#define sinfonica 1
#define filarmonica 2
#define camara 3
#define cuerdas 1
#define viento_madera 2
#define viento_metal 3
#define percusion 4


static int generateID(void);

/** \brief Esta funcion para indicar que todas las posiciones del array estan vacias, pone el flag isEmpty en 1.
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \return (-1) si es error [Tamaño invalido o puntero NULL] - (0) si esta Ok
*
*/
int musico_Inicializar(Musico *pMusico, int size)
{
    int retorno=-1;
    if(pMusico!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            pMusico[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca el primer lugar vacio en el array Musico.
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \param posicion Puntero a la posicion del array Musico donde se encuentra el valor buscado
* \return (-1) si no encuentra un espacio vacio o Error [Tamaño invalido o puntero NULL] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico *pMusico, int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(pMusico!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(pMusico[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en el array Musico y devuelve la posicion en que se encuentra.
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \param posicion Puntero a la posicion del array Musico donde se encuentra el valor buscado.
* \return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico *pMusico, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pMusico!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pMusico[i].isEmpty==1)
                continue;
            else if(pMusico[i].idMusico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Esta funcion busca el ID instrumento en el array de Instrumento, que pertenece al Musico.
 *
 * \param Instrumento pInstrumento Puntero a la estructura Instrumento.
 * \param size Tamaño del array.
 * \param valorBuscado El ID encontrado.
 * \param posicion El lugar donde se encuentra el ID en el array.
 * \return -1 Si no se encontro el ID, 0 si se encontro.
 *
 */

int musico_buscarIDinstrumento(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int e;
    if(pInstrumento!= NULL && size>=0)
    {
        for(e=0;e<size;e++)
        {
            if(pInstrumento[e].isEmpty==1)
                continue;
            else if(pInstrumento[e].idInstrumento==valorBuscado)
            {
                retorno=0;
                *posicion=e;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Esta funcion busca el ID Orquesta perteneciente al musico.
 *
 * \param Musico pMusico Puntero a la estructura Musico.
 * \param size Tamaño del array.
 * \param valorBuscado El ID encontrado.
 * \param posicion El lugar donde se encuentra el ID en el array.
 * \return -1 Si no se encontro el ID, 0 si se encontro.
 *
 */
int musico_buscarIdOrquesta(Musico *pMusico, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int e;
    if(pMusico!= NULL && size>=0)
    {
        for(e=0;e<size;e++)
        {
            if(pMusico[e].isEmpty==1)
                continue;
            else if(pMusico[e].suOrquesta==valorBuscado)
            {
                retorno=0;
                *posicion=e;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un int en el array Musico y devuelve la posicion en que se encuentra
* \param Musico pMusico Puntero a la estructura Musico.
 * \param size Tamaño del array.
* \param posicion  Puntero a la posicion del pMusico donde se encuentra el valor buscado
* \return int (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico *pMusico, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pMusico!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pMusico[i].isEmpty==1)
                continue;
            else if(pMusico[i].suInstrumento==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un string en el array Musico.
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \param posicion  Puntero a la posicion del pMusico donde se encuentra el valor buscado
* \return (-1) si no encuentra el valor buscado o Error [Tamaño invalido o puntero NULL] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico *pMusico, int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(pMusico!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pMusico[i].isEmpty==1)
                continue;
            else if(strcmp(pMusico[i].nombre,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Solicita los datos para completar la primer posicion vacia del array Musico.
* \param Musico pMusico Puntero a la estructura Musico.
* \param Orquesta pOrquesta Puntero a la estructura Orquesta.
* \param Instrumento pInstrumento Puntero a la estructura Instrumento
* \param size int Tamaño del array.
* \param contadorID Puntero al ID unico que se va a asignar al nuevo elemento
* \return  (-1) si Error [largo no valido o puntero NULL o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico* pMusico, Orquesta* pOrquesta, Instrumento* pInstrumento, int size, int* contadorID)
{
    int retorno=-1;
    int posicion;

    int bufferInstrumento;
    int bufferOrquesta;

    generateID();
    if(pMusico!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(pMusico,size,&posicion)==-1)
        {
            printf("\nNo hay espacios vacios");
        }
        else
        {
            (*contadorID)++;
            pMusico[posicion].idMusico=*contadorID;
            pMusico[posicion].isEmpty=0;
            utn_getName("Ingrese nombre de musico\n: ","\nError",1,TEXT_SIZE,1,pMusico[posicion].nombre);
            utn_getTexto("Ingrese apellido\n: ","\nError",1,TEXT_SIZE,1,pMusico[posicion].apellido);
            utn_getUnsignedInt("Ingrese edad \n:","\nError",1,sizeof(int),1,99,1,&pMusico[posicion].edad);
            utn_getUnsignedInt("\nQue instrumento seleccionas?\n 1)Cuerdas 2)Viento-Madera 3)Viento-Metal 4)Percusion\n","Error, fuera de rango",1,sizeof(int),1,4,1,&bufferInstrumento);
            pMusico[posicion].suInstrumento= bufferInstrumento;
            utn_getUnsignedInt("\nQue orquesta seleccionas?\n 1)Sinfonica 2)Filarmonica 3)Camara","Error, fuera de rango",1,sizeof(int),1,3,1,&bufferOrquesta);
            pMusico[posicion].suOrquesta= bufferOrquesta;

            printf("\n ID: %d\n \n nombre: %s\n apellido: %s \n Su orquesta es: %d \n Su Instrumento es: %d",
                   pMusico[posicion].idMusico,pMusico[posicion].nombre,pMusico[posicion].apellido,pMusico[posicion].suOrquesta,pMusico[posicion].suInstrumento);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Borra un elemento del array Musico por ID
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \return (-1) si Error [largo no valido o puntero NULL o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico *pMusico, int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(pMusico!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID de Musico a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(musico_buscarID(pMusico,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            pMusico[posicion].isEmpty=1;
            pMusico[posicion].idMusico=0;
            pMusico[posicion].suInstrumento=0;
            strcpy(pMusico[posicion].nombre,"");
            strcpy(pMusico[posicion].apellido,"");
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Borra los musicos pertenecientes al ID de la Orquesta.
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \param idOrquesta ID otorgado a una orquesta especifica.
* \return (-1) si Error [largo no valido o puntero NULL o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaPorOrquesta(Musico *pMusico, int sizeArray, int idOrquesta)
{
    int retorno=-1;
    int posicion;
    if(pMusico!=NULL && sizeArray>0)

    {
        if(musico_buscarIdOrquesta(pMusico,sizeArray,idOrquesta,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            pMusico[posicion].isEmpty=1;
            pMusico[posicion].idMusico=0;
            pMusico[posicion].suInstrumento=0;
            strcpy(pMusico[posicion].nombre,"");
            strcpy(pMusico[posicion].apellido,"");
            retorno=0;
            printf("\nSe elimino con exito\n");
        }
    }
    return retorno;
}

/** \brief Borra todos los elemento del pMusico que contengan el valor buscado
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \param valorBuscado  Valor a buscar en el array Musico
* \return  (-1) si Error [largo no valido o puntero NULL o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico *pMusico, int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(pMusico!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(pMusico[i].idMusico==valorBuscado)
            {
                pMusico[i].isEmpty=1;
                pMusico[i].idMusico=0;
                pMusico[i].suInstrumento=0;
                strcpy(pMusico[i].nombre,"");
                strcpy(pMusico[i].apellido,"");
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Busca un elemento por ID del Musico y modifica sus campos
* \param Musico pMusico Puntero a la estructura Instrumento.
* \param size Tamaño del array.
* \return int Return (-1) si Error [largo no valido o puntero NULL o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico *pMusico,Orquesta *pOrquesta, int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(pMusico!=NULL && sizeArray>0)
    {
        musico_listar(pMusico,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(musico_buscarID(pMusico,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                utn_getChar("\nModificar del Musico:\n A)Edad\n B)ID de la Orquesta \nS)Salir\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nIngrese nueva edad:\n","\nError",1,sizeof(int),1,99,1,&pMusico[posicion].edad);
                        printf("\nEdad modificada, ahora tiene %d\n",pMusico[posicion].edad) ;

                        break;
                    case 'B':
                        utn_getUnsignedInt("\nIngrese nuevo ID:\n","\nError",1,sizeof(int),1,sizeArray,1,&pOrquesta[posicion].idOrquesta);
                        printf("\nID modificado, ahora el ID es :%d\n",pOrquesta[posicion].idOrquesta);

                        break;
                    case 'S':

                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Ordena por campo XXXXX los elementos del array Musico
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \return (-1) si Error [largo no valido o puntero NULL] - (0) si se ordena exitosamente
*
*/
int musico_ordenarPorString(Musico *pMusico,int size)
{
    int retorno=-1;
    int i, j;
    char bufferString[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    int bufferInt;
    char bufferLongString[TEXT_SIZE];

    if(pMusico!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferString,pMusico[i].nombre);
            bufferId=pMusico[i].idMusico;
            bufferIsEmpty=pMusico[i].isEmpty;
            bufferInt=pMusico[i].suInstrumento;
            strcpy(bufferLongString,pMusico[i].apellido);
            j = i - 1;

            while ((j >= 0) && strcmp(bufferString,pMusico[j].nombre)<0)
            {
                strcpy(pMusico[j + 1].nombre,pMusico[j].nombre);
                pMusico[j + 1].idMusico=pMusico[j].idMusico;
                pMusico[j + 1].isEmpty=pMusico[j].isEmpty;
                pMusico[j + 1].suInstrumento=pMusico[j].suInstrumento;
                strcpy(pMusico[j + 1].apellido,pMusico[j].apellido);
                j--;
            }
            strcpy(pMusico[j + 1].nombre,bufferString);
            pMusico[j + 1].idMusico=bufferId;
            pMusico[j + 1].isEmpty=bufferIsEmpty;
            pMusico[j + 1].suInstrumento=bufferInt;
            strcpy(pMusico[j + 1].apellido,bufferLongString);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Lista los elementos del array Musico.
* \param Musico pMusico Puntero a la estructura Musico.
* \param size Tamaño del array.
* \return  (-1) si Error [largo no valido o puntero NULL] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico *pMusico, int CANT_MUSICO)
{
    int retorno=-1;
    int i;
    if(pMusico!=NULL && CANT_MUSICO>=0)
    {
        for(i=0;i<CANT_MUSICO;i++)
        {
            if(pMusico[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n suInstrumento: %d\n nombre: %s\n apellido: %s\n ",
                       pMusico[i].idMusico,pMusico[i].suInstrumento,pMusico[i].nombre,pMusico[i].apellido);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Genera un ID para el Musico.
 *

 * \return El id del Musico autoincrementado.
 *
 */

static int generateID(void)
{
    static int idMus = 0;
    return idMus++;
}
