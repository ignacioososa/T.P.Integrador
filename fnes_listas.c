#include "fnes_insertar.c"

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
				while(linea[i]!=','){ //recorre la cadena "linea" hasta que encuentra una "," para así quedarme con el valor, en este caso "apellido y nombre"
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


/*Funcion para crear la lista de "Medxusuario" a partir del Archivo "MedXUsuario.txt"*/
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
