/*Ejercicio 8
Una disquera procesa diariamente el archivo “TITULOS .DAT”. Este archivo almacena la información de cada 
grabación musical: Código de grabación, Título, y Cantidad de reproducciones. El archivo está ordenado en forma 
secuencial por código de grabación a partir del número 1. 
Se pide realizar un programa óptimo que a través del uso de funciones responda a las siguientes solicitudes: 
a) Agregar una nueva grabación musical.
b) Generar una lista enlazada con punteros, con los códigos de grabación y título que fueron reproducidos por 
menos de 10000 personas. 
// c) Ingresar un título y eliminarlo de la lista.
d) Generar un nuevo archivo con la información de la lista
e) Eliminar del archivo las grabaciones con mas de 5000 reproduciones y guardarlo en otro arcivo*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct grabacion
{
    int cod, repro;
    char titulo[20];
}grabacion;

typedef struct nodo
{
    grabacion datos;
    nodo *sig;
}nodo;

typedef nodo *puntero;

void cargar(FILE *archi){
    grabacion g;
    fpos_t x;

    printf("\nTitulo ('fin' para terminar): ");
    fflush(stdin);
    gets(g.titulo);     
    while (strcmp(g.titulo,"fin")!=0)
    {
        fseek(archi,0, SEEK_END); 
        fgetpos(archi,&x);
        int cod=(int)(x/sizeof(grabacion))+1;
        printf("El codigo del nuevo producto es: %d",cod); 
        g.cod=cod;
        printf("\nCantidad de reproduciones: ");
        scanf("%d",&g.repro);
        fwrite(&g, sizeof(g), 1, archi);

        printf("\nTitulo(fin para terminar): ");
        fflush(stdin);
        gets(g.titulo);
    }
}

void generalista(FILE *archi, puntero &cabe){
    if ((archi=fopen("musica.dat", "r"))==NULL)
    {
        printf("Hubo un error al abrir el archivo");
    }
    else{
        grabacion g;
        while (fread(&g, sizeof(g), 1, archi)!=0)
        {
            if (g.repro<10000)
            {
                puntero nuevo;
                nuevo=(puntero)malloc(sizeof(nodo));
                nuevo->datos=g;
                
                nuevo->sig=cabe; //insertar
		        cabe=nuevo;
            }
        }
    }
}

void mostrarlista(puntero cabe){
	puntero p;
	p=cabe;
	while (p!=NULL)
	{
		printf("Titulo: %s codigo: %d \n", p->datos.titulo, p->datos.cod);
		p=p->sig;
	}
	return;
}

void mostrararchi2(FILE *archi2){
    grabacion g;
    rewind(archi2);
    while(fread(&g,sizeof(g),1,archi2)!=0 )
    printf("\nTitulo: %s", g.titulo);
}

void generaarchivo(puntero cabe){
    FILE *archi2;
    puntero p=cabe;
    grabacion g;
    if ((archi2=fopen("musica2.dat", "w+"))==NULL)
    {
        printf("Hubo un error al abrir el archivo");
    }
    else
    {
        while (p!=NULL)
        {
          fseek(archi2, 0, SEEK_END);
          g=p->datos;
          fwrite(&g, sizeof(g),1,archi2);
          p=p->sig;
        }

        printf("\nNuevo archivo generado: ");
        mostrararchi2(archi2);
        fclose(archi2);
    }
}

void marcar(FILE *archi){
    if ((archi=fopen("musica.dat", "r+"))==NULL)
    {
        printf("Hubo un error al abrir el archivo");
    }
    else
    {
        int nro;
        grabacion g;

        printf("\nEliminar canciones que tengan mas de las siguientes reproducciones: ");
        scanf("%d",&nro);
        while (fread(&g, sizeof(g), 1, archi)!=0)
        {
            if (g.repro>nro)
            {
                fseek(archi, sizeof(g), SEEK_CUR);
                g.repro=-1;
            }
        }
    }
}

void compactar(FILE *archi, FILE *aux){
    grabacion g;
    rewind(archi);
    while(fread(&g, sizeof(g),1, archi)!=0)
    {
        if (g.repro!=-1)
        {
            fwrite(&g, sizeof(g),1,aux);
        }
        fread(&g, sizeof(g),1, archi);
    }
    fclose(archi);
    fclose(aux);
   }

int main(){
    puntero cabe=NULL;
    FILE *archi, *aux;
    if ((archi=fopen("musica.dat", "w+"))==NULL)
    {
        printf("Hubo un error al abrir el archivo");
    }
    else{
        cargar(archi);
        fclose(archi);
        generalista(archi, cabe);
        fclose(archi);
        printf("Lista de grabaciones con menos de 10000 reproducciones: \n");
        mostrarlista(cabe);
        //inciso d) crear un archivo a partir de la lista
        //generaarchivo(cabe);

        //eliminar un titulo de archivo y luego crear un archivo nuevo
        marcar(archi);
        if ((aux=fopen("aux.dat", "w+"))==NULL)
        {
            printf("Hubo un error al abrir el archivo");
        }
        else{
            compactar(archi, aux);
            remove("musica.dat");
            rename("aux.dat", "nuevo.dat");
        }
    }
}