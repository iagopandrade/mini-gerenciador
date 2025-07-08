#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "utils.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");	
	
	char cmd[50];
	printf("Gerenciador de Arquivos\n");	
	printf("Digite 'ajuda' para ver a lista de comandos\n");
	printf("Comandos adicionados:\n");		
	printf("\t - read <arquivo.txt>\n");	
	printf("\t - sair\n>> ");			
	
	// Cria um laço infinito, saindo apenas com o comando 'sair'
	while (1) {
		
		// Limpa o buffer do teclado
		setbuf(stdin, NULL);
		fgets(cmd, sizeof(cmd), stdin);	
	
		CommandText(cmd, sizeof(cmd));		
	}
	
	return 0;
}
