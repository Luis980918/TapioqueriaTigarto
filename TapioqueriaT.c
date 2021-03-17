#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	int contador=0;
	FILE* flujo=fopen("pedidos.txt", "rb");
	if(flujo==NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}
	char cadena[100];

	while(feof(flujo)==0){
		fscanf(flujo, "%s\n", cadena);
		
		/*Utilizaré la funcion atoi de c para convertir
		de cadena a numero*/
		if(isdigit(*cadena)){
			
			printf("\n %d",(atoi(cadena)+1));
			contador++;
		}
	}

	fclose(flujo);
	printf("\n Se ha leido el archivo correctamente!! %d\n", contador);

	return 0;
}