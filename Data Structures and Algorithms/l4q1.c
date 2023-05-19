// 1. Create a Linked List of size N, where each node
//    will have a random character and pointer to the next node.
//    N should be given as user input.
//    WAP to remove the duplicate characters from the list.
// cs20b1100 K.Anuj
// Complexity: n
#include <stdio.h>
#include <stdlib.h>

struct characters
{
    char ch;
    struct characters *next;
} * head;

void CreateList(int N)
{
    int x;
    struct characters *temp;
    head = malloc(sizeof(struct characters));
    do
    {
        x = 65 + rand() % 58;
    } while (x > 90 && x < 97);
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    head->ch = x;
    head->next = NULL;
    temp = head;
    for (int i = 2; i <= N; ++i)
    {
        struct characters *newNode;
        newNode = malloc(sizeof(struct characters));
        if (newNode == NULL)
        {
            printf("out of memory space\n");
            exit(0);
        }
        do
        {
            x = 65 + rand() % 58;
        } while (x > 90 && x < 97);
        newNode->ch = x;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
}

void RemoveDuplicate(int N)
{
    struct characters *ptr1, *ptr2, *prevPtr2, *toDelete;
    ptr2 = head;
    ptr1 = head;
    do
    {
        prevPtr2 = ptr2;
        ptr2 = ptr2->next;
        if (ptr2->ch == ptr1->ch && ptr2->next != NULL)
        {
            toDelete = ptr2;
            ptr2 = prevPtr2;
            prevPtr2->next = toDelete->next;

            toDelete->next = NULL;
            free(toDelete);
        }
        if (ptr2->ch == ptr1->ch && ptr2->next == NULL)
        {
            toDelete = ptr2;
            prevPtr2->next = NULL;
            free(toDelete);
            ptr1 = ptr1->next;
            ptr2 = ptr1;
        }
        if (ptr2->next == NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr1;
        }
    } while (ptr1->next != NULL);
}

void TraverseList()
{
    printf("The characters in the List are: ");
    struct characters *node = head;
    while (node != NULL)
    {
        printf("%c -> ", node->ch);
        node = node->next;
    }

    puts("");
}

void freeList()
{
    struct characters *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    int n;
    puts("Enter size of linked list of characters");
    scanf("%d", &n);
    CreateList(n);
    TraverseList();
    puts("After removing duplicte characters");
    RemoveDuplicate(n);
    TraverseList();
    freeList();

    return 0;
}
