#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED


#define TEXT_SIZE 50

typedef struct
{
    int idInstrumento;
    int isEmpty;
    char nombreInstrumento[TEXT_SIZE];
    int instrumento;


}Instrumento;




int instrumento_Inicializar(Instrumento *pInstrumento, int size);
int instrumento_buscarEmpty(Instrumento *pInstrumento, int size, int* posicion);
int instrumento_buscarID(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion);
int instrumento_buscarIDnuevo(Instrumento *pInstrumento, int size, char* valorBuscado, int* posicion);
int musico_buscarIDinstrumento(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion);
int instrumento_buscarInt(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion);
int instrumento_buscarString(Instrumento *pInstrumento, int size, char* valorBuscado, int* indice);
int musico_buscarIDinstrumento(Instrumento *pInstrumento, int size, int valorBuscado, int* posicion);
int instrumento_alta(Instrumento *pInstrumento, int size, int* contadorID);
int instrumento_baja(Instrumento *pInstrumento, int sizeArray);
int instrumento_bajaValorRepetidoInt(Instrumento *pInstrumento, int sizeArray, int valorBuscado);
int instrumento_modificar(Instrumento *pInstrumento, int sizeArray);
int instrumento_ordenarPorString(Instrumento *pInstrumento,int size);
int instrumento_listar(Instrumento *pInstrumento, int size);



#endif // INSTRUMENTO_H_INCLUDED

