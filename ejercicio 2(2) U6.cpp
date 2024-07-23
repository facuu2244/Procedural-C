/*Programa 2:
a) Generar un archivo alumnosAL.dat que contiene la siguiente información correspondiente a los alumnos que 
cursan la materia Algebra Lineal: Nombre, Número de Registro y Resultado de un parcial (‘A’: Aprobado – ‘R’: 
Reprobado). El archivo debe estar ordenado por Número de Registro.
b) Codificar una función que permita mostrar la información de cada uno de los alumnos*/
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nombre[30];
    int numReg;
    char resultParcial;
}alumno;


void carga(FILE *archi){
    alumno c;
    printf("\nNombre del alumno: ");
    fflush(stdin);
    gets(c.nombre);
    while (strcmp(c.nombre, "fin")!=0)
    {
        printf("Resultado del parcial (A. Aprobado; R. Reprobado): ");
        scanf("%c", &c.resultParcial);
        fwrite(&c, sizeof(c), 1, archi);
        printf("Numero de registro: ");
        scanf("%d", &c.numReg);
        printf("\nNombre del alumno: ");
        fflush(stdin);
        gets(c.nombre);
    }
}

void mostar(FILE *archi){
    alumno c;
    rewind(archi);
    fread(&c, sizeof(c), 1, archi);
    while (feof(archi)==0)
    {
        printf("\nNombre: %s    Resultado del parcial: %c", c.nombre, c.resultParcial);
        fread(&c, sizeof(c), 1, archi);
    }   
}

int main(){
    FILE *archi;
    if ((archi=fopen("alumnosAL.data", "a+"))==NULL)
    {
        printf("No se pudo abir el archivo.");
    }
    else{
        carga(archi);
        mostar(archi);
    }
    fclose(archi);
}