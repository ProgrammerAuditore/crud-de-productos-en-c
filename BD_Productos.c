/*
I. Crear una base de datos de productos sin repetion de ellas y almacenarlo en un archivo .txt
Nota: Todo el programa debe ser con char de preferencia 
Objetivo: Aprender a usar las cadenas de texto en C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#define SALTO_LINEA printf("\n");
#define SEPARADOR printf("\t****************************************\n");
#define BORRAR_PANTALLA system("cls");
#define TAB printf("\t\t");
#define PAUSAR system("pause>nul");
#define PAUSAR_MSG system("pause");

// Decalaracion de funciones globales
void fnc_Menu_Principal();
void fnc_Modificar_productos();
void fnc_Crear_producto();
void fnc_Ver_productos();
void fnc_Buscar_productos();
void fnc_Actualizar_DB();
void fnc_Incializar_programa();
void fnc_Eliminar_DB();

// Variables globales
struct PRODUCTOS{
	int Identificador;
	char _Nombre[50];
	char _Costo[20];
	char _Descripcion[100];
}_mis_productos[100];

// Mensajes para el menu principal
const char* aMensajes_MenuPrincipal[10][10] = { 
"MENU PRINCIPAL",
"Total de productos : %i",
"1 > Crear producto",
"2 > Modificar productos",
"3 > Ver todos los productos",
"4 > Buscar producto",
"5 > Eliminar base de datos" ,
"0 > Salir",
"Seleccione una opcion: _",
"**** FIN DEL PROGRAMA *****"
};

char comandos_attrib[1][2][20] = {
"attrib -s -h  %s",
"attrib +s +h  %s",
};

const char* colores_menu[6][10] = {
// Color menu principal
"color f0",
// Color menu modificar y ver productos
"color 0f",
// Color menu BD no existe y eliminar producto
"color 0C",
// Color menu buscar productos
"color 3F"
};

const char mostrar_productos[1][5][100] = {
"Producto (ID): %i \n",
"Nombre:[%s]\n",
"Costo:[$%s]\n",
"Descripcion:\n>> %s <<\n"
};

char _nombre_archivoDB[30] = "_bd_productos_.dat";
char opc_Principal;
int _contador_productos = 0;
char _nombre_definido[11] = "----------";
char comando[50];

/**********************************************
 				PRINCIPAL MAIN 
*********************************************/
int main(){	
	
	// Menu principal
	do{
		
		// Bucamos cambios a la base de datos
		fnc_Incializar_programa();
		
		// Mostrar menu principal
		BORRAR_PANTALLA;
		system(colores_menu[0][0]);
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
		printf(aMensajes_MenuPrincipal[0][8]);
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
		fflush(stdin);
		
		// Termina el programa cuando el usuario
		// introduce el 0
	}while ( opc_Principal != '0');

	// Mostrar mensaje cuando sale del programa
	BORRAR_PANTALLA;
	SALTO_LINEA;
		TAB; printf(aMensajes_MenuPrincipal[0][9]);
	SALTO_LINEA;
	PAUSAR;
}


/**********************************************
 				FUNCIONES 
*********************************************/

