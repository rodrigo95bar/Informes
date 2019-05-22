#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
//int Informes_listarPorCriterio(arrayA, arrayB, int sizeI, int sizeJ, char* criterio);
//int Informes_listarCriterioContadorAcumulado(arrayA,arrayB, int sizeI, int sizeJ);
//int Informes_maxContadorAcumulado(arrayA, arrayB, int sizeI, int sizeJ);
//int Informes_ordenarPorDobleCriterio(Fantasma array[],int size, int orderFirst, int orderSecond);
void ordenar_numerosMayorAmenor(Musico *pMusico, int TAM);
void ordenar_numerosMenorAmayor(Musico *pMusico, int TAM);
void promedioTotalMusicoOrquesta(Musico *pMusico,Orquesta *pOrquesta,int sizeM,int sizeO);
void promedioInstrumentoDeTipo(Instrumento *pInstrumento,int size);

void instrumentoMasUsado(Instrumento *pInstrumento, int size);
void instrumentoMenosUsado(Instrumento *pInstrumento, int size);
void crearMusicos(Musico *pMusico);
void crearOrquesta(Orquesta *pOrquesta);
void crearInstrumentos(Instrumento *pInstrumento);

void OrquestaConMayorMusicoYcantidadMusico(Musico *pMusico, int sizeM);
void OrquestaConMenorMusicoYcantidadMusico(Musico *pMusico, int sizeM);
//void nombreMasLargo(int size);
#endif // INFORMES_H_INCLUDED
