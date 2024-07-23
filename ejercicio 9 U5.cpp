/*Ejercicio 9
La clínica de la salud San Juan, necesita registrar los pacientes en espera para cada una de las 12 especialidades 
con la que cuenta la misma.
Realizar un programa, que a través de un menú de opciones permita:
a) Ingresar los datos correspondientes a cada especialidad: Numero de especialidad (1-12) y nombre (cardiología, 
maternidad, laboratorio,…,etc.).
b) Registrar los turnos, ingresando el DNI del paciente y el número de especialidad al que desea asistir.
c) Eliminar el turno de un paciente que no podrá asistir, los datos del paciente y numero de especialidad se 
ingresan por teclado.
d) Dado el número de una especialidad, mostrar su nombre y la cantidad total de pacientes en cola de espera. 
e) Dado el DNI de un paciente, informar la/las especialidades (número y nombre) en las que se anotó.
Nota: Para cada ítem emplear al menos una función recursiva.

Odontologia
Dermatologia
1
1
45
0
1
50
1

*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 2

typedef struct nodo
{
    int dni;
    nodo *sig;
}nodo;

typedef nodo *puntero;

struct especialidad
{
    char titulo[20];
    int cant;
    puntero paciente;
};

void iniciar(especialidad arre[N], int i){
    if (i==N)
    {
        return;
    }
    else
    {
        printf("\nIngrese la especialidad numero %d: ", i+1);
        fflush(stdin);
        gets(arre[i].titulo);
        arre[i].cant=0;
        arre[i].paciente=NULL;
        iniciar(arre,i+1);
    }
}

void insertar(puntero &cabe, puntero nuevo){
    if(cabe == NULL){
        cabe=nuevo;
    }
    else{
        puntero siguiente;
        siguiente=cabe;
        cabe=nuevo;
        nuevo->sig=siguiente;
    }
    return;
}

void carga(especialidad arre[N], int i){
    if (i==0)
    {
        int numero;
        puntero nuevo; 
        nuevo=(puntero)malloc(sizeof(nodo));
        printf("\nIngrese numero de la especialidad: ");
        scanf("%d", &numero);
        printf("\nDni del paciente: ");
        scanf("%d", &nuevo->dni);
        nuevo->sig=NULL;
        insertar(arre[numero-1].paciente, nuevo);
        arre[numero-1].cant++;
        printf("\nPaciente cargado. Desea cargar otro paciente?  1. No  0. Si\n");
        scanf("%d", &i);
        carga(arre, i);
    }
    else{
        return;
    }
}

void elimnodo(puntero &cabe){
    puntero p, anterior;
    int dnielim;
    printf("\nDni del paciente: ");
    scanf("%d", &dnielim);
    if (cabe->dni==dnielim)
    {
        p=cabe;
        cabe=cabe->sig;
        free(p);
    }
    else{
        p=cabe;
        anterior=cabe;
        while ((p->dni != dnielim) && (p != NULL)){
            anterior=p;
            p=p->sig;
        }
        if (p != NULL)
        {
            anterior->sig=p->sig;
            free(p);
            printf("\nEl turno fue eliminado");
        }
        else{
            printf("\nEl paciente no se encuentra");
        }
    }
    return;
}

void elimpaciente(especialidad arre[N], int i){
    if (i==0)
    { 
        int indice;
        printf("\nIngresar el numero de especialidad del turno a eliminar: ");
        scanf("%d", &indice);
        elimnodo(arre[indice-1].paciente);

        printf("\nDesea eliminar otro turno? 1. No 0. Si: ");
        scanf("%d", &i);
        elimpaciente(arre, i);
    }
    else{
        return;
    }
}

/*void mostrar(puntero &cabe) {
    puntero p = cabe;
    while (p != NULL) {
        printf("%d\n", p->dni);
        p = p->sig;
    }
}
*/
void mostrarespe(especialidad arre[N]){
    int espe;
    printf("\nIngresar el numero de una especialidad: ");
    scanf("%d", &espe);
    if ((espe<1) || (espe>12))
    {
        printf("\nEspecialidad invalida");
        mostrarespe(arre);
    }
    else{
        printf("\nLa especialidad %s tiene %d pacientes en espera ", arre[espe-1].titulo, arre[espe-1].cant);
    }
}

void buscarenlista(especialidad arre[N], puntero cabe, int i, int paciente, int &esta){
    if (cabe==NULL)
    {
        return;
    }
    else{
        if (cabe->dni==paciente)
        {
            esta=1;
            printf(" %s", arre[i].titulo);
            return;
        }
        else{
            buscarenlista(arre, cabe->sig, i, paciente, esta);
        }
    }
    
}

void buscarpaciente(especialidad arre[N]){
    int esta, paciente;
    esta=0;
    printf("\nDni del paciente: ");
    scanf("%d", &paciente);
    printf("\nEl paciente se encuentra en las especialidades: ");
    for (int i = 0; i < N; i++)
    { 
        buscarenlista(arre, arre[i].paciente, i, paciente, esta);
    }
    if (esta==0)
    {
        printf("0");
    }
    
    
}

int main(){
    int i=0, opcion=0;
    especialidad arre[N];
    printf("\nInicializacion del arreglo:");
    iniciar(arre, i);
    printf("\nInicializacion terminada");
    while (opcion!=5)
    {
        printf("\n           *MENU DE OPCIONES* ");
        printf("\n1. Cargar paciente");
        printf("\n2. Eliminar un turno");
        printf("\n3. Buscar especialidad");
        printf("\n4. Buscar paciente");
        printf("\n5. Salir");
        
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion){
        case 1:
            carga(arre, i);
            printf("\nCarga terminada.");
            break;
        
        case 2:
            elimpaciente(arre, i);
            break;
        
        case 3:
            mostrarespe(arre);
            break;

        case 4: 
            buscarpaciente(arre);
            break;
        /*case 7:
            mostrar(arre[0].paciente);
            break;
        */
        case 5:
            break;

        default:
            printf("\nAccion no valida");
            break;
        }
    }
    printf("\nFin del programa\n");
}

