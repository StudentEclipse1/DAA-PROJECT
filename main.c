#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Sorting Headers/HeapSort.h"
#include "Sorting Headers/Selection-Insertion.h"
#include "Sorting Headers/MergeSort.h"
#include "Sorting Headers/QuickSort.h"
#include "Sorting Headers/BubbleSort.h"
#include "runtimes.h"

#define DEFAULT_RUNS 5

int output_to_file=0, output_arr_to_file=0;
unsigned int seed;
int selection=1, insertion=1, bubble=1, merges=1, heap=1, quick=1;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Print out a usage if args were incorrect, or args was help
void print_usage(char *prog_name) {
    fprintf(stderr, "Usage: %s (-r | -s=<X>) [-m=<MAX_RANGE>] [-o='file-name'] [-p='file-name2'] [-i=<NUM_OF_RUNS>] [-f=<s|i|b|m|h|q>]<N>\n", prog_name);
    fprintf(stderr, "Gives the avg. execution time for Selection, Bubble, Insertion, Merge, Heap, and Quick sort on array specified by user.\n");
    fprintf(stderr, "Examples: %s -r -m=32768 -p='tests' 100\n", prog_name);
    fprintf(stderr, "          %s -s=20 -o='test.csv' -i=3 -f=hq 1000\n", prog_name);

    fprintf(stderr, "\n<N> = Number of integers to be sorted, must be positive.\n");
    fprintf(stderr, "<X> = The number the sequence starts from, must be positive.\n");
    fprintf(stderr, "<MAX_RANGE> = Specified max_range for array values, can be any positive number from 1 to INT_MAX.\n");
    fprintf(stderr, "'file-name' = Output file destination, must contain no whitespace and can include an extension (e.g. test.csv).\n");
    fprintf(stderr, "<NUM_OF_RUNS> = The number of runs the program will calculate the average runtime for, default is 5.\n");

    fprintf(stderr, "\n(OPTIONS)\n");
    fprintf(stderr, "\t-r Assigns random values to array from the range [0, <MAX_RANGE>], by default MAX_RANGE=INT_MAX.\n");
    fprintf(stderr, "\t-s Assigns the array with asequence of values starting from <X>.\n");
    fprintf(stderr, "\t-m Sets the limit for the array values.\n");
    fprintf(stderr, "\t-o Outputs the result into a desired file type, .csv recommended for convenient table formatting.\n");
    fprintf(stderr, "\t-p Output array values before and after sorting, file-name should not include extensions for this.\n");
    fprintf(stderr, "\t-i Set the number of runs to calculate average for.\n");
    fprintf(stderr, "\t-f Filter out the given sorting algorithms, s for selection, i for insertion and so on (can input multiple e.g. -f=ibh).\n");


    exit(1);
}

int main(int argc, char* argv[]) {
    int *arr, seq_start=1;
    int is_random=0, is_sequenced=0, num_of_runs=DEFAULT_RUNS;
    int i;
    unsigned long int n=0, max_range = RAND_MAX;
    FILE* outfile = NULL;
    char out_name[1000], arr_out_name[1000], filter[100];
    seed = time(NULL);  //init seed value

    //Check for leading '-' in argv to see user specification
    for(i=1; i<argc; i++) {
        
        if(*argv[i] != '-') {
            break;
        }

        switch(argv[i][1]) {
            case 'r':
                if(is_sequenced) {
                    fprintf(stderr, "Cannot have both random and sequenced values.\n");
                    exit(1);
                }
                is_random=1;

                break;
            case 's':
                if(is_random) {
                    fprintf(stderr, "Cannot have both random and sequenced values.\n");
                    exit(1);
                }
                is_sequenced=1;

                //Get the sequence start after the '=' sign
                if((sscanf(&(argv[i][2]), "=%d", &seq_start)) != 1) 
                    print_usage(argv[0]);
                if(n+(unsigned long) seq_start > __INT_MAX__) {
                    fprintf(stderr, "Input cannot have N(%lu) + X(%d) > INT+MAX (%d).\n", n, seq_start, __INT_MAX__);
                    exit(1);
                }

                break;
            case 'm':
                //Get the max range after the '=' sign
                if((sscanf(&(argv[i][2]), "=%lu", &max_range)) != 1) 
                    print_usage(argv[0]);
               
                break;
            case 'o':
                //Get the file name after the '=' sign
                output_to_file=1;
                if(( sscanf(&(argv[i][2]), "=%[^']", out_name)) != 1)  {
                    print_usage(argv[0]);
                }
                outfile = fopen(out_name, "w");
                break;
            case 'p':
                output_arr_to_file=1;
                if(( sscanf(&(argv[i][2]), "=%[^']", arr_out_name)) != 1)  {
                    print_usage(argv[0]);
                }
                break;
            case 'i':
                if((sscanf(&(argv[i][2]), "=%d", &num_of_runs)) != 1) 
                    print_usage(argv[0]);
                if(num_of_runs<=0)
                    print_usage(argv[0]);
                break;
            case 'f':
                if(( sscanf(&(argv[i][2]), "=%s", filter)) != 1) 
                    print_usage(argv[0]);
                for(char *s=filter; *s; s++) {
                    switch(*s) {
                        case 's':
                            selection=0;
                            break;  
                        case 'i':
                            insertion=0;
                            break;  
                        case 'b':
                            bubble=0;
                            break;  
                        case 'm':
                            merges=0;
                            break;  
                        case 'h':
                            heap=0;
                            break;  
                        case 'q':
                            quick=0;
                            break;  
                        default:
                            print_usage(argv[0]);
                    }
                }
                break;
            default:
                print_usage(argv[0]);
        }
    }

    //Ensure that user at least inputted N and the array orientation
    if(i>=argc)
        print_usage(argv[0]);

    if(!is_random && !is_sequenced)
        print_usage(argv[0]);

    //Read N
    sscanf(argv[i], "%lu", &n);
    if(n >__INT_MAX__) {
        fprintf(stderr, "N must be positive and less than INT_MAX(%d).\n", __INT_MAX__);
        exit(1);
    }

    arr = malloc(sizeof(int)*n);

    if(is_random) {
        generate_random_runtimes(arr, n, max_range, outfile, arr_out_name, num_of_runs);
    }

    if(is_sequenced) {
        generate_sequenced_runtimes(arr, n, seq_start, outfile, arr_out_name, num_of_runs);
    }

    if(outfile)
        fclose(outfile);
    return 0;
}