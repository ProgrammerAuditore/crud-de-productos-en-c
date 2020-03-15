
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