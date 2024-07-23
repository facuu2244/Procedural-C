/*Ejercicio 7
Cargar aleatoriamente una tabla de 5x4 con números enteros y:
a) Mostrar la suma de cada una de las filas.
b) Calcular el promedio de la tercera columna.
c) Decir cuántos números mayores a 100 se ingresaron.*/

#include <stdio.h>
#define filas 5
#define columnas 4

void inicializar(int tabla[filas][columnas]){
    int i, j;
    for(i=0; i<5; i++){
        for (j = 0; j < 4; j++){
            tabla[i][j]=0;
        }
    }
}

void cargar(int tabla[filas][columnas]){
    int i, fila, colum, num, cont;
    cont=0;
    for (i = 0; i < (filas*columnas); i++){
        printf("Numero a cargar: ");
        scanf("%d", &num);
        printf("\nFila donde quiere cargarlo: ");
        scanf("%d", &fila);
        printf("\nColumna donde quiere cargarlo: ");
        scanf("%d", &colum);
        tabla[fila-1][colum-1]=num;
        if (num>100){
            cont++;
        }
    }

    for (i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("%d ", tabla[i][j]);
        }
        printf("\n");
    }
    printf("\nNumeros mayores a 100 ingresados: %d", cont);
}

void promedio(int tabla[filas][columnas]){
    int i, acum;
    float prom;
    acum=0;

    for (i = 0; i < filas; i++){
            acum+=tabla[i][columnas-1];
    }
    prom=(acum/2);
    printf("\nPromedio de la tercer columna: %.1f", prom);
}

int main(){
    int tabla[filas][columnas];
    inicializar(tabla);
    cargar(tabla);
    promedio(tabla);
}