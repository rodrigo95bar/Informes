#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "informes.h"
#define CANT_ORQUESTA 50
#define SORT_UP 1
#define SORT_DOWN 0
#define CANT_MUSICO 1000
#define CANT_INSTRUMENTO 20
int main()
{
    int opcion;
    int contadorId=0;

    Orquesta pOrquesta[CANT_ORQUESTA];
    Musico pMusico[CANT_MUSICO];
    Instrumento pInstrumento [CANT_INSTRUMENTO];
    orquesta_Inicializar(pOrquesta,CANT_ORQUESTA);
    musico_Inicializar(pMusico,CANT_MUSICO);
    instrumento_Inicializar(pInstrumento,CANT_INSTRUMENTO);

    crearMusicos(pMusico);
    crearOrquesta(pOrquesta);
    crearInstrumentos(pInstrumento);
    do
    {
        utn_getUnsignedInt("\n\n1) Agregar Orquesta\n2) Eliminar Orquesta \n3) Imprimir orquesta \n4) Agregar Musico \n5) Modificar musico \n6) Eliminar Musico\n7) Imprimir musicos\n8) Agregar instrumentos\n9) Imprimir instrumentos\n",                   //cambiar
                      "\nError",1,sizeof(int),1,10,1,&opcion);
        switch(opcion)
        {
            case 1:
                orquesta_alta(pOrquesta,CANT_ORQUESTA,&contadorId);

                break;

            case 2:
                musico_bajaPorOrquesta(pMusico,CANT_MUSICO, orquesta_baja(pOrquesta,CANT_ORQUESTA));

                break;

            case 3:
                orquesta_listar(pOrquesta,CANT_ORQUESTA);
                break;

            case 4:
                musico_alta(pMusico, pOrquesta, pInstrumento,CANT_MUSICO,&contadorId);

                break;

            case 5:
                  musico_modificar(pMusico,pOrquesta,CANT_MUSICO);
                break;

            case 6:
                 musico_baja(pMusico,CANT_MUSICO);
                break;

             case 7:
                musico_listar(pMusico,CANT_MUSICO);
                    break;

             case 8:
                 instrumento_alta(pInstrumento,CANT_INSTRUMENTO,&contadorId);
                    break;

             case 9:
                 //OrquestaConMenorMusicoYcantidadMusico(pMusico, CANT_MUSICO);
                 //OrquestaConMayorMusicoYcantidadMusico(pMusico,CANT_MUSICO);
                 //instrumentoMasUsado(pInstrumento, CANT_INSTRUMENTO);
                 instrumentoMenosUsado(pInstrumento,CANT_INSTRUMENTO);
                 //promedioInstrumentoDeTipo(pInstrumento,CANT_INSTRUMENTO);
                 //promedioTotalMusicoOrquesta(pMusico,pOrquesta,CANT_MUSICO,CANT_ORQUESTA);
                 //instrumento_listar(pInstrumento,CANT_INSTRUMENTO);
                    break;

             case 10:
                    break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10);
    return 0;
}
