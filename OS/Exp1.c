//Process Creation
/*
The fork() system call is used to create a new process.
If fork() returns a negative value, an error occurred.
If fork() returns 0, it means the current process is the child process.
If fork() returns a positive value, it is the process ID (PID) of the child process, and the current process is the parent process.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main () {
int child_pid;
child_pid = fork();//fork creates a new process
if (child_pid < 0) 
{
 //if fork() returns a negative number, it means child process could not be made
printf("Failed to create child process");
}

if (child_pid == 0) 
{
// This code is executed by the child process

printf("Child process: My PID is %d\n", getpid());

} 
else {

// This code is executed by the parent process
printf("Parent process: Child PID is %d\n", child_pid);
}

return 0;}