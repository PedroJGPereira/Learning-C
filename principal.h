#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "configuracao.h"
#include "lugar.h"
#include "estacionar.h"
#include "apresentar.h"
#include "retirar.h"
#include "eliminar.h"
#include "apresenta.h"
#include "alterar.h"
int principal(struct lugar* ptr,int abcissa,int ordenada,int cota,struct configuracao* config)
{
	int i=1,a=0,l;
	while(i!=7)
	{
		l=0;
		for(i=0;i<abcissa*ordenada*cota;i++)
		{
			if(ptr[i].ocupado == 'L')// conta o nº de lugares disponiveis//
			{
				l++;
			} 
		}
		system("@cls||clear");
		printf("**************************************************************\n");
		printf("*   Bem vindo ao nosso parque temos: %d lugares disponiveis. *\n",l);
		printf("**************************************************************\n");
		printf("*                                                            *\n");
		printf("*   Estacionar um carro:                          Digite 1   *\n");
		printf("*   Retirar um carro:                             Digite 2   *\n");
		printf("*   Apresentar os lugares livres e ocupados:      Digite 3   *\n");
		printf("*   Criar um novo parque de estacionamento:       Digite 4   *\n");
		printf("*   Apresentar os carros estacionados:            Digite 5   *\n");
		printf("*   Alterar o preco por hora:                     Digite 6   *\n");
		printf("*   Fechar o programa :                           Digite 7   *\n");
		printf("*                                                            *\n");
		printf("**************************************************************\n");
		scanf("%d",&i);
		if(i==7){}// se for 7 nao acontece nada apenas fecha - for vazio//
		else
		{
			if(i==1)
			{
				estacionar(ptr,abcissa,ordenada,cota);
				printf("\nPressione qualquer tecla para continuar.");
				getch();
			}
			else
			{
				if(i==2)
				{
					retirar(ptr,abcissa,ordenada,cota,config->preco);
					printf("\nPressione qualquer tecla para continuar.");
					getch();
				}
				else
				{
					if(i==3)
					{
						apresentar(ptr,abcissa,ordenada,cota);
						printf("\nPressione qualquer tecla para continuar.");
						getch();
					}
					else
					{
						if(i==4)
						{
							if (eliminar() == 0)// elimina o parque//
							{
								i = 7;
								a = 1;
							}
							printf("\nPressione qualquer tecla para continuar.");
							getch();
							system("@cls||clear");
						}
						else
						{
							if(i==5)
							{
								apresenta(ptr,abcissa,ordenada,cota);
								printf("\nPressione qualquer tecla para continuar.");
								getch();
							}
							else
							{				
								if(i==6)
								{
									alterar(&config);
									printf("\nPressione qualquer tecla para continuar.");
									getch();
								}
								else
								{
									printf("Insira outro valor.\n");
									printf("Pressione qualquer tecla para continuar.");
									getch();	
								}
							}
						}
					}
				}
			}
		}
	}
	return a;
}
#endif
