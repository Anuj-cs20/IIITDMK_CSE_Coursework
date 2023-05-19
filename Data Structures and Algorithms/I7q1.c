// 1. Implement a Circular QUEUE using an array.
// cs20b1100 K.Anuj
// Complexity: worst case O(n)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CAPACITY 100

int queue[CAPACITY];
unsigned int size = 0;
unsigned int rear = CAPACITY - 1;
unsigned int front = 0;

int enqueue(int data);
int dequeue();
int isEmpty();
int getRear();
int getFront();
void traverse();

int main()
{
    int ch, data;
    puts(" ");
    puts(" QUEUE ARRAY IMPLEMENTATION PROGRAM ");
    puts(" ");
    puts("1. Enqueue");
    puts("2. Dequeue");
    puts("3. Size");
    puts("4. Get Rear");
    puts("5. Get Front");
    puts("6. Elements in queue");
    puts("0. Exit");
    puts(" ");
    while (1)
    {
        printf("Select an option: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to enqueue: ");
            scanf("% d", &data);
            if (enqueue(data))
                printf("Element added to queue.");
            else
                printf("Queue is full.");
            break;
        case 2:
            data = dequeue();
            if (data == INT_MIN)
                printf("Queue is empty.");
            else
                printf("Data => % d", data);
            break;
        case 3:
            if (size == 0)
                printf("Queue is empty.");
            else
                printf("Queue size => % d", size);

            break;
        case 4:
            if (size == 0)
                printf("Queue is empty.");
            else
                printf("Rear => % d", getRear());
            break;
        case 5:
            if (size == 0)
                printf("Queue is empty.");
            else
                printf("Front => % d", getFront());
            break;
        case 6:
            puts("Element in queue are:");
            traverse();
            break;
        case 0:
            printf("Exiting from code.\n");
            exit(0);
        default:
            printf("Invalid choice, please input number between (0-6).");
            break;
        }
        printf("\n\n");
    }
}

int enqueue(int data)
{
    if (size == CAPACITY)
    {
        return 0;
    }
    rear = (rear + 1) % CAPACITY;
    size++;
    queue[rear] = data;
    return 1;
}

int dequeue()
{
    int data = INT_MIN;
    if (size == 0)
    {
        return INT_MIN;
    }
    data = queue[front];
    front = (front + 1) % CAPACITY;
    size--;
    return data;
}

int getFront()
{
    return (size == 0)
               ? INT_MIN
               : queue[front];
}

int getRear()
{
    return (size == 0)
               ? INT_MIN
               : queue[rear];
}

void traverse()
{
    for (int i = front; i <= rear; i = (i + 1))
    {
        printf("% d ", queue[i]);
    }
}
