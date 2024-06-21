#include <stdio.h>
#include <stdlib.h>

// Defining the structure for processes 

struct Process {
    int id;
    int arrival_time;
    int cpu_burst;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};
//Function to sort Processes according to their arrival times 
void sortProcesses(struct Process *Process)
{
}

// Function to calculate Turn Around Time
void calculateTurnaroundTime(struct Process *process) 
{
    process->turnaround_time = process->completion_time - process->arrival_time;
}

// Function to calculate Waiting Time
void calculateWaitingTime(struct Process *process) 
{
    process->waiting_time = process->turnaround_time - process->cpu_burst;
}

int main() 
{
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Declaring an array to strore all processes 
    struct Process processes[num_processes];

    // Input process details
    for (int i = 0; i < num_processes; i++) {
        printf("Enter details for process %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("CPU Burst Time: ");
        scanf("%d", &processes[i].cpu_burst);
    }

    // Calculate completion times
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].completion_time = current_time + processes[i].cpu_burst;
        current_time = processes[i].completion_time;
    }

    // Calculate turnaround time and waiting time for each process

    for (int i = 0; i < num_processes; i++) 
   {
        calculateTurnaroundTime(&processes[i]);
        calculateWaitingTime(&processes[i]);
    }

    // Print process details
    printf("\nProcess\tArrival Time\tCPU Burst\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < num_processes; i++) 
{
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
               processes[i].cpu_burst, processes[i].completion_time, processes[i].turnaround_time,
               processes[i].waiting_time);
    }

    return 0;
}
