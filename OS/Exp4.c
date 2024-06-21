//Program executing sleep command using getpid 
// sleep command is used to delay the execution of the program for the specified number of seconds provided in the argument.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
int my_pid;
// Get the process ID of the current process
my_pid = getpid();
printf("My PID is %d\n", my_pid);//printing the pid using function getpid

printf("Sleeping for 3 seconds\n");
sleep(3);//Main command for sleeping for 3 seconds
printf("After sleep\n");
return 0; }