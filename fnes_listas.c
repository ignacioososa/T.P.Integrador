#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

/*******************************FUNCION PARA CREAR LA LISTAS**********************************************/

/*Funcion para crear la lista de "Usuarios" a partir del Archivo "Usuarios.txt"*/
struct usuarios* lista_usuario(){
	FILE *usu;
	struct usuarios *nv=NULL,*L=NULL; //nv: nuevo nodo que se crea e inserta en la lista - L: puntero inicial de la lista
	char linea[1000],aux[100]; //linea: cadena que guarda los valores de cada linea del block de notas - aux: cadena que sirve para pasar los valores de "linea" a las variables de mi estructura
	int i,j;

	if((usu=fopen("Usuarios.txt","r"))!=NULL){
		while(!feof(usu)){
			nv = (struct usuarios *) malloc(sizeof(struct usuarios));
			if(nv!=NULL){
					i=0;
				j=0;

				fgets(linea,sizeof(linea),usu); //funcion para guardar una linea entera del bloc de notas

				memset(aux,0,100); //funcion para vaciar mi cadena "aux", (lo que hace es asignar el valor "\0" a todas las celdas de la cadena)
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idusuario = atol(aux); //atol: trasnforma una cadena en un numero "long" - asigna el primer valor de la linea de texto a la variable idusuario

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){ //recorre la cadena "linea" hasta que encuentra una "," para as? quedarme con el valor, en este caso "apellido y nombre"
					aux[j] = linea[i];
					j++; i++;
				}
				strcpy(nv->apellidonombre,aux);

				i++;j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}

				nv->fechaalta = atol(aux);

				nv->sgte = NULL;


				L = insertar_usuario(nv,L); //Inserta nv en la lista L
				nv = NULL;
			}
			else
				printf("Error");
		}

	}

	else
	printf("Error");

	fclose(usu); //cierra el archivo "Usuario.txt"

	return L; //retorna el puntero inicial al main
}
//----------------------------------------------------------------------------------





//Funcion para crear la lista de "Medxusuario" a partir del Archivo "MedXUsuario.txt"
struct medxusuario* lista_medxusuario(){
	FILE *medx; //puntero para el archivo "MedXUsuario.txt"
	struct medxusuario *nv=NULL,*L=NULL;
	char linea[1000],aux[100];
	int i,j;

	if((medx=fopen("MedXUsuario.txt","r"))!=NULL){
		while(!feof(medx)){
			nv = (struct medxusuario *) malloc(sizeof(struct medxusuario));
			if(nv!=NULL){
				i=0;
				j=0;

				fgets(linea,sizeof(linea),medx);

				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idusuario = atol(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idmedidor = atol(aux);

				i++;j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idcuenta = atol(aux);

				i++;j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->fechaalta = atol(aux);

				i++;j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->fechabaja = atol(aux);

				nv->sgte = NULL;

				L = insertar_medxusuario(nv,L);
				nv = NULL;	
			}
			else
				printf("Error");
		}
	}
	else
		printf("Error");

	fclose(medx);

	return L;
}
//----------------------------------------------------------------------------------





/*Funcion para crear la lista de "Medidores" a partir del Archivo "Medidores.txt"*/
struct medidores* lista_medidores(){
	FILE *medidor; //puntero para el archivo "Medidores.txt"
	struct medidores *nv=NULL,*L=NULL;
	char linea[1000],aux[100];
	int i,j;

	if((medidor=fopen("Medidores.txt","r"))!=NULL){
		while(!feof(medidor)){
			nv = (struct medidores *) malloc(sizeof(struct medidores));
			if(nv!=NULL){
				i=0;
				j=0;

				fgets(linea,sizeof(linea),medidor); //funcion para guardar una linea entera del bloc de notas

				memset(aux,0,100); //funcion para vaciar mi cadena "aux", (lo que hace es asignar el valor "\0" a todas las celdas de la cadena)
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idmedidor = atol(aux); //atol: trasnforma una cadena en un numero "long" - asigna el primer valor de la linea de texto a la variable idmedidor

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->numero = atol(aux);

				i++;j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}

				strcpy(nv->modelo,aux);

				nv->sgte = NULL;


				L = insertar_medidores(nv,L); //Inserta nv en la lista L
				nv = NULL;
			}
			else
				printf("Error");
		}

	}
	else
		printf("Error");

