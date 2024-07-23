#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 10
struct nodo{
    char dni[11];
    struct nodo *sig;
};

typedef struct nodo* Lista;

struct tut{
    int numero;
    char titulo[20];
    Lista inscriptos;
};
void inic(tut arr[N], int i){
    if(i == N){
        return;
    }
    printf("Ingrese nombre del tutorial nro %d\n", i+1);
    arr[i].numero= i+1;
    fflush(stdin);
    fgets(arr[i].titulo, 20, stdin);
    arr[i].inscriptos= NULL;
    inic(arr, i + 1);
    return;
}

Lista crearNodo(char dni[11]){
    Lista nuevo= (Lista)malloc(sizeof(nodo));
    strcpy(nuevo->dni, dni);
    nuevo->sig= NULL;
    return nuevo;
}
void insertarAlFinal(Lista *lista, Lista nuevo){
    if(*lista == NULL){
        *lista= nuevo;
        return;
    }
    else{
        insertarAlFinal(&(*lista)->sig, nuevo);
    }
}
int buscaremos(Lista lista, char dnia[]){
    int result= 0;
    if(lista == NULL){
        return result;
    }
    if(strcmp(dnia, lista->dni) == 0){
        result= 1;
        return result;
    }
    else{
       return(buscaremos(lista->sig, dnia));
    }
}

void buscar(tut arr[N], char dnia[]){
    int i;
    for(i= 0; i < N; i++){
        if(buscaremos(arr[i].inscriptos, dnia) != 0){
            printf("El dni se encuentra inscripto en el tutorial nro %d llamado %s\n", arr[i].numero, arr[i].titulo);
        }
    }
}
void carga(tut arr[N]){
    int num;
    char dnia[11];
    printf("Ingrese numero de tutorial.\n");
    fflush(stdin);
    scanf("%d", &num);
    if(num >= 1 && num <= 10){
        printf("Ingrese DNI\n");
        fflush(stdin);
        fgets(dnia, sizeof(dnia), stdin);
        Lista nuevo= crearNodo(dnia);
        insertarAlFinal(&arr[num-1].inscriptos, nuevo);
        printf("Digite numero del 1 al 10 para continuar, caso contrario, digite 0 \n");
        fflush(stdin);
        scanf("%d", &num);
        if(num != 0){
            carga(arr);
        }
        else{
            printf("Carga finalizada.\n");
        }
    }
    return;
}

void eliminarNodo(Lista *lista, char dnia[]){
    Lista actual = *lista;
    if (actual == NULL){
        printf("Elemento no encontrado o la lista se encuentra vacía.\n");
        return;
    }
    if (strcmp(actual->dni, dnia) == 0){
        *lista = actual->sig;
        free(actual);
        printf("Elemento eliminado exitosamente.\n");
        return;
    }
    eliminarNodo(&(*lista)->sig, dnia);
}
void contarElemento(Lista lista, int *c){
    if(lista == NULL){
    printf("Fin de la lista.\n");
    return;
    }
    else{
        (*c)++;
        contarElemento(lista->sig, c);
    }
}

int main(){
    int i= 0, op= 0, num, Num, contador= 0;
    tut arr[N];
    char dni[11];
    inic(arr, i);
    while(op != 4){
        printf("Menú de Opciones:\n");
        printf("0. Cargar matriz\n");
        printf("1. Eliminar un inscripto\n");
        printf("2. Mostrar informacion de un tutorial\n");
        printf("3. Mostrar info de un inscripto\n");
        printf("4. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &op);
        switch(op){
    case 0:
        carga(arr);
        break;
    case 1:
        fflush(stdin);
        printf("\nIngrese numero del tutorial.\n");
        scanf("%d", &num);
        if(num < 1||num > 10){
            printf("Numero de tutorial invalido. Intenta nuevamente...\n");
            break;
        }
        printf("Ingrese el DNI del inscripto a eliminar.\n");
        fflush(stdin);
        fgets(dni, 11, stdin);
        eliminarNodo(&arr[num-1].inscriptos, dni);
        break;
    case 2:
        printf("Ingrese numero del tutorial del que desea obtener informacion.\n");
        fflush(stdin);
        scanf("%d", &Num);
        contarElemento(arr[Num-1].inscriptos, &contador);
        printf("El titulo del tutorial es %s y la cantidad de inscriptos es %d.\n", arr[Num-1].titulo, contador);
        contador= 0;
        break;
    case 3:
        printf("Ingrese el DNI del inscripto del que desea obtener informacion.\n");
        fflush(stdin);
        fgets(dni, 11, stdin);
        buscar(arr, dni);
        break;
    case 4:
        printf("Finalizando programa.\n");
        break;
    default:
        printf("Operacion no valida. Intente nuevamente.\n");
        break;
    }
}
return 0;
}
