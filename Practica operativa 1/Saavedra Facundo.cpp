#include <stdio.h>

float proceso(int xx, int zz){
	float p;
	p = (xx+zz)/2;
	return(p);
}

void mostrar(float m){
	printf("El resultado es: %.2f", m);
	printf("\nSaavedra Facundo");
}

int main(){
	int cant, num1, num2;
	float s;
	s = 0;
	cant = 0;
	
	while(cant<=1){
		printf("Ingrese el primer numero: ");
		scanf("%d", &num1);
		printf("Ingrese el segundo numero: ");
		scanf("%d", &num2);
		
		if (num2<=100 && num1>=0)
			s = s + proceso(num1, num2);
		
		cant++;
	}
	mostrar(s);
}