// Funcion para crear producto
void fnc_Crear_producto(){
	
	// Mensajes para el menu crear producto
	char aMensajes_cp[1][10][100] = {
		"INTRODUCIR DATOS DEL PRODUCTO",
		"0 > Volver",
		"Introduzca el nombre del producto:\n>",
		"Introduzca una descripcion del producto:\n>",
		"Introduzca el precio del producto:\n>",
		"Producto (%i) insertado exitosamente.",
		"Este producto ya existe.\nFallo al insertar el producto nuevo."
	};
	
	// Variables globales
	bool existe_producto;
	
	// Mostrar el menu
	BORRAR_PANTALLA;
	TAB; printf("%s",aMensajes_cp[0][0]); SALTO_LINEA;
	SEPARADOR;
	TAB; printf("%s",aMensajes_cp[0][1]); SALTO_LINEA;
	SEPARADOR;
	SALTO_LINEA;
	
	// Capturar el nombre
	fflush(stdin);
	char _xNombre[50];
	printf(aMensajes_cp[0][2]);
	gets(_xNombre);	
	
	// Esto no se ejecuta cuando el usaurio introduce un 0
	if( *_xNombre != '0'){
		
		// Aumentar en uno el contador de productos
		_contador_productos++;
			
		// Pregustar si el nombre tiene mas de 0 caracteres
		// si no cambiar el nombre por uno definido
		if(strlen(_xNombre) > 0){	
			
			// Comparar nombres de la base de datos
			int i;
			for(i=_contador_productos; i > 0; i--){
				// Si el nombre del producto es igual al nombre
				// que introdujo el usuario
				if(strcmp(_mis_productos[i]._Nombre, _xNombre) == 0){
					// producto existe y no puedo crear el producto
					existe_producto = true;
					// terminar el ciclo
					break;
				}else{
					// producto no existe y puede crear el producto
					existe_producto = false;
				}
			}
			
			// Puedo insertar el nombre ?
			// Si existe_producto = true, (false) no puedes
			// Si existe_producto = false, (true) si puedes
			if(!existe_producto)
				strcpy(_mis_productos[_contador_productos]._Nombre, _xNombre);
			
		}else{
			
			// Cambiar el nombre por uno definido
			strcpy(_mis_productos[_contador_productos]._Nombre,_nombre_definido);
		
		}
		
		// Puedo crear el producto ?
		// Si existe_producto = true, (false) no puedo crear producto
		// Si existe_producto = false, (true) puedo crear producto
		if(!existe_producto){
			
			// Captura la descripcion del producto
			SALTO_LINEA;
			fflush(stdin);
			char _xDescripcion[255];
			printf(aMensajes_cp[0][3]);
			gets(_xDescripcion);
			
			// Preguntar si la descripcion del producto
			// tiene mayor que 0 caracteres
			if(strlen(_xDescripcion) > 0){
				// de ser asi, cambiar la descripcion por la nueva
				strcpy(_mis_productos[_contador_productos]._Descripcion,_xDescripcion);
			}else{
				// si no, cambiar la descripcion por uno definido
				strcpy(_mis_productos[_contador_productos]._Descripcion,_nombre_definido);
			}			
			
			// Capturar el costo del producto
			SALTO_LINEA;
			fflush(stdin);
			float _fC = 0.00; char _cC[50];
			printf(aMensajes_cp[0][4]);
			scanf("%f",&_fC);
			
			// Convertimos el float a string o caracteres
			sprintf(_cC, "%0.2f", _fC);
			
			// Registrar el costo del producto
			strcpy(_mis_productos[_contador_productos]._Costo,_cC);
			
			
			// Registrar el producto
			_mis_productos[_contador_productos].Identificador = _contador_productos;
			
				
			// Mostar mensaje cuando se crea un nuevo producto
			SALTO_LINEA; SALTO_LINEA;
			printf(aMensajes_cp[0][5],_mis_productos[_contador_productos].Identificador); 
			fnc_Actualizar_DB();
			PAUSAR;
		}else{
			
			// Mostrar mensaje cuando no puede crear el producto
			SALTO_LINEA; printf(aMensajes_cp[0][6]);
			SALTO_LINEA;
			PAUSAR;
			
		}
	}
}

