/*Ejercicio 9
En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un área 
temática. En cada sala se dictan 4 conferencias en distintos turnos. Por cada interesado se ingresa número del área 
temática (1-6), y turno al que quiere asistir (1-4). La Facultad desea llevar un registro de la cantidad de alumnos 
inscriptos en cada área y en cada turno, para ello realizar los siguientes items:
a) Carga de los datos. La carga es desordenada, cada alumno indica área y turno. No se sabe la cantidad de alumnos.
b) Indicar la cantidad de inscriptos en cada turno de cada área.
c) Dada un área temática, indicar el promedio de inscriptos.*/

#include <stdio.h>
#define filas 6
#define columnas 4

void cerear(int tabla[filas][columnas]){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            tabla[i][j]=0;
        }
    }
}

void carga(int tabla[filas][columnas]){
    int area, turno;
    printf("Ingrese el area: ");
    scanf("%d", &area);
    while (area!=0){
        printf("Ingrese turno: ");
        scanf("%d", &turno);
        tabla[area-1][turno-1]++;
        printf("---------¡Inscripto!---------");
        printf("\nIngrese el area: ");
        scanf("%d", &area);
    }
}

void mostrar(int tabla[filas][columnas]){
    printf("\nArea     Turno     Cantidad de inscriptos");
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++) {
            printf("\n %d         %d               %d", i+1, j+1, tabla[i][j]);
        }
        printf("\n");
    }
}

int promedio(int tabla[filas][columnas]){
    int area_ingr, acum;
    acum=0;
    printf("\nIngresar area para ver el promedio de alumnos: ");
    scanf("%d", &area_ingr);
    for (int j = 0; j < columnas; j++){
        acum+=tabla[area_ingr-1][j];
    }
    return(acum/columnas);
}

int main(){
    int tabla[filas][columnas], prom;

    cerear(tabla);
    carga(tabla);
    mostrar(tabla);
    prom=promedio(tabla);
    printf("\nCantidad promedio de alumnos en el area ingresada: %d", prom);
}