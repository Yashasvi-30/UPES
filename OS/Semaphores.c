#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <semaphore.h> 
#define MAX_COUNT 1000000 
int shared_variable = 0; 
sem_t semaphore; 
void* incrementer(void* arg) { for (int 
i = 0; i < MAX_COUNT; i++) { 
sem_wait(&semaphore); 
shared_variable++; 
 sem_post(&semaphore); 
 } 
 pthread_exit(NULL); 
} 
int main() { 
sem_init(&semaphore, 0, 1); 
 pthread_t thread1, thread2; 
pthread_create(&thread1, NULL, incrementer, NULL); 
pthread_create(&thread2, NULL, incrementer, NULL); 
 pthread_join(thread1, NULL); 
pthread_join(thread2, NULL); 
 sem_destroy(&semaphore); 
 printf("Final value of shared variable: %d\n", shared_variable); 
 return 0; 
}