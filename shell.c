#include <shell.h>
#include <prompt.h>
#include <execute.h>

int main(void)
{
     char *command = NULL;
     size_t bufsize = 0;

     while (1)
     {
          display_prompt();
          getline(&command, &bufsize, stdin);

          if (strcmp(command, "exit\n") == 0)
          {
               free(command);
               exit(EXIT_SUCCESS);
          }

          execute_command(command);
     }

     return (0);
}