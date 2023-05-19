// 2. Implement a Parking Lot problem using a Header Linked List based QUEUE with the following properties.
// • Cars can enter from the REAR end and leave from the FRONT end. Cars are given sequential integer tokens.
// • The user should take input for the Parking Lot size (MAX size) at the beginning.
// • The header node in the header linked list should be used to store the current QUEUE size.
// • While the cars enter to the QUEUE, if the current size exceeds the MAX size, it should give an Overflow error - “Parking Lot FULL”.
// • If a car from k-th location wants to leave, all the cars at the FRONT of the k-th car are first removed and put into a STACK. Then, the k-th car is removed. Then, all the cars from the STACK are popped out and again inserted at the FRONT of the queue.
// • At every step, the header node value, FRONT and REAR need to be updated based on the operation.
// cs20b1100 K.Anuj
// Complexity: worst case O(n)

#include <stdio.h>
#include <stdlib.h>
struct ParkingLot
{
    int data;
    struct ParkingLot *next;
} *HEAD, *FRONT, *REAR, *top;

unsigned int size;

void enqueue(unsigned int n)
{
    struct ParkingLot *newNode;
    newNode = (struct ParkingLot *)malloc(sizeof(struct ParkingLot));
    if (FRONT == HEAD)
    {
        newNode->data = n;
        newNode->next = NULL;
        HEAD->next = newNode;
        FRONT = FRONT->next;
        REAR = REAR->next;
        ++size;
    }
    else
    {
        newNode->data = n;
        newNode->next = NULL;
        REAR->next = newNode;
        REAR = REAR->next;
        ++size;
    }
    HEAD->data = size;
}

void dequeue()
{
    struct ParkingLot *tmp;
    if (FRONT == HEAD)
    {
        printf("!!!! PARKING LOT IS EMPTY !!!!\n");
    }
    else if (FRONT == REAR)
    {
        tmp = FRONT;
        FRONT = HEAD;
        REAR = HEAD;
        free(tmp);
        --size;
    }
    else
    {
        tmp = FRONT;
        FRONT = FRONT->next;
        HEAD->next = FRONT;
        free(tmp);
        --size;
    }
    HEAD->data = size;
}

void push(int d)
{
    if (top == NULL)
    {
        top = (struct ParkingLot *)malloc(sizeof(struct ParkingLot));
        top->data = d;
        top->next = NULL;
    }
    else
    {
        struct ParkingLot *Node;
        Node = (struct ParkingLot *)malloc(sizeof(struct ParkingLot));
        Node->data = d;
        Node->next = top;
        top = Node;
    }
}

int pop()
{
    struct ParkingLot *node;
    int num = 0;
    if (top == NULL)
    {
        puts("stack is empty!");
    }
    else if (top->next == NULL)
    {
        node = top;
        top = NULL;
        num = node->data;
        free(node);
    }
    else
    {
        node = top;
        top = top->next;
        num = node->data;
        free(node);
    }
    return (num);
}

void stack(int p)
{
    for (int i = 1; i < p; ++i)
    {
        push(FRONT->data);
        dequeue();
    }
    dequeue();
    int k = 1;
    if (FRONT == HEAD)
    {
        struct ParkingLot *newNode;
        newNode = (struct ParkingLot *)malloc(sizeof(struct ParkingLot));
        newNode->data = pop();
        HEAD->next = newNode;
        newNode->next = NULL;
        FRONT = newNode;
        REAR = newNode;
        ++size;
        ++k;
        HEAD->data = size;
    }
    for (int j = k; j < p; ++j)
    {
        struct ParkingLot *newNode;
        newNode = (struct ParkingLot *)malloc(sizeof(struct ParkingLot));
        newNode->data = pop();
        HEAD->next = newNode;
        newNode->next = FRONT;
        FRONT = newNode;
        ++size;
        HEAD->data = size;
    }
}

void traverse()
{
    struct ParkingLot *temp = HEAD;
    printf("Total Number of Cars in Parking Lot are:");
    printf(" % d\n", temp->data);
    temp = temp->next;
    if (HEAD->data != 0)
    {
        printf(" And there token Numbers are:");
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
    }
}

void freeQueue()
{
    struct ParkingLot *tmp2, *tmp1 = HEAD;
    while (tmp1 != NULL)
    {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
        free(tmp2);
    }
}

int main()
{
    HEAD = (struct ParkingLot *)malloc(sizeof(struct ParkingLot));
    FRONT = HEAD;
    REAR = HEAD;
    unsigned int max, token;
    int ch, position;
    puts("Enter Maximum Parking Lots is");
    scanf("%u", &max);
    puts(" ");
    puts(" QUEUE LINKED LIST IMPLEMENTATION PROGRAM ");
    puts(" ");
    puts("1. Enqueue a car to Parking Lot.");
    puts("2. Dequeue a car from Parking Lot.");
    puts("3. Dequeue a car other than FRONT Parking Lot.");
    puts("4. Parking Lot contains ");
    puts("0. Exit");
    puts(" ");
    while (1)
    {
        printf("Select an option: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (size == max)
            {
                puts("!!!! Parking Lot is full.!!!!");
            }
            else
            {
                ++token;
                enqueue(token);
            }
            break;
        case 2:
            dequeue();
            break;
        case 3:
            puts("Enter position of car you want to remove");
            scanf("%d", &position);
            if (position == 1)
            {
                dequeue();
            }
            else if (position > size)
            {
                puts("there is no car in that position");
            }
            else
            {
                stack(position);
            }
            break;
        case 4:
            traverse();
            break;
        case 0:
            printf("Total Number of Cars entered and exited our ParkingLot are:");
            printf(" %d\n", token);
            puts("!!! AT LAST !!!");
            traverse();
            printf("\nExiting from code.");
            freeQueue();
            exit(0);
        default:
            printf("Invalid choice, please input number between (0-4).");
            break;
        }
        puts("");
    }
}