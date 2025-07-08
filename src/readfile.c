#include <stdio.h>
#include <string.h>

#include "utils.h"

int ReadFile(char nameFile[], int tam) {
	// Variáveis de arquivos
	FILE *file;	
	file = fopen(nameFile, "r");
	
	// Variáveil para armazenar o conteúdo dos arquivos
	char fileContent[100];
	char *ReturnContent = fileContent;
	
	// Verifica se o usuário digitou o nome do arquivo
	if (nameFile == NULL) 
		return 1; // Retorna 1, se o usuário não digitou o nome
		
	// Verifica se o arquivo existe
	if (file == NULL) 
		return 2; // Retorna 2, se o arquivo não existir

	// Precisa retornar o fileContet para o comparador de cmds		
	printf("O arquivo'%s' foi aberto\n", nameFile);	
	fscanf(file, "%s", fileContent);
	printf("%s\n", fileContent);		
	return 0;
}

// bugada, vou resolver depois
// Condição para verificar formatação (Está bugada)
		/*
		if(!strcspn(arg, "'!@#$%") == NULL) {
			printf("Formatação inválida\n");
			return 1;
		}
		*/
