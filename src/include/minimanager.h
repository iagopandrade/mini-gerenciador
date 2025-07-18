#ifndef MINIMANAGER_H
#define MINIMANAGER_H

int command_text ( char cmd_text[], int tam );
int read_file ( char file_name[], int tam );
int write_file( char file_name[], int tam );
void fprintc( char file_name[], int tam );
char get_option();

#endif
