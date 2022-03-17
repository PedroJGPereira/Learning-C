#ifndef ELIMINAR_H
#define ELIMINAR_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int eliminar()
{
	int r;
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
		printf("*******************************************************************************\n");
		printf("*                                                                             *\n");
		printf("*   Tem a certeza que pretende criar um novo parque estacionamento            *\n");
		printf("*   ao faze-lo estara a apagar o parque de estacionamento atual e             *\n");
		printf("*   e toda a informacao nele contida.                                         *\n");
		printf("*   Se realmente pretender eliminar o parque de estacionamento:     Digite 1  *\n");
		printf("*   Se nao pretender eliminar o parque estacionamento:              Digite 2  *\n");
		printf("*                                                                             *\n");
		printf("*******************************************************************************\n");
		scanf("%d", &r);
		if(r == 1)
		{
			remove("config");
			remove("data");
			return 0;
		}
		else
		{
			return 1;// se escolher um nº diferente de 1//
		}
	}
	return 1;// se a palavra chave for a incorreta//
}
#endif
