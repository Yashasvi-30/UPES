/*Perform linear search and find the time required to search an element.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int *list, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (list[i] == x) {
            return i;
        }
    }

    return -1;
}

int main() {
    int list[100];
    int n;
   printf("Enter a number of elements : ");
  scanf("%d", &n);
    int x;
    double time_taken;

    // Create the list of elements
    for (int i = 0; i < n; i++) {
int number ;
     printf("Enter a number: ");
  scanf("%d", &number);


list[i]=number;
    }

    // Get the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &x);

    // Start the timer
   clock_t start = clock();

    // Do the linear search
    int index = linear_search(list, n, x);

    // Stop the timer
   clock_t end = clock();

    // Get the time taken
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the result
    if (index == -1) {
        printf("The element %d is not found in the list.\n", x);
    } else {
        printf("The element %d is found at index %d.\n", x, index);
    }
    printf("The time taken to search using linear search is: %lf seconds.\n", time_taken);

    return 0;
}
