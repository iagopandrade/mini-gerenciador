#include <stdio.h>
#include <string.h>

#include "utils.h"

int CommandText(char cmdtext[], int tam) {
	char *arg;
	// Teste
	int retorno;
	
	// Remove o "\n" que a função fgets() colocou
	cmdtext[strcspn(cmdtext, "\n")] = 0;
	
	// Separa o argumento do comando (Comando: read; argumento: arquivo.txt)
    arg = strtok(cmdtext, " ");	
	
	if (strcmp(cmdtext, "ler") == 0) {
		arg = strtok(NULL, " ");
		
		retorno = ReadFile(arg, sizeof(arg)); 
		if(retorno == 1) {
			printf("DEBUG :retorno %d\n", retorno);
			printf("Digite: read [nomedoarquivo.txt]\n");		
			//file = fopen(arg, "r");
			return 1;
		} if (retorno == 2) {
			printf("'%s' não existe.\n", arg);		
			//file = fopen(arg, "r");
			return 1;
		} 
		
		//debug
		printf("\n\n\nAbriu?\n\n\n");
		return 0; 	
	} 
	
	if (strcmp(cmdtext, "sair") == 0) {		
		Exit();  
	} 	
	
	else {
		printf("'%s' comando não encontrado\n> ", cmdtext);
	}

}
