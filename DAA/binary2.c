/*1.Sort a given set of elements using bubble and selection sort and hence find the time required to sort elements. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort
void bubble_sort(int *list, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                // Swap the elements
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int *list, int n) {
    int min_index, temp;
    for (int i = 0; i < n - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (list[j] < list[min_index]) {
                min_index = j;
            }
        }
        // Swap the minimum element with the current element
        temp = list[i];
        list[i] = list[min_index];
        list[min_index] = temp;
    }
}

int main() {
    int list[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int x;
    double time_taken;

    // Create the list of elements
    for (int i = 0; i < n; i++) {
        int number;
        printf("Enter a number: ");
        scanf("%d", &number);
        list[i] = number;
    }

    clock_t start, end; // Initialize start and end here

    // Bubble Sort
    int bubble_sorted_list[100]; // Create a copy of the list for bubble sort
    for (int i = 0; i < n; i++) {
        bubble_sorted_list[i] = list[i];
    }
    start = clock();
    bubble_sort(bubble_sorted_list, n);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted list using Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", bubble_sorted_list[i]);
    }
    printf("\nTime taken for Bubble Sort: %lf seconds.\n", time_taken);

    // Selection Sort
    start = clock();
    selection_sort(list, n);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted list using Selection Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\nTime taken for Selection Sort: %lf seconds.\n", time_taken);

    return 0;
}
