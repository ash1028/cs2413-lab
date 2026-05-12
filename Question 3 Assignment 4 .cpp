void swap(int arr[], int a, int b) {
    int temp;

    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr, i, j);
            i++;
        }
    }

    swap(arr, i, high);

    return i;
}

void quickSortPart(int arr[], int low, int high) {
    int p;

    if (low < high) {
        p = partition(arr, low, high);

        quickSortPart(arr, low, p - 1);
        quickSortPart(arr, p + 1, high);
    }
}

void quickSort(int arr[], int size) {
    if (size > 1) {
        quickSortPart(arr, 0, size - 1);
    }
}