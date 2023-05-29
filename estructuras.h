#ifndef _ESTRUCTURAS	//funciones para crear la libreria
#define _ESTRUCTURAS

/*								FORMATO DE LOS ARCHIVOS CSV												*/

/*	Los archivos son archivos de texto (".txt") en bloc de notas. El formato es (ejemplo del archivo Usuarios.txt):
											" 1,Perez Juan,20180912, "
		Los valores estan separados por coma, (IMPORTANTE) termina con una "," al final para evitar problemas varios
*/




/*								DEFINICION DE ESTRUCTURAS												*/

// Formato fecha: aaaa/mm/dd (Ejemplo: 20230513)	-	Formato periodo: aaaa/mm (Ejemplo: 202305)

struct usuarios{
	long idusuario,fechaalta;
	char apellidonombre[30];
	struct usuarios *sgte;
};

struct medxusuario{ //un usuario puede tener varios medidores, la estructura define a que usuario, y cuenta, le pertenece cada medidor
	long idusuario,idmedidor,idcuenta,fechaalta,fechabaja; //fechabaja puede ser: "0" si sigue en uso, o "mayor a 0" si el medidor esta dado de baja
	struct medxusuario *sgte;
};

struct medidores{ //Lista Enlazda Circular
	long idmedidor,numero;
	char modelo[20];
	struct medidores *sgte;
};

struct mediciones{ //cargada con cuentas que tienen "fechabaja" = 0
	long idcuenta,periodo,fechalectura;
	float lectura; //lectura: cantidad de metros cubicos que marca el medidor de esa cuenta
	struct mediciones *ant,*sgte; //Lista Doblemente Enlazada
};

struct facturas{
	int pagado; //1: pago - 0: no pago
	long idcuenta,periodo,fechaemision; //fechaemision: tiene que ser la fecha del sistema cuando se ejecute el programa
	float consumo,totalapagar; //consumo: es el resultado de la resta entre la lectura actual menos la anterior, de esa cuenta - totalapagar: se debe crear la tabla de valores como explico el profe
	struct facturas *sgte;
};


/*									PROTOTIPOS PARA CREAR LAS LISTAS								*/

struct usuarios* lista_usuario();
struct medxusuario* lista_medxusuario();
struct medxusuario *lista_rutacaminante();//crea una lista enlasada simple de los usuarios que tienen "fechabaja = 0"
struct medidores* lista_medidores();
struct mediciones* lista_mediciones();
struct mediciones* lista_NVmedicion(); //crea lista doblemente enlasada con los con los datos actualizados que recaudo el caminante
struct facturas* lista_facturas();


/*									PROTOTIPOS PARA LAS FUNCIONES INSERTAR								*/

struct usuarios* insertar_usuario(struct usuarios*,struct usuarios*);
struct medxusuario* insertar_medxusuario(struct medxusuario*,struct medxusuario*);
struct medidores* insertar_medidores(struct medidores*,struct medidores*);
struct mediciones* insertar_mediciones(struct mediciones*,struct mediciones*,struct mediciones*);
struct facturas* insertar_facturas(struct facturas*,struct facturas*);

/*									PROTOTIPOS PARA LAS FUNCIONES BORRAR LISTA								*/
struct usuarios* borrar_usuario(struct usuarios*);
struct medxusuario* borrar_medxusuario(struct medxusuario*);
struct medidores* borrar_medidores(struct medidores*);
struct mediciones* borrar_mediciones(struct mediciones*);
struct facturas* borrar_facturas(struct facturas*);

/*									PROTOTIPOS PARA LAS FUNCIONES BORRAR LISTA								*/


void recorrer_usu(struct usuarios*);
void recorrer_medx(struct medxusuario*);
void recorrer_medidores(struct medidores*);
void recorrer_mediciones(struct mediciones*);
void recorrer_mediciones_2(struct mediciones*);
void recorrer_facturas(struct facturas*);

/*									PROTOTIPO PARA CREAR LA RUTA DE LOS CAMINANTES							*/
void crearuta(struct medxusuario *);


/*									PROTOTIPO PARA ACTUALIZAR EL ARCHIVOS						*/
void archivo_facturas(struct facturas*);
void actualiza_mediciones(struct mediciones *);


#endif
