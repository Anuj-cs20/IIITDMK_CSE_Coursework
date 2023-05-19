// 1. Create a Linked List of size N, where each node
//    will have a random floating point value and pointer to
//    the next node.WAP to reverse the linked list based on
//    a given GP series.The factor of the GP series will be
//    taken as an user input.(Ex : 1, 2, 4, 8, 16.....: Factor 2)
// cs20b1100 K.Anuj
// for loop will run until m^k = n => k = log n(base m)
// Complexity: log n(base m)
#include <stdio.h>
#include <stdlib.h>

struct Ls
{
    int x;
    struct Ls *next;
} * head, *ptr1, *ptr2, *ptr1prev, *ptr2next;

void CreateList(int N)
{
    struct Ls *temp;
    head = malloc(sizeof(struct Ls));
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    head->x = rand() % 10;
    head->next = NULL;
    temp = head;
    for (int i = 2; i <= N; ++i)
    {
        struct Ls *newNode;
        newNode = malloc(sizeof(struct Ls));
        if (newNode == NULL)
        {
            printf("out of memory space\n");
            exit(0);
        }
        newNode->x = rand() % 10;
        newNode->next = NULL;
        temp->next = newNode;

        temp = newNode;
    }
}

void reverse1()
{
    struct Ls *Node = NULL, *nextNode = NULL;
    nextNode = ptr1->next;
    ptr1->next = ptr2next;
    Node = ptr1;
    ptr1 = nextNode;
    do
    {
        nextNode = ptr1->next;
        ptr1->next = Node;
        Node = ptr1;
        ptr1 = nextNode;
    } while (ptr1 != ptr2next);
    ptr1prev->next = Node;
}

void reverse2()
{
    struct Ls *Node = NULL, *nextNode = NULL;
    while (ptr1)
    {
        nextNode = ptr1->next;
        ptr1->next = Node;
        Node = ptr1;
        ptr1 = nextNode;
    }
    ptr1prev->next = Node;
}

void TraverseList()
{
    printf("\nThe integers in the List are:\n");
    struct Ls *node = head;
    while (node)
    {
        printf("%d,", node->x);
        node = node->next;
    }
    puts("");
}

void freeList()
{
    struct Ls *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    int n, m, i = 1, count = 1;
    puts("Enter size of linked list is");
    scanf("%d", &n);
    puts("Enter common factor of G.P.");
    scanf("%d", &m);
    CreateList(n);
    TraverseList();
    printf("\nAfter reversing the linked list");
    for (i = 1; i <= n - count; i *= m)
    {
        ptr1 = head;
        for (int j = 1; j <= count; ++j)
        {
            ptr1prev = ptr1;
            ptr1 = ptr1->next;
        }

        if (n - count <= i * m)
        {
            reverse2();
            break;
        }
        else
        {
            ptr2 = ptr1;
            for (int k = 1; k <= i * m - 1; ++k)
            {
                ptr2 = ptr2->next;
                ptr2next = ptr2->next;
            }
            count += i * m;
            reverse1();
        }
    }
    ptr1 = head;
    for (int j = 1; j <= count; ++j)
    {
        ptr1prev = ptr1;
        ptr1 = ptr1->next;
    }

    if (n - count < i)
    {
        reverse2();
    }
    TraverseList();
    freeList();
    return 0;
}
