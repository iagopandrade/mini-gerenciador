/***
 *                                         /$$  /$$$$$$  /$$ /$$          
 *                                        | $$ /$$__  $$|__/| $$          
 *      /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$| $$  \__/ /$$| $$  /$$$$$$ 
 *     /$$__  $$ /$$__  $$ |____  $$ /$$__  $$| $$$$    | $$| $$ /$$__  $$
 *    | $$  \__/| $$$$$$$$  /$$$$$$$| $$  | $$| $$_/    | $$| $$| $$$$$$$$
 *    | $$      | $$_____/ /$$__  $$| $$  | $$| $$      | $$| $$| $$_____/
 *    | $$      |  $$$$$$$|  $$$$$$$|  $$$$$$$| $$      | $$| $$|  $$$$$$$
 *    |__/       \_______/ \_______/ \_______/|__/      |__/|__/ \_______/
 *                                                                        
 *                                                                        
 *                                                                        
 */
 
#include <stdio.h>
#include <string.h>
#include "utils.h"

/**
 * @brief Ler um arquivo.
 *
 * @param nameFile Nome do arquivo.
 * @param tam Tamanho do array nameFile.
 *
 * @return int Retorna 1 se não receber parâmetro, 2 caso o parâmetro seja inválido.
 *
 */
int
readfile ( char nameFile[], int tam ) 
{
	FILE *file = fopen(nameFile, "r");
	
	if (nameFile == NULL)
		return 1;
	
	if (file == NULL) 
		return 2;
		
	else 
	{
		char fileContent;
		
		printf("\n");
		printf("Arquivo '%s'\n", nameFile);
		printf("\t-----------------------\n");
		int i = 1;
		printf("\t%d. ", i);
		
		while ((fileContent = fgetc(file)) != EOF) 
			{
				if (fileContent == '\n') 
				{
					i++;
					fileContent = 0;
					printf("\n\t%d. ", i);			
				}
				putchar(fileContent);
			}

		fclose(file);

		printf("\n\t-------------------\n");
		printf("%d linhas\n", i); i = 0;
		printf("Arquivo '%s' foi fechado", nameFile);
		printf("\n\n >");
	}
	return 0;
}
