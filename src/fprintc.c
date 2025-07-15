/***
 *     $$$$$$\                     $$\            $$\               
 *    $$  __$$\                    \__|           $$ |              
 *    $$ /  \__|$$$$$$\   $$$$$$\  $$\ $$$$$$$\ $$$$$$\    $$$$$$$\ 
 *    $$$$\    $$  __$$\ $$  __$$\ $$ |$$  __$$\\_$$  _|  $$  _____|
 *    $$  _|   $$ /  $$ |$$ |  \__|$$ |$$ |  $$ | $$ |    $$ /      
 *    $$ |     $$ |  $$ |$$ |      $$ |$$ |  $$ | $$ |$$\ $$ |      
 *    $$ |     $$$$$$$  |$$ |      $$ |$$ |  $$ | \$$$$  |\$$$$$$$\ 
 *    \__|     $$  ____/ \__|      \__|\__|  \__|  \____/  \_______|
 *             $$ |                                                 
 *             $$ |                                                 
 *             \__|                                                 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/**
 * @brief Imprime o conteúdo de um arquivo.
 *
 * @param nameFile Nome do arquivo.
 * @param tam Tamanho do array nameFile.
 *
 */
void
fprintc(char nameFile[], int tam) 
{
	FILE *file = fopen(nameFile, "r");
	char ch;
	while ((ch = fgetc(file)) != EOF) 
	{
		putchar(ch);
	}
	fclose(file);
}
