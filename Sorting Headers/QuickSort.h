extern void swap(int *a, int *b);

int medianOfThree(int array[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (array[low] > array[mid])
        swap(&array[low], &array[mid]);
    if (array[low] > array[high])
        swap(&array[low], &array[high]);
    if (array[mid] > array[high])
        swap(&array[mid], &array[high]);

    swap(&array[mid], &array[high]);
    return array[high];
}


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
        medianOfThree(array, low, high);
        int p = partition(array, low, high);

        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }
}
