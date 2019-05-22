#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#define COL 25
//cambiar por nombre entidad
/*
** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*
int Informes_listarPorCriterio(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(arrayA[i].isEmpty==1)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            if(strcmp(arrayA[i].varString,criterio)==0)
            {
                fantasma_buscarID(arrayB,sizeJ,arrayA[i].idUnico,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID A: %d\nID B: %d",
                       arrayA[i].idUnico,arrayB[j].idUnico);
            }

        }
        retorno=0;
    }
    return retorno;
}

** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*
//Lista un campo que se repite, lo imprime una sola vez y calcula contador y acumulado
int Informes_listarCriterioContadorAcumulado(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            fantasma_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].varString);                                   //Imprimo el valor que voy a listar
                for(k=i,contador=0,acumulado=0;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].varString,arrayA[i].varString)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        fantasma_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].varInt*arrayB[j].varInt);

                        printf("\nID A: %d\nID B: %d",
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                printf("\nCantidad: %d \nAcumulado: %d",contador,acumulado);
                //contador=0;
                //acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}

** \brief Busca un maximo de ocurrencia y acumulado
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*
int Informes_maxContadorAcumulado(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int maxAcumulado=0;
    int maxContador=0;
    int acumulador=0;
    int contador=0;
    int iMaxAcumulado [sizeI];
    int iMaxContador [sizeI];

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            fantasma_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                printf("\nCampo: %s",arrayA[i].varString);                                   //Imprimo el valor que voy a listar
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].varString,arrayA[i].varString)==0)     //Busco todas las veces que aparece ese cuit
                    {

                        fantasma_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;                                                         //calculos acumulados y contador
                        acumulador+=(arrayA[k].varInt*arrayB[j].varInt);

                        printf("\nID A: %d\nID B: %d",                                         //imprimo datos que haya que mostrar
                                arrayA[k].idUnico,arrayB[j].idUnico);
                    }
                }
                //Guardo los max acumulado y contador
                if(acumulador>maxAcumulado)
                {
                    maxAcumulado=acumulador;
                    iMaxAcumulado[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxAcumulado[i]=i;
                }
                else if(acumulador==maxAcumulado)
                    iMaxAcumulado[i]=i;
                else
                    iMaxAcumulado[i]=-2;                         //Para marcar los lugares vacios

                acumulador=0;

                if(contador>maxContador)
                {
                    maxContador=contador;
                    iMaxContador[i-1]=-1;                       //Si mas de un cuit tiene la mayor facturacion
                    iMaxContador[i]=i;
                }
                else if(contador==maxContador)
                    iMaxContador[i]=i;
                else
                    iMaxContador[i]=-2;                         //Para marcar los lugares vacios

                contador=0;
            }
        }

        printf("\nMayor acumulado: %d \nMayor contador: %d \nI: ",maxAcumulado,maxContador);
        for(;iMaxAcumulado[i]!=-1;i--)                                                      //Uno o el otro, sino agregar otro contador que no sea el i
        {
            if(iMaxAcumulado[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxAcumulado[i]].varString);
            }
        }
        for(;iMaxContador[i]!=-1;i--)
        {
            if(iMaxContador[i]!=-2)                         //Salteo los vacios
            {
                printf("\n          CUIT: %s",arrayA[iMaxContador[i]].varString);
            }
        }

        retorno=0;
    }
    return retorno;
}

** \brief Crea una entidad auxiliar para ordenar e informar XXXXX
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*
int Informes_listarAuxiliarOrdenar(Fantasma arrayA[], Fantasma arrayB[], int sizeI, int sizeJ)         //cambiar Fantasma
{
    int retorno=-1;
    int i;
    int j;
    int k;
    int auxPosicion;
    int contador=0;
    int acumulado=0;

    Fantasma arrayAux[sizeI];                                                           //cambiar Fantasma y size si corresponde

    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            fantasma_buscarString(arrayA,i,arrayA[i].varString,&auxPosicion);                  //cambiar nombreFuncion y campo      va a analizar hasta <i
            if(arrayA[i].isEmpty==1 && auxPosicion!=-1)
                continue;                                                                 //Si ese valor ya aparecio > continue
            else
            {
                strcpy(arrayAux[i].varString,arrayA[i].varString);                              //cambio varstring
                for(k=i;k<sizeI;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    if(arrayA[k].isEmpty!=1 && strcmp(arrayA[k].varString,arrayA[i].varString)==0)     //Busco todas las veces que aparece ese cuit
                    {
                        fantasma_buscarID(arrayB,sizeJ,arrayA[k].idUnico,&j);                 //cambiar Fantasma, busco por el campo en comun

                        contador++;
                        acumulado+=(arrayA[k].varInt*arrayB[j].varInt);

                    }
                }
                arrayAux[i].varInt=contador;                                    //completo el resto de los campos
                arrayAux[i].varInt=acumulado;
                arrayAux[i].isEmpty=0;

                contador=0;
                acumulado=0;
            }
        }
        retorno=0;
    }
    return retorno;
}
*/

