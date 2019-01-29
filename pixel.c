#include <stdio.h>
#include <stdlib.h>
#define columnas 10
#define filas 8

int main(int argc, char const *argv[])
{
	int matriz[filas][columnas];
	int i=0;
	int j=0;

	//Llenar la matriz de 0's
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			matriz[i][j] = 0;
		}
	}

	//Asignando valores de 1 a la matriz
	matriz[2][2] = 1;
	matriz[2][3] = 1;
	matriz[2][4] = 1;
	matriz[2][5] = 1;
	matriz[3][2] = 1;
	matriz[3][3] = 1;
	matriz[3][4] = 1;
	matriz[3][5] = 1;
	matriz[4][2] = 1;
	matriz[4][3] = 1;
	matriz[5][2] = 1;
	matriz[5][3] = 1;

	//Visualizar matriz
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d ", matriz[i][j]);
		}
		printf("\n");
	}

	printf("-----------------------------\n");
	//Buscar posiciones donde se encuentran 1's
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			if(matriz[i-1][j] == 1){
				if(matriz[i][j-1] == 1){
					if(matriz[i+1][j] == 1){
						if(matriz[i][j+1] == 1){
							//matrizNueva[i][j] = matriz[i][j];	

						}
					}
				}
				printf(" %d,%d ", i-1,j);
			}
		}
		printf("\n");
	}

	return 0;
}