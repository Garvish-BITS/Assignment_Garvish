#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX], front = 0, rear = -1;

void insert();
void delete();
void display();

int main() {
    int choice;
    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");
    
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice! Please see the options.\n");
        }
    }
    
    return 0;
}

void insert() {
    if(rear == MAX - 1) {
        printf("\nQueue is Full\n");
    } else {
        int value;
        printf("Enter a value to be inserted: ");
        scanf("%d", &value);
        rear++;
        queue[rear] = value;
    }
}

void delete() {
    if(front > rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nDeleted Element is %d\n", queue[front]);
        for(int i = front; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}

void display() {
    if(front > rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nQueue Elements are:\n");
        for(int i = front; i <= rear; i++) {
            printf("%d \n", queue[i]);
        }
        printf("\n");
    }
}