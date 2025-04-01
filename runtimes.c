#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "runtimes.h"

extern void generate_n_randoms(int arr[], unsigned long int n, unsigned long int max_range);
extern void selectionSort(int arr[], int N);
extern void insertionSort(int arr[], int N);
extern void modifiedBubbleSort(int arr[], int n);
extern void heapSort(int array[], int size);
extern void mergeSort(int arr[], int l, int r);
extern void quickSort(int array[], int low, int high);
extern void generate_n_sequence(int arr[], unsigned long int n, int X);

void generate_random_runtimes(int arr[], unsigned long int n, int max_range, int output_to_file, FILE* outfile) {
    //Computes the execution time for the 6 sort algos on random array input
    //Prints a table to terminal
    printf("\tResult of the Experiment for RANDOM input: N=%lu\n", n);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    printf("| Sorting Algorithm |    Run 1    |    Run 2    |    Run 3    |    Run 4    |    Run 5    | Avg. Time for N = %lu\n", n);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    if(output_to_file) {
        fprintf(outfile, "Result of the Experiment for RANDOM input: N=%lu\n", n);
        fprintf(outfile, "Sorting Algorithm,Run 1,Run 2,Run 3,Run 4,Run 5,Avg. Time for N = %lu\n", n);
    }
    clock_t start, end;
    double cpu_time_used, total_used=0.0;

    printf("| Selection Sort    | ");
    if(output_to_file) fprintf(outfile, "Selection Sort,");
    //Selection Sort
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        start = clock();
        selectionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Bubble Sort       | ");
    if(output_to_file) fprintf(outfile, "Bubble Sort,");
    //Bubble Sort
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        start = clock();
        modifiedBubbleSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Insertion Sort    | ");
    if(output_to_file) fprintf(outfile, "Insertion Sort,");
    //Insertion Sort
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        start = clock();
        insertionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Heap Sort         | ");
    if(output_to_file) fprintf(outfile, "Heap Sort,");
    //Heap Sort
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        start = clock();
        heapSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Merge Sort        | ");
    if(output_to_file) fprintf(outfile, "Merge Sort,");
    //Merge Sort  
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        start = clock();
        mergeSort(arr, 0, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Quick Sort        | ");
    if(output_to_file) fprintf(outfile, "Quick Sort,");
    //Quick Sort  
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        start = clock();
        quickSort(arr, 0, n-1);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;
}

void generate_sequenced_runtimes(int arr[], unsigned long int n, int seq_start, int output_to_file, FILE* outfile) {
    //Computes the execution time for the 6 sort algos on sequenced array input
    //Prints a table to terminal
    printf("\tResult of the Experiment for SEQUENCED input: N=%lu\n", n);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    printf("| Sorting Algorithm |    Run 1    |    Run 2    |    Run 3    |    Run 4    |    Run 5    | Avg. Time for N = %lu\n", n);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    if(output_to_file) {
        fprintf(outfile, "Result of the Experiment for SEQUENCED input: N=%lu\n", n);
        fprintf(outfile, "Sorting Algorithm,Run 1,Run 2,Run 3,Run 4,Run 5,Avg. Time for N = %lu\n", n);
    }
    clock_t start, end;
    double cpu_time_used, total_used=0.0;

    printf("| Selection Sort    | ");
    //Selection Sort
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        start = clock();
        selectionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Bubble Sort       | ");
    if(output_to_file) fprintf(outfile, "Bubble Sort,");
    //Bubble Sort
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        start = clock();
        modifiedBubbleSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Insertion Sort    | ");
    //Insertion Sort
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        start = clock();
        insertionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Heap Sort         | ");
    //Heap Sort
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        start = clock();
        heapSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Merge Sort        | ");
    //Merge Sort
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        start = clock();
        mergeSort(arr, 0, n);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;

    printf("| Quick Sort        | ");
    //QuickSort
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        start = clock();
        quickSort(arr, 0, n-1);
        end = clock();
        cpu_time_used = ((double) (end-start))/CLOCKS_PER_SEC;
        printf("%10lfs | ", cpu_time_used);
        if(output_to_file) fprintf(outfile, "%lf,", cpu_time_used);
        total_used += cpu_time_used;
    }
    printf("%lfs\n", total_used/5);
    if(output_to_file) fprintf(outfile, "%lf\n", total_used/5);
    printf("+-------------------+-------------+-------------+-------------+-------------+-------------+\n");
    total_used=0.0;
}