// Funcion para modificar productos
void fnc_Modificar_productos(){
	
	// Mensajes  para menu modificar productos
	char aMensajes_mp[1][20][255] = { 
		"MODIFICAR PRODUCTOS",
		"Aun no tiene productos registrados",
		"1 > Cambiar nombre del producto",
		"2 > Cambiar la descripcion del producto",
		"3 > Cambiar el costo del producto",
		"4 > Eliminar un producto",
		"0 > Volver",
		"Seleccione una opcion: >#",
		"Seleccione el ID del producto (1 - %i): >#",
		"Introduzca el nuevo nombre para el producto: \n(%s) > ",
		"Lo siento, ( %s ) nombre no disponible.",
		"El nombre del producto (%i) se actualizo exitosamente.",
		"Escribe la nueva descripcion del producto (%s):\n>",
		"La descripcion del producto (%i) se actualizo exitosamente.",
		"Introduzca el nuevo costo del producto (%s):\n(%s) > ",
		"El costo del producto (%i) se actualizo exitosamente.",
		"El producto (%i) se ha eliminado exitosamente.",
		"Lo siento, no encontre el producto."
	};
	
	// Cambiar el color de la consola
	system(colores_menu[0][1]);
	// Buscar cambios de la base de datos
	fnc_Incializar_programa();
	// Variables globales
	char _opc_Modificar;
	int _Id_producto;
	int i;
	int _producto_encontrado = 0;
	int _cambio_nombre = 0;
	
	do{
	// Encabezado
	BORRAR_PANTALLA
	TAB; printf("%s",aMensajes_mp[0][0]); SALTO_LINEA;
	SEPARADOR;
	
	
	if( _contador_productos == 0){
		// Mostrar mensaje cuando no tienes productos registrados
		TAB; printf(aMensajes_mp[0][1]); SALTO_LINEA;
		SALTO_LINEA;
	}else{
		// Mostrar todos los prodctos
		for(i=_contador_productos; i > 0; i--){
			printf(mostrar_productos[0][0], _mis_productos[i].Identificador);
			printf(mostrar_productos[0][1],_mis_productos[i]._Nombre);
			printf(mostrar_productos[0][2],_mis_productos[i]._Costo);
			printf(mostrar_productos[0][3],_mis_productos[i]._Descripcion);
			SALTO_LINEA;
		}
	}	
	
	// Menu para modificar la base de datos
	SEPARADOR;
	// Opcines desactivadas si no tienes productos registrados
if(_contador_productos != 0){
	 TAB; printf("%s",aMensajes_mp[0][2]); SALTO_LINEA;
	 TAB; printf("%s",aMensajes_mp[0][3]); SALTO_LINEA;
	 TAB; printf("%s",aMensajes_mp[0][4]); SALTO_LINEA;
	 TAB; printf("%s",aMensajes_mp[0][5]); SALTO_LINEA;
}
	 TAB; printf("%s",aMensajes_mp[0][6]); SALTO_LINEA;
	SEPARADOR;

		
		// Capturar una opcion del menu
		fflush(stdin);
		 printf(aMensajes_mp[0][7]);
		scanf("%c",&_opc_Modificar);
		
		// Si el total de productos es diferente de 0 y
		// Si la opcion es diferente de '0' y
		// Si la opcion es diferente de caracteres
		if(_contador_productos != 0 && _opc_Modificar != '0' && isdigit(_opc_Modificar) != 0)
{	
		// Capturar el ID del producto
		fflush(stdin);
		 printf(aMensajes_mp[0][8],_contador_productos);
		scanf("%i",&_Id_producto);	
		
		// Buscar el producto
		for(i=1; i <= _contador_productos; i++){
			// Si el producto es igual al que el usuario introdujo
			if(_mis_productos[i].Identificador == _Id_producto){
				// Existe el producto, termina el ciclo
				_producto_encontrado = 1; 
					break;
			}else{
				// El producto no existe
				_producto_encontrado = 0;
			}
		}

// Cuando encuentra el producto se ejecuta el switch
if( _producto_encontrado == 1){ 
		switch(_opc_Modificar){
/* EN CASO DE 1 EN CASO DE 1 EN CASO DE 1*/
case '1': // Cambiar nombre
{			
			// Salvamos el nombre original
			char nombre_anterior[50];
			strcpy(nombre_anterior,_mis_productos[_Id_producto]._Nombre);
			
			// Introducimos el nuevo nombre
			char nuevo_nombre[50];
			 printf(aMensajes_mp[0][9],nombre_anterior);
			fflush(stdin);
			gets(nuevo_nombre);		
			
			// Preguntar si el nombre tiene mas de 0 caracteres
			// si no cambiar por un nombre ya definido
			if( strlen(nuevo_nombre) > 0){
				
				// Comparar nombres con la base de datos
				for(i=_contador_productos; i > 0; i--){
					// Si nombre son iguales, no se cambia
					if(strcmp(_mis_productos[i]._Nombre,nuevo_nombre) == 0){ 
						 // Existe el nombre se termina el ciclo
						_cambio_nombre = 0; break;
					}else{
						// Si nombre son diferentes, se cambia
						_cambio_nombre = 1;
					}
				}
					
			}else{
				// Cambiar por un nombre ya definido
				_cambio_nombre = 2;
			}
			
			// Si nombre son iguales, no se cambia
			if( _cambio_nombre == 0){
				
				// Cambiar el nombre por el nombre anterior
				strcpy(_mis_productos[_Id_producto]._Nombre,nombre_anterior);
			
				// Mostrar mensaje cuando no se cambio el nombre
				SALTO_LINEA;
				 printf(aMensajes_mp[0][10], nuevo_nombre);
				SALTO_LINEA;
				PAUSAR;
			}	
			
			// Si nombre son diferentes, se cambia
			if( _cambio_nombre == 1 || _cambio_nombre == 2 ){
				
				// Si nombre es mayor que 0 caracteres
				if(_cambio_nombre == 1){
					// de ser asi, se cambia por el nuevo nombre
					strcpy(_mis_productos[_Id_producto]._Nombre,nuevo_nombre);
				}else if(_cambio_nombre == 2){
					// si no, se cambia por un nombre definido
					strcpy(_mis_productos[_Id_producto]._Nombre,_nombre_definido);
				}
					
				// Mostrar mensaje cuando se cambia el nombre
				SALTO_LINEA;
				 printf(aMensajes_mp[0][11],_Id_producto);
				fnc_Actualizar_DB();
				PAUSAR;
			}
								
	}break;
			
case '2':
{
	// Capturar la nueva descripcion del producto
	char xDescripcion[100];
	 printf(aMensajes_mp[0][12],_mis_productos[_Id_producto]._Nombre);
	fflush(stdin);
	gets(xDescripcion);
	
	// Calcular el tama�o de la descripcion
	if( strlen(xDescripcion) > 0){
		// Cambia la descripcion si tiene algun contenido
		strcpy(_mis_productos[_Id_producto]._Descripcion,xDescripcion);
	}else{
		// Cambia la descripcion no tiene algun contenido
		strcpy(_mis_productos[_Id_producto]._Descripcion,_nombre_definido);
	}
	
	// Mostrar mensaje cuando cambia la descripcion del producto
	SALTO_LINEA;
	 printf(aMensajes_mp[0][13],_Id_producto);
	// Actualizamos la base de datos
	fnc_Actualizar_DB();
	PAUSAR;	
	
	}break;

case '3':
{
	// Capturar el nuevo costo del producto
	float _fCosto = 0.00; char _cCosto[50];
	fflush(stdin);
	printf(aMensajes_mp[0][14],_mis_productos[_Id_producto]._Nombre,_mis_productos[_Id_producto]._Costo);
	scanf("%f",&_fCosto);
	
	// Convertir el float a string o caracteres
	sprintf(_cCosto,"%.2f",_fCosto);
		
	// Modificar el costo del producto
	strcpy(_mis_productos[_Id_producto]._Costo,_cCosto);
		
	// Mostrar mensaje cuando cambia el costo del productos
	SALTO_LINEA;
	printf(aMensajes_mp[0][15],_Id_producto);
	fnc_Actualizar_DB();
	PAUSAR;
	}break;

case '4':
{
	// Eliminar un producto
	for(i = _Id_producto+1; i <= _contador_productos; i++){
		strcpy(_mis_productos[i-1]._Descripcion,_mis_productos[i]._Descripcion);
		strcpy(_mis_productos[i-1]._Nombre,_mis_productos[i]._Nombre);
	}
	
	_contador_productos--; // Elimino al ultimo elemento del array 
	
	// Mostramos el mensaje cuando un producto se elimina
	SALTO_LINEA;
	 printf(aMensajes_mp[0][16],_Id_producto);	
	// Actualizamos la base de datos
	fnc_Actualizar_DB();	
	PAUSAR;
	}break;	

		}// FIN DEL SWITCH

}else{ // if ... else
				// Mostrar mensaje cuando el producto 
				// no exista en la base de datos
				SALTO_LINEA;
				 printf(aMensajes_mp[0][17]);
				SALTO_LINEA;
				PAUSAR;
}
		
} // FIN DE LA CONDICON
		
	}while(_opc_Modificar != '0');	
}

