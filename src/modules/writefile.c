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
 * @return int Retorna 1 se n�o receber par�metro, 2 caso o par�metro seja inv�lido.
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

	printf("\e[1;93mTiaNFM\e[0m: Modo de edi��o\n");
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
		printf("Voc� deseja salvar as altera��es? (s/N) ");	
		option = getoption();

	} while (option != 's' && option != 'N');

	if (option == 's') 
	{
		fclose(file);

		printf("Conte�do modificado:"); 
		fileContent[strcspn(fileContent, "\n")] = 0;
		printf("\e[92;1m \"%s\" \e[0m\n", fileContent);

		printf("\e[92;1mMudan�as feitas em: \"%s\" \e[0m\n\n", nameFile);
	}
	else
	{
		printf("Altera��o cancelada.\n");
	}
	printf("\n");
	system("cd");
	printf("\e[1;93m > \e[0m");
	return 0;
}
