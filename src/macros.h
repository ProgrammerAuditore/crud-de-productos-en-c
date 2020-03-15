#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXCARACTERES 250
#define SALTO_LINEA printf("\n");
#define SEPARADOR printf("\t****************************************\n");
#define TAB printf("\t\t");
#define PAUSAR system("pause>nul");
#define PAUSAR_MSG system("pause");

#ifdef __WIN32
    #define BORRAR_PANTALLA system("cls");
#elif __linux__
    #define BORRAR_PANTALLA system("clear");
#endif

#define BUFFERFREE \
    if( getchar() != '\n'  ) \
        while( getchar() != '\n');

#define SEPARARSTR(DESTINO_STR, STRS, DELIMITADOR) \
    strtok(STRS, DELIMITADOR); \
    sprintf(DESTINO_STR, "%s" , STRS)
