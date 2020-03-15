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
		

		#ifdef __WIN32
			// Cambiar el color de la consola
			system(colores_menu[0][2]);
		#endif

		// Mostrar mensaje si no existe el archvio
		printf("%s \n", aMensajes_i_programa[0][0]);
		SALTO_LINEA;
		
		// Preguntar si desea crear el archivo
		char _respuesta;
		printf("%s \n",aMensajes_i_programa[0][1]);
		scanf("%c",&_respuesta);
		
		// Si la respuesta es y o Y se crea el archivo
		// si no termina el programa
		if( _respuesta == 'y' ||  _respuesta == 'Y'){
			SALTO_LINEA;
			printf("%s \n",aMensajes_i_programa[0][2]);
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
