/***
 *                            $$\   $$\                $$$$$$\  $$\ $$\           
 *                            \__|  $$ |              $$  __$$\ \__|$$ |          
 *    $$\  $$\  $$\  $$$$$$\  $$\ $$$$$$\    $$$$$$\  $$ /  \__|$$\ $$ | $$$$$$\  
 *    $$ | $$ | $$ |$$  __$$\ $$ |\_$$  _|  $$  __$$\ $$$$\     $$ |$$ |$$  __$$\ 
 *    $$ | $$ | $$ |$$ |  \__|$$ |  $$ |    $$$$$$$$ |$$  _|    $$ |$$ |$$$$$$$$ |
 *    $$ | $$ | $$ |$$ |      $$ |  $$ |$$\ $$   ____|$$ |      $$ |$$ |$$   ____|
 *    \$$$$$\$$$$  |$$ |      $$ |  \$$$$  |\$$$$$$$\ $$ |      $$ |$$ |\$$$$$$$\ 
 *     \_____\____/ \__|      \__|   \____/  \_______|\__|      \__|\__| \_______|
 *                                                                                
 *                                                                                
 *                                                                                
 */

#include <stdio.h>
#include <string.h>

#include "../include/minimanager.h"

/**
 * @brief Escreve em um arquivo.
 *
 * @param nameFile Nome do arquivo.
 * @param tam Tamanho do array nameFile.
 *
 * @return int Retorna 1 se não receber parâmetro, 2 caso o parâmetro seja inválido.
 *
 */
int
writefile ( char nameFile[], int tam ) 
{
	FILE *file = fopen(nameFile, "a+");

	if (nameFile == NULL)
	{
		return 1;
	}

	if (file == NULL) 
	{
		return 2;
	}

	printf("\n");	

	fprintc(nameFile, sizeof(nameFile));

	printf("\n");

	printf("\e[1;93mTiaNFM\e[0m: Modo de edição\n");
	printf("Adicionar ao arquivo:\n");
	printf("\e[1;93m > \e[0m");	
	char fileContent[100];

	// Limpa o buffer do teclado
	setbuf(stdin, NULL);
	fgets(fileContent, sizeof(fileContent), stdin);
	fileContent[strcspn(fileContent, "\n")] = 0;
	fprintf(file, "%s", fileContent);

	char option;
	do
	{
		printf("\n");
		printf("Você deseja salvar as alterações? (s/N) ");	
		option = getoption();

	} while (option != 's' && option != 'N');

	if (option == 's') 
	{
		fclose(file);

		printf("Conteúdo modificado:"); 
		fileContent[strcspn(fileContent, "\n")] = 0;
		printf("\e[92;1m \"%s\" \e[0m\n", fileContent);

		printf("\e[92;1mMudanças feitas em: \"%s\" \e[0m\n\n", nameFile);
	}
	else
	{
		printf("Alteração cancelada.\n");
	}
	printf("\n");
	system("cd");
	printf("\e[1;93m > \e[0m");
	return 0;
}
