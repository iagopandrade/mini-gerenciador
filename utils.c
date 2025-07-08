#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int CommandText(char cmdtext[], int tam) {
	
	// Remove o "\n" que a função fgets() colocou
	cmdtext[strcspn(cmdtext, "\n")] = 0;
	
    char *arg;
	
	// Separa o argumento do comando (Comando: read; argumento: arquivo.txt)
    arg = strtok(cmdtext, " ");	
	
	if (strcmp(cmdtext, "read") == 0) {
		arg = strtok(NULL, " ");
		
		// Condição para verificar formatação (Está bugada)
		/*
		if(!strcspn(arg, "'!@#$%¨&*()+=´`^~{}[],;:/?|") == NULL) {
			printf("Formatação inválida\n");
			return 1;
		}
		*/
		ReadFile(arg, sizeof(arg)); 
		return 0; 	
	} 
	
	if (strcmp(cmdtext, "sair") == 0) {		
		Exit();  
	} 	
	
	else 
		printf("'%s' não é reconhecido como um comando do gerenciador.\n>> ", cmdtext);
}

// função para ler arquivos (Incompleto)
int ReadFile(char nameFile[], int tam) {
	FILE *fp;
	
	fp = fopen(nameFile, "a");
							
	while (fp == NULL) {
			printf("read 'nomedoarquivo.txt'\n", nameFile);		
			fp = fopen(nameFile, "a");
			return 1;
		}
		
		printf("'%s' foi aberto\n", nameFile);			
		return 0;
}

int Exit(void) {
	printf("Programa encerrado.\n");
	exit(0);
	return 0;
}
