		ALX SIMPLE SHELL TEAM PROJECT

CONTRIBUTORS;	 IYENAGBE RAYMOND OGEYANOR:
		 OKON PATIENCE IMA-OBONG:

This Project Was Written Using C Programming Language Shell Betty Linter
General Requirement for project;

* All files are compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89.
* All files ended with a new line.
* A README.md file was created at the root of the folder of the project.
* Betty style was use in the code as demanded by Alx and will be checked using betty-style.pl and betty-doc.pl.
* All header files  include Guarded.
* 

- hsh is a simple UNIX command.
(How hsh works) it Prints a prompt and waits for a command from the user.
Creates a child process in which the command is Checks for builtins, aliases in the PATH,
and local executable programs The child process is replaced by the command, 

When a user opens a shell it known as the parent process (PPID). 
The program you will execute is called the child-process (PID).

When a child-process (PID) is been executed the parent (PPID) has to wait,
and the parent-process will take over again 

