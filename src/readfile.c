#include <stdio.h>
#include <string.h>

#include "utils.h"

int ReadFile(char nameFile[], int tam) {
	// Variáveis de arquivos
	FILE *file;	
	file = fopen(nameFile, "r");
	
	// Variáveil para armazenar o conteúdo dos arquivos
	char fileContent[100];
	
	// Verifica se o usuário digitou o nome do arquivo
	if (nameFile == NULL) return 1; // Retorna 1, se o usuário não digitou o nome
		
	// Verifica se o arquivo existe
	if (file == NULL) return 2; // Retorna 2, se o arquivo não existir
		
	printf("Arquivo '%s'\n", nameFile);
	printf("Conteúdo: ");
	fscanf(file, "%s\n", fileContent);
	printf("%s\n", fileContent);		
	return 0; 
}

