#include <stdbool.h>

void bubbleSort(int arr[], int size) {
    int i;
    int j;
    int temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }
}

void bubbleSortOptimized(int arr[], int size) {
    int i;
    int j;
    int temp;
    bool swapped;

    for (i = 0; i < size - 1; i++) {

        swapped = false;

        for (j = 0; j < size - 1 - i; j++) {

            if (arr[j] > arr[j + 1]) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}