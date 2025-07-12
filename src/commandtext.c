/***
 *                                                                              $$\   $$\                           $$\     
 *                                                                              $$ |  $$ |                          $$ |    
 *     $$$$$$$\  $$$$$$\  $$$$$$\$$$$\  $$$$$$\$$$$\   $$$$$$\  $$$$$$$\   $$$$$$$ |$$$$$$\    $$$$$$\  $$\   $$\ $$$$$$\   
 *    $$  _____|$$  __$$\ $$  _$$  _$$\ $$  _$$  _$$\  \____$$\ $$  __$$\ $$  __$$ |\_$$  _|  $$  __$$\ \$$\ $$  |\_$$  _|  
 *    $$ /      $$ /  $$ |$$ / $$ / $$ |$$ / $$ / $$ | $$$$$$$ |$$ |  $$ |$$ /  $$ |  $$ |    $$$$$$$$ | \$$$$  /   $$ |    
 *    $$ |      $$ |  $$ |$$ | $$ | $$ |$$ | $$ | $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |  $$ |$$\ $$   ____| $$  $$<    $$ |$$\ 
 *    \$$$$$$$\ \$$$$$$  |$$ | $$ | $$ |$$ | $$ | $$ |\$$$$$$$ |$$ |  $$ |\$$$$$$$ |  \$$$$  |\$$$$$$$\ $$  /\$$\   \$$$$  |
 *     \_______| \______/ \__| \__| \__|\__| \__| \__| \_______|\__|  \__| \_______|   \____/  \_______|\__/  \__|   \____/ 
 *                                                                                                                          
 *                                                                                                                          
 *                                                                                                                          
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

/**
 * @brief Compara comandos.
 *
 * Esta função compara uma string com um comando interno.
 *
 * @param cmdtext Comando digitado pelo usuário.
 * @param tam Tamanho do array cmdtext.
 *
 * @return int Retorna 1 se o comando for executado, caso contrário retorna 0.
 *
 */
 int
 commandtext(char cmdtext[], int tam)
 {
 	char *arg = NULL;

 	// Remove o "\n" que a função fgets() colocou
 	cmdtext[strcspn(cmdtext, "\n")] = 0;

 	// Separa o argumento do comando 
 	arg = strtok(cmdtext, " ");
	// >ler arquivo.txt
	// Comando = 'ler'; Argumento = 'arquivo.txt'

 	if (strcmp(cmdtext, "ler") == 0)
 		{
 			int status = 0;
 			arg = strtok(NULL, " ");

 			status = readfile(arg, sizeof(arg));

 			if (status != 0)
 			{
 				if (status == 1)
 				{
 					printf("Digite: ler [nomedoarquivo.txt]");
 					printf("\n\n >");
 				}

 				if (status > 1)
 				{
 					printf("O arquivo '%s' não existe.", arg);
 					printf("\n\n >");
 				}
 			}
			// printf("DEBUG: RETURN: %d", status);
 			status = 0;
 			return 1;
 		}

 	if (strcmp(cmdtext, "sair") == 0)
 	{
 		printf("Programa encerrado.\n");
 		exit(0);
 	}

 	if (strcmp(cmdtext, "limpar") == 0)
 	{
 		system("cls");
 		return 1;
 	}

 	printf("O comando '%s' não existe!", cmdtext);
 	printf("\n\n >");
 	return 0;
 }
