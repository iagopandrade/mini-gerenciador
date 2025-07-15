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
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#ifndef UTILS_H
#define UTILS_H

int commandtext ( char [], int );
int readfile ( char [], int );
int writefile( char [], int );

void printcf( char[], int );
int getoption();

#endif
