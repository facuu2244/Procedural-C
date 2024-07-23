/*Un local comercial de ventas de repuestos de automotores desea obtener cierta información sobre todas las ventas 
registradas en un periodo de tiempo dado. El comercio cuenta con 250 artículos, almacenados en una estructura y 
de los cuales se conocen los siguientes datos: Código, Nombre, Precio Unitario y Stock. 
Se procesan las ventas y los datos ingresados de cada una son: Nombre del artículo, Cantidad de unidades vendidas
(con esta información actualizar el stock de cada artículo). El ingreso de ventas termina con nombre igual “FIN”.
Se pide realizar un programa en C, que utilizando subprogramas óptimos y estructuras adecuadas permita:
1. Procesar las ventas registradas en ese periodo de tiempo.
2. Mostrar en el main la cantidad de artículos que quedaron con stock nulo y cuantos tienen un precio mayor a 
$7000.
3. Imprimir los nombres de los 20 artículos que quedaron con mayor stock.
4. Indicar para cada artículo el monto total obtenido por ventas.*/

#include <stdio.h>
#include <string.h>

struct productos{
    int cod, stock;
    float precio;
    char nombre[20];
};

void cerea(productos arre[250]){
    for (int i = 0; i < 250; i++){
        arre[i].stock=0;
    }
}

void ventas(productos arre[250]){
    char nom[20];
    int cant_uni;
    printf("Nombre del producto: ");
    gets(nom);
    while ((strcmp(nom,"Fin"))!=0){
        
    }  
}

int main(){
    productos arre[250];
    cerea(arre);
    ventas(arre);
}