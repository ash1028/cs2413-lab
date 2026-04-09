#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

static int hash(int key);
static void insert(Node* table[], int key, int value);
static int find(Node* table[], int key, int* value);
static void freeTable(Node* table[]);

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[TABLE_SIZE] = {0};
    int i;

    for (i = 0; i < numsSize; i++) {
        int need = target - nums[i];
        int index;

        if (find(table, need, &index)) {
            int* ans = (int*)malloc(2 * sizeof(int));
            ans[0] = index;
            ans[1] = i;
            *returnSize = 2;
            freeTable(table);
            return ans;
        }

        insert(table, nums[i], i);
    }

    freeTable(table);
    *returnSize = 0;
    return NULL;
}

static int hash(int key) {
    if (key < 0) {
        key = -key;
    }
    return key % TABLE_SIZE;
}

static void insert(Node* table[], int key, int value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

static int find(Node* table[], int key, int* value) {
    int index = hash(key);
    Node* curr = table[index];

    while (curr != NULL) {
        if (curr->key == key) {
            *value = curr->value;
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}

static void freeTable(Node* table[]) {
    int i;

    for (i = 0; i < TABLE_SIZE; i++) {
        Node* curr = table[i];

        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}