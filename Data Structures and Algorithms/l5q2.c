//  2. Create a two - way Linked List of N Fibonacci numbers.
//     N should be given as user input.
//     WAP to delete the nodes in the two - way linked list
//     based on a given GP series.The factor of the GP series
//     will be taken as an user input.(Ex : 1, 2, 4, 8, 16.....: Factor 2)
// cs20b1100 K.Anuj
// for loop will run until m^k = n => k = log n(base m)
// Complexity: log n(base m)
#include <stdio.h>
#include <stdlib.h>

struct fibonacci
{
    int F;
    struct fibonacci *forw;
    struct fibonacci *back;
} * first, *last, *head1, *head2;

void CreateList(int N)
{
    struct fibonacci *temp, *prevNode, *prevprevNode;
    head1 = malloc(sizeof(struct fibonacci));
    head2 = malloc(sizeof(struct fibonacci));
    if (head1 == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    first = head1;
    head1->F = 1;
    prevNode = head1;
    head1->forw = head2;
    head1->back = NULL;
    head2->F = 1;
    prevprevNode = head2;
    head2->forw = NULL;
    head2->back = head1;
    temp = head2;
    for (int i = 3; i <= N; ++i)
    {
        struct fibonacci *ptr;

        ptr = (struct fibonacci *)malloc(sizeof(struct fibonacci));
        if (ptr == NULL)
        {
            printf("out of memory space\n");
            exit(0);
        }
        ptr->F = prevprevNode->F + prevNode->F;
        ptr->forw = NULL;
        ptr->back = temp;
        temp->forw = ptr;
        temp = ptr;
        prevNode = prevNode->forw;
        prevprevNode = prevprevNode->forw;
        if (i == N)
        {
            last = ptr;
        }
    }
}

void Delete(int N, int M)
{
    int count = 0;
    struct fibonacci *temp;
    for (int i = 1; i <= N; i *= M)
    {
        if (i == 1 || i == 2)
        {
            temp = first;
            first = temp->forw;
            temp->forw->back = NULL;
            temp->forw = NULL;
            free(temp);
        }
        else if (i == N)
        {
            temp = last;
            last = temp->back;
            temp->back->forw = NULL;
            temp->back = NULL;
            free(temp);
        }
        else
        {
            temp = first;
            for (int j = 1; j <= i - count - 1; ++j)
            {
                temp = temp->forw;
            }
            temp->back->forw = temp->forw;
            temp->forw->back = temp->back;
            temp->forw = NULL;
            temp->back = NULL;

            free(temp);
        }
        count += 1;
    }
}

void TraverseList()
{
    printf("\nThe values in the List are:\n");
    struct fibonacci *node = first;
    while (node != NULL)
    {
        printf("%d,", node->F);
        node = node->forw;
    }
    puts("");
}

void freeList()
{
    struct fibonacci *tmp;
    while (first != NULL)
    {
        tmp = first;
        first = first->forw;
        free(tmp);
    }
}

int main()
{
    int n, m;
    puts("Enter size of linked list of fibonacci series");
    scanf("%d", &n);
    puts("Enter common factor of G.P.");
    scanf("%d", &m);
    CreateList(n);
    TraverseList();
    Delete(n, m);
    TraverseList();
    freeList();
    return 0;
}