#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "lugar.h"
#include "configuracao.h"
#include "principal.h"
#include "criar.h"
main()
{
	int i=1;
	struct lugar* ptr;
	struct configuracao config;
	FILE *confi; 
	FILE *data;
	while(i != 0)
	{
		confi = fopen("config","r");
		if (confi != NULL)//se o ficheiro nao tiver vazio//
		{
			fclose(confi);	
			confi = fopen("config","rb");
			data = fopen("data","rb");
			fread(&config, sizeof(struct configuracao), 1, confi);//saber o tamanho do ficheiro - consultar o tamanho do parque atraves da abcissa, ordenada e cota //
			ptr = (struct lugar*)malloc((config.abcissa * config.ordenada * config.cota) * sizeof(struct lugar));//alocar a memoria//
			fread(ptr,sizeof(struct lugar)*config.abcissa*config.ordenada*config.cota,1,data);
			fclose(confi);
			fclose(data);
			if(principal(ptr,config.abcissa,config.ordenada,config.cota,&config) == 1)// caso elimine o parque//
			{
				free(ptr);//liberta a memoria//
			}
			else
			{
				i = 0; 
			}
		}
		 else // criar um novo parque//
		{
			fclose(confi);	
			criar(&config);
			ptr = (struct lugar*)malloc((config.abcissa * config.ordenada * config.cota) * sizeof(struct lugar));
			for( i = 0 ; i < (config.abcissa * config.ordenada * config.cota); i++ )
			{
				ptr[i].ocupado = 'L';
			}
			if(principal(ptr,config.abcissa,config.ordenada,config.cota,&config) == 1)
			{
				free(ptr);
			}
			else
			{
				i = 0;
			}
		}
	}
	confi = fopen("config","wb");
	data = fopen("data","wb");
	fwrite(&config,sizeof(struct configuracao),1,confi);
	fwrite(ptr,sizeof(struct lugar)*config.abcissa*config.ordenada*config.cota,1,data);	 
	fclose(confi);
	fclose(data);			
	free(ptr);
}
