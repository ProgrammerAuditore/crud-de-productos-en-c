/*
I. Crear una base de datos de productos sin repetion de ellas y almacenarlo en un archivo .txt
Nota: Todo el programa debe ser con char de preferencia 
Objetivo: Aprender a usar las cadenas de texto en C
// Si he modificado este proyecto significa que, ya he aprendido.
*/
#include "Run.h"

// gcc BD_Productos.c -c -I"./src/" -I"./fnc/" -std=c99 && gcc BD_Productos.o -o BD_Productos 

int main(){	
	
	// Menu principal
	do{
		
		#ifdef __WIN32
			system(colores_menu[0][0]);
		#endif

		// Bucamos cambios a la base de datos
		fnc_Incializar_programa();
		
		// Mostrar menu principal
		BORRAR_PANTALLA;
		TAB; printf(aMensajes_MenuPrincipal[0][0], _contador_productos); SALTO_LINEA;
		SEPARADOR;
		TAB; printf(aMensajes_MenuPrincipal[0][1], _contador_productos); SALTO_LINEA;
		SEPARADOR;
		TAB; printf("%s",aMensajes_MenuPrincipal[0][2]); SALTO_LINEA;
			if( _contador_productos != 0){
				TAB; printf("%s",aMensajes_MenuPrincipal[0][3]); SALTO_LINEA;
				TAB; printf("%s",aMensajes_MenuPrincipal[0][4]); SALTO_LINEA;
				TAB; printf("%s",aMensajes_MenuPrincipal[0][5]); SALTO_LINEA;
				TAB; printf("%s",aMensajes_MenuPrincipal[0][6]); SALTO_LINEA;
			}
		TAB; printf("%s",aMensajes_MenuPrincipal[0][7]); SALTO_LINEA;
		SEPARADOR;
		
		// Capturar una opcion del menu
		printf("%s",aMensajes_MenuPrincipal[0][8]);
		scanf("\t\t %c",&opc_Principal);
		
		// Seleccionamos la opcion elegida
		switch(opc_Principal){
			case '1': fnc_Crear_producto(); break;
			// Opciones desactivadas si no hay productos registrados
			case '2': if( _contador_productos != 0) fnc_Modificar_productos(); break;
			case '3': if( _contador_productos != 0) fnc_Ver_productos(); break;
			case '4': if( _contador_productos != 0) fnc_Buscar_productos(); break;
			case '5': if( _contador_productos != 0) fnc_Eliminar_DB(); break;
		}
		
		// Liberar teclado
		BUFFERFREE;
		
		// Termina el programa cuando el usuario
		// introduce el 0
	}while ( opc_Principal != '0');

	// Mostrar mensaje cuando sale del programa
	BORRAR_PANTALLA;
	SALTO_LINEA;
		TAB; printf("%s \n",aMensajes_MenuPrincipal[0][9]);
	SALTO_LINEA;
	BUFFERFREE;
}