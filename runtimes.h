#ifndef RUNT_H   //header guard
#define RUNT_H
#include <stdio.h>

void generate_random_runtimes(int arr[], unsigned long int n, int max_range, int output_to_file, FILE* outfile);
void generate_sequenced_runtimes(int arr[], unsigned long int n, int seq_start, int output_to_file, FILE* outfile);

#endif