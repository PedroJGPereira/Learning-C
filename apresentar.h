//Mostrar o parque de estacionamento//

#ifndef APRESENTAR_H
#define APRESENTAR_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "lugar.h"
void apresentar(struct lugar* ptr,int abcissa,int ordenada,int cota)
{
	system("@cls||clear");
	int x,y,z,i;
	for(z=0;z<cota;z++)
	{
		printf("____________");
		for(i=0;i<=abcissa;i++)
		{
			printf("__");
		}
		printf("\n");
		printf("Andar - %d ",z+1);
		printf("\n\n");
		printf("            Colunas");
		printf("\n\n");
		printf("            ");
		for(i=1;i<=abcissa;i++)
		{
			printf("%d ",i);
		}
		printf("\n\n");
		for(y=0;y<ordenada;y++)
		{	
			if(y==0)
			{
				printf("Linhas   %d  ",y+1);
			}
			else
			{
				printf("         %d  ",y+1);
			}
			for(x=0;x<abcissa;x++)
			{
				printf("%c ", ptr[(abcissa*ordenada*z)+(abcissa*y)+x].ocupado);
			}
			printf("\n");
		}
		printf("\n\n");
	}
}
#endif
