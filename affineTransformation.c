/********************************************************************/
/*	Program Assignment: Programa #3 							  	*/
/*	Name: José Baltazar Ramírez Rodríguez							*/
/*	Date: 08 de febrero de 2018										*/
/*	Description: Programa para realizar transformaciones a una		*/
/*				 imagen a nivel pixel								*/
/********************************************************************/

/********************************************************************************/
/* Compilation instructions														*/
/* ejecutar en consola: gcc affineTransformation.c -o affineTransformation		*/
/********************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define columnas 10
#define filas 10

void trasladar(int i, int j);
void escalar(int i, int j);
void rotar(int i, int j);
void mostrarMatrizTrasladada();
void mostrarMatrizEscalada();
void mostrarMatrizRotada();
int matrizTrasladada[filas][columnas] = {0};
int matrizEscalada[filas][columnas] = {0};
int matrizRotada[filas][columnas] = {0};
int i=0;
int j=0;

int main(int argc, char const *argv[])
{
	int matriz[filas][columnas];
	


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


	printf("Matriz Original\n");
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
			if(matriz[i][j] == 1)
			{
				trasladar(i,j);
				escalar(i,j);
				rotar(i,j);
			}
		}
	}
	printf("Matriz Trasladada\n");
	mostrarMatrizTrasladada();
	printf("-----------------------------\n");
	printf("Matriz Escalada\n");
	mostrarMatrizEscalada();
	printf("-----------------------------\n");
	printf("Matriz Rotada\n");
	mostrarMatrizRotada();

	return 0;
}

void trasladar(int i, int j)
{
	int auxPos = 0;	
	int coordX = 0;
	int coordY = 0;
	int vectorCoordenada[3] = {i,j,1};
	
	int vectorCoordenadaNueva[3] = {0};
	

	int matrizTransformacion[3][3] = {{1, 0, 0},
									  {0, 1, 0},
									  {0, 2, 1}};	//Aquí se define el incremento a transformar en T31 y T32

	int x = 0;
	int y = 0;

	for(x = 0; x < 3; x++)
	{
		for(y = 0; y < 3; y++)
		{
			auxPos += vectorCoordenada[y] * matrizTransformacion[y][x];
			
		}
		vectorCoordenadaNueva[x] = auxPos;
		auxPos = 0;
	}


//Para sacar coordenadas X y Y nuevas

	coordX = vectorCoordenadaNueva[0];	//Para trasladar en filas
	coordY = vectorCoordenadaNueva[1];	//Para trasladar en columnas
	
	matrizTrasladada[coordX][coordY] = 1;



}
void mostrarMatrizTrasladada()
{
	//Visualizar matriz
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d ", matrizTrasladada[i][j]);
		}
		printf("\n");
	}
}
void escalar(int i, int j)
{
	int auxPos = 0;	
	int coordX = 0;
	int coordY = 0;
	int vectorCoordenada[3] = {i,j,1};
	int vectorCoordenadaNueva[3] = {0};

	int matrizTransformacion[3][3] = {{1, 0, 0},
									  {0, 1, 0},
									  {0, 0, 1}};	//Aquí se define el incremento a escalar en T11 y T22

	int x = 0;
	int y = 0;


	for(x = 0; x < 3; x++)
	{
		for(y = 0; y < 3; y++)
		{
			auxPos += vectorCoordenada[y] * matrizTransformacion[y][x];
			
		}
		vectorCoordenadaNueva[x] = auxPos;
		auxPos = 0;
	}

	//Para sacar coordenadas X y Y nuevas

	coordY = vectorCoordenadaNueva[0];
	coordX = vectorCoordenadaNueva[1];

	
	for(x = 0; x < coordX; x++)
	{
		for(y = 0; y < coordY; y++)
		{
			matrizEscalada[i+x][j+y] = 1;
		}			
	}
			

}
void mostrarMatrizEscalada()
{
	//Visualizar matriz
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d ", matrizEscalada[i][j]);
		}
		printf("\n");
	}
}

void rotar(int i, int j)
{
	int auxPos = 0;	
	int coordX = 0;
	int coordY = 0;
	int vectorCoordenada[3] = {i,j,1};
	int vectorCoordenadaNueva[3] = {0};

	int matrizTransformacion[3][3] = {{cos(1), sin(1), 0},
									  {-sin(1), cos(1), 0},
									  {0, 0, 1}};	//Aquí se define el incremento a escalar en T11 y T22

	int x = 0;
	int y = 0;

	//Para sacar coordenadas X y Y nuevas

	coordX = vectorCoordenadaNueva[0];
	coordY = vectorCoordenadaNueva[1];

	for(x = 0; x < coordX; x++)
	{
		for(y = 0; y < coordY; y++)
		{
			matrizRotada[i][j] = 1;
		}			
	}

	
}
void mostrarMatrizRotada()
{
	//Visualizar matriz
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf(" %d ", matrizRotada[i][j]);
		}
		printf("\n");
	}
}