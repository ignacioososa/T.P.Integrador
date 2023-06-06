#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"


void main(){
	struct usuarios *Lusuario=NULL;
	struct medxusuario *Lmedx=NULL;
	struct medidores *Lmedidor=NULL;
	struct mediciones *Lmedicion=NULL;
	struct facturas *Lfacturas=NULL;
	struct medxusuario *L = NULL;
	struct mediciones *L2 = NULL;

	printf("\tPRUEBA\n");

/*	Lusuario = lista_usuario();
	
	recorrer_usu(Lusuario);
	
	Lmedx = lista_medxusuario();
	
	recorrer_medx(Lmedx);
	
	Lmedidor = lista_medidores();
	
	recorrer_medidores(Lmedidor);*/

//	Lmedicion = lista_mediciones();
//
//	recorrer_mediciones_2(Lmedicion);

/*	Lfacturas = lista_facturas();
	
	recorrer_facturas(Lfacturas);*/

//	archivo_facturas(Lfacturas);
	
	
//	seccion para pribar si anda las actividades 1 y 2
	L = lista_rutacaminante(20230206);//le devuelve una lista enlasada simple con los usuarios con "fechabaja = 0"
	
	crearuta(L);//crea el archivo csv con la ruta para los caminantes
	
	L2 = lista_NVmedicion();
	
	actualiza_mediciones(L2);
//	-------------------------------------------------
}