// Funcion para ver producto
void fnc_Ver_productos(){
	// Mensajes para el menu ver prodctos
	char aMensajes_vp[1][1][100] = {
	"VER TODOS LOS PRODUCTOS"
	};
	
	// Cambiar el color de la consola
	system(colores_menu[0][1]);
	
	// Menu de ver productos
	BORRAR_PANTALLA
	SEPARADOR;
	TAB; printf("%s",aMensajes_vp[0][0]); SALTO_LINEA;
	SEPARADOR;
	
	// Mostrar todos los productos
	int i;
	for(i=_contador_productos; i > 0; i--){
		SALTO_LINEA;
		printf(mostrar_productos[0][0], _mis_productos[i].Identificador);
		printf(mostrar_productos[0][1],_mis_productos[i]._Nombre);
		printf(mostrar_productos[0][2],_mis_productos[i]._Costo);
		printf(mostrar_productos[0][3],_mis_productos[i]._Descripcion);
		SEPARADOR;
	}
	
	PAUSAR_MSG;
}

// Funcion para buscar producto
void fnc_Buscar_productos(){
	// Mensajes para el menu buscar prodctos
	char aMensajes_bp[1][5][50] = {
	"BUSCAR PRODUCTOS",
	"0 > Volver",
	"Buscar a: _",
	"\nLo siento, %s no esta registrado. \n"
	};
	
	// Cambiar el color de la consola
	system(colores_menu[0][3]);
	
	// Menu de buscar productos
	BORRAR_PANTALLA;
	TAB; printf("%s",aMensajes_bp[0][0]); SALTO_LINEA; // Titulo
	SEPARADOR;
	TAB; printf("%s",aMensajes_bp[0][1]); SALTO_LINEA; // Opcion 0
	SEPARADOR;

	char xBuscar[50];
	int i, _resultado;
	
	// Capturamos el producto a buscar
	fflush(stdin);
	printf(aMensajes_bp[0][2]);
	gets(xBuscar);
	
	if( *xBuscar != '0'){
		
		// Buscar producto
		for(i= 1; i <= _contador_productos; i++){
			// Si el producto es igual al que busca el usario
			if( strcmp(_mis_productos[i]._Nombre,xBuscar) == 0){
				// Mostrar el producto encontado
				SALTO_LINEA;
				SALTO_LINEA;
				printf(mostrar_productos[0][0],_mis_productos[i].Identificador);
				printf(mostrar_productos[0][1],_mis_productos[i]._Nombre);
				printf(mostrar_productos[0][2],_mis_productos[i]._Costo);
				printf(mostrar_productos[0][3],_mis_productos[i]._Descripcion);
				SALTO_LINEA;
				SALTO_LINEA;
				_resultado=1;
				break;
			}else
				_resultado=0;	
		}	
		
		// Mostrar mensaje cuando no encuentra el producto
		if( _resultado == 0){
			printf(aMensajes_bp[0][3],xBuscar);
		}
		
		PAUSAR_MSG;
	}
}