/** \brief Busca un valor y lista los elementos de dos arrays vinculados
* \param arrayA Fantasma Array de Fantasma
* \param arrayB Fantasma Array de Fantasma
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \param criterio char* Puntero al valor que debe contener el elemento del array para que se liste
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*
*/
int Informes_listarPorCriterio(Musico *pMusico, Instrumento *pInstrumento, int sizeI, int sizeJ, char* criterio)  //Valores de dos arrays. Si es valor repetido se vuelve a imprimir
{
    int retorno=-1;
    int i;
    int j;
    if(pMusico!=NULL && sizeI>=0 && pInstrumento!=NULL && sizeJ>=0 && criterio!=NULL)
    {
        for(i=0;i<sizeI;i++)                                                                            //Obtengo la posicion de la primer entidad
        {
            if(pMusico[i].isEmpty==1)                 //cambiar campo donde busco el criterio
                continue;                                                                       //si esta vacio o no tiene el criterio > continue
            if(strcmp(pMusico[i].nombre,criterio)==0)
            {
                instrumento_buscarIDnuevo(pInstrumento,sizeJ,pMusico[i].nombre,&j);                            //Obtengo la posicion de la 2da entidad buscando por el campo en comun
                printf("\nID A: %s\nID B: %s",
                       pMusico[i].nombre,pInstrumento[j].nombreInstrumento);
            }

        }
        retorno=0;
    }
    return retorno;
}

/*
void nombreMasLargo(int size)
{
int i,j,x,lmax=0,imax;
char mat[size][COL],aux[COL];
for(i=0;i<size;i++)
{
printf("Ingrese nombre: ");
gets(mat[i]);
}
// Ordeno alfabeticamente la matriz
for(i=0;i<size-1;i++)
{
for(j=i+1;j<size;j++)
{
if((strcmp(mat[i],mat[j]))>0)
{
strcpy(aux,mat[i]);
strcpy(mat[i],mat[j]);
strcpy(mat[j],aux);
}
}
}
// Busqueda del nombre mas largo
for(i=0;i<size;i++)
{
x=strlen(mat[i]);
if(x>lmax)
{
lmax=x;
imax=i;
}
}
printf("El nombre mas largo es %s",mat[imax]);
}
*/



/*int ordenar_numeros(Musico *pMusico, int size)
{
int Aux;

         for(int i=0;i<size;i++)
                for(int j=0;j<size-1;j++){
                    if(pMusico[j].idMusico<pMusico[j+1].idMusico){
                                                                        // cambia "<" a ">" para cambiar la manera de ordenar
                        Aux=pMusico[j].idMusico;
                        pMusico[j].idMusico=pMusico[j+1].idMusico;
                        pMusico[j+1].idMusico=Aux; }

           for(int i=0;i<size;i++)
                if(pMusico[i].isEmpty==0 && pMusico[i].idMusico!=0 && pMusico!=NULL )
                     printf("\nID : %d\n",pMusico[j].idMusico);

                else
                   continue;
                }
                return 0;
                }

*/

/*int ordenar_numeros(Musico *pMusico, int TAM)

{
int temp;
int i,j;

for (i=1;i<TAM;i++)
{
	for (j=0;j<TAM-1;j++)
	{
		if (pMusico[j].edad > pMusico[j+1].edad)
		{
			temp = pMusico[j].edad;
			pMusico[j].edad=pMusico[j+1].edad;
			pMusico[j+1].edad=temp;
		}
	}

}
printf("\nLos valores ORDENADOS de lista son: \n");
for(i=0;i<TAM;i++)
{
     if(pMusico[i].isEmpty==1)
        continue;
     else{
        printf("\nEdad ordenada : %d\n",pMusico[j].edad);
         }

}
return 0;
}

*/



