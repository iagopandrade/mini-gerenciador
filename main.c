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

	system("color 0F");
	
	printf("\e[1;93m\t\tTiaNFM\e[0m\n");
	printf("\e[1;97m\tTerminal Console Manager\e[0m\n");

	printf("\n");
	printf(" Comandos adicionados:\n");
	printf(" - ler  \tExibe o conteúdo de um arquivo.\n");
	printf(" - limpar\tLimpa a tela.\n");
	printf(" - listar\tLista os diretórios locais.\n");
	printf(" - sair \tEncerra o programa.\n");
	printf("\n");
	
	printf(" Comandos em desenvolvimento:\n");
	printf(" - editar\n\n");
	
	printf("\n");
	system("cd");
	printf("\e[1;93m  > \e[0m");
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
