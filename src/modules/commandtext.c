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
 * @param cmd_text Comando digitado pelo usuário.
 * @param tam Tamanho do array cmd_text.
 *
 * @return int Retorna 1 se o comando for executado, caso contrário retorna 0.
 *
 */
int
command_text( char cmd_text[], int tam )
{	
//	Separa os argumentos.
	char *arg = strtok(cmd_text, " ");
//	Por exemplo, se o usuário digitar a string: "ler comando"
//	A função retorna o endereço de array até um delimitador (Nesse caso, um espaço branco: " ").
//	Ou seja, [arg] passa a valer: "ler". 
//	Se a função for chamada novamente, o retorno será o próximo argumento: "comando".
	
 	if (strcmp(cmd_text, "ler") == 0)
 	{
 		arg = strtok(NULL, " ");
		
 		int ret = read_file(arg, sizeof(arg));

 		if (ret != 0)
 		{
 			if (ret == 1)
 			{
 				printf("   \e[92;1mler \e[0m <\e[31;1mnomedoarquivo.txt\e[0m>\n");
 				printf("\e[31;1mERRO: Nome de arquivo não informado!\e[0m\n");
 			}

 			if (ret == 2)
 			{
 				printf("O arquivo \"\e[31;1m%s\e[0m\" não foi encontrado.\n", arg);
 			}
 		}
 		return 1;
 	}

 	if (strcmp(cmd_text, "editar") == 0)
 	{
		arg = strtok(NULL, " ");

 		int ret = write_file(arg, sizeof(arg));

 		if (ret != 0)
 		{
 			if (ret == 1)
 			{
 				printf("   \e[92;1meditar\e[0m <\e[31;1mnomedoarquivo.txt\e[0m>\n");
 			}

 			if (ret > 1)
 			{
 				printf("O arquivo \"\e[31;1m%s\e[0m\" não foi encontrado.\n", arg);			
			}
 		}
 		return 1;
 	}
		
 	if (strcmp(cmd_text, "renomear") == 0)
 	{
 		char *old_file_name = strtok(NULL, " ");
 		char *new_file_name = strtok(NULL, " ");
 		char *MAX_ARGUMENTS = strtok(NULL, " ");
 		
 		if ( MAX_ARGUMENTS != NULL )
		{
			perror("Syntax errada.\nMais de 2 argumentos");
//			return -1;
		} 		
 		
 		if (old_file_name == NULL || new_file_name == NULL)
		{
			perror("Syntax errada");
//			return -1;
		}
 		else
 		{
	 		if( rename(old_file_name, new_file_name) == 0)
	 			printf("%s renomeado para %s\n", old_file_name, new_file_name);
	 		else
	 			perror("Erro ao renomear o arquivo");
	 	}
	 	return 1;
 	}

 	if (strcmp(cmd_text, "sair") == 0)
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

 	if (strcmp(cmd_text, "listar") == 0)
 	{
 		system("dir");
 		return 1;
 	}	

 	if (strcmp(cmd_text, "limpar") == 0)
 	{
 		system("cls");
 		return 1;
 	}

	return 0;
}
