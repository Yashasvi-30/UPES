//Program to execute sleep command 
/*This program is a simple example of using the sleep function to introduce a 
delay in the execution of a program. It's commonly used in scenarios 
where a program needs to wait for a specific amount of time before 
proceeding with the next set of instructions.*/

#include <stdio.h>
#include <unistd.h>
int main()
{
printf("Program to sleep for 5 second in my Macbook.\n");
sleep(5);
// after 5 seconds this next line will be executed.
printf("This line will be executed after 5 seconds");
return 0; }