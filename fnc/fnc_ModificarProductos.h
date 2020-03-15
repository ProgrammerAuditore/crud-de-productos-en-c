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
		TAB; printf("%s \n",aMensajes_mp[0][1]); SALTO_LINEA;
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
		 printf("%s \n", aMensajes_mp[0][7]);
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
			printf("%s %s \n",aMensajes_mp[0][9],nombre_anterior);
			fgets(nuevo_nombre, MAXCARACTERES, stdin);
			SEPARARSTR(nuevo_nombre, nuevo_nombre, "\n");
			BUFFERFREE;

			
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
				 printf("%s %s \n", aMensajes_mp[0][10], nuevo_nombre);
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
				 printf("%s %i \n", aMensajes_mp[0][11],_Id_producto);
				fnc_Actualizar_DB();
				PAUSAR;
			}
								
	}break;
			
case '2':
{
	// Capturar la nueva descripcion del producto
	char xDescripcion[100];
	printf("%s %s \n",aMensajes_mp[0][12],_mis_productos[_Id_producto]._Nombre);
	fgets(xDescripcion, MAXCARACTERES, stdin);
	SEPARARSTR(xDescripcion, xDescripcion, "\n");
	BUFFERFREE;
	
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
	 printf("%s %i \n", aMensajes_mp[0][13],_Id_producto);
	// Actualizamos la base de datos
	fnc_Actualizar_DB();
	PAUSAR;	
	
	}break;

case '3':
{
	// Capturar el nuevo costo del producto
	float _fCosto = 0.00; char _cCosto[50];
	//printf"%s %s %i \n",(aMensajes_mp[0][14],_mis_productos[_Id_producto]._Nombre,_mis_productos[_Id_producto]._Costo);
	scanf("%f",&_fCosto);
	BUFFERFREE;
	
	// Convertir el float a string o caracteres
	sprintf(_cCosto,"%.2f",_fCosto);
		
	// Modificar el costo del producto
	strcpy(_mis_productos[_Id_producto]._Costo,_cCosto);
		
	// Mostrar mensaje cuando cambia el costo del productos
	SALTO_LINEA;
	printf("%s %i \n", aMensajes_mp[0][15],_Id_producto);
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
	 printf("%s %i \n",aMensajes_mp[0][16],_Id_producto);	
	// Actualizamos la base de datos
	fnc_Actualizar_DB();	
	PAUSAR;
	}break;	

		}// FIN DEL SWITCH

}else{ // if ... else
				// Mostrar mensaje cuando el producto 
				// no exista en la base de datos
				SALTO_LINEA;
				printf("%s \n",aMensajes_mp[0][17]);
				SALTO_LINEA;
				PAUSAR;
}
		
} // FIN DE LA CONDICON
		
	}while(_opc_Modificar != '0');	
}