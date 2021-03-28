#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void dinamico(char *ingrediente);
int primerRecorrido();
int pp;
void segundoRecorrido(int pp, int i);
int contU=0;


int main(void){
	printf("\n %d \n", primerRecorrido());
	printf("\n %d \n", contU);
	segundoRecorrido(pp, contU);
	remove("v.txt");
	return 0;
}


/*En este metodo se lleva a cabo el primer recorrido del archivo o la primer lectura*/
int primerRecorrido(){
	FILE* flujo=fopen("pedidos.txt", "rb");
	if(flujo==NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}
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
	fclose(flujo);
	return acum;
}

/*Algoritmo para hacer la matriz*/
void segundoRecorrido(int pp, int i){
	FILE* flujo=fopen("pedidos.txt", "rb");
	char cadena2[100];
	int contador=1;
	char cadena[100];
	int matriz[pp][i];

	for(int j=0;j<i;j++){
		for(int k=0;k<pp;k++){
			matriz[k][j]=0;
		}
	}
	while(feof(flujo)==0){
		fscanf(flujo, "%s\n", cadena);
		if(isdigit(*cadena)){
			contador++;
		}else{
			FILE * flujo3=fopen("v.txt", "rb");
			int b=0;
			while(feof(flujo3)==0){
				fscanf(flujo3, "%s\n", cadena2);
				if(strcmp(cadena2, cadena)==0){
					matriz[contador-6][b]=1;
					//printf("\n%d\n",b);
				}
				b++;
			}
			fclose(flujo3);
		}
	}
	for(int j=0;j<i;j++){
		for(int k=0;k<pp;k++){
			printf(" %d", matriz[k][j]);
		}
		printf("\n");
	}
	fclose(flujo);
}	

/*En este metodo se utiliza un archivo de texto plano para almacenar
la información dinamicamente y saber la totalidad de platos distintos*/
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