/** \brief Ordena de mayor a menor Numeros.
 *
 * \param Musico pMusico Puntero a la estructura Musico.
 * \param TAM Tamaño del array.
 * \return void.
 *
 */

void ordenar_numerosMayorAmenor(Musico *pMusico, int TAM)
{

int temp;
    int i,j;

    for(i = 0; i < TAM-1; i++){
        for(j = i+1; j < TAM; j++){
            if(pMusico[i].edad < pMusico[j].edad)
            {
                temp = pMusico[i].edad;
                pMusico[i].edad = pMusico[j].edad;
                pMusico[j].edad = temp;
            }
        }
    }
    for(int j = 0; j<TAM; j++){
            if(pMusico[j].isEmpty==1)
            continue;
    else
        printf("%d\n",pMusico[j].edad);
    }
}

/** \brief Ordena de menor a mayor Numeros.
 *
 * \param Musico pMusico Puntero a la estructura Musico.
 * \param TAM Tamaño del array.
 * \return void.
 *
 */

void ordenar_numerosMenorAmayor(Musico *pMusico, int TAM)
{

int temp;
    int i,j;

    for(i = 0; i < TAM-1; i++){
        for(j = i+1; j < TAM; j++){
            if(pMusico[i].edad > pMusico[j].edad)
            {
                temp = pMusico[i].edad;
                pMusico[i].edad = pMusico[j].edad;
                pMusico[j].edad = temp;
            }
        }
    }
    for(int j = 0; j<TAM; j++){
            if(pMusico[j].isEmpty==1)
            continue;
    else
        printf("%d\n",pMusico[j].edad);
    }
}


/** \brief Saca el promedio total de los musicos en todas las orquestas.
 *
 * \param Musico pMusico Puntero a la estructura Musico.
 * \param Orquesta pOrquesta Puntero a la estructura Orquesta.
 * \param sizeM Tamaño del array Musico.
 * \param sizeO Tamaño del array Orquesta.
 * \return void.
 *
 */

void promedioTotalMusicoOrquesta(Musico *pMusico,Orquesta *pOrquesta,int sizeM,int sizeO)
{
  int contadorMusico=0;
  int contadorOrquesta=0;
  int i,j;
  int promedio;
   for(i=0;i < sizeM;i++)
   {
       if(pMusico[i].isEmpty==0)
          contadorMusico++;

       else
         continue;
   }

    for(j=0; j < sizeO;j++)
    {
        if(pOrquesta[j].isEmpty==0)
            contadorOrquesta++;

        else
            continue;
    }
    promedio = contadorMusico / contadorOrquesta;

    printf("\nEl promedio de musicos es: %d\n",promedio);

}










/** \brief Determina la cantidad de instrumentos de cada tipo.
 *
 * \param Instrumento pInstrumento Puntero a la estructura Instrumento
 * \param size Tamaño del array instrumento.
 * \return
 *
 */

 void promedioInstrumentoDeTipo(Instrumento *pInstrumento,int size)
 {
int contadorInstrumento1=0;
int contadorInstrumento2=0;
int contadorInstrumento3=0;
int contadorInstrumento4=0;
int i;

for(i=0; i<size;i++)
{
    if(pInstrumento[i].isEmpty==0 && pInstrumento[i].instrumento==1)
    {
        contadorInstrumento1++;
        continue;
    }
    if(pInstrumento[i].isEmpty==0 && pInstrumento[i].instrumento==2)
    {
        contadorInstrumento2++;
        continue;
    }
    if(pInstrumento[i].isEmpty==0 && pInstrumento[i].instrumento==3)
    {
        contadorInstrumento3++;
        continue;
    }
    if(pInstrumento[i].isEmpty==0 && pInstrumento[i].instrumento==4)
    {
        contadorInstrumento4++;
        continue;
    }
    else
        continue;
}

printf("\n La cantidad de Instrumentos de tipo 1 es: %d\n La cantidad de Instrumentos de tipo 2 es: %d\n La cantidad de Instrumentos de tipo 3 es: %d\n La cantidad de Instrumentos de tipo 4 es: %d\n",contadorInstrumento1,
                                                                                                                                                                                                      contadorInstrumento2,
                                                                                                                                                                                                      contadorInstrumento3,
                                                                                                                                                                                                      contadorInstrumento4);


 }







