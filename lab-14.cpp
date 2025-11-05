#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Size of hash table

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Hash table array of pointers
struct Node* hashTable[SIZE];

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert element into hash table
void insert(int data) {
    int index = hashFunction(data);
    struct Node* newNode = createNode(data);

    // Insert at beginning (chaining)
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search element in hash table
int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];

    while (temp) {
        if (temp->data == key)
            return 1; // Found
        temp = temp->next;
    }
    return 0; // Not found
}

// Display hash table
void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Simple sorting (collect all keys and sort)
void sortHashTable() {
    int arr[100], k = 0;
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = hashTable[i];
        while (temp) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }

    // Bubble sort
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Elements: ");
    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int choice, data, key;

    while (1) {
        printf("\n----- Hash Table Menu -----\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Sort\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("Enter element to search: ");
            scanf("%d", &key);
            if (search(key))
                printf("Element %d found in hash table.\n", key);
            else
                printf("Element %d not found.\n", key);
            break;
        case 3:
            display();
            break;
        case 4:
            sortHashTable();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


