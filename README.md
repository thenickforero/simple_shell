# Simple Shell

## Project Overview:
This is a very simple clone of BASH based in C language and using the Linux Programming Interface.

The shell output is the exact same output as `sh` (`/bin/sh`) as well as the exact same error output excepting that when you print an error, the name of the program is `./hsh` instead of `sh`.

## Files

| File | Description |
| :------: | :------: |
|	AUTHORS			|	List of contributors to this repo				| 
|	README			|	Contains the basic info of the project and how to use it	|
|	man_1_simple_shell	|	Custom manual page for the simple_shell				|
|	prototype		|	Header file used throughout each file				|  
|	simple_shell		|	The entry point (main file)					|
|	funEnv			|	Functions that controls the environment 		variables												|
|	funPath			|	Functions that controls and traverse the PATH			|
|	funStr			|	Functions that manipulates strings text				|
|	funThread		|	Functions that executes certain command				|


## Functions

|	Functions		|	Description							|
|:------:|:------:|
|	_printenv			|	Print the enviroment variables of the shell				|
|	_getenv			|	Search the value of an enviroment variable			|
|	getstrtok		|	Parses the input to get the correct argv for execute the input command				|
|	_funValPath		|	Get the absolute path to the executable of the input command				|  
|	_strlen			|	Compute the length of a string					|
|	_strcmp			|	Compares two strings 		variables												|
|	_strconcat		|	Concatenates two strings					|
|	_strdup			|	Creates a duplicate of a string in a new space of memory				|
|	_strWrite		| Prints a string to STDOUT													|
|	createfork		|	Executes certain command in a new thread (child proccess)												|
|	funMain			|	Get the input from the shell promt and proccess it (Execute the command)												|
|	main			|	Checks if the shell is executed in interactive or non-interactive mode and prints the prompt										|

## INSTALLATION AND USAGE EXAMPLES

####  Build Process

1. Clone this repo with `git clone `
2. Go to the source directory using  `cd simple_shell`  
3. Compile all the source code files with `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
4. That's all, in the current directory will be created the executable file `hsh` with the simple shell.

#### Using simple shell in Interactive mode

1. Enter into the interactive mode with `./hsh`  after that you will see the prompt: ($) waiting for your input. 
2. Enter any command that you want, for example: `ls -l` and press enter.  
3. See the output of your command and the prompt will rise again.
4. Exit with the builtin command `exit` or with the `CTRL + D` or `CTRL + C` signals.  

#### Using simple shell in Non-Interactive mode
The shell can also be run like `sh` you online need to pipe it your input and it will execute your input and print the output to the stdout, for doing that you can do for example `echo "/bin/ls -la *.c" | ./hsh`
  
## Authors
[Yennifer Tobon Yate](https://twitter.com/TobonYennifer/)	-> Coding and Bugfixing



[Nicolas Forero Puello](https://twitter.com/F0R3R0X)		-> Documentation and Code Testing
