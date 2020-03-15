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
	char _xNombre[50];
	printf("%s", aMensajes_cp[0][2]);
	fgets(_xNombre, MAXCARACTERES, stdin);
	SEPARARSTR(_xNombre, _xNombre, "\n");
	BUFFERFREE;
	
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
			char _xDescripcion[255];
			printf("%s", aMensajes_cp[0][3]);
			fgets(_xDescripcion, MAXCARACTERES, stdin);
			SEPARARSTR(_xDescripcion, _xDescripcion, "\n");
			BUFFERFREE;
			
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
			float _fC = 0.00; char _cC[50];
			printf("%s", aMensajes_cp[0][4]);
			scanf("%f",&_fC);
			BUFFERFREE;
			
			// Convertimos el float a string o caracteres
			sprintf(_cC, "%0.2f", _fC);
			
			// Registrar el costo del producto
			strcpy(_mis_productos[_contador_productos]._Costo,_cC);
			
			
			// Registrar el producto
			_mis_productos[_contador_productos].Identificador = _contador_productos;
			
				
			// Mostar mensaje cuando se crea un nuevo producto
			SALTO_LINEA; SALTO_LINEA;
			printf(aMensajes_cp[0][5], _mis_productos[_contador_productos].Identificador); 
			fnc_Actualizar_DB();
			BUFFERFREE;
		}else{
			
			// Mostrar mensaje cuando no puede crear el producto
			SALTO_LINEA; printf("%s \n", aMensajes_cp[0][6]);
			SALTO_LINEA;
			PAUSAR;
			
		}
	}
}