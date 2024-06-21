//Program to execute a command 
/*The primary purpose of this program is to demonstrate the use of execlp to execute a command. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
printf("Executing ls command...\n");
// Execute the ls command using execlp
execlp("ls", "ls", "-l", NULL);

// If execlp returns, it means an error occurred
perror("execlp");
return 1; }

