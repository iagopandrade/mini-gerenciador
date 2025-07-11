#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "src/utils.h"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Gerenciador de Arquivos\n\n");
	printf("Comandos adicionados:\n");
	printf("- ler[nome do arquivo]\n");
	printf("- sair\n");
	system("cd");
	printf(" > ");

	// Cria um laço infinito, saindo apenas com o comando 'sair'
	while (1) {
		char cmd[50];
		// Limpa o buffer do teclado
		setbuf(stdin, NULL);
		fgets(cmd, sizeof(cmd), stdin);

		command_text(cmd, sizeof(cmd));
	}
	return 0;
}
