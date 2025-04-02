#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "runtimes.h"

extern void selectionSort(int arr[], int N);
extern void insertionSort(int arr[], int N);
extern void modifiedBubbleSort(int arr[], int n);
extern void heapSort(int array[], int size);
extern void mergeSort(int arr[], int l, int r);
extern void quickSort(int array[], int low, int high);
extern int output_to_file;
extern int output_arr_to_file;
extern unsigned int seed;

//Assigns random values to arr from the range [0, max_range]
//max_range is inclusive, by default it is RAND_MAX defined in stdlib.h (usually same as INT_MAX)
void generate_n_randoms(int arr[], unsigned long int n, unsigned long int max_range) {
    srand(seed++);  //Give rand() a new seed each time this is called.
    if(max_range > RAND_MAX) {
        fprintf(stderr, "Max range input is larger than the max for Random Integers (%d)\n", RAND_MAX);
        exit(1);
    }
    for(unsigned long i=0; i<n; i++) {
        arr[i] = rand() % max_range+1;      //Uses function rand() from stdlib.h
    }
}

//Assigns values to arr in a sequence starting from X to n.
void generate_n_sequence(int arr[], unsigned long int n, int X) {
    for(unsigned long i=0; i<n; i++) {
        arr[i] = X+i;
    }
}

void print_arr_to_file(int arr[], unsigned long n, FILE* out) {
    for(unsigned long i=0; i<n; i++)
        fprintf(out, "%d, ", arr[i]);
    fprintf(out, "\n\n");
}

void generate_random_runtimes(int arr[], unsigned long int n, int max_range, FILE* outfile, char* arr_out_name) {
    //Computes the execution time for the 6 sort algos on random array input
    //Prints a table to terminal
    FILE* arr_outfile=NULL;
    char sort_out_name[1000];
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_selection.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Selection Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        selectionSort(arr, n);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_bubble.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Bubble Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        modifiedBubbleSort(arr, n);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_insertion.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Insertion Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        insertionSort(arr, n);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_heap.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Heap Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        heapSort(arr, n);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_merge.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Merge Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        mergeSort(arr, 0, n-1);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_quick.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Quick Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_randoms(arr, n, max_range);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        quickSort(arr, 0, n-1);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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

void generate_sequenced_runtimes(int arr[], unsigned long int n, int seq_start, FILE* outfile, char* arr_out_name) {
    //Computes the execution time for the 6 sort algos on sequenced array input
    //Prints a table to terminal
    FILE* arr_outfile;
    char sort_out_name[1000];
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_selection.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Selection Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        selectionSort(arr, n);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_bubble.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Bubble Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        modifiedBubbleSort(arr, n);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_insertion.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Insertion Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        insertionSort(arr, n);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_heap.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Heap Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        heapSort(arr, n);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_merge.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Merge Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        mergeSort(arr, 0, n-1);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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
    if(output_arr_to_file) {
        sprintf(sort_out_name, "%s%s", arr_out_name, "_quick.txt");
        arr_outfile = fopen(sort_out_name, "w");
        fprintf(arr_outfile, "Quick Sort, N=%lu\n", n);
    }
    for(int i=0; i<5; i++) {
        generate_n_sequence(arr, n, seq_start);
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Run %d Array:\n", i+1);
            print_arr_to_file(arr, n, arr_outfile);
        }
        start = clock();
        quickSort(arr, 0, n-1);
        end = clock();
        if(output_arr_to_file) {
            fprintf(arr_outfile, "Sorted Array:\n");
            print_arr_to_file(arr, n, arr_outfile);
        }
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