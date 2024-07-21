#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

// Structure definition for List
typedef struct {
    int count;
    int items[MAX_LIST_SIZE];
} List;

// Function declarations
void initializeList(List *list);
int isFull(List *list);
int isEmpty(List *list);
void insert(List *list, int item);
void delete(List *list, int item);
void display(List *list);

int main() {
    List list;
    initializeList(&list);

    int option, item;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &item);
                insert(&list, item);
                break;
            case 2:
                printf("Enter the number to delete: ");
                scanf("%d", &item);
                delete(&list, item);
                break;
            case 3:
                display(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

// Initialize the list
void initializeList(List *list) {
    list->count = 0;
}

// Check if the list is full
int isFull(List *list) {
    return list->count == MAX_LIST_SIZE;
}

// Check if the list is empty
int isEmpty(List *list) {
    return list->count == 0;
}

// Insert an item into the list
void insert(List *list, int item) {
    if (isFull(list)) {
        printf("The list is full.\n");
        return;
    }

    // Insert the item at the end of the list
    list->items[list->count++] = item;
    printf("Inserted %d into the list.\n", item);
}

// Delete an item from the list
void delete(List *list, int item) {
    if (isEmpty(list)) {
        printf("The list is empty.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (list->items[i] == item) {
            found = 1;
            for (int j = i; j < list->count - 1; j++) {
                list->items[j] = list->items[j + 1];
            }
            list->count--;
            printf("Deleted %d from the list.\n", item);
            break;
        }
    }

    if (!found) {
        printf("Item %d not found in the list.\n", item);
    }
}

// Display the items in the list
void display(List *list) {
    if (isEmpty(list)) {
        printf("The list is empty.\n");
        return;
    }

    printf("List items: ");
    for (int i = 0; i < list->count; i++) {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}
