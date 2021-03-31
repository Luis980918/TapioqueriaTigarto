#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void segundoRecorrido(int pp, int i);
void permute(char *a, int i, int n);
void dinamico(char *ingrediente);
void swap(char *a, char*b);
void delimitador(char *a);
int primerRecorrido();
int contU=0;
int x, y, z; //para los pedidos de 1, 2 y 3 respectivamente
int pp;


int main(void){
	int ntpp=0;
	
	//printf("\n %d \n", contU);
	ntpp=primerRecorrido();
	printf("\n %d \n", ntpp);
	segundoRecorrido(pp, contU);
	char ap[ntpp+1];
	for(int i=1;i<ntpp+2; i++){
		ap[i-1]=i+'0';
		if(i==ntpp+1){
			ap[i-1]='\0';
		}
	}
	remove("v.txt");
	permute(ap, 0, ntpp);
	
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
				if ((contador==2)){
						x = (atoi(cadena)*2);
						printf("\n%d\n", x);
					}
					if ((contador==3)){
						y = (atoi(cadena)*3)+x;
						printf("\n%d\n", y);
					} 
					if ((contador==4)){
						z = (atoi(cadena)*4)+y;
						printf("\n%d\n", z);
					}
				
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

/*Algoritmo encargado de realizar permutaciones*/
void permute(char *a, int i, int n){
    int j;
    if (i==n){
		if(strlen(a)==n){
			//printf("%s \n", a);
			/*if((a[0]-'0')==1){
				printf("%s \n", a);
			}*/
			delimitador(a);
		}
	}else
    {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
}
/*Algoritmo para particionar el vector de permutaciones*/
void delimitador(char *a){
	for(int k=0;k<x; k++){
		printf("\n%c\n",a[k]);
	}
	for(int l=x;l<y; l++){
		printf("%c",a[l]);
	}
	for(int m=y;m<z; m++){
		printf("%c",a[m]);
	}
	printf("\n");
}

/*Algoritmo complementario para realizar permutaciones
en un vector de n posiciones*/
void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
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