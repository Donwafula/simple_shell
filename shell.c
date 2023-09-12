#include "shell.h"

void execute_command(char *command)
{
     pid_t pid;
     int status;

     pid = fork();

     if (pid == -1)
     {
          perror("fork");
          exit(EXIT_FAILURE);
     }
     else if (pid == 0)
     {
          // Child process
          char *argv[] = {command, NULL};
          if (execve(command, argv, NULL) == -1)
          {
               perror("execve");
               exit(EXIT_FAILURE);
          }
     }
     else
     {
          // Parent process
          wait(&status);
     }
}
