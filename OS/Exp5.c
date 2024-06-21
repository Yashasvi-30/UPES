//Program to show execution of wait command
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() 
{
pid_t child_pid, parent_pid;
// Create a new process

child_pid = fork();
if (child_pid < 0) 
{
perror("Fork failed");
return 1; }

if (child_pid == 0) 
{
// This code is executed by the child process
printf("Child process: My PID is %d\n", getpid());
sleep(5);
printf("Child process completed");
exit(0);
} 
else 
{
// This code is executed by the parent process
printf("Parent process: Child PID is %d\n", child_pid);
int status;
// Wait for the child process to complete
wait(&status); 
//The wait function is called, and its result is stored in the status variable.
//After the child process terminates, the status variable will contain information about the child's termination status.

if (WIFEXITED(status)) {
printf("Parent process: Child exited with status %d\n", WEXITSTATUS(status));
} 
else if (WIFSIGNALED(status)) {
printf("Parent process: Child terminated by signal %d\n", WTERMSIG(status));
} 
}
return 0;
 }