void merge(int arr[], int left, int mid, int right) {
    int temp[100];
    int i = left;
    int j = mid + 1;
    int k = left;
    int x;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

void mergeSortPart(int arr[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;

        mergeSortPart(arr, left, mid);
        mergeSortPart(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int size) {
    if (size > 1) {
        mergeSortPart(arr, 0, size - 1);
    }
}