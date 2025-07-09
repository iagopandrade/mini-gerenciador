#include <stdio.h>
#include <string.h>

#include "utils.h"

int CommandText(char cmdtext[], int tam) {
	char *arg = NULL;
	
	// Remove o "\n" que a fun��o fgets() colocou
	cmdtext[strcspn(cmdtext, "\n")] = 0;
	
	// Separa o argumento do comando (Comando: read; argumento: arquivo.txt)
    arg = strtok(cmdtext, " ");	
	
	if (strcmp(cmdtext, "ler") == 0) {
		arg = strtok(NULL, " ");
		
		// Vari�vel para armazenar o retorno da fun��o
		int functionResult = NULL;

		functionResult = ReadFile(arg, sizeof(arg)); 
		
		if(functionResult != 0) {
			if(functionResult == 1) {
				printf("Digite: ler [nomedoarquivo.txt]\n");		
				//file = fopen(arg, "r");		
			} if (functionResult > 1) {
				printf("O arquivo '%s' n�o existe.\n", arg);		
				//file = fopen(arg, "r");
			}			
		} // else printf("O arquivo '%s' foi aberto.\n", arg);	 	
	
	return 1;	
	} 
	
	if (strcmp(cmdtext, "sair") == 0) {		
		Exit();  
	} 	
	
	else {
		printf("O comando '%s' n�o foi encontrado\n> ", cmdtext);
	}
	
	return 0;
}
