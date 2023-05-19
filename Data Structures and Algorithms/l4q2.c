// 2. Create a Linked List of N Fibonacci numbers.
//    N should be given as user input.
//    WAP to find the summation of odd and even Fibonacci numbers in the series.
//    The program should be run in one pass
//    (only one for/while loop in the entire program).
// cs20b1100 K.Anuj
// Complexity: n
#include <stdio.h>
#include <stdlib.h>

struct fibonacci
{
    int F;
    struct fibonacci *next;
} * head1;

void CreateList(int N)
{
    static int Sum_Odd, Sum_Even;
    struct fibonacci *head2, *temp, *prevNode, *prevprevNode;
    head1 = malloc(sizeof(struct fibonacci));
    head2 = malloc(sizeof(struct fibonacci));
    if (head1 == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    head1->F = 1;
    prevNode = head1;
    head1->next = head2;
    head2->F = 1;
    prevprevNode = head2;
    head2->next = NULL;
    temp = head2;
    for (int i = 3; i <= N; ++i)
    {
        struct fibonacci *newNode;
        newNode = (struct fibonacci *)malloc(sizeof(struct fibonacci));
        if (newNode == NULL)
        {
            printf("out of memory space\n");
            exit(0);
        }
        newNode->F = prevprevNode->F + prevNode->F;
        newNode->next = NULL;

        if ((newNode->F) % 2 == 0)
        {
            Sum_Even += newNode->F;
        }
        else
        {
            Sum_Odd += newNode->F;
        }
        temp->next = newNode;
        temp = newNode;
        prevNode = prevNode->next;
        prevprevNode = prevprevNode->next;
    }
    printf("sum of even numbers is: %d\n", Sum_Even);
    printf("sum of odd numbers is: %d\n", Sum_Odd + 2);
}

void TraverseList()
{
    printf("\nThe values in the List are: ");
    struct fibonacci *node = head1;
    while (node != NULL)
    {
        printf("%d,", node->F);

        node = node->next;
    }
    puts("");
}

void freeList()
{
    struct fibonacci *tmp;
    while (head1 != NULL)
    {
        tmp = head1;
        head1 = head1->next;
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
    freeList();
    return 0;
}