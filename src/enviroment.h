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