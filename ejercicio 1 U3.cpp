/*Ejercicio 1
Crear un arreglo de 50 números enteros y cargarlo generando cada numero de manera aleatoria. 
Codificar un programa en C que permita: 
1. Indicar en el main si cantidad de números mayores a cero es mayor o igual a la cantidad de números menores a 
cero. 
2. Indicar en el main, la sumatoria de las componentes que se encuentren en las posiciones pares y la sumatoria de 
las que está en posiciones impares.
3. Leer un número e indicar si se encuentra en el arreglo indicar su posición (puede estar repetido). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 50

void cargar(int arre[n], int min, int max){
    for(int i = 0; i < n; i++){
        arre[i]=min+rand()%(max-min+1);
    }
    
    printf("Arreglo generado:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arre[i]);
    }
}

int calcularmayores(int arre[n]){
    int contmayor, contmenor, result;
    for (int i = 0; i < n; i++){
        if (arre[i]>0){
            contmayor++;
        }
        else{
            contmenor++;
        }
    }

    if (contmayor==contmenor){
        result=0;
    }
    else if (contmayor<contmenor){
        result=-1;
    }
    else{
        result=1;
    }
    return(result);
}

int sumaimp(int arre[n]){
    int acumimp=0;
    for (int i = 0; i < n; i++){
        if ((arre[i]%2)!=0){
            acumimp+=arre[i];
        }
    }
    return(acumimp);
}

int sumapar(int arre[n]){
    int acumpar=0;
    for (int i = 0; i < n; i++){
        if ((arre[i]%2)==0){
            acumpar+=arre[i];
        }
    }
    return(acumpar);
}

void buscarnum(int arre[n]){
    int num, esta=0;
    printf("\n\nIngrese un numero para buscar: ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++){
        if (arre[i]==num){
            esta=1;
            printf("\nEl numero si esta en el arreglo, y esta en la posicon %d.", i);
        }
    }
    
    if (esta==0){
        printf("\nEl numero no se encuentra en el arreglo.");
    }
}

int main(){
    int arre[n], min, max, cnmayores;
    min=-1000;
    max=1000;
    srand(time(NULL));
    cargar(arre, min, max);
    cnmayores=calcularmayores(arre);
    
    if (cnmayores==1){
        printf("\n\nLa cantidad de numeros mayores a 0 es mayor que la de menores a 0");
    }
    else if (cnmayores==0){
        printf("\n\nLa cantidad de numeros mayores a 0 es igual que la de menores a 0");
    }
    else{
        printf("\n\nLa cantidad de numeros mayores a 0 es menor que la de menores a 0");
    }

    printf("\nLa suma de todos los numero impares es: %d", sumaimp(arre));
    printf("\nLa suma de todos los numero pares es: %d", sumapar(arre));

    buscarnum(arre);
}