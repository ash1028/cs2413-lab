void selectionSort(int arr[], int size) {
    int i, j, min, temp;

    for (i = 0; i < size - 1; i++) {
        min = i;

        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}