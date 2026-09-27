#include <stdio.h>

#define SIZE 10

void initTable(int table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

void insert(int table[], int key) {
    int hash = key % SIZE;
    int index = hash;
    int i = 0;

    while (table[index] != -1) {
        i++;
        index = (hash + i) % SIZE;
    }
    table[index] = key;
    printf("Inserted %d at index %d (Collisions: %d)\n", key, index, i);
}

void display(int table[]) {
    printf("Hash Table: [ ");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1) printf("- ");
        else printf("%d ", table[i]);
    }
    printf("]\n");
}

int searchHash(int table[], int key, int *comparisons) {
    int hash = key % SIZE;
    int index = hash;
    int i = 0;
    *comparisons = 0;

    while (table[index] != -1 && i < SIZE) {
        (*comparisons)++;
        if (table[index] == key) return index;
        i++;
        index = (hash + i) % SIZE;
    }
    (*comparisons)++;
    return -1;
}

int searchLinear(int arr[], int n, int key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int songs[] = {105, 210, 315, 420, 525, 630, 735, 840};
    int n = sizeof(songs) / sizeof(songs[0]);
    int hashTable[SIZE];

    initTable(hashTable);

    printf("--- Insertion Phase ---\n");
    for (int i = 0; i < n; i++) {
        insert(hashTable, songs[i]);
        display(hashTable);
    }

    printf("\n--- Search Phase ---\n");
    int target = 315;
    int hComp, lComp;

    searchHash(hashTable, target, &hComp);
    searchLinear(songs, n, target, &lComp);

    printf("Searching for ID %d:\n", target);
    printf("-> Hashing Comparisons: %d\n", hComp);
    printf("-> Linear Search Comparisons: %d\n", lComp);

    return 0;
}