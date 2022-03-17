#ifndef CRIAR_H
#define CRIAR_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "configuracao.h"
void criar(struct configuracao* config)
{
	system("@cls||clear");
	printf("Defina o tamanho do parque estacionamento:                              Colunas              \n");
	printf("Indique o numero de colunas:                                       <--------------->         \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *           \n");
	scanf("%d",&config->abcissa);//guarda o valor da abcisssa introduzido pelu uti na struct config atraves do endereço de memoria//
	system("@cls||clear");
	printf("Defina o tamanho do parque estacionamento:                                                   \n");
	printf("Indique o numero de linhas:                                                         |        \n");
	printf("                                                                     * * * * * * *  |        \n");
	printf("                                                                     * * * * * * *  | Linhas \n");
	printf("                                                                     * * * * * * *  |        \n");
	printf("                                                                     * * * * * * *  |        \n");
	scanf("%d",&config->ordenada);
	system("@cls||clear");
	printf("Defina o tamanho do parque estacionamento:                                                   \n");
	printf("Indique o numero de andares:                                                                 \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *   1ºAndar \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                                             \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *   2ºAndar \n");
	printf("                                                                     * * * * * * *           \n");
	printf("                                                                     * * * * * * *           \n");
	scanf("%d",&config->cota);
	system("@cls||clear");
	printf("Defina o preco por hora a ser aplicado no parque de estacionamento.\n");
	scanf("%lf",&config->preco);
}
#endif
