#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"

/**********************************FUNCION PARA INSERTAR NODOS A LAS LISTAS*******************************************/

/*Funcion para insertar nodos en la LES "usuarios"*/
struct usuarios* insertar_usuario(struct usuarios *p,struct usuarios *l){
	if(l != NULL){
		l->sgte = insertar_usuario(p,l->sgte);
	}
	else
		l = p;
	return l;
}

/*Funcion para insertar nodos en la LES "medxusuario"*/
struct medxusuario* insertar_medxusuario(struct medxusuario *p,struct medxusuario *l){
	if(l != NULL){
		l->sgte = insertar_medxusuario(p,l->sgte);
	}
	else
		l = p;
	return l;
}

/*Funcion para insertar nodos en la LEC "medidores"*/
struct medidores* insertar_medidores(struct medidores *p,struct medidores *l){ //Lista Enlazada Circular
	if(l == NULL){ //Si la lista esta vacia "l" el primer nodo se apunta a si misma
		l = p;
		l->sgte = p;
	}
	else{
		p->sgte = l->sgte;
		l->sgte = p;
	}
	return l;
}

/*Funcion para insertar nodos ORDENADOS en la LDE "mediciones"*/
struct mediciones* insertar_mediciones(struct mediciones *p, struct mediciones *l,struct mediciones *ant){
	if(l == NULL){ //inserta el primer o ultimo nodo
		p->ant = ant;
		l = p;
	}
	else{
		if(ant == NULL){ //inserta un segundo nodo
			if(p->idcuenta < l->idcuenta){
				p->sgte = l;
				l->ant = p;
				l = p;
			}
			else{
				if(p->idcuenta == l->idcuenta && p->periodo < l->periodo){
					p->sgte = l;
					l->ant = p;
					l = p;
				}
				else
					l->sgte = insertar_mediciones(p,l->sgte,l);
			}
		}
		else{ //inserta un nodo que esta en el medio
			if(p->idcuenta < l->idcuenta){
				p->ant = ant;
				p->sgte = l;
				l->ant = p;
				l = p;
			}
			else{
				if(p->idcuenta == l->idcuenta && p->periodo < l->periodo){
					p->ant = ant;
					p->sgte = l;
					l->ant = p;
					l = p;
				}
				else
					l->sgte = insertar_mediciones(p,l->sgte,l);
			}
		}
	}
	
	return l;
}

/*Funcion para insertar nodos en la LES "facturas"*/
struct facturas* insertar_facturas(struct facturas *p,struct facturas *l){
	if(l != NULL){
		l->sgte = insertar_facturas(p,l->sgte);
	}
	else
		l = p;
	return l;
}


/*							FUNCIONES PARA BORRAR LAS LISTAS					*/
//Estas funciones deben ir SIEMPRE al final del codigo para no ocupar espacio de memoria

struct usuarios* borrar_usuario(struct usuarios *l){
	struct usuarios *aux=NULL;
	
	while(l != NULL){
		aux = l;
		l = l->sgte;
		aux->sgte = NULL;
		free(aux);
	}
	
	return NULL;
}

struct medxusuario* borrar_medxusuario(struct medxusuario *l){
	struct medxusuario *aux=NULL;
	
	while(l != NULL){
		aux = l;
		l = l->sgte;
		aux->sgte = NULL;
		free(aux);
	}
	
	return NULL;
}

struct medidores* borrar_medidores(struct medidores *l){
	struct medidores *aux=NULL,*bor=NULL,*ant=NULL;
	
	if(l != NULL){
		ant = l;
		l = l->sgte;
		while(l != ant){
			aux = l;
			l = l->sgte;
			ant->sgte = l;
			aux->sgte = NULL;
			free(aux);
		}
		
		if(l == ant){
			l->sgte = NULL;
			free(aux);
		}
	}
	
	return NULL;
}

struct mediciones* borrar_mediciones(struct mediciones *l){
	struct mediciones *aux=NULL;
	
	while(l != NULL){
		aux = l;
		l = l->sgte;
		if(l != NULL){
			l->ant = NULL;
			aux->sgte = NULL;
		}
		free(aux);
	}
	
	return NULL;
}

struct facturas* borrar_facturas(struct facturas *l){
	struct facturas *aux=NULL;
	
	while(l != NULL){
		aux = l;
		l = l->sgte;
		aux->sgte = NULL;
		free(aux);
	}
	
	return NULL;
}
