****0x16. C - Simple Shell****

***Background Context:
Write a simple UNIX command interpreter.

***Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

***General
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?

*****Requirement*****s
***General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

***List of allowed functions and system calls:
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

*****PROJECT BREAKDOWN*****

Simple flowchart:

Display prompt > Read User input > Parsing and Tokenizing user input > Executing command; handling built-in commands; handling errors Handling special characters >>>>

Break down of the project into smaller tasks to guide us through the implementation process. Here are the main steps involved in creating a simple shell:
1. Displaying a prompt: Write a function to display a prompt (e.g., "$") to indicate that the shell is ready to accept commands.

2. Reading user input: Implement a function to read input from the user. You can use getline() to read the input line by line.

3.Parsing the user input: Create a function to parse the user input into individual commands and arguments. You can use strtok() to split the input into tokens.

 4. Handling built-in commands: Identify built-in commands like "cd" “alias”, “exit” without arguments and implement separate functions to handle them. For example, when the user enters "cd directory", you should change the current working directory to "directory".

5. Executing external commands: Implement a function to execute external commands using the execve() system call. You will need to fork a child process and replace it with the desired command using execve(). The parent process should wait for the child process to complete.

6. Handle the PATH fork must not be called if the command doesn’t exist.

7. Handle Implementation of the env built-in, that prints the current environment.

8. Handling signals: Set up signal handlers to handle signals like Ctrl+C (SIGINT) and Ctrl+Z (SIGTSTP). You can use the signal() function to register signal handlers.

9. Handling input/output redirection: Detect and handle input/output redirection symbols ("<", ">", ">>") in the user input. For example, if the user enters "command > file.txt", you should redirect the command's output to the specified file.

10. Handling piping: Detect and handle pipe symbol ("|") in the user input. If the user enters "command1 | command2", you should connect the output of "command1" as the input of "command2".

11. Handling background processes: Implement the ability to run commands in the background by appending "&" at the end of the command. The shell should not wait for background processes to complete.

12. Exit command with arguments: Implement the ability to exit the shell when the user enters the "exit" command.

13. Memory management and cleanup: Make sure to free any dynamically allocated memory and handle any necessary cleanup before exiting the shell
**Flowchart

graph TD
A[Start] --> B(Display Prompt)
B --> C(Read User Input)
C --> D(Parse User Input)
D --> E(Handle Built-in Commands)
D --> F(Handle External Commands)
D --> G(Handle PATH)
D --> H(Handle Env Implementation)
D --> I(Handle Signals)
D --> j(Handle Input/Output Redirection)
D --> K(Handle Piping)
D --> L(Handle Background Processes)
D --> M(Exit Shell With Arguments)
D --> N(Memory Management and cleanup)
L --> O[End]
