extern void swap(int *a, int *b);
int partition(int array[], int start, int end){

    int pivot = array[end];
    int i = start-1;

    for (int j = start; j < end; j++){
        if (array[j]<pivot){
            i++;
            swap(&array[i],&array[j]);
        }
    }

    swap(&array[i+1],&array[end]);
    return (i+1);
}

void quickSort(int array[], int low, int high) {

    if (low < high) {
        int p = partition(array, low, high);

        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }
}
