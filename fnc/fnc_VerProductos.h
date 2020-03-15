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