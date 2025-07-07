#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "utils.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");	
	
	char cmd[10];
	//printf("Gerenciador de Arquivos\n");	
	//printf("Digite 'ajuda' para ver a lista de comandos\n");	
		
	printf("Primeiro comando: 'teste'\n>> ");	
			
	// Limpa o buffer do teclado
	setbuf(stdin, NULL);
	fgets(cmd, sizeof(cmd), stdin);	
	
	CommandText(cmd, sizeof(cmd));
			
	system("pause");
	return 0;
}
