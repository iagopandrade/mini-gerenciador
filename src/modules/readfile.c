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

#include "../include/minimanager.h"

/**
 * @brief Ler um arquivo.
 *
 * @param file_name Nome do arquivo.
 * @param tam Tamanho do array file_name.
 *
 * @return int Retorna 1 se não receber parâmetro, 2 caso o parâmetro seja inválido.
 *
 */
int
read_file ( char file_name[], int tam ) 
{
	FILE *file = fopen(file_name, "r");

	if (file_name == NULL)
		return 1;

	if (file == NULL) 
		return 2;

	else 
	{
		//char file_content;
		system("cd");
		printf("\n");
		printf("\e[1;93mTiaNFM\e[0m: Modo de leitura\n");
		printf("Arquivo '%s'\n\n", file_name);

		fprintc(file_name, sizeof(file_name));

		fclose(file);

		printf("Arquivo '%s' foi fechado\n", file_name);
 		printf("\n");
		system("cd");
		printf("\e[1;93m > \e[0m");
	}
	return 0;
}
