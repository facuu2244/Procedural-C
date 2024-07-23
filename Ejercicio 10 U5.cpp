#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define N 2

typedef struct nodo{
	char nombre[30];
	float prom;
	int ano;
	struct nodo* sig;
}nodo;

typedef nodo*puntero;

struct facultad{
	char facumbre[30];
	int cant;
	puntero alumno;
};

void inicia(struct facultad a[N],int i){
	if(i==N){
		return;
	}else{
		printf("\nNombre de la facultad %d: ", i+1);
		fgets(a[i + 1].facumbre, sizeof(a[i + 1].facumbre), stdin);
        a[i + 1].facumbre[strcspn(a[i + 1].facumbre, "\n")] = '\0';
        a[i + 1].cant = 0;
        a[i + 1].alumno = NULL;
        inicia(a, i + 1);
	}
}

void insertar(puntero*xp, puntero nuevo){
	puntero p;
	puntero anterior;
	if (*xp == NULL){
		*xp = nuevo;
		nuevo->sig=NULL;
	}else{
		p=*xp;
		anterior=*xp;
		while((p!=NULL)&&(nuevo->prom>p->prom)){
			anterior=p;
			p=p->sig;
		}
		anterior->sig=nuevo;
		nuevo->sig=p;
	}
}

void carga(struct facultad a[N]){
	for(int i=0;i<N;i++){
		printf("\nCarga de la facultad %d: ",i+1);
		int seguir=1;
		while (seguir != 0) {
            puntero nuevo;
            nuevo = (puntero)malloc(sizeof(nodo));
            printf("\nNombre del alumno: ");
            fflush(stdin);
            fgets(nuevo->nombre, sizeof(nuevo->nombre), stdin);
            nuevo->nombre[strcspn(nuevo->nombre, "\n")] = '\0';
            printf("\nPromedio del alumno: ");
            scanf("%f", &nuevo->prom);
            printf("\nAnio que cursa: ");
            scanf("%d", &nuevo->ano);
            insertar(&(a[i].alumno), nuevo);
            printf("\nDesea cargar otro alumno? 1:SI ... 0:NO: ");
            scanf("%d", &seguir);
        }
	}
}

int contarAlumnos(puntero p, int anio) {
    if (p == NULL) {
        return 0;
    } else {
        if (p->prom >= 7 && p->ano >= anio) {
            return 1 + contarAlumnos(p->sig, anio);
        } else {
            return contarAlumnos(p->sig, anio);
        }
    }
}

void mostrarRecursivo(struct facultad a[N], int i, int anio) {
    if (i > 0) {
        printf("\nFacultad %d - %s: %d alumnos con promedio >= 7 y cursando de %d en adelante",
        i, a[i - 1].facumbre, contarAlumnos(a[i - 1].alumno, anio), anio);
        mostrarRecursivo(a, i - 1, anio);
    }
}

int main(){
	int i=0;
	int anio=2;
	struct facultad a[N];
	printf("\nINICIALIZACION DEL ARREGLO");
	inicia(a,i);
	carga(a);
	mostrarRecursivo(a,i,anio);
	
	for (int j=0;j>N;j++){
		puntero actual= a[j].alumno;
		while (actual!=NULL){
			puntero siguiente = actual->sig;
			free (actual);
			actual = siguiente;
		}
	}
	return 0;
}