/***
 *                $$\     $$\ $$\           
 *                $$ |    \__|$$ |          
 *    $$\   $$\ $$$$$$\   $$\ $$ | $$$$$$$\ 
 *    $$ |  $$ |\_$$  _|  $$ |$$ |$$  _____|
 *    $$ |  $$ |  $$ |    $$ |$$ |\$$$$$$\  
 *    $$ |  $$ |  $$ |$$\ $$ |$$ | \____$$\ 
 *    \$$$$$$  |  \$$$$  |$$ |$$ |$$$$$$$  |
 *     \______/    \____/ \__|\__|\_______/ 
 *                                          
 *                                          
 *                                          
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/minimanager.h"

/**
 * @brief Retornar um caractere.
 *
 * @return char Retorna o caractere digitado.
 *
 */
char
get_option()
{
	char option[50];

	setbuf(stdin, NULL); 
    fgets(option, sizeof(option), stdin);

    return option[0];
}

void
fprintc(char file_name[], int tam) 
{
	FILE *file = fopen(file_name, "r");
	char ch;
	while ((ch = fgetc(file)) != EOF) 
	{
		putchar(ch);
	}
	fclose(file);
}
