#include <stdio.h>
#include <stdlib.h>
#define columnas 10
#define filas 8
#define TRUE 1
#define FALSE 0

typedef struct Posiciones
{
	int fil;
	int col;
	int region;

}Posiciones;
int region = 1;
int vecino = 0;
int main(int argc, char const *argv[])
{
	int matriz[filas][columnas];
	Posiciones posicionesMatriz[15];
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
	matriz[6][6] = 1;
	matriz[6][8] = 1;
	// matriz[6][9] = 1;
	// matriz[7][8] = 1;
	// matriz[7][9] = 1;

	
	//Visualizar matriz
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d ", matriz[i][j]);
		}
		printf("\n");
	}

	printf("-----------------------------\n");
	
	
	for(i = 0; i < filas; i++)
	{
		for(j = 0; j < columnas; j++)
		{
			
			//if(vecino != TRUE)
			//{
			//Para encontrar un uno!
				if(matriz[i][j] == 1)
				{
					//Verifica que tenga vecinos en 8d
					if(matriz[i-1][j] == 1 || matriz[i][j-1] == 1 || matriz[i+1][j] == 1 || matriz[i][j+1] == 1 || matriz[i-1][j-1] == 1 || matriz[i-1][j+1] == 1 || matriz[i+1][j-1] == 1 || matriz[i+1][j+1] == 1)
					{
						posicionesMatriz[i].fil = i;
						posicionesMatriz[j].col = j;
						posicionesMatriz[i].region = region;	//Region a la que pertenece
						
						vecino = TRUE;  //Aquí defino que ha encontrado un vecino en 8d				
					}
					else
					{
						vecino = FALSE;
						region++;
						printf("\n");

					}
					
					printf(" %d,%d |R%d|", posicionesMatriz[i].fil, posicionesMatriz[j].col, region);



				}
			//}
		}
			printf("\n");
	}


	return 0;
}