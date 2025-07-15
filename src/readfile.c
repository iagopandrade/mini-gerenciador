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
		
		printcf(nameFile, sizeof(nameFile));

		fclose(file);

		printf("Arquivo '%s' foi fechado\n", nameFile);
 		printf("\n");
		system("cd");
		printf("\e[1;93m > \e[0m");
	}
	
	return 0;
}

void
printcf(char nameFile[], int tam) 
{
	FILE *file = fopen(nameFile, "r");
	char ch;
	while ((ch = fgetc(file)) != EOF) 
		{
			putchar(ch);
		}
	fclose(file);
}

int
getoption()
{
	char option;
	scanf(" %c", &option);
	
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);	

	switch(option)
		{
			case 's': return 1;
			case 'N': return 2;
			default: return 3;
		}
}
