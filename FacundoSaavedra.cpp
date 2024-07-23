#include <stdio.h>
#define N 4

void carga(int tabla[N][N]){ //carga y muestra el arreglo
    int num;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("Ingresar numero a cargar: ");
            scanf("%d", &num);
            tabla[i][j]=num;
        }
    }
    printf("\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", tabla[i][j]);
        }
        printf("\n");
    }
}

void sumacolum(int tabla[N][N], int *sumacol){
    for (int i = 0; i < N; i++){
        *sumacol+=tabla[i][2];
    }
}

int sumafila(int tabla[N]){
    int suma;
    for (int j = 0; j < N; j++){
        suma+=tabla[j];
    }
    return(suma);
}

void pares(int tabla[N][N], int par){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if ((tabla[i][j]%2)== 0){
                par++;
            }
        }
    }
    printf("\nHay %d numeros pares", par);
}

void numpositiv(int tabla[N][N], int *positivos){
    for (int i = 0; i < N; i++){
        if (tabla[i][i]>0){
            *positivos= *positivos+1;
        }
    }
}

int main(){
    int tabla[N][N], sumacol3=0, sumafila2;
    int par=0, positivos=0;
    carga(tabla);
    sumacolum(tabla, &sumacol3);
    printf("\nLa suma de los elementos de la 3er columna es: %d", sumacol3);
    sumafila2=sumafila(tabla[1]);
    printf("\nLa suma de los elementos de la 2da fila es: %d", sumafila2);
    pares(tabla, par);
    numpositiv(tabla, &positivos);
    printf("\nHay %d numeros positivos en la diagonal", positivos);
}