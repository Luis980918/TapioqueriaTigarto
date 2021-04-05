#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void segundoRecorrido(int pp, int i, int argc, char* argv[]);
void dinamico(char *ingrediente);
void swap(char *a, char*b);
int primerRecorrido(int argc, char* argv[]);
int contU=0;
int x, y, z; //para los pedidos de 1, 2 y 3 respectivamente
int ntpp=0;
int mA1, mA2, mA3;
char *aU;
int pp=0;



int main(int argc, char* argv[]){
	if(argc<2){
		printf("Debe indicar un argumento\n");
		return -1;
	}

	ntpp=primerRecorrido(argc, argv);
	
	if(ntpp==pp){
		segundoRecorrido(pp, contU, argc, argv);
	}else{
		printf("\nla cantidad de platos pedidos no concuerda con la especificada al principio del archivo\n");
		remove("v.txt");
		return -1;
	}
	
	
	return 0;
}


/*En este metodo se lleva a cabo el primer recorrido del archivo o la primer lectura*/
int primerRecorrido(int argc, char* argv[]){
	FILE* flujo=fopen(argv[1], "rb");
	if(flujo==NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}
	int acum=0;
	int contador=1;
	int comparador=0;
	int verificador=0;
	char cadena[100];
	while(feof(flujo)==0){
		fscanf(flujo, "%s\n", cadena);
		if(isdigit(*cadena)){
			if(contador==1){
				pp=atoi(cadena);
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
				if(contador>5){
					if(!(comparador==verificador)){
						printf("\nLa cantidad de ingredientes no corresponde con la indicada en el archivo\n");
						remove("v.txt");
						exit(-1);
					}
				}
			contador++;
			comparador=atoi(cadena);
			verificador=0;
		}	else{
				dinamico(cadena);
				verificador++;
		}
	}
	fclose(flujo);
	if((contador-5)==pp){
		return acum;
	}else{
		printf("\nProblema leyendo el archivo, el numero de pedidos no concuerda con el indicado\n");
		remove("v.txt");
		exit(-1);
	}
	
}

/*Algoritmo para hacer la matriz*/
void segundoRecorrido(int pp, int i, int argc, char* argv[]){
	FILE* flujo=fopen(argv[1], "rb");
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
	void output(char *a, int matriz[pp][contU], int c);
	output(aU, matriz,(mA1+mA2+mA3));
	exit(0);
}	

/*Algoritmo encargado de realizar permutaciones*/
void permute(char *a, int i, int n, int matriz[pp][contU]){
    int j;
	int cont1=0;
	int cont2=0;
	int cont3=0;
	int vector[pp];

    if (i==n){
		if(strlen(a)==n){
			for(int k=0;k<x; k++){
				for(int j=0;j<contU;j++){
					if(vector[j]==1 || matriz[(a[k]-'0')-1][j]==1){
						vector[j]=1;
					}
				}
			}
			for(int i=0;i<10; i++){
				if(vector[i]==1){
					cont1++;
					vector[i]=0;
				}	
			}
			for(int l=x;l<y; l++){
				for(int j=0;j<contU;j++){
					if(vector[j]==1 || matriz[(a[l]-'0')-1][j]==1){
						vector[j]=1;
					}
				}
			}
			
			for(int i=0;i<10; i++){
				if(vector[i]==1){
					cont2++;
					vector[i]=0;
				}	
			}

			for(int m=y;m<z; m++){
				for(int j=0;j<contU;j++){
					if(vector[j]==1 || matriz[(a[m]-'0')-1][j]==1){
						vector[j]=1;
					}
				}
			}
			
			for(int i=0;i<10; i++){
				if(vector[i]==1){
					cont3++;
					vector[i]=0;
				}	
			}

			if(cont1>=mA1&&cont2>=mA2&&cont3>=mA2){
				mA1=cont1;
				mA2=cont2;
				mA3=cont3;
				aU=a;
			}

			if(cont1>=(contU*0.8)&&cont2>=(contU*0.7)&&cont3>=(contU*0.8)&&(cont1>(contU*0.8)||cont2>(contU*0.8)||cont3>(contU*0.8))){
				printf("\n%s\n", a);
				void output(char *a, int matriz[pp][contU], int c);
				output(a, matriz,(cont1+cont2+cont3));
				exit(0);
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

/*Algoritmo necesario para imprimir los resultados en un archivo de salida*/
void output(char *a, int matriz[pp][contU], int c){


	FILE * flujo2=fopen("output.txt", "a");
	char hola[100];
	char total[100];
	if(flujo2==NULL){
		perror("Error en la creacion del archivo \n\n");
	}else{
		fputs("Esta es la matriz de platos: \n\n",flujo2);
		for(int j=0;j<contU;j++){
			for(int k=0;k<pp;k++){
				sprintf(hola, "%d", matriz[k][j]);
				fputs(hola, flujo2);
			}
			fputs("\n", flujo2);
		}

	}
		fputs("\nEste es el vector solucion: \n", flujo2);
		fputs(a, flujo2);
		fputs("\n\n", flujo2);
		sprintf(total, "%d", c);
		fputs("La cantidad total de ingredientes distintos es: ", flujo2);	
		fputs(total, flujo2);	
		fclose(flujo2);	
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