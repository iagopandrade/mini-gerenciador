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
#include <stdlib.h>
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
		system("cd");
		printf("\n");
		printf("\e[1;93mTiaNFM\e[0m: Modo de leitura\n");
		printf("Arquivo '%s'\n\n", nameFile);
		
		fprintc(nameFile, sizeof(nameFile));

		fclose(file);

		printf("Arquivo '%s' foi fechado\n", nameFile);
 		printf("\n");
		system("cd");
		printf("\e[1;93m > \e[0m");
	}
	
	return 0;
}