// Funcion para borrar todos los productos
// en el archivo de la base de datos
void fnc_Eliminar_DB(){
	// Mensajes para menu eliminar base de datos
	char aMensajes_e_bd[1][2][60] = {
	"Seguro que deseas eliminar la base de datos (yY/nN)?",
	"La base de datos se elimino exitosamente."
	};
	
	// Cambiar el color de la consola
	system(colores_menu[0][2]);
	
	// Aparece el archvio para
	// actualizar la base de datos
	sprintf(comando,comandos_attrib[0][0],_nombre_archivoDB);
	system(comando);
	
	// Abrir el archivo
	char _respuesta;
	FILE *_mi_base_datos = fopen(_nombre_archivoDB,"r+w");
	
	// Preguntar si existe el archivo
	// si no termina el programa
	if( _mi_base_datos == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Preguntar si desea eliminar la base de datos
	fflush(stdin);
	printf(aMensajes_e_bd[0][0]);
	scanf("%c",&_respuesta);
	
	// Si la respuesta es y o Y
	// se elimina la base de datos
	// si no cerrar el archivo
	if( _respuesta == 'y' || _respuesta == 'Y' ){
		
		// Renombramos la estructura de nuestro productos
		// durante la ejecucion
		int i;
		for( i = 1; i <= _contador_productos; i++){
			_mis_productos[i].Identificador = 0;
			strcpy(_mis_productos[i]._Costo,"00000");
			strcpy(_mis_productos[i]._Nombre,"|!%$&|!$%|");
			strcpy(_mis_productos[i]._Descripcion,"|!%$&|!$%|");
		}
		
		// Eliminar la base de datos
		_contador_productos = 0;
		fnc_Actualizar_DB();
		
		// Mostrar mensaje cuando la base de datos se elimina
		printf(aMensajes_e_bd[0][1]);
		SALTO_LINEA; SALTO_LINEA;
		PAUSAR;
	}
	
	// Cerrar el archivo
	fclose(_mi_base_datos);
	
	// Desaparece el archvio para
	// desactivar la base de datos
	sprintf(comando,comandos_attrib[0][1],_nombre_archivoDB);
	system(comando);
}

// Funcion para actualizar el archivo de la base de datos
void fnc_Actualizar_DB(){
	// Mensajes para el menu actualizar base de datos
	char aMensajes_a_bd[30] = "Base de datos actualizado.";
	
	// Aparece el archvio para
	// actualizar la base de datos
	sprintf(comando,comandos_attrib[0][0],_nombre_archivoDB);
	system(comando);
	
	// Abrir el archivo de la base de datos
	FILE *_mi_base_datos = fopen(_nombre_archivoDB, "w");
	int i;
	
	// Preguntar si existe
	// si no el programa termina  
	if( _mi_base_datos == NULL){
		exit(EXIT_FAILURE);
	}
	
	char Datos[255];
	// Registramos el total de productos en la primera line
	sprintf(Datos,"%i\n",_contador_productos);
	fputs(Datos, _mi_base_datos);
	
	// Registramos todos los productos line por line
	for(i = 1 ; i <=  _contador_productos ; i++){
		sprintf(Datos,"Producto (ID) :%i\n",_mis_productos[i].Identificador);
			fputs(Datos, _mi_base_datos);
		sprintf(Datos,"%s\n",_mis_productos[i]._Nombre);
			fputs(Datos, _mi_base_datos);
		sprintf(Datos,"%s\n",_mis_productos[i]._Costo);
			fputs(Datos, _mi_base_datos);
		sprintf(Datos,"%s\n",_mis_productos[i]._Descripcion,_mis_productos[i].Identificador);
			fputs(Datos, _mi_base_datos);
			fputs("*****************************************\n", _mi_base_datos);
	}
	
	// Cerrar la base de datos
	fclose(_mi_base_datos);
	
	// Desaparece el archivo para
	// desactivar la base de datos
	sprintf(comando,comandos_attrib[0][1],_nombre_archivoDB);
	system(comando);
	
	// Mostrar mensaje cuando el proceso termine
	SALTO_LINEA;
	printf(aMensajes_a_bd);
	SALTO_LINEA;
}

// Funcion para actualizar el archivo de la base de datos
void fnc_Incializar_programa(){
	// Mensajes para el menu inicializar programa
	char aMensajes_i_programa[1][3][50] = {
	"Lo siento, la base de datos no existe.",
	"Deseas crear la base de datos (yY/nN)? _",
	"La base de datos, se ha creado."
	};
	
	// Aparece el archvio para
	// actualizar la base de datos
	sprintf(comando,comandos_attrib[0][0],_nombre_archivoDB);
	system(comando);
	
	// Abrir el archivo de la base de datos
	FILE *_mi_base_datos = fopen(_nombre_archivoDB,"r");
	
	// Preguntar si existe el archivo 
	if( _mi_base_datos == NULL ){
		
		// Cambiar el color de la consola
		system(colores_menu[0][2]);
		
		// Mostrar mensaje si no existe el archvio
		printf(aMensajes_i_programa[0][0]);
		SALTO_LINEA;
		
		// Preguntar si desea crear el archivo
		char _respuesta;
		printf(aMensajes_i_programa[0][1]);
		scanf("%c",&_respuesta);
		
		// Si la respuesta es y o Y se crea el archivo
		// si no termina el programa
		if( _respuesta == 'y' ||  _respuesta == 'Y'){
			SALTO_LINEA;
			printf(aMensajes_i_programa[0][2]);
			fnc_Actualizar_DB();
			SALTO_LINEA;
			PAUSAR;
		}else exit(EXIT_FAILURE);	
	}	
	
	char primera_linea[5];
	char _datos[100];
	char *xNombre,*xEdad;
	
	// Capuro la primera linea
	fgets(primera_linea,10, _mi_base_datos);
	
	// Capturamos el numero hasta el retorno/salto de linea
	// eliminando el salto de linea
	// guardarlo a la variable _xProductos
	char *_xProductos = strtok(primera_linea, "\n");
	
	// Preguntar si el _xProductos es mayor o igual a uno
	// de ser asi capturamos todos los productos uno por uno
	// si no cerramos el archivo de la base de datos.
	if( atoi(_xProductos) >= 1){
		
		// El total de productos es igaul a _xProductos
		_contador_productos = atoi(_xProductos);
		int i;
		
		// Capturamos todos elemento para todos los productos uno por uno
		for(i=1; i <= _contador_productos; i++){
			_mis_productos[i].Identificador = i;
			/***************
				CAPTURAMOS EL PRODUCTO(ID)
			************/
			// Captura la segunda linea
			fgets(_datos,99,(FILE*)_mi_base_datos);
			// hasta el salto de linea / retorno
			strtok(_datos, "\n");  // Eliminar salto de linea
						
			/***************
				CAPTURAMOS EL NOMBRE
			************/
			// Captura la tercera linea
			fgets(_datos,99,(FILE*)_mi_base_datos);
			// hasta el salto de linea / retorno
			strtok(_datos, "\n"); // Eliminar salto de linea
			// Guardar el elemento al nombre del producto
			// que esta almacenado el la variable _datos
			strcpy(_mis_productos[i]._Nombre,_datos);
			
			/***************
				CAPTURAMOS EL COSTO
			************/
			// Captura la cuarta linea
			fgets(_datos,99,(FILE*)_mi_base_datos);
			// hasta el salto de linea / retorno
			strtok(_datos, "\n"); // Eliminar salto de linea
			// Guardar el elemento al nombre del producto
			// que esta almacenado el la variable _datos
			strcpy(_mis_productos[i]._Costo,_datos);
			
			/***************
				CAPTURAMOS LA DESCRIPCION
			************/
			// Captura la quinta linea
			fgets(_datos,99,(FILE*)_mi_base_datos);
			// hasta el salto de linea / retorno
			strtok(_datos, "\n"); // Eliminar salto de linea
			// Guardar el elemento a la descripcion del producto
			// que esta almacenado el la variable _datos
			strcpy(_mis_productos[i]._Descripcion,_datos);
			
			/***************
				CAPTURAMOS EL SEPARADOR
			************/
			// Captura la sexta linea
			fgets(_datos,99,(FILE*)_mi_base_datos);
			// hasta el salto de linea / retorno
			strtok(_datos, "\n"); // Eliminar salto de linea
		}					
	}
	
	// Cerrar archivo
	fclose(_mi_base_datos);
	
	// Desaparece el archvio para
	// desactivar la base de datos
	sprintf(comando,comandos_attrib[0][1],_nombre_archivoDB);
	system(comando);
}
