#include <stdio.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int completion_time;
    int turnaround_time;
} Process;

void sortProcessesByArrival(Process processes[], int n);
void calculateWaitingTime(Process processes[], int n);
void calculateTurnAroundTime(Process processes[], int n);
void calculateCompletionTime(Process processes[], int n);
void printTable(Process processes[], int n);

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter process ID: ");
        scanf("%d", &processes[i].pid);

        printf("Enter arrival time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
    }

    sortProcessesByArrival(processes, n);
    calculateWaitingTime(processes, n);
    calculateTurnAroundTime(processes, n);
    calculateCompletionTime(processes, n);

    printTable(processes, n);

    return 0;
}

void sortProcessesByArrival(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculateWaitingTime(Process processes[], int n) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int complete = 0, t = 0, min = 1e9, shortest = 0, finish_time, check = 0;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((processes[j].arrival_time <= t) && (remaining_time[j] < min) && remaining_time[j] > 0) {
                min = remaining_time[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        remaining_time[shortest]--;
        min = remaining_time[shortest];
        if (min == 0) {
            min = 1e9;
        }

        if (remaining_time[shortest] == 0) {
            complete++;
            finish_time = t + 1;
            processes[shortest].waiting_time = finish_time - processes[shortest].burst_time - processes[shortest].arrival_time;
            if (processes[shortest].waiting_time < 0) {
                processes[shortest].waiting_time = 0;
            }
        }
        t++;
    }
}

void calculateTurnAroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void calculateCompletionTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].completion_time = processes[i].turnaround_time + processes[i].arrival_time;
    }
}

void printTable(Process processes[], int n) {
    printf("\n\nTable:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
                                                processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time);
    }
}
