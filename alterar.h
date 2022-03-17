//Alterar o preço por hora//

#ifndef ALTERAR_H
#define ALTERAR_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "configuracao.h"
void alterar(struct configuracao** config)//Aponta o endereço de memoria da struct guardada no ficheiro config//
{
	char login [7];
	system("@cls||clear");
	printf("**************************************************************\n");
	printf("*                                                            *\n");
	printf("*   Para aceder a esta funcionalidade e necessario um gestor *\n");
	printf("*   ou um admnistrador.                                      *\n");
	printf("*   Introduza a palavra chave.                               *\n");
	printf("*                                                            *\n");
	printf("**************************************************************\n");
	scanf("%s",&login);
	if(strcmp(login,"admin") == 0)
	{
		
		system("@cls||clear");
		printf("O preco atual por hora e %lf.\n Introduza o novo preco por hora: ",(*config)->preco);// Guarda o novo preço por hora introduzido pelo admin//
		scanf("%lf", &(*config)->preco);															//Aponta o endereço de memoria da struct config correspondente ao preço//
	}
}
#endif
