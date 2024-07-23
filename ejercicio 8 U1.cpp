/*Ejercicio 8
Realizar un programa en lenguaje C, que usando funciones óptimas realice lo siguiente:
a) Generar y cargar un arreglo bidimensional de enteros de 3x4.
b) Mostrar en el main la suma de los elementos con valor impar.
c) Ingresar un número de fila y mostrar en el main la cantidad de elementos mayores a 10 (realice una función que 
devuelva la cantidad al main).*/

#include <stdio.h>
#define filas 3
#define columnas 4
void inicializa(int tabla[filas][columnas]){
    int i, j, num;
    for(i = 0; i < filas; i++){
        for (j = 0; j < columnas; j++){
            tabla[i][j]=0;
        }
    }
    printf("LOS NUMEROS SE CARGARAN DE FORMA SECUENCIAL\n");
    
    for (i = 0; i < filas; i++){
        for (j= 0; j < columnas; j++){
            printf("\nNumero a ingresar: ");
            scanf("%d", &num);
            tabla[i][j]=num;
        }
    }
}

int calc_mayores(int tabla[filas][columnas]){
    int cont, fil;
    cont=0;
    printf("\nIngrese el numero de la fila: ");
    scanf("%d", &fil);
    for (int j = 0; j<columnas; j++){
        if (tabla[fil-1][j]>10){
            cont++;
        }
    }
    return(cont);
}

int main(){
    int tabla[filas][columnas], acum, mayores_10;
    acum=0;
    inicializa(tabla);
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            if ((tabla[i][j])%2!=0){
                acum+=tabla[i][j];
            }
            
        }
        
    }
    printf("\nLa suma de todos los numeros impares es: %d", acum);
    mayores_10=calc_mayores(tabla);
    printf("\nCantidad de numeros mayores que 10 de la fila ingresada: %d", mayores_10);
}