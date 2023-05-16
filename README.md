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


