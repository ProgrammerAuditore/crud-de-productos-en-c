
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
		sprintf(Datos,"%s %i\n",_mis_productos[i]._Descripcion,_mis_productos[i].Identificador);
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
	printf("%s \n", aMensajes_a_bd);
	SALTO_LINEA;
}
