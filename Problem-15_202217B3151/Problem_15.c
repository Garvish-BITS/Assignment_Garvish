#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node structure
struct node {
    char* key;       // Key of the key-value pair
    char* value;     // Value of the key-value pair
    struct node* next; // Pointer to the next node in the list
};

// Function to initialize a new node
void setNode(struct node* node, char* key, char* value) {
    node->key = strdup(key);  // Duplicate key string
    node->value = strdup(value);  // Duplicate value string
    node->next = NULL;  // Initialize next pointer to NULL
}

// Hash table structure
struct hashMap {
    int numOfElements;  // Current number of elements in hashMap
    int capacity;       // Capacity of hashMap
    struct node** arr;  // Array of pointers to linked list nodes
};

// Function to initialize the hashMap
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;  // Default capacity
    mp->numOfElements = 0;  // Initialize number of elements
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;  // Initialize each bucket to NULL
    }
}

// Hash function to calculate bucket index from key
int hashFunction(struct hashMap* mp, char* key) {
    int bucketIndex;
    int sum = 0;
    int factor = 31;
    
    for (int i = 0; i < strlen(key); i++) {
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    
    bucketIndex = sum;
    return bucketIndex;
}

// Function to insert a key-value pair into the hashMap
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    setNode(newNode, key, value);
    
    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;  // No collision
    } else {
        newNode->next = mp->arr[bucketIndex];  // Collision, insert at head
        mp->arr[bucketIndex] = newNode;
    }
    
    mp->numOfElements++;  // Increment the number of elements
}

// Function to delete a key-value pair from the hashMap
void delete(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];
    
    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;  // Head node deletion
            } else {
                prevNode->next = currNode->next;  // Middle or last node deletion
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;  // Decrement the number of elements
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for a value by key in the hashMap
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];
    
    while (bucketHead != NULL) {
        if (strcmp(key, bucketHead->key) == 0) {
            return bucketHead->value;  // Key found
        }
        bucketHead = bucketHead->next;
    }
    
    // Key not found
    return "Oops! No data found.\n";
}

// Main function to test the hashMap operations
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);
    
    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");
    
    printf("%s\n", search(mp, "elite_Programmer"));  // Should print "Manish"
    printf("%s\n", search(mp, "Yogaholic"));  // Should print "Anjali"
    printf("%s\n", search(mp, "pluto14"));  // Should print "Vartika"
    printf("%s\n", search(mp, "decentBoy"));  // Should print "Mayank"
    printf("%s\n", search(mp, "GFG"));  // Should print "BITS"
    printf("%s\n", search(mp, "randomKey"));  // Should print "Oops! No data found."
    
    printf("\nAfter deletion:\n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));  // Should print "Oops! No data found."
    
    // Free allocated memory
    for (int i = 0; i < mp->capacity; i++) {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) {
            struct node* tempNode = currNode;
            currNode = currNode->next;
            free(tempNode->key);
            free(tempNode->value);
            free(tempNode);
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}
