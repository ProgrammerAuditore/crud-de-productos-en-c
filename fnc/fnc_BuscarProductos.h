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