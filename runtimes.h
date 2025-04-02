#ifndef RUNT_H   //header guard
#define RUNT_H
#include <stdio.h>

void generate_n_randoms(int arr[], unsigned long int n, unsigned long int max_range);
void generate_n_sequence(int arr[], unsigned long int n, int X);
void print_arr_to_file(int arr[], unsigned long n, FILE* out);
void generate_random_runtimes(int arr[], unsigned long int n, int max_range, FILE* outfile, char* arr_out_name, int num_of_runs);
void generate_sequenced_runtimes(int arr[], unsigned long int n, int seq_start, FILE* outfile, char* arr_out_name, int num_of_runs);

#endif