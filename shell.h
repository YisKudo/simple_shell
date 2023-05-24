#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_LENGTH 100
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>


void tokenize_input(char *input, char **args);
void handle_exit_command(char **args, char *input);
int _atoi(char *s);
void execute_shell(int argc, char *argv[], char **env);
char *my_strchr(char *s, int c);
char *my_strncpy(char *dest, const char *src, size_t n);

void process_input(char *input, char *argv[], char **env);

void display_prompt(void);
void execute_command(char *command, char **args, char **env, char *pgrm_name);
int my_strncmp(const char *s1, const char *s2, size_t n);
size_t my_strlen(const char *s);
void my_strcpy(char *dest, const char *src);
void my_strcat(char *dest, const char *src);
char *my_getenv(char **env, char *name);
int my_strcmp(const char *s1, const char *s2);


#endif /* SHELL_H */