	fclose(medidor); //cierra el archivo "Medidores.txt"

	return L; //retorna el puntero inicial al main
}
//----------------------------------------------------------------------------------




/*Funcion para crear la lista de "Mediciones" a partir del Archivo "Mediciones.txt"*/
struct mediciones* lista_mediciones(){
	FILE *medicion; //puntero para el archivo "Mediciones.txt"
	struct mediciones *nv=NULL,*L=NULL;
	char linea[1000],aux[100];
	int i,j;

	if((medicion=fopen("Mediciones.txt","r"))!=NULL){
		while(!feof(medicion)){
			nv = (struct mediciones *) malloc(sizeof(struct mediciones));
			if(nv!=NULL){
				i=0;
				j=0;

				fgets(linea,sizeof(linea),medicion); //funcion para guardar una linea entera del bloc de notas

				memset(aux,0,100); //funcion para vaciar mi cadena "aux", (lo que hace es asignar el valor "\0" a todas las celdas de la cadena)
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idcuenta = atol(aux); //atol: trasnforma una cadena en un numero "long" - asigna el primer valor de la linea de texto a la variable idcuenta

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->periodo = atol(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->fechalectura = atol(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->lectura = atof(aux);

				nv->sgte = NULL;
				nv->ant = NULL;

				L = insertar_mediciones(nv,L,NULL); //Al ser LDE hay que pasar el puntero anterior
				nv = NULL;
			}
			else
				printf("Error");
		}

	}
	else
		printf("Error");

	fclose(medicion); //cierra el archivo "Mediciones.txt"

	return L; //retorna el puntero inicial al main
}
//----------------------------------------------------------------------------------




/*Funcion para crear la lista de "Facturas" a partir del Archivo "Facturas.txt"*/
struct facturas* lista_facturas(){
	FILE *factura; //puntero para el archivo "Facturas.txt"
	struct facturas *nv=NULL,*L=NULL;
	char linea[1000],aux[100];
	int i,j;

	if((factura=fopen("Facturas.txt","r"))!=NULL){
		while(!feof(factura)){
			nv = (struct facturas *) malloc(sizeof(struct facturas));
			if(nv!=NULL){
				i=0;
				j=0;

				fgets(linea,sizeof(linea),factura); //funcion para guardar una linea entera del bloc de notas

				memset(aux,0,100); //funcion para vaciar mi cadena "aux", (lo que hace es asignar el valor "\0" a todas las celdas de la cadena)
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idcuenta = atol(aux); //atol: trasnforma una cadena en un numero "long" - asigna el primer valor de la linea de texto a la variable idcuenta

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->periodo = atol(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->fechaemision = atol(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->consumo = atof(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->totalapagar = atof(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->pagado = atoi(aux);

				nv->sgte = NULL;

				L = insertar_facturas(nv,L);
				nv = NULL;
			}
			else
				printf("Error");
		}

	}
	else
		printf("Error");

	fclose(factura); //cierra el archivo "Facturas.txt"

	return L; //retorna el puntero inicial al main
}
//----------------------------------------------------------------------------------

struct costos* lista_costos(){
	FILE *costo; //puntero para el archivo "Costos.txt"
	struct costos *nv=NULL,*L=NULL;
	char linea[1000],aux[100];
	int i,j;
	
	if((costo=fopen("Costos.txt","r"))!=NULL){
		while(!feof(costo)){
			nv = (struct costos *) malloc(sizeof(struct costos));
			if(nv!=NULL){
				i=0;
				j=0;
					
				fgets(linea,sizeof(linea),costo);
				
				memset(aux,0,100); 
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idcostos = atoi(aux); 
				
				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->mtsdesde = atoi(aux);
			
				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->mtshasta = atoi(aux);
				
				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->valorMetro = atoi(aux);
			
				nv->sgte = NULL;
			
				L = insertar_costos(nv,L);
				nv = NULL;
			}
			else
				printf("Error");
		}	
	}else
		printf("Error");
	
	fclose(costo); //cierra el archivo "Costos.txt"
	
	return L; //retorna el puntero inicial al main
}

//Crea una lista con los usuarios que tienen "fechabaja = 0".(ACTIVIDAD 1)
struct medxusuario *lista_rutacaminante(){
	FILE *medx; //puntero para el archivo "MedXUsuario.txt"
	struct medxusuario *nv=NULL,*L=NULL;
	char linea[1000],aux[100];
	int i,j;

	if((medx=fopen("MedXUsuario.txt","r"))!=NULL){
		while(!feof(medx)){
			nv = (struct medxusuario *) malloc(sizeof(struct medxusuario));
			if(nv!=NULL){
				i=0;
				j=0;

				fgets(linea,sizeof(linea),medx);

				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idusuario = atol(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idmedidor = atol(aux);

				i++;j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idcuenta = atol(aux);

				i++;j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->fechaalta = atol(aux);

				i++;j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->fechabaja = atol(aux);

				nv->sgte = NULL;
				
				if((nv->fechabaja == 0)&&(nv->fechaalta <= fecha)){
					L = insertar_medxusuario(nv,L);
				}
				
				nv = NULL;
				
					
			}
			else
				printf("Error");
		}
	}
	else
		printf("Error");

	fclose(medx);
	
	return L;
}
//-------------------------------------------------------------------------------------







//crea una lista doblemente enlasada con los datos que le da el archivo "Ruta_caminante.txt"(ACTIVIDAD 2)
struct mediciones* lista_NVmedicion(){
	FILE *NVmedicion; //puntero para el archivo "Ruta_caminante.txt"
	struct mediciones *nv=NULL,*L=NULL;
	char linea[1000],aux[100],periodo[7],nomArchivo[30] = "Ruta_caminante_",anio[5],mes[3];
	int i,j,b = 0,a,m;
	
	while(b != 1){
		
		printf("Ingrese el periodo (aaaamm): ");
		gets(periodo);
		
		strncpy(anio,periodo,4);
		anio[4] = '\0';
		strncpy(mes,periodo + 4,2);
		mes[2] = '\0';
		a = atoi(anio);
		m = atoi(mes);

		if((a != 2023)||(m < 1)||(m > 12)){//ajustar rango
			printf("\nERROR: fecha no valida\n");
		}else{
			b = 1;
		}

	}
	
	strcat(nomArchivo,anio);
	strcat(nomArchivo,mes);
	strcat(nomArchivo,".txt");

	if((NVmedicion=fopen(nomArchivo,"r"))!=NULL){
		while(!feof(NVmedicion)){
			nv = (struct mediciones *) malloc(sizeof(struct mediciones));
			if(nv!=NULL){
				i=0;
				j=0;

				fgets(linea,sizeof(linea),NVmedicion); //funcion para guardar una linea entera del bloc de notas

				memset(aux,0,100); //funcion para vaciar mi cadena "aux", (lo que hace es asignar el valor "\0" a todas las celdas de la cadena)
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->idcuenta = atol(aux); //atol: trasnforma una cadena en un numero "long" - asigna el primer valor de la linea de texto a la variable idcuenta

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->periodo = atol(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->fechalectura = atol(aux);

				i++; j=0;
				memset(aux,0,100);
				while(linea[i]!=','){
					aux[j] = linea[i];
					j++; i++;
				}
				nv->lectura = atof(aux);

				nv->sgte = NULL;
				nv->ant = NULL;

				L = insertar_mediciones(nv,L,NULL); //Al ser LDE hay que pasar el puntero anterior
				nv = NULL;
			}
			else
				printf("Error");
		}

	}
	else
		printf("\nERROR: no se pudo abrir este archivo\n");

	fclose(NVmedicion); //cierra el archivo "Ruta_caminante_aaaa/mm.txt"

	return L; //retorna el puntero inicial al main
}
//-------------------------------------------------------------------------------------









/*								FUNCION PARA SOBREESCRIBIR / ACTUALIZAR LOS ARCHIVOS CSV								*/

/*Funcion para actualizar el archivo "Facturas.txt" a partir de la lista "Facturas"*/
void archivo_facturas(struct facturas *l){
	FILE *factura=NULL;

	if((factura=fopen("Facturas.txt","w"))!=NULL){
		while(l != NULL){
			if(l->sgte == NULL){ //Si es el ultimo nodo de la lista no debe imprimir "\n" para evitar problemas
				fprintf(factura,"%ld,%ld,%ld,%.2f,%.2f,%d,",l->idcuenta,l->periodo,l->fechaemision,l->consumo,l->totalapagar,l->pagado);
			}
			else{
				fprintf(factura,"%ld,%ld,%ld,%.2f,%.2f,%d,\n",l->idcuenta,l->periodo,l->fechaemision,l->consumo,l->totalapagar,l->pagado);
			}
			l = l->sgte;
		}
	}
	else
		printf("ERROR DE APERTURA");

	fclose(factura);
}
//----------------------------------------------------------------------------------




//Actualiza el archivo "Mediciones.txt" (cargando la lista enviada por parametro) (ACTIVIDAD 2)
void actualiza_mediciones(struct mediciones *l){
	FILE *med=NULL;

	if((med=fopen("Mediciones.txt","w"))!=NULL){
		while(l != NULL){
			if(l->sgte == NULL){ 
				fprintf(med,"%ld,%ld,%ld,%.2f,",l->idcuenta,l->periodo,l->fechalectura,l->lectura);
			}
			else{
				fprintf(med,"%ld,%ld,%ld,%.2f,\n",l->idcuenta,l->periodo,l->fechalectura,l->lectura);
			}
			l = l->sgte;
		}
	}
	else printf("ERROR DE APERTURA");

	fclose(med);
}
//-------------------------------------------------------------------------------------





//Crea la ruta en un archivo csv llamado "Ruta_caminante.txt", con la lista envida por parametro (ACTIVIDAD 1)
void crearuta(struct medxusuario *l){
	FILE *ruta=NULL;
	char periodo[7],nomArchivo[30] = "Ruta_caminante_",anio[5],mes[3];
	int a,m,b = 0;
	
	while(b != 1){
		
		printf("Ingrese el periodo (aaaamm): ");
		gets(periodo);
		
		strncpy(anio,periodo,4);
		anio[4] = '\0';
		strncpy(mes,periodo + 4,2);
		mes[2] = '\0';
		a = atoi(anio);
		m = atoi(mes);

		if((a != 2023)||(m < 1)||(m > 12)){//ajustar rango
			printf("\nERROR: fecha no valida\n");
		}else{
			b = 1;
		}

	}
	
	strcat(nomArchivo,anio);
	strcat(nomArchivo,mes);
	strcat(nomArchivo,".txt");
	
	if((ruta=fopen(nomArchivo,"r"))!=NULL){
		printf("\nERROR: este archivo ya fue creado\n");
		fclose(ruta);
	}else{
		if((ruta=fopen(nomArchivo,"w"))!=NULL){
			while(l != NULL){
				if(l->sgte == NULL){ //Si es el ultimo nodo de la lista no debe imprimir "\n" para evitar problemas
					fprintf(ruta,"%ld,%s,",l->idcuenta,periodo);
				}
				else{
					fprintf(ruta,"%ld,%s,\n",l->idcuenta,periodo);
				}
				l = l->sgte;
			}
		}
		else printf("\nERROR: no se pudo abrir arvhivo\n");

		fclose(ruta);
	}
	
}
//-------------------------------------------------------------------------------------




/******************FUNCIONES PARA COMPROBAR SI FUNCIONA (esto no va estar dentro del codigo que presentemos)***************************/
void recorrer_usu(struct usuarios *r){
	if(r!=NULL){
		printf("%d\n",r->idusuario);
		printf("%s\n",r->apellidonombre);
		printf("%ld\n",r->fechaalta);
		recorrer_usu(r->sgte);
	}
}

void recorrer_medx(struct medxusuario *r){
	if(r!=NULL){
		printf("%d\n",r->idusuario);
		printf("%d\n",r->idmedidor);
		printf("%d\n",r->idcuenta);
		printf("%d\n",r->fechaalta);
		printf("%d\n",r->fechabaja);
		recorrer_medx(r->sgte);
	}
}

void recorrer_medidores(struct medidores *r){
	struct medidores *ini=r;
	printf("%d\n",r->idmedidor);
	printf("%d\n",r->numero);
	printf("%s\n",r->modelo);
	r=r->sgte;
	while(r!=ini){
		printf("%d\n",r->idmedidor);
		printf("%d\n",r->numero);
		printf("%s\n",r->modelo);
		r=r->sgte;
	}
}

void recorrer_mediciones(struct mediciones *r){
	if(r!=NULL){
		printf("%d\n",r->idcuenta);
		printf("%d\n",r->periodo);
		recorrer_mediciones(r->sgte);
	}
}

void recorrer_mediciones_2(struct mediciones *r){
	struct mediciones *l=NULL;

	while(r != NULL){
		l = r;
		r = r->sgte;
	}
	while(l != NULL){
		printf("%d\n",l->idcuenta);
		printf("%d\n",l->periodo);
		l = l->ant;
	}
}

void recorrer_facturas(struct facturas *r){
	if(r!=NULL){
		printf("%d\n",r->idcuenta);
		printf("%ld\n",r->periodo);
		recorrer_facturas(r->sgte);
	}
}

void recorrer_costos(struct costos *r){
	if(r!=NULL){
		printf("%d, %d\n",r->idcostos,r->valorMetro);
		recorrer_costos(r->sgte);
	}
}

//								FUNCIONES PARA FACTURAR
int buscar_facturas(long x, struct facturas *r){
	int v=0;
	while((r!=NULL)&&(!v)){
		if(r->periodo==x){
			v=1;
		}	
		r = r->sgte;
	}
	return v;
}

struct facturas* facturar(long p_act, struct mediciones *m, struct facturas *f, struct costos *c){
	struct mediciones *aux=NULL, *aux2=NULL;
	struct facturas *n=NULL;
	long p_ant;
	float lect_act, lect_ant, consumo = 0;
	int v=0;
	
	aux=m;
	aux2=aux;
	p_ant=periodo_anterior(p_act); //cambiar
	
	while(m!=NULL){
		if(m->periodo==p_act){
			v=1;
			//cambiar
			aux2=aux;
			while(aux2!=NULL){
				if((m->idcuenta==aux2->idcuenta)&&(p_ant==aux2->periodo)){
					lect_ant=aux2->lectura;
					aux2=NULL;
				}else
					aux2=aux2->sgte;
			}
			lect_act=m->lectura;
			consumo= lect_act-lect_ant;
			n=(struct facturas *) malloc(sizeof(struct facturas));
			if(n!=NULL){
				n->consumo = consumo;
				n->fechaemision = fecha_emision();
				n->idcuenta = m->idcuenta;
				n->pagado = 0;
				n->periodo = p_act;
				n->totalapagar = buscar_costo(consumo,c);
				n->sgte = NULL;
				f = insertar_facturas(n,f);
				n=NULL;
			}else
				printf("\nError en facturar");
		}
		m=m->sgte;
	}
	
	if(v==0)
		printf("\nNo se encontraron mediciones del periodo.\n");
	else
		printf("\nFacturacion exitosa.\n");
		
	return f;
}

long periodo_anterior(long x){
	long y;
	y = x-1;
	if(y%10==0){
		y = (x/100);
		y = y - 1;
		y = (y*100) + 12;
	}
	return y;
}

float buscar_costo(float consumo, struct costos *r){
	float resto;
	float costo=0;

/*
1,0,15,130,
2,15,25,145,
3,25,45,155,
4,45,1000,175,
*/
	while(r!=NULL){
		if(consumo>=r->mtshasta){
			costo = costo + (r->mtshasta - r->mtsdesde) * r->valorMetro;
		}else{
			if(consumo>=r->mtsdesde){
				resto = consumo - r->mtsdesde;
				costo = costo + resto * r->valorMetro;
			}
		/*	else
				r = NULL;*/
		}
		
		r=r->sgte;
	}
	return costo;
}

long fecha_emision(){
	
	long fecha;
	SYSTEMTIME st;
    GetLocalTime(&st);

    // Construir el valor long de la fecha actual
    fecha = st.wYear * 10000 + st.wMonth * 100 + st.wDay;

    return fecha;
}
