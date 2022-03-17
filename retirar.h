#ifndef RETIRAR_H
#define RETIRAR_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "lugar.h"
void retirar(struct lugar* ptr,int abcissa,int ordenada,int cota,double preco)
{
	system("@cls||clear");
	int l,i;
	time_t temp;
	char mat [7];
	struct tm *info;
	for(i=0;i<abcissa*ordenada*cota;i++)
	{
		if(ptr[i].ocupado == 'O')// verificar se tem algum lugar ocupado//
		{
			l++;
		} 
	}
	if(l!=0)
	{
		printf("Apresenta a matricula:\n");
		scanf("%s",&mat);
		int x, y, z;
		for(z=0;z<cota;z++)
		{
			for(y=0;y<ordenada;y++)
			{
				for(x=0;x<abcissa;x++)
				{
					if(strcmp(ptr[(abcissa*ordenada*z)+(abcissa*y)+x].matricula, mat) == 0)
					{			
						info = localtime( &ptr[(abcissa*ordenada*z)+(abcissa*y)+x].data_entrada);
						ptr[(abcissa*ordenada*z)+(abcissa*y)+x].ocupado = 'L';
						strcpy(ptr[(abcissa*ordenada*z)+(abcissa*y)+x].matricula, "");
						time(&temp);
						if(temp -ptr[(abcissa*ordenada*z)+(abcissa*y)+x].data_entrada<=3600)// se o tempo de saida for inferior ou igual a 1 hora//
						{
							printf("O carro esta estacionado desde %s",asctime(info));
							printf("O preco a pagar e %lf euros.\n",preco);
						}
						else
						{
							printf("O carro esta estacionado desde %s",asctime(info));
							printf("O preco a pagar e %lf euros.\n",(double)(temp -ptr[(abcissa*ordenada*z)+(abcissa*y)+x].data_entrada)*(preco/3600));
						}
						return;
					}
				}
			}
		}
		printf("Essa matricula nao esta associada a nenhum estacionamento.\n");
	}
	else
	{
		printf("Não se encontra estacionado nenhum veiculo.\n");
	}
}
#endif
