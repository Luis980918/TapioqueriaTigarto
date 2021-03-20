#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void dinamico(char *ingrediente);
int contU=0;

int main(void){
	FILE* flujo=fopen("pedidos.txt", "rb");
	if(flujo==NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}
	char *vectordinamico[1000];
	int pp;
	int acum=0;
	int contador=1;
	char cadena[100];
	while(feof(flujo)==0){
		fscanf(flujo, "%s\n", cadena);
		if(isdigit(*cadena)){
			if(contador==1){
				pp=atoi(cadena);
				//printf("\n %d",pp);
			}
			if((contador>1) && (contador<5)){
				acum=acum+(atoi(cadena)*contador);
			}
				//printf("\n %d",(atoi(cadena)));
			contador++;
		}	else{
				//printf("\n %s",cadena);
				dinamico(cadena);
		}
	}
	printf("\n %d",acum);
	printf("\n %d \n", contU);
	fclose(flujo);
	remove("v.txt");
	return 0;
}

void dinamico(char *dato){

	int bandera=1;
	if(contU!=0){
		FILE * flujo3=fopen("v.txt", "rb");

		char cadena2[100];
		while(feof(flujo3)==0){
			fscanf(flujo3, "%s\n", cadena2);
			if(strcmp(dato, cadena2)==0){
				bandera=0;
			}
		}
		fclose(flujo3);
	}
	
	FILE * flujo2=fopen("v.txt", "a");
	if(bandera!=0){
		if(flujo2==NULL){
		perror("Error en la creacion del archivo \n\n");
		}else{
			fputs(dato,flujo2);
			fputs("\n",flujo2);
			contU++;
		}
		fclose(flujo2);
	}
}