/** \brief Determina el instrumento mas usado a traves del ordenamiento mayor a menor, solo mostrando el numero mas grande.
 *
 * \param Instrumento pInstrumento Puntero a la estructura Instrumento
 * \param size Tamaño array de Instrumento
 * \return
 *
 */

void instrumentoMasUsado(Instrumento *pInstrumento, int size)
{
int temp;
int i;
int j,k;

int contadorInstrumento1=0;
int contadorInstrumento2=0;
int contadorInstrumento3=0;
int contadorInstrumento4=0;
int bufferInstrumento1;
int bufferInstrumento2;
int bufferInstrumento3;
int bufferInstrumento4;
int maximo=0;
int maximoFinal;
for(k=0; k<size;k++)
{
    if(pInstrumento[k].isEmpty==0 && pInstrumento[k].instrumento==1)
    {
        contadorInstrumento1++;
        continue;
    }
    if(pInstrumento[k].isEmpty==0 && pInstrumento[k].instrumento==2)
    {
        contadorInstrumento2++;
        continue;
    }
    if(pInstrumento[k].isEmpty==0 && pInstrumento[k].instrumento==3)
    {
        contadorInstrumento3++;
        continue;
    }
    if(pInstrumento[k].isEmpty==0 && pInstrumento[k].instrumento==4)
    {
        contadorInstrumento4++;
        continue;
    }
    else
        continue;
}

 bufferInstrumento1 = contadorInstrumento1;
 bufferInstrumento2 = contadorInstrumento2;
 bufferInstrumento3 = contadorInstrumento3;
 bufferInstrumento4 = contadorInstrumento4;


  if(bufferInstrumento1>maximo)
{

    maximo=bufferInstrumento1;
   //maximo=bufferMusico1;
   maximoFinal=1;

}
 if(bufferInstrumento2>maximo)
{
    maximo=bufferInstrumento2;
   // maximo=bufferMusico2;
    maximoFinal=2;
}
 if(bufferInstrumento3>maximo)
{
    maximo=bufferInstrumento3;
   //maximo=bufferMusico3;
   maximoFinal=3;
}

if(bufferInstrumento4>maximo)
{
    maximo=bufferInstrumento4;
   //maximo=bufferMusico3;
   maximoFinal=4;
}


int array[4] = {bufferInstrumento1,bufferInstrumento2,bufferInstrumento3,bufferInstrumento4};
    for(i = 0; i < 4-1; i++){
        for(j = i+1; j < 4; j++){
            if(array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }



  switch(maximoFinal)
  {
    case 1:
        printf("\nEl instrumento mas utiliazado es de tipo: %d, Cuerdas\n",maximoFinal);
        break;

    case 2:
        printf("\nEl instrumento mas utiliazado es de tipo: %d, Viento Madera\n",maximoFinal);
        break;

    case 3:
        printf("\nEl instrumento mas utiliazado es de tipo:: %d, Viento Metal\n",maximoFinal);
        break;

    case 4:
        printf("\nEl instrumento mas utiliazado es de tipo: %d, Percusion\n",maximoFinal);
        break;

    default:
        break;
  }





  for(int j = 0; j<4; j++){
        printf("\nLa cantidad total del instrumento mas utilizado es: %d\n",array[j]);
        break;
    }
}



/** \brief Determina el instrumento menos usado a traves del ordenamiento menor a mayor, solo mostrando el numero mas pequeño.
 *
 * \param Instrumento pInstrumento Puntero a la estructura Instrumento
 * \param size Tamaño array de Instrumento
 * \return
 *
 */

void instrumentoMenosUsado(Instrumento *pInstrumento, int size)
{
int temp;
int i;
int j,k;

int contadorInstrumento1;
int contadorInstrumento2;
int contadorInstrumento3;
int contadorInstrumento4;
int bufferInstrumento1;
int bufferInstrumento2;
int bufferInstrumento3;
int bufferInstrumento4;
int minimo=1;
int minimoFinal;
for(k=0; k<size;k++)
{
    if(pInstrumento[k].isEmpty==0 && pInstrumento[k].instrumento==1)
    {
        contadorInstrumento1++;
        continue;
    }
    if(pInstrumento[k].isEmpty==0 && pInstrumento[k].instrumento==2)
    {
        contadorInstrumento2++;
        continue;
    }
    if(pInstrumento[k].isEmpty==0 && pInstrumento[k].instrumento==3)
    {
        contadorInstrumento3++;
        continue;
    }
    if(pInstrumento[k].isEmpty==0 && pInstrumento[k].instrumento==4)
    {
        contadorInstrumento4++;
        continue;
    }
    else
        continue;
}

 bufferInstrumento1 = contadorInstrumento1;
 bufferInstrumento2 = contadorInstrumento2;
 bufferInstrumento3 = contadorInstrumento3;
 bufferInstrumento4 = contadorInstrumento4;


 if(bufferInstrumento1<=minimo)
{
    minimo=bufferInstrumento1;
   //maximo=bufferMusico1;
    minimoFinal=1;

}
 if(bufferInstrumento2<=minimo)
{
    minimo=bufferInstrumento2;
   // maximo=bufferMusico2;
    minimoFinal=2;
}
 if(bufferInstrumento3<=minimo)
{
    minimo=bufferInstrumento3;
   //maximo=bufferMusico3;
   minimoFinal=3;
}

if(bufferInstrumento4<=minimo)
{
    minimo=bufferInstrumento4;
   //maximo=bufferMusico3;
   minimoFinal=4;
}



int array[4] = {bufferInstrumento1,bufferInstrumento2,bufferInstrumento3,bufferInstrumento4};
    for(i = 0; i < 4-1; i++){
        for(j = i+1; j < 4; j++){
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }


  switch(minimoFinal)
  {
    case 1:
        if(minimoFinal==1){
        printf("\nEste instrumento es de tipo: 1)Cuerdas\n");
        }
        break;

    case 2:
        if(minimoFinal==2){
        printf("\nEste instrumento es de tipo: 2)Viento Madera\n");
        }
        break;

    case 3:
        if(minimoFinal==3){
        printf("\nEste instrumento es de tipo: 3)Viento Metal\n");
        }
        break;

    case 4:
        if(minimoFinal==4){
        printf("\nEste instrumento es de tipo: 4)Percusion\n");
        }
        break;
    default:
        break;
  }


  for(int j = 0; j<4; j++){
        printf("La cantidad de este instrumento es de: %d\n",array[j]);
        break;
    }
}



//FUNCION HARDCODEADA PARA LA ORQUESTA 1, PUEDE SER OTRA.


/** \brief Esta funcion calcula la cantidad de musicos y a la vez la Orquesta que mas Musicos tenga.
 *
 * \param Musico pMusico Puntero a la estrucura Musico.
 * \param sizeM Tamaño del array musico.
 * \return
 *
 */

void OrquestaConMayorMusicoYcantidadMusico(Musico *pMusico, int sizeM)
{
int contadorMusico1=0;
int contadorMusico2=0;
int contadorMusico3=0;
int bufferMusico1;
int bufferMusico2;
int bufferMusico3;
int maximo=0;
int maximoFinal=0;
int i,j,k;
int temp;

for(k=0;k<sizeM;k++)
{
        if(pMusico[k].isEmpty==0 && pMusico[k].suOrquesta==1)
        {
            contadorMusico1++;
            continue;
        }
        if(pMusico[k].isEmpty==0 && pMusico[k].suOrquesta==2)
        {
            contadorMusico2++;
            continue;
        }
        if(pMusico[k].isEmpty==0 && pMusico[k].suOrquesta==3)
        {
            contadorMusico3++;
            continue;
        }
    else
        continue;
}

 bufferMusico1 = contadorMusico1;
 bufferMusico2 = contadorMusico2;
 bufferMusico3 = contadorMusico3;

int array[3] = {bufferMusico1,bufferMusico2,bufferMusico3};
    for(i = 0; i < 3-1; i++){
        for(j = i+1; j < 3; j++){
            if(array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
  if(bufferMusico1>maximo)
{
   maximo=bufferMusico1;
   maximoFinal=1;

}
 if(bufferMusico2>maximo)
{
   maximo=bufferMusico2;
    maximoFinal=2;
}
if(bufferMusico3>maximo)
{
   maximo=bufferMusico3;
   maximoFinal=3;
}
  switch(maximoFinal)
  {
    case 1:
        if(maximoFinal==1){
        printf("\nLa orquesta con mas musicos es la de tipo: 1)Sinfonica\n");
        }
        break;

    case 2:
        if(maximoFinal==2){
        printf("\nLa orquesta con mas musicos es la de tipo: 2)Filarmonica\n");


        }
        break;

    case 3:
        if(maximoFinal==3){
        printf("\nLa orquesta con mas musicos es la de tipo: 3)Camara\n");
        }
        break;

    default:
        break;
  }

for(j = 0; j<3; j++)
    {
        printf("Esta orquesta esta compuesta por %d Musicos\n",array[j]);
        break;
    }
}


/** \brief Esta funcion calcula la cantidad de musicos y a la vez la Orquesta que menos Musicos tenga.
 *
 * \param Musico pMusico Puntero a la estrucura Musico.
 * \param sizeM Tamaño del array musico.
 * \return
 *
 */

void OrquestaConMenorMusicoYcantidadMusico(Musico *pMusico, int sizeM)
{
int contadorMusico1=0;
int contadorMusico2=0;
int contadorMusico3=0;
int bufferMusico1;
int bufferMusico2;
int bufferMusico3;
int minimo=1;
int minimoFinal;
int i,j,k;
int temp;

for(k=0;k<sizeM;k++)
{
        if(pMusico[k].isEmpty==0 && pMusico[k].suOrquesta==1)
        {
            contadorMusico1++;
            continue;
        }
        if(pMusico[k].isEmpty==0 && pMusico[k].suOrquesta==2)
        {
            contadorMusico2++;
            continue;
        }
        if(pMusico[k].isEmpty==0 && pMusico[k].suOrquesta==3)
        {
            contadorMusico3++;
            continue;
        }
    else
        continue;
}

 bufferMusico1 = contadorMusico1;
 bufferMusico2 = contadorMusico2;
 bufferMusico3 = contadorMusico3;

int array[3] = {bufferMusico1,bufferMusico2,bufferMusico3};
    for(i = 0; i < 3-1; i++){
        for(j = i+1; j < 3; j++){
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
  if(bufferMusico1<=minimo)
{
  minimo=bufferMusico1;
   minimoFinal=1;

}
 if(bufferMusico2<=minimo)
{
    minimo=bufferMusico2;
    minimoFinal=2;
}
  if(bufferMusico3<=minimo)
{
   minimo=bufferMusico3;
   minimoFinal=3;
}
  switch(minimoFinal)
  {
    case 1:
        printf("\nLa orquesta con menos musicos es la de tipo: %d, Sinfonica\n",minimoFinal);
        break;

    case 2:
        printf("\nLa orquesta con menos musicos es la de tipo: %d, Filarmonica\n",minimoFinal);
        break;

    case 3:
        printf("\nLa orquesta con menos musicos es la de tipo: %d, Camara\n",minimoFinal);
        break;

    default:
        break;
  }

for(j = 0; j<3; j++)
    {
        printf("Esta orquesta esta compuesta por %d Musicos\n",array[j]);
        break;
    }
}
/** \brief Crea musicos hardcodeados.
 *
 * \param Musico pMusico Puntero a la estructura Musico.
 * \return
 *
 */

void crearMusicos(Musico *pMusico)
{
            pMusico[0].isEmpty=0;
            pMusico[0].idMusico=1;
            pMusico[0].edad=20;
            pMusico[0].suOrquesta=1;
            pMusico[0].suInstrumento=1;
            strcpy(pMusico[0].nombre,"Rodri");
            strcpy(pMusico[0].apellido,"Barb");


             pMusico[1].isEmpty=0;
            pMusico[1].idMusico=2;
            pMusico[1].edad=32;
            pMusico[1].suOrquesta=2;
            pMusico[1].suInstrumento=2;
            strcpy(pMusico[1].nombre,"Sergio");
            strcpy(pMusico[1].apellido,"Fafa");

             pMusico[2].isEmpty=0;
            pMusico[2].idMusico=3;
            pMusico[2].edad=42;
            pMusico[2].suOrquesta=2;
            pMusico[2].suInstrumento=3;
            strcpy(pMusico[2].nombre,"Michel");
            strcpy(pMusico[2].apellido,"Sans");


             pMusico[3].isEmpty=0;
            pMusico[3].idMusico=4;
            pMusico[3].edad=31;
            pMusico[3].suOrquesta=2;
            pMusico[3].suInstrumento=1;
            strcpy(pMusico[3].nombre,"Gordo");
            strcpy(pMusico[3].apellido,"Toni");

             pMusico[4].isEmpty=0;
            pMusico[4].idMusico=5;
            pMusico[4].edad=15;
            pMusico[4].suOrquesta=3;
            pMusico[4].suInstrumento=2;
            strcpy(pMusico[4].nombre,"Flaco");
            strcpy(pMusico[4].apellido,"Tatoh");

}

/** \brief Crea Orquesta hardcodeados.
 *
 * \param Orquesta pOrquesta Puntero a la estructura Orquesta.
 * \return
 *
 */
void crearOrquesta(Orquesta *pOrquesta)
{
            pOrquesta[0].isEmpty=0;
            pOrquesta[0].idOrquesta=1;
            pOrquesta[0].tipoOrquesta=1;
            strcpy(pOrquesta[0].nombre,"ra");
            strcpy(pOrquesta[0].lugar,"fa");

             pOrquesta[1].isEmpty=0;
            pOrquesta[1].idOrquesta=2;
            pOrquesta[1].tipoOrquesta=1;
            strcpy(pOrquesta[1].nombre,"ta");
            strcpy(pOrquesta[1].lugar,"za");
}

void crearInstrumentos(Instrumento *pInstrumento)
{
//INSTRUMENTO1 HAY 2   INSTRUMENTO2 HAY 1     INSTRUMENTO3 HAY  2   INSTRUMENTO4 HAY 5
            pInstrumento[0].isEmpty=0;
            pInstrumento[0].idInstrumento=1;
            pInstrumento[0].instrumento=2;
            strcpy(pInstrumento[0].nombreInstrumento,"lola");

            pInstrumento[1].isEmpty=0;
            pInstrumento[1].idInstrumento=2;
            pInstrumento[1].instrumento=1;
            strcpy(pInstrumento[1].nombreInstrumento,"fasa");

            pInstrumento[2].isEmpty=0;
            pInstrumento[2].idInstrumento=3;
            pInstrumento[2].instrumento=1;
            strcpy(pInstrumento[2].nombreInstrumento,"tita");

            pInstrumento[3].isEmpty=0;
            pInstrumento[3].idInstrumento=4;
            pInstrumento[3].instrumento=4;
            strcpy(pInstrumento[3].nombreInstrumento,"rora");

            pInstrumento[4].isEmpty=0;
            pInstrumento[4].idInstrumento=5;
            pInstrumento[4].instrumento=4;
            strcpy(pInstrumento[4].nombreInstrumento,"saerasa");

            pInstrumento[5].isEmpty=0;
            pInstrumento[5].idInstrumento=6;
            pInstrumento[5].instrumento=4;
            strcpy(pInstrumento[5].nombreInstrumento,"instrumentoh");

            pInstrumento[6].isEmpty=0;
            pInstrumento[6].idInstrumento=7;
            pInstrumento[6].instrumento=4;
            strcpy(pInstrumento[6].nombreInstrumento,"hola");

            pInstrumento[7].isEmpty=0;
            pInstrumento[7].idInstrumento=8;
            pInstrumento[7].instrumento=4;
            strcpy(pInstrumento[7].nombreInstrumento,"chau");

            pInstrumento[8].isEmpty=0;
            pInstrumento[8].idInstrumento=9;
            pInstrumento[8].instrumento=3;
            strcpy(pInstrumento[8].nombreInstrumento,"bueni");

            pInstrumento[9].isEmpty=0;
            pInstrumento[9].idInstrumento=10;
            pInstrumento[9].instrumento=3;
            strcpy(pInstrumento[9].nombreInstrumento,"dale");

}


