#Simple Shell Practise

##forking

When we use fork() a child process is created and starts executing the same lines
The child process executes alongside the main process at the same time
So when we use fork we have two processes are running
The fork() function returns the process ids
Everything before the fork() function is executed once but after the fork() function
everything gets executed twice
The ids returned by fork() are two... the 0 id always represents the child process and the other
one represents the main process
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