#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;

    hashTable[index] = key;
}

int hashSearch(int key, int *comparisons)
{
    int index = hashFunction(key);
    int start = index;

    *comparisons = 0;

    while (hashTable[index] != -1)
    {
        (*comparisons)++;

        if (hashTable[index] == key)
            return index;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return -1;
}

int linearSearch(int key, int *comparisons)
{
    *comparisons = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
        {
            (*comparisons)++;

            if (hashTable[i] == key)
                return i;
        }
    }

    return -1;
}

void display()
{
    printf("\nIndex : ");

    for (int i = 0; i < SIZE; i++)
        printf("%4d", i);

    printf("\nValue : ");

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%4s", "-");
        else
            printf("%4d", hashTable[i]);
    }

    printf("\n");
}

int main()
{
    int songs[] = {105, 210, 315, 420, 525, 630, 735, 840};
    int n = 8;
    int totalHash = 0;
    int totalLinear = 0;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("SONG ID HASH TABLE - DIVISION METHOD\n");
    printf("Hash function: h(k) = k %% 10\n");
    printf("Collision resolution: Linear Probing\n");

    printf("\n--- INSERTION ---\n");

    for (int i = 0; i < n; i++)
    {
        int key = songs[i];
        int hash = hashFunction(key);

        printf("\nInsert %d: hash(%d) = %d", key, key, hash);

        if (hashTable[hash] == -1)
            printf(" -> placed at index %d\n", hash);
        else
            printf(" -> collision");

        insert(key);

        int pos = hash;

        while (hashTable[pos] != key)
            pos = (pos + 1) % SIZE;

        if (pos != hash)
            printf(", placed at index %d\n", pos);

        display();
    }

    printf("\n--- SEARCH COMPARISON ---\n\n");

    printf("%-10s %-18s %-20s\n",
           "Song ID", "Hash Comparisons", "Linear Comparisons");

    printf("--------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        int hashComp, linearComp;

        hashSearch(songs[i], &hashComp);
        linearSearch(songs[i], &linearComp);

        printf("%-10d %-18d %-20d\n",
               songs[i], hashComp, linearComp);

        totalHash += hashComp;
        totalLinear += linearComp;
    }

    printf("\nTotal hash comparisons    : %d", totalHash);
    printf("\nTotal linear comparisons  : %d", totalLinear);

    printf("\nAverage hash comparisons  : %.2f",
           (float)totalHash / n);

    printf("\nAverage linear comparisons: %.2f",
           (float)totalLinear / n);

    printf("\nLoad factor               : %.2f (%.0f%%)\n",
           (float)n / SIZE,
           ((float)n / SIZE) * 100);

    printf("\nConclusion:\n");
    printf("Hashing requires fewer comparisons for these successful searches,\n");
    printf("but collisions increase the number of probes. With a load factor\n");
    printf("of 0.80, collision handling is important for search performance.\n");

    return 0;
}

    

   

 

