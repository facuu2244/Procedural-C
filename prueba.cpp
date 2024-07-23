#include <stdio.h>
#include <string.h>

struct productos{
	int numero;
	float precio;
	int stock;
};

struct provee{
	char nombre [30];
	int cont;
};

struct provee_10{
	char nombre [30];
	int cont;
};

void cerear(productos produc[50], provee prov[22]){
	int i;
	for(i = 0; i<50; i++){
		produc[i].stock = 0;
	}
	
	for(i = 0; i<22; i++){
		prov[i].cont = 0;
	}
}

void cargar(productos produc[50], provee prov[22]){
	int numero_pedido, acum, num_pro;
	
	printf("Numero del producto: ");
	scanf("%d", &numero_pedido);
	
	while(numero_pedido!=0){
		printf("\nPrecio del producto: ");
		scanf("%f", &produc[numero_pedido-1].precio);
		
		printf("\nCantidad de undiades: ");
		scanf("%d", &acum);
		produc[numero_pedido-1].stock+=acum;
		
		printf("\nNumero del provedor: ");
		scanf("%d", &num_pro);
		prov[num_pro-1000].cont++;
		
		fflush(stdin);
		printf("\nNombre del proveedor: ");
		gets(prov[num_pro-1000].nombre);
		
		printf("\nNumero del producto: ");
		scanf("%d", &numero_pedido);
	}
}

void invertido(productos produc[50]){
	int i;
	for(i=1;i<51;i++){
		printf("\nDinero invertido en el producto: %d es de $%.2f", i, (produc[i-1].stock)*produc[i-1].precio);
	}
}

int proveedores_10(provee prov[22], provee_10 prov_10[22]){
	int i, j;
	j=0;
	
	for(i=0; i<22; i++){
		if (prov[i].cont>=10){
			strcpy(prov_10[j].nombre, prov[j].nombre);
			prov_10[j].cont=prov[j].cont;
			j++;
		}
	}
	return(j);
}

void ordenar(provee_10 prov_10[22], int indice){
	int i, k, cota;
	provee_10 aux[indice];
	cota=21;
	k=1;
	while(k!=-1){
		k=-1;
		for(i=0; i < cota-1;i++){
			if(strcmp(prov_10[i].nombre, prov_10[i+1].nombre)>0){
				strcpy(aux[i].nombre, prov_10[i].nombre);
				aux[i].cont=prov_10[i].cont;
				strcpy(prov_10[i].nombre, prov_10[i+1].nombre);
				prov_10[i].cont=prov_10[i+1].cont;
				strcpy(prov_10[i+1].nombre, aux[i].nombre);
				prov_10[i+1].cont=aux[i].cont;
				k=i;
			}
		}
		cota=k;
	}
	
	printf("\nProveedores ordenados alfabeticamente: ");
	for(i=0;i<indice;i++){
		puts(prov_10[i].nombre);
		printf("\nVentas: %d", prov_10[i].cont);
		printf("\n");
	}
}

void informar_proveedor(provee_10 prov_10[22], int indice){
	int prov_ingresado;
	printf("\nIngresar numero de proveedor: ");
	scanf("%d", &prov_ingresado);
	
	printf("\n Nombre del proveedor: ");
	puts(prov_10[prov_ingresado-1000].nombre);
	printf("\nNumero de ventas de este proveedor: ", prov_10[prov_ingresado-1000].cont);
}

int main(){
	int i, indice;
	
	productos produc[50];
	provee prov[22];
	provee_10 prov_10[22];
	
	cerear(produc, prov);
	cargar(produc, prov);
	invertido(produc);
	indice=proveedores_10(prov, prov_10);
	ordenar(prov_10, indice);
	informar_proveedor(prov_10, indice);
}