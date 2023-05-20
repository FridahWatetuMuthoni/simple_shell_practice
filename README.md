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

16. System Calls
Linux System Calls
System calls provided by the linux kernel are exposed in the C programming language via glibc. When
a system call is used, you are communicating to the OS and on return the OS communicates to you
thru the parameters that are returned to system call functions (return values).

Stat System Call:
stats system call is system call in linux to check the status of a file such as to check when the file was accessed. The stat() system call actually returns file attributes. The file attributes of 
an inode are basically returned by stat() function. An inode contains the metadata of the file. An inode contains: the type of the file, the size of the file, when the file was accesed (modified, deleted) that is time stamps, and the path of the file, the user ID and the group ID, links of the file and physical address of the file content.
syntax:
int stat(const char *path, struct stat *buff)
1. st_dev:its the ID of the device in which we have our file residing currently
2. st_rdev:this filed describes that a particular file represents a particular device
3. st_ino:it is the inode number or the serial number of the file
4. st_size: st_size is the size of the file in bytes
5. st_atime:its is the last time or the recent time at which the file was accessed
6. st_ctime: it is the recent time at which the status or the permissins of the file was changed
7. st_mtime:it is the recent time at whic the file was modified
8. st_blksize: this field gives the preffered block size for I/O file system which may vary from file to file
9. st_blocks: this field tells the total number of blocks in multiples of 512 bytes
10. st_nlink: this is the field that tells the total number of hard links
11. st_uid: this field indicates the user ID
12. st_gid: This field indicates the group ID
13. st_mode: it indicates the permissions of the file, tells the modes on the file. following are the flags that should be defined for st_mode field

17. snprintf() function

`snprintf(filename, sizeof(filename), "%s/%s", token, argv[1]);`

`snprintf` is a function in C that is used to format a string and store it in a buffer. It allows you to specify the maximum length of the buffer to prevent buffer overflow. In this case, the buffer is `filename`, and its size is determined by `sizeof(filename)`.

The format string `"%s/%s"` is used to define the desired format of the resulting string. It consists of two format specifiers `%s`, which are placeholders for strings. The first `%s` corresponds to `token`, and the second `%s` corresponds to `argv[1]`.

`token` is a string that contains an individual directory path obtained by tokenizing the PATH environment variable. It represents one of the directories in which the program will search for the file.

`argv[1]` is a string representing the filename provided as a command-line argument to the program.

By using `snprintf`, the line of code combines the `token` (directory path) and `argv[1]` (filename) into a single string, separated by a forward slash (`/`). The resulting string is stored in the `filename` buffer, ensuring that it does not exceed the size of the buffer.

For example, if `token` is "/usr/local/bin" and `argv[1]` is "myfile.txt", the `snprintf` line will create the full path to the file: "/usr/local/bin/myfile.txt", which is then stored in the `filename` buffer.

This full path is used later in the program to attempt to open the file and check if it exists in that location.
