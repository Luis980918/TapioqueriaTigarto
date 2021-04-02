#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void segundoRecorrido(int pp, int i);
void dinamico(char *ingrediente);
void swap(char *a, char*b);
int primerRecorrido();
int vector[10];
int contU=0;
int acumU=0;
int x, y, z; //para los pedidos de 1, 2 y 3 respectivamente
int mAlto1=0;
int mAlto2=0;
int mAlto3=0;
int ntpp=0;
int pp=0;



int main(void){
	
	
	//printf("\n %d \n", contU);
	ntpp=primerRecorrido();
	segundoRecorrido(pp, contU);
	
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
					}
					if ((contador==3)){
						y = (atoi(cadena)*3)+x;
					} 
					if ((contador==4)){
						z = (atoi(cadena)*4)+y;
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
	remove("v.txt");
	//
	void permute(char *a, int i, int n, int matriz[pp][contU]);

	char ap[ntpp+1];
	for(int i=1;i<ntpp+2; i++){
		ap[i-1]=i+'0';
		if(i==ntpp+1){
			ap[i-1]='\0';
		}
	}
	permute(ap, 0, ntpp, matriz);

	
	/*void vectorSolucion(int matriz[pp][contU], int dato);
	for(int i=0;i<10; i++){
		vector[i]=0;
	}
	/*vectorSolucion(matriz, 1);
	vectorSolucion(matriz, 2);
	
	for(int i=0;i<10; i++){
		printf("\n%i\n", vector[i]);
	}*/
	printf("\n%d\n", mAlto1);
	printf("\n%d\n", mAlto2);
	printf("\n%d\n", mAlto3);

}	

/*Algoritmo encargado de realizar permutaciones*/
void permute(char *a, int i, int n, int matriz[pp][contU]){
    int j;
	int cont1=0;
	int cont2=0;
	int cont3=0;

    if (i==n){
		if(strlen(a)==n){
			for(int k=0;k<x; k++){
			//printf("%c",a[k]);
				for(int j=0;j<contU;j++){
					//printf(" %d", matriz[dato][j]);
					if(vector[j]==1 || matriz[a[k]-'0'][j]==1){
						vector[j]=1;
					}
				}

			}
			for(int i=0;i<10; i++){
				//printf("\n%i\n", vector[i]);
				if(vector[i]==1){
					cont1++;
					vector[i]=0;
				}	
			}
			if(cont1>mAlto1){
				mAlto1=cont1;
			}
////////////////////////////////////////////////////////////////////////////////
			
			for(int l=x;l<y; l++){
				//printf("%c",a[l]);
				for(int j=0;j<contU;j++){
					//printf(" %d", matriz[dato][j]);
					if(vector[j]==1 || matriz[a[l]-'0'][j]==1){
						vector[j]=1;
					}
				}
			}
			for(int i=0;i<10; i++){
				//printf("\n%i\n", vector[i]);
				if(vector[i]==1){
					cont2++;
					vector[i]=0;
				}	
			}
			if(cont2>mAlto2){
				mAlto2=cont2;
			}
/////////////////////////////////////////////////////////////////////////////////////

			for(int m=y;m<z; m++){
				//printf("%c",a[m]);
				for(int j=0;j<contU;j++){
					//printf(" %d", matriz[dato][j]);
					if(vector[j]==1 || matriz[a[m]-'0'][j]==1){
						vector[j]=1;
					}
				}
			}
			for(int i=0;i<10; i++){
				//printf("\n%i\n", vector[i]);
				if(vector[i]==1){
					cont3++;
					vector[i]=0;
				}	
			}
			if(cont3>mAlto3){
				mAlto3=cont3;
			}
			/*printf("\n%s\n", a);
			printf("\n%d\n", mAlto1);
			printf("\n%d\n", mAlto2);
			printf("\n%d\n", mAlto3);
			exit(-1);*/
			
			if((mAlto1>=8)&&(mAlto2>=8)&&(mAlto3>=8)){
				printf("Hola");
				printf("\n%s\n", a);
				exit(-1);
			}
		}

	}else
    {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n, matriz);
            swap((a + i), (a + j));
        }
    }
}
/*Puto el que lo lea*/
void vectorSolucion(int matriz[pp][contU], int dato){
	
	for(int j=0;j<contU;j++){
		//printf(" %d", matriz[dato][j]);
		if(vector[j]==1||matriz[dato][j]==1){
			vector[j]=1;
		}
		printf("\n");
	}
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