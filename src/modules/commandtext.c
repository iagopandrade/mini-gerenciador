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
#include <stdlib.h>
#include <string.h>

#include "../include/minimanager.h"

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

 	// Remove o "\n" do ENTER
 	cmdtext[strcspn(cmdtext, "\n")] = 0;

 	// Separa o argumento do comando 
 	arg = strtok(cmdtext, " ");
	// > ler arquivo.txt
	// Comando = "ler"; Argumento = "arquivo.txt"

 	if (strcmp(cmdtext, "ler") == 0)
 		{
 			int ret = 0;
 			arg = strtok(NULL, " ");

 			ret = readfile(arg, sizeof(arg));

 			if (ret != 0)
 			{
 				if (ret == 1)
 				{
 					printf("   \e[92;1mler \e[0m <\e[31;1mnomedoarquivo.txt\e[0m>\n");
 					printf("\e[31;1mERRO: Nome de arquivo não informado!\e[0m\n");
 					printf("\n\n");
					system("cd");
					printf("\e[1;93m > \e[0m"); 
 				}

 				if (ret > 1)
 				{
 					printf("O arquivo \"\e[31;1m%s\e[0m\" não foi encontrado.\n", arg);
 					printf("\n");
					system("cd");
					printf("\e[1;93m > \e[0m");
 				}
 			}
 			ret = 0;
 			return 1;
 		}

 	if (strcmp(cmdtext, "editar") == 0)
 		{
 			int ret = 0;
 			arg = strtok(NULL, " ");

 			ret = writefile(arg, sizeof(arg));

 			if (ret != 0)
 			{
 				if (ret == 1)
 				{
 					printf("    \e[92;1meditar\e[0m <\e[31;1mnomedoarquivo.txt\e[0m>\n");
 					printf("\n");
					system("cd");
					printf("\e[1;93m > \e[0m");
 				}

 				if (ret > 1)
 				{
 					printf("O arquivo \"\e[31;1m%s\e[0m\" não foi encontrado.\n", arg);
 					printf("\n");
					system("cd");
					printf("\e[1;93m > \e[0m");				
				}
 			}
 			ret = 0;
 			return 1;
 		}

 	if (strcmp(cmdtext, "sair") == 0)
 		{
 			printf("Programa encerrado.\n");
 			exit(0);
 		}

	
	/***
 	*                                    $$\                                                      $$\ $$\           
 	*                                    $$ |                                                     $$ |$$ |          
 	*     $$$$$$$\ $$\   $$\  $$$$$$$\ $$$$$$\    $$$$$$\  $$$$$$\$$$$\         $$$$$$$\ $$$$$$\  $$ |$$ | $$$$$$$\ 
 	*    $$  _____|$$ |  $$ |$$  _____|\_$$  _|  $$  __$$\ $$  _$$  _$$\       $$  _____|\____$$\ $$ |$$ |$$  _____|
 	*    \$$$$$$\  $$ |  $$ |\$$$$$$\    $$ |    $$$$$$$$ |$$ / $$ / $$ |      $$ /      $$$$$$$ |$$ |$$ |\$$$$$$\  
 	*     \____$$\ $$ |  $$ | \____$$\   $$ |$$\ $$   ____|$$ | $$ | $$ |      $$ |     $$  __$$ |$$ |$$ | \____$$\ 
 	*    $$$$$$$  |\$$$$$$$ |$$$$$$$  |  \$$$$  |\$$$$$$$\ $$ | $$ | $$ |      \$$$$$$$\\$$$$$$$ |$$ |$$ |$$$$$$$  |
 	*    \_______/  \____$$ |\_______/    \____/  \_______|\__| \__| \__|       \_______|\_______|\__|\__|\_______/ 
 	*              $$\   $$ |                                                                                       
 	*              \$$$$$$  |                                                                                       
 	*               \______/                                                                                        
 	*/

 	if (strcmp(cmdtext, "listar") == 0)
 	{
 		system("dir");
 		printf("\n");
		system("cd");
		printf("\e[1;93m > \e[0m");
 		return 1;
 	}	

 	if (strcmp(cmdtext, "limpar") == 0)
 	{
 		system("cls");
 		printf("\n");
		system("cd");
		printf("\e[1;93m > \e[0m");
 		return 1;
 	}

 	printf("  \"\e[31;1m%s\e[0m\": comando não encontrado.\n", cmdtext);
 	printf("\n");
	system("cd");
	printf("\e[1;93m > \e[0m");
 	return 0;
}
