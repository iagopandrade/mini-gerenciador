
/***
 *                           /$$                           /$$     /$$                    
 *                          | $$                          | $$    |__/                    
 *      /$$$$$$   /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$  /$$$$$$   /$$  /$$$$$$  /$$$$$$$ 
 *     /$$__  $$ /$$__  $$|_  $$_/   /$$__  $$ /$$__  $$|_  $$_/  | $$ /$$__  $$| $$__  $$
 *    | $$  \ $$| $$$$$$$$  | $$    | $$  \ $$| $$  \ $$  | $$    | $$| $$  \ $$| $$  \ $$
 *    | $$  | $$| $$_____/  | $$ /$$| $$  | $$| $$  | $$  | $$ /$$| $$| $$  | $$| $$  | $$
 *    |  $$$$$$$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$$$$$$/  |  $$$$/| $$|  $$$$$$/| $$  | $$
 *     \____  $$ \_______/   \___/   \______/ | $$____/    \___/  |__/ \______/ |__/  |__/
 *     /$$  \ $$                              | $$                                        
 *    |  $$$$$$/                              | $$                                        
 *     \______/                               |__/                                        
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/**
 * @brief Ler a escolha de uma opção.
 *
 * @return int Retorna 1 caso receba 's', 2 caso'N', 3 caso contrário.
 *
 */
int
getoption()
{
    char option[50];

    if (fgets(option, sizeof(option), stdin) == NULL)
	{
        return 3;
    }
				
    if (option[0] == '\n' || option[0] == '\0')
	{
        return 3;
    }
     
    switch (option[0])
    {
        case 's': return 1;
        case 'N': return 2;
        default: return 3;
    }
}
