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

int ReadFile(char nameFile[], int tam) {
	FILE *file;	
	file = fopen(nameFile, "r");
	char fileContent[100];
	
	// Verifica se o usuário digitou o nome do arquivo
	if (nameFile == NULL) {
		printf("Digite: read [nomedoarquivo.txt]\n", nameFile);		
		file = fopen(nameFile, "r");
		return 1;
	// Verifica se o arquivo existe
	} if (file == NULL) {	
		printf("'%s' não existe.\n", nameFile);		
		file = fopen(nameFile, "r");
		return 1;
	}
		
	printf("O arquivo'%s' foi aberto\n", nameFile);	
	fscanf(file, "%s", fileContent);
	printf("%s\n", fileContent);		
	return 0;
}

int Exit(void) {
	printf("Programa encerrado.\n");
	exit(0);
	return 0;
}
