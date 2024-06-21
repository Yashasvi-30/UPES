#include <stdio.h> 
#define MAX_PROCESSES 5 
#define MAX_RESOURCES 3 
int available[MAX_RESOURCES]; int 
maximum[MAX_PROCESSES][MAX_RESOURCES]; int 
allocation[MAX_PROCESSES][MAX_RESOURCES]; int 
need[MAX_PROCESSES][MAX_RESOURCES]; 
int is_safe(int process, int request[]) { for (int i = 0; i < 
MAX_RESOURCES; i++) { if (request[i] > 
need[process][i] || request[i] > available[i]) return 0; 
 } 
 return 1; 
} 
void request_resources(int process, int request[]) { 
if (is_safe(process, request)) { 
    for (int i = 0; i < MAX_RESOURCES; i++) {
         available[i] -= request[i]; allocation[process][i] += 
request[i]; 
 need[process][i] -= request[i]; 
 } 
 printf("Resource request granted.\n"); 
 } else { 
 printf("Resource request denied. System not in a safe state.\n"); 
 } 
} 
void release_resources(int process, int release[]) { 
 for (int i = 0; i < MAX_RESOURCES; i++) { 
available[i] += release[i]; allocation[process][i] -= release[i]; 
 need[process][i] += release[i]; 
 } 
} 
void display_state() { printf("Available resources: ");
 for (int i = 0; i < MAX_RESOURCES; i++) {
     
 printf("\n"); 
 printf("Maximum resources:\n"); for (int i = 0; i < MAX_PROCESSES; i++) { for (int j = 0; j < MAX_RESOURCES; j++) { 
printf("%d ", maximum[i][j]); 
 } 
 printf("\n"); 
 } 
 printf("Allocation:\n"); for (int i = 0; i < MAX_PROCESSES; i++) { for (int j = 0; j <MAX_RESOURCES; j++) { 
 printf("%d ", allocation[i][j]); 
 } 
 printf("\n"); 
 } 
 printf("Need:\n"); for (int i = 0; i < MAX_PROCESSES; i++) { for (int j = 0; j < MAX_RESOURCES; j++) { 
 printf("%d ", need[i][j]); 
 } 
 printf("\n"); 
 } 
} 
int main() { 
    printf("Enter available resources for each type:\n"); for (int i = 0; i < MAX_RESOURCES; i++) { 
 scanf("%d", &available[i]); 
 } 
 printf("Enter maximum resources for each process:\n"); 
for (int i = 0; i < MAX_PROCESSES; i++) { 
printf("For Process %d: ", i); for (int j = 0; j < MAX_RESOURCES; j++) { scanf("%d", 
&maximum[i][j]); 
 need[i][j] = maximum[i][j]; 
 } 
 } 
 int process; 
 printf("Enter process number making request: "); 
scanf("%d", &process); 
 int request[MAX_RESOURCES]; 
 printf("Enter request for each resource type: "); 
for (int i = 0; i < MAX_RESOURCES; i++) { 
 scanf("%d", &request[i]); 
 } 
 request_resources(process, request); 
 display_state(); 
 
 return 1; 

