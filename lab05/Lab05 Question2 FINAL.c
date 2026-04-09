#include <stdlib.h>

static void swap(int* a, int* b);
static void heapifyUp(int* heap, int i);
static void heapifyDown(int* heap, int size, int i);

int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = malloc(sizeof(int) * k);
    int size = 0;

    for (int i = 0; i < numsSize; i++) {

        if (size < k) {
            heap[size] = nums[i];
            heapifyUp(heap, size);
            size++;
        }
        else {
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                heapifyDown(heap, size, 0);
            }
        }
    }

    int result = heap[0];
    free(heap);
    return result;
}

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyUp(int* heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i]) {
            break;
        }

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

static void heapifyDown(int* heap, int size, int i) {
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}