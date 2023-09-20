#ifndef _SHELL_
#define _SHELL_

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <limits.h>

#define MAX_TOKENS 128
#define EXIT_STATUS_EOF 127
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/*Global declarations*/
extern char **environ;

/*String manipulation functions*/
size_t _strlen(const char *s);
char *_strdup(const char *command);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
int _atoi(char *s);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strcpy(char *dest, char *src);

/*Simple shell functions*/
void _print(const char *str);
void _prompt(void);
void _commands(char **command, char **env, int *sh_exit);
char *_input(void);
char **_parsetokens(const char *input);

/*Inbuilt commands*/
char *_getenv(const char *name);
void _cd_command(char **tokens);
void _exit_env(char **tokens, char **env, int sh_exit);
int printenvronment(char **_envir, int *_exit);
void _external_exec(char *tokens[], char **env);
void execute_command(const char *path, char *tokens[], char **env);
void locate_and_execute(char *tokens[], char **env);
char *locate(const char *name);
char *join_paths(const char sep, const char *path1, const char *path2);
int file_exists(const char *filepath);

/*cleanup*/
void cleanup_tokens(char **tokens);

/*Signals*/
void handlesigs(int sig);
int _ctrld(char *string, ssize_t read_result, int *exit_status);

/*Other inbuilts*/
int _setunsetenv(char **tokens);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void replacePID(char **tokens);

#endif
