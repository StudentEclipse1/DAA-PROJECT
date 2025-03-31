#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generate_n_rand_ints(int arr[], int n, int max_range) {
    //Assigns random values from the range [0, max_range] to arr 
    //max_range is inclusive, by default it is RAND_MAX defined in stdlib.h (usually same as INT_MAX)
    if(max_range > RAND_MAX) {
        fprintf(stderr, "Max range input is larger than the max for Random Integers (%d)", RAND_MAX);
        exit(1);
    }
    for(int i=0; i<n; i++) {
        arr[i] = rand() % max_range+1;      //Uses function rand() from stdlib.h
    }
}

void generate_n_sequence(int arr[], int n, int X) {
    //Assigns values to arr in a sequence starting from X to n.
    for(int i=0; i<n; i++) {
        arr[i] = X+i;
    }
}

void print_arr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b \n");
}

int main() {
    int *arr, n=100, max_range = RAND_MAX, sequence_start=1;

    arr = malloc(sizeof(int)*n);
    printf("Hello, World!, Rand Max: %d\n", RAND_MAX);

    generate_n_rand_ints(arr, n, max_range);
    printf("\nRandom Array:\n");
    print_arr(arr, n);

    generate_n_sequence(arr, n, sequence_start);
    printf("\nSequenced Array:\n");
    print_arr(arr, n);

    return 0;
}
