// #include <stdio.h>
// #include <stdlib.h>
// #define columnas 10
// #define filas 8
// #define TRUE 1
// #define FALSE 0

// typedef struct Posiciones
// {
// 	int fil;
// 	int col;
// 	int region;

// }Posiciones;
// int region = 1;
// int vecino = 0;
// int main(int argc, char const *argv[])
// {
	
// 	int matriz[filas][columnas];
// 	//Posiciones posicionesMatriz[20];
// 	Posiciones posicionesMatriz[15] = {0};
// 	int i=0;
// 	int j=0;
// 	int k=0;

	
	

// 	//Llenar la matriz de 0's
// 	for(i = 0; i < filas; i++){
// 		for(j = 0; j < columnas; j++){
// 			matriz[i][j] = 0;
// 		}
// 	}

// 	//Asignando valores de 1 a la matriz
// 	matriz[2][2] = 1;
// 	matriz[2][3] = 1;
// 	matriz[2][4] = 1;
// 	matriz[2][5] = 1;
// 	matriz[3][2] = 1;
// 	matriz[3][3] = 1;
// 	matriz[3][4] = 1;
// 	matriz[3][5] = 1;
// 	matriz[4][2] = 1;
// 	matriz[4][3] = 1;
// 	matriz[5][2] = 1;
// 	matriz[5][3] = 1;
	


// 	// matriz[6][0] = 1;
	
// 	// matriz[7][8] = 1;
// 	// matriz[7][9] = 1;


	
// 	//Visualizar matriz
// 	for(i = 0; i < filas; i++){
// 		for(j = 0; j < columnas; j++){
// 			printf(" %d ", matriz[i][j]);
// 		}
// 		printf("\n");
// 	}

// 	printf("-----------------------------\n");
	
	
// 	for(i = 0; i < filas; i++)
// 	{
// 		for(j = 0; j < columnas; j++)
// 		{
// 			//Para encontrar un uno!
// 				if(matriz[i][j] == 1)
// 				{
// 					//Verifica que tenga vecinos en 8d
// 					vecino = FALSE;
// 					if(matriz[i-1][j] == 1 || matriz[i][j-1] == 1 || matriz[i+1][j] == 1 || matriz[i][j+1] == 1 || matriz[i-1][j-1] == 1 || matriz[i-1][j+1] == 1 || matriz[i+1][j-1] == 1 || matriz[i+1][j+1] == 1)
// 					{
// 						vecino = TRUE;  //Aquí defino que ha encontrado un vecino en 8d

// 						//posicionesMatriz[i].regionMarcada = TRUE;	
// 						posicionesMatriz[j].fil = i;
// 						posicionesMatriz[j].col = j;
// 						posicionesMatriz[j].region = region;	//Region a la que pertenece
									
// 					}
// 					else
// 					{
// 						vecino = FALSE;
// 						region++;
// 						//printf(" %d,%d |R%d|", posicionesMatriz[i].fil, posicionesMatriz[i].col, region);
// 						printf("\n");
// 					}
					
// 					printf(" %d,%d |R%d|", posicionesMatriz[i].fil, posicionesMatriz[i].col, region);
// 				}
// 		}
// 			printf("\n");
// 	}
	
// //printf("%d\n", posicionesMatriz[10]);
// 	return 0;
// }
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
	Posiciones posicionesMatriz[15] = {0};
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
			//Para encontrar un uno!
			//if(vecino != TRUE)
			//{
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