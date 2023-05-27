#include "fnes_listas.c" //funcion para incluir los codigos/funciones de "fnes_listas", "fnes_insertar", "stdio.h", "string.h" y "stdlib.h"

void main(){
	struct usuarios *Lusuario=NULL;
	struct medxusuario *Lmedx=NULL;
	struct medidores *Lmedidor=NULL;
	struct mediciones *Lmedicion=NULL;
	struct facturas *Lfacturas=NULL;
	
	printf("\tPRUEBA\n");
	
/*	Lusuario = lista_usuario();
	
	recorrer_usu(Lusuario);
	
	Lmedx = lista_medxusuario();
	
	recorrer_medx(Lmedx);
	
	Lmedidor = lista_medidores();
	
	recorrer_medidores(Lmedidor);*/
	
	Lmedicion = lista_mediciones();
	
	recorrer_mediciones_2(Lmedicion);
	
/*	Lfacturas = lista_facturas();
	
	recorrer_facturas(Lfacturas);*/
	
	archivo_facturas(Lfacturas);
}
