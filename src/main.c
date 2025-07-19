/***
 *                  $$\           $$\                                                                     $$\                 $$\                     
 *                  \__|          \__|                                                                    \__|                $$ |                    
 *    $$$$$$\$$$$\  $$\ $$$$$$$\  $$\          $$$$$$\   $$$$$$\   $$$$$$\   $$$$$$\  $$$$$$$\   $$$$$$$\ $$\  $$$$$$\   $$$$$$$ | $$$$$$\   $$$$$$\  
 *    $$  _$$  _$$\ $$ |$$  __$$\ $$ |$$$$$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  _____|$$ | \____$$\ $$  __$$ |$$  __$$\ $$  __$$\ 
 *    $$ / $$ / $$ |$$ |$$ |  $$ |$$ |\______|$$ /  $$ |$$$$$$$$ |$$ |  \__|$$$$$$$$ |$$ |  $$ |$$ /      $$ | $$$$$$$ |$$ /  $$ |$$ /  $$ |$$ |  \__|
 *    $$ | $$ | $$ |$$ |$$ |  $$ |$$ |        $$ |  $$ |$$   ____|$$ |      $$   ____|$$ |  $$ |$$ |      $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |$$ |      
 *    $$ | $$ | $$ |$$ |$$ |  $$ |$$ |        \$$$$$$$ |\$$$$$$$\ $$ |      \$$$$$$$\ $$ |  $$ |\$$$$$$$\ $$ |\$$$$$$$ |\$$$$$$$ |\$$$$$$  |$$ |      
 *    \__| \__| \__|\__|\__|  \__|\__|         \____$$ | \_______|\__|       \_______|\__|  \__| \_______|\__| \_______| \_______| \______/ \__|      
 *                                            $$\   $$ |                                                                                              
 *                                            \$$$$$$  |                                                                                              
 *                                             \______/                                                                                               
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "include/minimanager.h"

int main( void )
{
	setlocale(LC_ALL, "ptb");

	system("color 0F");

	printf("\e[1;93m\t\tTiaNFM\e[0m\n");
	printf("\e[1;97m\tTerminal file manager\e[0m\n");

	printf("\n\t-------------------------------------\n");
	printf("\t-------------------------------------\n");
	printf("\n");

	printf(" - * Em Desenvolvimento\n");
	printf(" - limpar\tLimpa a tela.\n");
	printf(" - sair \tEncerra o programa.\n\n");

	printf("Arquivos e Diret�rios\n\n");
	printf(" - * criar\tCria diret�rios e arquivos.\n");
	printf(" - editar\tModifica o cont�udo de um arquivo.\n");
	printf(" - ler  \tExibe o conte�do de um arquivo.\n");
	printf(" - listar\tLista os diret�rios locais.\n");
	printf(" - * remover\tRemove diret�rios e arquivos\n");
	printf(" - * renomear\tModifica o nome de diret�rios e arquivos.\n\n");

//	Cria um la�o infinito, saindo apenas com o comando "sair"
	while (1) 
	{
//		printf("\n");
		system("cd");
		printf("\e[1;93m > \e[0m");
		
		char input[50];
		fgets(input, sizeof(input), stdin);
		
//		Remove o "\n" do ENTER
	 	input[strcspn(input, "\n")] = 0;
	 	
		if (strlen(input) == 0) 
		{
//			void
//			i++ Condi��o para for�ar uma a��o: exibir um aviso, aplicar delay, encerrar o programa, etc
		}
		else
		{
			if( command_text(input, sizeof(input)) == 1)
			{
//				void
//				printf("Comando executado com sucesso!\n");
			}
			else
			{
				printf("  \"\e[31;1m%s\e[0m\": comando n�o encontrado.\n", input);
//				printf("  %s: comando n�o encontrado.\n", input);
			}	
		}
	}
	return 0;
}
