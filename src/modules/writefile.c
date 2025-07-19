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
 * @param file_name Nome do arquivo.
 * @param tam Tamanho do array file_name.
 *
 * @return int Retorna 1 se não receber parâmetro, 2 caso o parâmetro seja inválido.
 *
 */
int
write_file ( char file_name[], int tam ) 
{
	FILE *file = fopen(file_name, "a+");

	if (file_name == NULL)
	{
		return 1;
	}

	if (file == NULL) 
	{
		return 2;
	}

	printf("\n");	

	fprintc(file_name, sizeof(file_name));

	printf("\n");

	printf("\e[1;93mTiaNFM\e[0m: Modo de edição\n");
	printf("Adicionar ao arquivo:\n");
	printf("\e[1;93m > \e[0m");	
	char file_content[100];

//	Limpa o buffer do teclado
	setbuf(stdin, NULL);
	fgets(file_content, sizeof(file_content), stdin);
	file_content[strcspn(file_content, "\n")] = 0;
	fprintf(file, "%s", file_content);

	char option;
	do
	{
		printf("\n");
		printf("Você deseja salvar as alterações? (s/N) ");	
		option = get_option();

	} while (option != 's' && option != 'N');

	if (option == 's') 
	{
		fclose(file);

		printf("Conteúdo modificado:"); 
		file_content[strcspn(file_content, "\n")] = 0;
		printf("\e[92;1m \"%s\" \e[0m\n", file_content);

		printf("\e[92;1mMudanças feitas em: \"%s\" \e[0m\n\n", file_name);
	}
	else
	{
		printf("Alteração cancelada.\n");
	}
	return 0;
}
