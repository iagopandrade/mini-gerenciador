#include <stdio.h>
#include <string.h>
#include "utils.h"

/**
 * @brief Compara comandos.
 *
 * Esta fun��o compara uma string com um comando interno.
 *
 * @param cmdtext Comando digitado pelo usu�rio.
 * @param tam Tamanho do array cmdtext.
 *
 * @return int Retorna 1 se o comando for executado.
 *
 */
int CommandText(char cmdtext[], int tam)
{
	char *arg = NULL;

	// Vari�vel para armazenar o retorno da fun��o
	int functionResult = NULL;

	// Remove o "\n" que a fun��o fgets() colocou
	cmdtext[strcspn(cmdtext, "\n")] = 0;

	// Separa o argumento do comando (Comando: read; argumento: arquivo.txt)
	arg = strtok(cmdtext, " ");

	if (strcmp(cmdtext, "ler") == 0) {
		arg = strtok(NULL, " ");

		functionResult = ReadFile(arg, sizeof(arg));

		if (functionResult != 0) {
			if (functionResult == 1) {
				printf("Digite: ler[nomedoarquivo.txt]\n > ");
			}

			if (functionResult > 1) {
				printf("O arquivo '%s' n�o existe.\n > ", arg);
			}
		}
		return 1;
	}

	if (strcmp(cmdtext, "sair") == 0) {
		Exit();
	}

	if (strcmp(cmdtext, "cls") == 0) {
		system("cls");
		return 1;
	}
	
	else {
		printf("O comando '%s' n�o existe!", cmdtext);
		printf("\n\n > ");
	}
}
