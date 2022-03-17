//Apresentar o andar, a linha e a coluna do carro atraves da matricula//

#ifndef APRESENTA_H
#define APRESENTA_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "lugar.h"
void apresenta(struct lugar* ptr,int abcissa,int ordenada,int cota)
{
	system("@cls||clear");
	struct tm *info; //struct existente na funcao time - local time - rever
	int x,y,z,i=0;
	for(z=0;z<cota;z++)
	{
		for(y=0;y<ordenada;y++)
		{	
			for(x=0;x<abcissa;x++)
			{
				if(ptr[(abcissa*ordenada*z)+(abcissa*y)+x].ocupado == 'O')
				{
					info = localtime( &ptr[(abcissa*ordenada*z)+(abcissa*y)+x].data_entrada);
					printf("O carro com a matricula %s esta estacionado no andar %d, na linha %d e na coluna %d, desde %s\n", ptr[(abcissa*ordenada*z)+(abcissa*y)+x].matricula,z+1,y+1,x+1,asctime(info));
					i++;
				}
			}
		}
	}
	if(i==0)
	{
		printf("\nNao se encontra estacionado nenhum veiculo no parque.");
	}
}
#endif
