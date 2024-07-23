/*Ejercicio 2
Se cuenta con información de los socios de un club provincial: DNI, edad, tipo y estado: “Activo “o “Inactivo”. Los 
tipos de socios están determinados por letras: ‘A’: Socio deportivo, …, ‘J’: Socio Jubilado. La cantidad de socios se 
ingresa por teclado. 
Escribir un programa en C que permita: 
a) Cargar los datos en una estructura adecuada. (Validar el ingreso, suponiendo que el tipo de socio varía entre ‘A’ 
y ‘J ‘) 
b) Para un tipo de socio determinado, mostrar los DNI de los socios que tienen edad mayor a 40. Generar una 
estructura auxiliar. 
c) Realizar un listado que muestre, cuantas personas se encuentran activas, para cada tipo de socio. Generar una 
estructura auxiliar.*/

#include <stdio.h>
#include "malloc.h"
#include<string.h>

typedef struct
{
    char nombre[30], estado[8], tipo;
    int dni, edad;
}socio;

void carga(socio *arre, int num){
    for (int i = 0; i < num; i++)
    {
        printf("\nDatos del socio numero %d: \n", i+1);
        printf("Nombre: ");
        fflush(stdin);
        gets(arre[i].nombre);
        printf("Edad: ");
        scanf("%d", &arre[i].edad);
        printf("Dni: ");
        scanf("%d", &arre[i].dni);
        printf("Estado (Activo o Inactivo): ");
        fflush(stdin);
        gets(arre[i].estado);
        printf("Tipo: ");
        fflush(stdin);
        scanf("%c", &arre[i].tipo);
        while((arre[i].tipo!='a')&&(arre[i].tipo!='j'))
        {
            printf("Tipo no valido.");
            printf("\nTipo: ");
            fflush(stdin);
            scanf("%c", &arre[i].tipo);
        }
    }
}

void mostrar(int *subarre, int cont){
    printf("\nSocios mayores de 40 anos:\n");
    for (int i = 0; i < cont; i++)
    {
            printf("Dni: %d\n", subarre[i]);
    }
}

void sub(socio *arre, int num){
    char est;
    int *subarre;
    int cont=0;
    printf("\nIngrese un tipo para mostrar los socios mayores de 40 anos:");
    fflush(stdin);
    scanf("%c", &est);
    while ((est!='a')&&(est!='j'))
    {
        printf("Tipo no valido.");
        printf("\nIngrese un tipo para mostrar los socios mayores de 40 anos:");
        fflush(stdin);
        scanf("%c", &est);
    }

    for (int i = 0; i < num; i++)
    {
        if ((arre[i].tipo==est)&&(arre[i].edad>40))
        {
            cont++;
        }
    }

    subarre=(int*)malloc(sizeof(int)*cont);
    int j=0;
    for (int i = 0; i < num; i++)
    {
        if ((arre[i].tipo==est)&&(arre[i].edad>40))
        {
            subarre[j]=arre[i].dni;
            j++;
        }
    }
    mostrar(subarre, cont);
    free(subarre);
}

void mostraractivas(socio *arre, int num){
    int activos[2]; //2 tipos diferentes
    for (int i = 0; i < 2; i++)
    {
        activos[i]=0;
    }
    
    for (int i = 0; i < num; i++)
    {
        if (strcmp(arre[i].estado, "Activo")==0)
        {
            if (arre[i].tipo=='a')
            {
                activos[0]++;
            }
            else if (arre[i].tipo=='j')
            {
                activos[1]++;
            }
        }
    }
    printf("\nCantidad de socion activos:\n");
    printf("Socio deportivo: %d", activos[0]);
    printf("\nSocio Jubilado: %d", activos[1]);
}
int main(){
    int num;
    socio *arre;
    printf("Ingrese la cantidad de socios del club: ");
    scanf("%d", &num);
    arre=(socio*)malloc(sizeof(socio)*num);
    carga(arre, num);
    sub(arre, num);
    mostraractivas(arre, num);
    free(arre);
}