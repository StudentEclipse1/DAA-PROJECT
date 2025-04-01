extern void swap(int *a, int *b);

void maxHeapify(int array[], int parentIndex, int length){

    int leftChildIndex = (2*parentIndex) + 1;
    int rightChildIndex = (2*parentIndex) + 2;
    int maxIndex = parentIndex;
    if (leftChildIndex < length && array[leftChildIndex] > array[parentIndex]){
        maxIndex = leftChildIndex;
    }

    if (rightChildIndex < length && array[rightChildIndex] > array[maxIndex]){
        maxIndex = rightChildIndex;
    }

    if (maxIndex != parentIndex){
        swap(&array[maxIndex], &array[parentIndex]);
        maxHeapify(array, maxIndex, length);
    }
}

void buildMaxHeap(int array[], int n){
    for(int i = (n/2)-1; i>=0; i--){
        maxHeapify(array, i, n);
    }
}

void heapSort(int array[], int size){

    buildMaxHeap(array, size);
    int heapSize = size-1;


    for (int i= heapSize ; i>0; i--){
        swap(&array[i], &array[0]);
        heapSize--;
        maxHeapify(array, 0, heapSize);
    }
}