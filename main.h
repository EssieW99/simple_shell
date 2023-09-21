#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
int print_any_string(char *str);
int _putcharacter(char character);
void termination(void);
char *remove_newline(char *buffer);
void termination_child(void);
void tokenization_args(char *str, char **argument);
int executing(char *fullpath, char **arg, char **envp);
char *pathing(char *path, char *array);
char *fetch_location(char *array);
void free_args(char **arg);
void print_current_environment(void);
int other_commands(char **arg);
int _atoi(const char *str);





#endif
