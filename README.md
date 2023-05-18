#Simple Shell Practise

##forking

When we use fork() a child process is created and starts executing the same lines
The child process executes alongside the main process at the same time
So when we use fork we have two processes are running
The fork() function returns the process ids
Everything before the fork() function is executed once but after the fork() function
everything gets executed twice
If fork() fails it returns -1, therefore to check if the fork function 
is successfull , we do this

pid_t id = fork();

if (id == -1)
{
	perror("Unsuccessfull\n");
}
else
{
	printf("Successful");
}

The fork() function returns the child process id
Every process has a process id
to count the number of process = 2^n
How to create just three processes
int id = fork();
if (id != 0)
{
    fork();
}


each process gets a copy of the environmental variables ...if we change an environmental variable in one 
process it wont reflect on the other one

parent process:
argc = 1 , argv="main.exe"

child process:
argc = 1; argv="main.exe"

Both executions are executed parallel to each other unless we have a wait()
function that pauses the main process execution until we are done executing the 
child process then the parent process is executed

QUESTIONS

1. What is a process Identifer PID and Parent process Identifer PPID?
A process is an instance of an executing program that has a unique id
a process is basically a program in execution

2. What is the pid_t data type?
the oid_t data type is a signed integer type which is capable of representing process IDS

3. What is a Parent process?
a parent process is the process that creates a child process

4. PPID
ppid is the parent process identifier
and we use getppid() to get it

If two programs have the same ppids it means that they share a single parent and 
in these instance the programs that are  being executed share the same shell instance
hence the same ppids

how to check the current shell id : echo $$

The ps command lists out the current processes that are running in the terminal

5. The Oprhan process
This is a running process whose parent has finished or teminated
It basically means that the parent terminated before the child

6. Init process
Init is the parent of all processes, executed by the kenel during the booting of the system
it has a pid of 1

6. The process table
The process table is a data structure in the RAM of the computer that holds info about the processes currently being handled by the OS

6. Process Entry
This is created when the process is creatd by a fork() system call

7. Zombie process
This is when the child terminates before the parent

8. Wait system call
All of these system calls are used to wait for state changes in a child of the calling process,
and obtain information about the child whose state has been changed.
A state change is considered to be:
i. The child is terminated
ii. The child was stopped by a signal
iii. The child was resumed by a signal
In case of a terminated child, performing a wait allows the system to release the resources associated with the child.
When a wait is not performed then the terminated child remains in the zombie state

9. execve
execve helps in program execution
int execve(const char *filename, char *const argv[], char *const envp[]);
filename=a binary executable or a script starting with a line of the form: #! interpreter[]
argv=an array of string arguments
envp=must be terminated by a NULL pointer

10. getline() function
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
stream = where to read our text from eg keyboard hence you will use stdin
n=size of the buffer created to store the text from standard input
**lineptr = used to store the address of the buffer that was created to store the text from the 
stardard input

11. strtok() function
The strtok() functions extracts tokens from strings
char *strtok(char *str, const char *delim);
str-the string that we are checking
delim- what is separating the text stream

12. Commandline arguements
These are arguements passed from the commandline to the c program when they are executed

13. Arguement Count (argc):
The number of commandline arguements passed by the user including the name of the program

14. Arguement Vectors (argv):
This is a null terminated array of stringd (charater pointers) used to store the entire list
of the commandline arguements

15. Commandline arguements
The shell environment is a REPL-> Read, Evaluate, Print, Loop
prompt-> read input
after enter-> the read input is evaluated
print-> The output from the evaluation is printed out to the terminal
Loop->We loop back again and prompt the user for another input
