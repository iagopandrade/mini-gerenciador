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
 * Esta fun��o compara uma string com um comando interno.
 *
 * @param cmd_text Comando digitado pelo usu�rio.
 * @param tam Tamanho do array cmd_text.
 *
 * @return int Retorna 1 se o comando for executado, caso contr�rio retorna 0.
 *
 */

int
command_text( char cmd_text[], int tam )
{
	// Remove o "\n" do ENTER
 	cmd_text[strcspn(cmd_text, "\n")] = 0;
 	
	// Separa os argumentos.
	char *arg = strtok(cmd_text, " ");
	//	Por exemplo, se o usu�rio digitar a string: "ler comando"
	// 	A fun��o retorna o endere�o de array at� um delimitador (Nesse caso, um espa�o branco: " ").
	//	Ou seja, [arg] passa a valer: "ler". 
	//	Se a fun��o for chamada novamente, o retorno ser� o pr�ximo argumento: "comando".
	 
 	if (strcmp(cmd_text, "ler") == 0)
 	{
 		arg = strtok(NULL, " ");
		
 		int ret = read_file(arg, sizeof(arg));

 		if (ret != 0)
 		{
 			if (ret == 1)
 			{
 				printf("   \e[92;1mler \e[0m <\e[31;1mnomedoarquivo.txt\e[0m>\n");
 				printf("\e[31;1mERRO: Nome de arquivo n�o informado!\e[0m\n");
 				printf("\n\n");
				system("cd");
				printf("\e[1;93m > \e[0m"); 
 			}

 			if (ret > 1)
 			{
 				printf("O arquivo \"\e[31;1m%s\e[0m\" n�o foi encontrado.\n", arg);
 				printf("\n");
				system("cd");
				printf("\e[1;93m > \e[0m");
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
 				printf("\n");
				system("cd");
				printf("\e[1;93m > \e[0m");
 			}

 			if (ret > 1)
 			{
 				printf("O arquivo \"\e[31;1m%s\e[0m\" n�o foi encontrado.\n", arg);
 				printf("\n");
				system("cd");
				printf("\e[1;93m > \e[0m");				
			}
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
 		printf("\n");
		system("cd");
		printf("\e[1;93m > \e[0m");
 		return 1;
 	}	

 	if (strcmp(cmd_text, "limpar") == 0)
 	{
 		system("cls");
 		printf("\n");
		system("cd");
		printf("\e[1;93m > \e[0m");
 		return 1;
 	}

 	printf("  \"\e[31;1m%s\e[0m\": comando n�o encontrado.\n", cmd_text);
 	printf("\n");
	system("cd");
	printf("\e[1;93m > \e[0m");
	return 0;
}
