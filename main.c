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
#include "src/utils.h"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "ptb");

	printf("Minigerenciador de Arquivos");
	system("cd");
	
	printf("\n");
	printf("Comandos adicionados:\n");
	printf("ler");
	printf("\tExibe o conteúdo de um arquivo.\n");
	printf("limpar");
	printf("\tLimpa a tela.\n");
	printf("sair");
	printf("\tEncerra o programa.\n");
	printf("\n");
	
	printf("Comandos em desenvolvimento:\n");
	printf("criar");
	
	printf("\n\n >");

	// Cria um laço infinito, saindo apenas com o comando 'sair'
	while (1) 
	{
		char cmd[50];
		
		// Limpa o buffer do teclado
		setbuf(stdin, NULL);
		fgets(cmd, sizeof(cmd), stdin);

		commandtext(cmd, sizeof(cmd));
		
		int i;
		for (i = 50; i > 0; i--)
			cmd[i] = 0;
	}
	return 0;
}
