#include <stdio.h>
#include <string.h>

#include "utils.h"

int CommandText(char cmdtext[], int tam) {
	
	// Remove o "\n" que a função fgets() colocou
	cmdtext[strcspn(cmdtext, "\n")] = 0;
	
	if (strcmp(cmdtext, "teste") == 0) {
		printf("Testado\n");
	} 
	
	else 
		printf("'%s' não é reconhecido como um comando do gerenciador.\n", cmdtext);
}
// falta os return de termino e aviso
