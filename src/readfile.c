#include <stdio.h>
#include <string.h>

#include "utils.h"

int ReadFile(char nameFile[], int tam) {
	// Vari�veis de arquivos
	FILE *file;	
	file = fopen(nameFile, "r");
	
	// Vari�veil para armazenar o conte�do dos arquivos
	char fileContent[100];
	char *ReturnContent = fileContent;
	
	// Verifica se o usu�rio digitou o nome do arquivo
	if (nameFile == NULL) 
		return 1; // Retorna 1, se o usu�rio n�o digitou o nome
		
	// Verifica se o arquivo existe
	if (file == NULL) 
		return 2; // Retorna 2, se o arquivo n�o existir

	// Precisa retornar o fileContet para o comparador de cmds		
	printf("O arquivo'%s' foi aberto\n", nameFile);	
	fscanf(file, "%s", fileContent);
	printf("%s\n", fileContent);		
	return 0;
}

// bugada, vou resolver depois
// Condi��o para verificar formata��o (Est� bugada)
		/*
		if(!strcspn(arg, "'!@#$%") == NULL) {
			printf("Formata��o inv�lida\n");
			return 1;
		}
		*/
