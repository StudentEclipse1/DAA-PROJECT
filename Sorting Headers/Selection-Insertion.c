
// Blame me: Renz
// Di marunong mag header file

#include <time.h>
#include <stdio.h>

    clock_t start, end;
    double cpu_time_used;


void selectionSort(int arr[], int N) {

    start = clock();

    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
}

void insertionSort(int arr[], int N) {
    start = clock();

    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
}

int main(){
	start = 0;
	end = 0;
	cpu_time_used = 0;

	int arr[10]={10,100,1,2,3,50,0,55,3,70};

	selectionSort(arr,10);
	printf("%lds %lds: %fs\n",start,end,cpu_time_used);

	insertionSort(arr,10);
    printf("%lds %lds: %fs\n",start,end,cpu_time_used);

	return 0;
}