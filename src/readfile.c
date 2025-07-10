#include <stdio.h>
#include <string.h>
#include "utils.h"

/**
 * @brief Ler um arquivo.
 *
 * @param nameFile Nome do arquivo.
 * @param tam Tamanho do array nameFile.
 *
 * @return int Retorna 1 se não receber parâmetro, 2 caso o parâmetro seja inválido.
 *
 */
int ReadFile(char nameFile[], int tam) {
	FILE *file = fopen(nameFile, "r");
	char fileContent;

	if (nameFile == NULL) return 1;

	if (file == NULL) return 2;
	else {
		printf("Arquivo '%s'\n", nameFile);
		printf("------------------------------------------------------------\n");
		while ((fileContent = fgetc(file)) != EOF)
			putchar(fileContent);

		fclose(file);

		printf("\n------------------------------------------------------------");
		printf("\n\n\nArquivo '%s' foi fechado\n > ", nameFile);
	}
	return 0;
}
