#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFERSIZE 10

int n, empty, full = 0, item, item1;
int buffer[BUFFERSIZE];
int in = 0, out = 0, mutex = 1;

void my_wait(int *s)
{
    while (*s <= 0)
    {
        printf("\n Cannot Add an item !");
        exit(0);
    }
    (*s)--;
}

void my_signal(int *s)
{
    (*s)++;
}

void producer()
{
    do
    {
        my_wait(&empty);
        my_wait(&mutex);
        printf("\n Enter an Item : ");
        scanf("%d", &item);
        buffer[in] = item;
        in = (in + 1) % n;
        my_signal(&mutex);
        my_signal(&full);

    } while (in < n);
}

void consumer()
{
    do
    {
        my_wait(&full);
        my_wait(&mutex);
        item1 = buffer[out];

        printf("\n Consumed Item is : %d", item1);
        out = (out + 1) % n;
        my_signal(&mutex);
        my_signal(&empty);

    } while (out < n);
}

int main()
{
    printf("\n Enter the Value of N :");
    scanf("%d", &n);
    empty = n;

    while (in < n)
        producer();

    while (out < n)
        consumer();

    return 0;
}
