void insertionSort(int arr[], int size) {
    int i, j, current;

    for (i = 1; i < size; i++) {
        current = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}