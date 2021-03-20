#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main(void){

	
	FILE* flujo=fopen("pedidos.txt", "rb");
	char cadena[100];

	if(flujo==NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}

	int pp;
	int acum=0;
	int contador=1;
	while(feof(flujo)==0){
		fscanf(flujo, "%s\n", cadena);
		if(isdigit(*cadena)){
			if(contador==1){
				pp=atoi(cadena);
				printf("\n %d",pp);
			}
			if((contador>1) && (contador<5)){
				acum=acum+(atoi(cadena)*contador);
			}
			printf("\n %d",(atoi(cadena)));
			contador++;
		}	else{
			printf("\n %s",cadena);
		}
	}
	fclose(flujo);
	return 0;
}