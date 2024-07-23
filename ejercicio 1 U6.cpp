/*Ejercicio 1
Almacenar la información de los asistentes a unas jornadas de capacitación, de cada asistente se conoce su nombre y 
edad.
Utilizando funciones óptimas realice lo siguiente:
a) Genere un archivo de acceso secuencial con la información de los asistentes a las jornadas.
b) Muestre los nombres de los asistentes mayores de 40 años*/

#include <stdio.h>
#include <string.h>
typedef struct 
{
    char nombre[30];
    int edad;
}alumno;

void carga(FILE *archi){
    alumno al;
    printf("\nNombre del alumno: ");
    fflush(stdin);
    gets(al.nombre);
    while (strcmp(al.nombre, "fin")!=0)
    {
        printf("\nEdad del alumno: ");
        scanf("%d", &al.edad);
        fwrite(&al, sizeof(al), 1, archi);
        printf("\nNombre del alumno: ");
        fflush(stdin);
        gets(al.nombre);
    }
}
void mostrar(FILE *archi){
    alumno al;
    rewind(archi);
    fread(&al, sizeof(al), 1, archi);
    while (feof(archi)==0)
    {
        if (al.edad>40)
        {
            printf("\nNombre %s edad %d", al.nombre, al.edad);
        }
        fread(&al, sizeof(al), 1, archi);
    }
}
int main(){
    FILE *archi;
    if ((archi=fopen("archi.dat", "a+"))==NULL)
    {
        printf("Error al crear el archivo");
    }
    else{
        carga(archi);
        mostrar(archi);
    }
    fclose(archi);
}