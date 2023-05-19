// 3)WAP to find out the mean and Standard deviation of the elements in a LinkedList.
//   What is the complexity of the algorithm? Please state the reason.
//   [Wite on a white paper and submitwith the assignment PDF file].
// cs20b1100 K.Anuj
// Complexity: n
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list
{
    int data;
    struct list *next;
};

void CreateList(struct list *node)
{
    printf("creation of link list\n\n");
    int i = 1;
    char ch;
    printf("enter the value for %d node: ", i);
    scanf("%d", &node->data);
    node->next = NULL;
    i++;
    printf("press 's' to quit or any other key to continue: ");
    scanf(" %c", &ch); // (space)%c made scanf to read properly
    while (ch != 's')
    {
        struct list *newNode = NULL;
        newNode = (struct list *)malloc(sizeof(struct list));
        if (newNode == NULL)
        {
            printf("out of memory space\n");
            exit(0);
        }
        node->next = newNode;
        node = newNode;
        printf("enter the value for %d node: ", i);
        scanf("%d", &node->data);
        node->next = NULL;
        i++;
        printf("press 's' to quit or any other key to continue: ");
        scanf(" %c", &ch); // (space)%c made scanf to read properly
    }
}

void MandS(struct list *node)
{
    static int sum, square, N;
    while (node != NULL)
    {
        sum += node->data;
        square += pow(node->data, 2);

        ++N;
        node = node->next;
    }
    float m, s;
    m = (float)sum / N;
    printf("Mean: %f", m);
    s = ((float)square / N) - pow(m, 2);
    s = sqrt(s);
    printf("\nstandard deviation: %f", s);
}

int main()
{
    struct list *head = NULL;
    head = (struct list *)malloc(sizeof(struct list));
    if (head == NULL)
    {
        printf("out of memory space\n");
        exit(0);
    }
    CreateList(head);
    MandS(head);
    return 0;
}