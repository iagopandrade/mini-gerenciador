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

int main(void)
{
	setlocale(LC_ALL, "ptb");

	system("color 0F");

	printf("\e[1;93m\t\tTiaNFM\e[0m\n");
	printf("\e[1;97m\tTerminal file manager\e[0m\n");

	printf("\n\t-------------------------------------\n");
	printf("\t-------------------------------------\n");
	printf("\n");

	printf(" - ler  \tExibe o conte�do de um arquivo.\n");
	printf(" - limpar\tLimpa a tela.\n");
	printf(" - listar\tLista os diret�rios locais.\n");
	printf(" - sair \tEncerra o programa.\n");
	printf(" - editar\n\n");

	printf("\n");
	system("cd");
	printf("\e[1;93m > \e[0m");
	// Cria um la�o infinito, saindo apenas com o comando "sair"
	while (1) 
	{
		char input[50];

		// Limpa o buffer do teclado
		setbuf(stdin, NULL);
		fgets(input, sizeof(input), stdin);

		command_text(input, sizeof(input));
	}
	return 0;
}
