/*Programa 3:
Codificar una función que permita mostrar Número de Registro y Nombre de alumnos que aprobaron ambas 
materias.*/
#include <stdio.h>

typedef struct 
{
    char nombre[30];
    int numReg;
    char resultParcial;
}alumno;

void mostrar(FILE *archi1, FILE *archi2){
    alumno c1, c2;
    rewind(archi1);
    fread(&c1, sizeof(c1), 1, archi1);

    rewind(archi2);
    fread(&c2, sizeof(c2), 1, archi2);

    while ((feof(archi1)==0)||(feof(archi2)==0))
    {
        if ((c1.resultParcial=='a')&&(c2.resultParcial=='a'))
        {
            printf("\nNombre: %s    Numero  de registro: %d", c1.nombre, c1.numReg);
        }
        fread(&c1, sizeof(c1), 1, archi1);
        fread(&c2, sizeof(c2), 1, archi2);
    }
}

int main(){
    FILE *archi1, *archi2;
    archi1=fopen("alumnosPP.data", "r");
    archi2=fopen("alumnosAL.data", "r");

    if ((archi1==NULL) || (archi2==NULL))
    {
        printf("Hubo un problema al abrir alguno de los archivos");
    }
    else
    {
        printf("Alumnos que aproaron ambas materias:\n");
        mostrar(archi1, archi2);
    }
    fclose(archi1);
    fclose(archi2);
}