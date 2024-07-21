#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int queue[MAX], front = 0, rear = -1;

void insert();
void delete();
void display();
double time_operation(void (*operation)());

int main() {
    int choice;
    printf("Queue using Array\n");
    printf("1. Insertion \n2. Deletion \n3. Display \n4. Exit\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Time taken for insertion: %.6f seconds\n", time_operation(insert));
                break;
            case 2:
                printf("Time taken for deletion: %.6f seconds\n", time_operation(delete));
                break;
            case 3:
                printf("Time taken for display: %.6f seconds\n", time_operation(display));
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
        queue[++rear] = value;
        display();
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
        display();
    }
}

void display() {
    if(front > rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nQueue Elements are:\n");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

double time_operation(void (*operation)()) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    operation();
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
