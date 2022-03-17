#ifndef ESTACIONAR_H
#define ESTACIONAR_H
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "lugar.h"
#include "apresentar.h"
void estacionar(struct lugar* ptr, int abcissa, int ordenada, int cota)
{
	int z, y, x, i;
	int a = 0;
	while(a != 1)
	{
		system("@cls||clear");
		printf("**************************************************************\n");
		printf("*                                                            *\n");
		printf("*    Escolher o lugar onde pretende estacionar:   Digite 1   *\n");
		printf("*    O lugar atribuido automaticamente:           Digite 2   *\n");
		printf("*    Para voltar ao menu principal                Digite 3   *\n");
		printf("*                                                            *\n");
		printf("**************************************************************\n");
		scanf("%d",&i);
		if (i==1)
		{
			system("@cls||clear");
			a = 0;
			while(a == 0)
			{
				int x,y,z;
				apresentar(ptr,abcissa,ordenada,cota);//chama a funcao apresentar//
				printf("\n");
				printf("Apresente a linha a coluna e o andar em que pretende estacionar: \n");
				scanf("%d %d %d",&y,&x,&z);
				if(ptr[(abcissa*ordenada*(z-1))+(abcissa*(y-1))+(x-1)].ocupado == 'L')// é o uti a introduzir o valor logo tens se de subtrair 1 para começar na posicao -1//
				{
					a = 1;
					while(a != 0)
					{
						printf("Apresente a matricula: \n");
						scanf("%s",&ptr[(abcissa*ordenada*(z-1))+(abcissa*(y-1))+(x-1)].matricula);
						if(strlen(ptr[(abcissa*ordenada*(z-1))+(abcissa*(y-1))+(x-1)].matricula) != 6)//O tamanho da matricula//
						{
							for(i=0;i<14;i++)
							{
								ptr[(abcissa*ordenada*(z-1))+(abcissa*(y-1))+(x-1)].matricula[i] ='\0';
							}
							printf("A matricula introduzida nao e valida.\n");
							printf("Introduza outra matricula.\n");
						}
						else
						{
							int k=0;
							for(i=0;i<abcissa*ordenada*cota;i++)
							{
								if(strcmp(ptr[(abcissa*ordenada*(z-1))+(abcissa*(y-1))+(x-1)].matricula, ptr[i].matricula) == 0)//verifica se em cada lugar do parque ja tem um carro estacionado(matricula)//
								{
									k++;
								}
							}
							if(k > 1)
							{
								printf("Esse veiculo ja se encontra estacionado.\n");
								printf("Introduza outra matricula.\n");
							}
							else
							{
								a = 0;
							}
						}
					}	
					time(&ptr[(abcissa*ordenada*(z-1))+(abcissa*(y-1))+(x-1)].data_entrada);//guarda um registo de entrada //
					ptr[(abcissa*ordenada*(z-1))+(abcissa*(y-1))+(x-1)].ocupado = 'O';//substitui o lugar livre para ocupado//
					a = 1;
				}
				else
				{
				printf("Esse estacionamento esta ocupado.");
				printf("\nPressione qualquer tecla para continuar.");
				getch();
				}
			}
			i = 1;
		}
		else
		{
			if (i==2)
			{
				system("@cls||clear");
				int x, y, z;
				for(z=0;z<cota;z++)
				{
					for(y=0;y<ordenada;y++)
					{
						for(x=0;x<abcissa;x++)
						{
							if(ptr[(abcissa*ordenada*z)+(abcissa*y)+x].ocupado == 'L')// Logo que encontre um lugar livre ele ocupa esse lugar//
							{
								a = 1;
								while(a != 0)
								{
									printf("Apresente a matricula: \n");
									scanf("%s",&ptr[(abcissa*ordenada*z)+(abcissa*y)+x].matricula);
									if(strlen(ptr[(abcissa*ordenada*z)+(abcissa*y)+x].matricula) != 6)
									{
										for(i=0;i<14;i++)
											{
												ptr[(abcissa*ordenada*z)+(abcissa*y)+x].matricula[i] ='\0';
											}
											printf("A matricula introduzida nao e valida.\n");
											printf("Introduza outra matricula.\n");
									}
									else
									{
										int k=0;
										for(i=0;i<abcissa*ordenada*cota;i++)
										{
											if(strcmp(ptr[(abcissa*ordenada*z)+(abcissa*y)+x].matricula,ptr[i].matricula) == 0)
											{
												k++;
											}	
										}
										if(k > 1)
										{
											printf("Esse veiculo ja se encontra estacionado.\n");
											printf("Introduza outra matricula.\n");
										}
										else
										{
											a = 0;
										}
									}
								}
								time(&ptr[(abcissa*ordenada*z)+(abcissa*y)+x].data_entrada);
								ptr[(abcissa*ordenada*z)+(abcissa*y)+x].ocupado = 'O';
								return;
							}
						}
					}
				}
				printf("O estacionamento esta cheio.");
				a = 1;
			}
			else
			{
				if(i==3)
				{
					a = 1;
				} 
				else
				{
					printf("Digite um numero valido.");
				}
			}
		}	
	}
}
#endif
