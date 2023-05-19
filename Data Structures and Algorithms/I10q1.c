// 1. Take a random connected directed acyclic graph.
// Store it using Adjacency Matrix as well as Adjacency list.
// Implement the Breadth - first search, Depth - first search and
// Topological sort using both the storage structures.
// cs20b1100 K.Anuj
// Complexity: O(V+E)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct AL
{
    int data;
    struct AL *adj;
};

struct stack
{
    int data;
    struct stack *down;
};

struct stack *top = NULL;

struct queue
{
    int data;
    struct queue *next;
} *front, *rear, *head;

struct linkedList
{
    int data;
    struct linkedList *link;
} *HEAD;

void push(int a)
{
    struct stack *tmp;
    if (top == NULL)
    {
        top = (struct stack *)malloc(sizeof(struct stack));
        top->data = a;
        top->down = NULL;
    }
    else
    {
        struct stack *newNode;
        newNode = (struct stack *)malloc(sizeof(struct stack));
        newNode->data = a;
        newNode->down = top;
        top = newNode;
    }
}

int pop()
{
    int d;
    struct stack *tmp;
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        d = top->data;
        tmp = top;
        top = top->down;
        free(tmp);
        return d;
    }
}

void enqueue(int y)
{
    struct queue *Node;
    Node = (struct queue *)malloc(sizeof(struct queue));
    Node->data = y;
    Node->next = NULL;
    if (front == head)
    {
        head->next = Node;
        front = Node;
        rear = Node;
    }
    else
    {
        rear->next = Node;
        rear = Node;
    }
}

int dequeue()
{
    int d;
    struct queue *tmp;
    if (front == head)
    {
        return 0;
    }
    else if (front == rear)
    {
        d = front->data;
        tmp = front;
        front = head;
        rear = head;
        head->next = NULL;
        free(tmp);
        return d;
    }
    else
    {
        d = front->data;
        tmp = front;
        front = front->next;

        head->next = front;
        free(tmp);
        return d;
    }
}

int traverse(int x)
{
    struct linkedList *tmp = HEAD;
    while (tmp)
    {
        if (x == tmp->data)
        {
            return 0;
        }
        tmp = tmp->link;
    }
    return 1;
}

void printVisited()
{
    struct linkedList *tmp = HEAD;
    while (tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
}

void freeLL()
{
    struct linkedList *tmp1, *tmp = HEAD->link;
    HEAD = NULL;
    while (tmp)
    {
        tmp1 = tmp;
        tmp = tmp->link;
        free(tmp1);
    }
}

int main()
{
    int v;
    printf("Enter Number of vertices of a graph:");
    scanf("%d", &v);
    int a[v][v];
    struct AL *b[v];
    struct AL *tmp;
    srand(time(NULL));
    // Making random connected directed acyclic graph //Making [v x v] Adjacency matrix
    for (size_t i = 0; i < v; ++i)
    {
        for (size_t j = i + 1; j < v; ++j)
        {
            a[i][j] = rand() % 2;
        }
    }
    for (size_t i = 0; i < v; ++i)
    {
        for (size_t j = 0; j < i + 1; ++j)
        {
            a[i][j] = 0;
        }
    }
    // Making Adjacency list
    for (size_t i = 0; i < v; ++i)
    {
        b[i] = (struct AL *)malloc(sizeof(struct AL));
        b[i]->data = i;
        b[i]->adj = NULL;
        tmp = b[i];
        for (size_t j = 0; j < v; ++j)
        {
            if (a[i][j] != 0)
            {
                struct AL *newNode;
                newNode = (struct AL *)malloc(sizeof(struct AL));
                tmp->adj = newNode;
                newNode->data = j;
                newNode->adj = NULL;
                tmp = tmp->adj;
            }
        }
    }
    // Printing Adjacency Matrix
    printf("Adjacency Matrix\n\n");
    printf(" ");
    for (int k = 0; k < v; ++k)
    {
        printf("%d ", k);
    }
    printf("\n\n");
    for (size_t i = 0; i < v; ++i)
    {
        printf("%zu ", i);
        for (size_t j = 0; j < v; ++j)
        {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    puts("");
    int n, u;
    printf("Enter value of a vertices:");
    scanf("%d", &n);
    printf("\nON ADJACENCY MATRIX\n");
    printf("Implementing Breadth-first search\n");
    push(n);
    while (top)
    {
        u = pop();
        struct linkedList *tmp;
        if (HEAD == NULL)
        {
            HEAD = (struct linkedList *)malloc(sizeof(struct linkedList));
            HEAD->data = u;
            HEAD->link = NULL;
            tmp = HEAD;
        }
        else
        {
            if (traverse(u))

            {
                struct linkedList *node;
                node = (struct linkedList *)malloc(sizeof(struct linkedList));
                node->data = u;
                node->link = NULL;
                tmp->link = node;
                tmp = tmp->link;
            }
        }
        for (size_t i = 0; i < v; ++i)
        {
            if (a[u][i] == 1 && traverse(i))
            {
                push(i);
            }
        }
    }
    printVisited();
    freeLL();
    puts("");
    printf("Implementing Depth-first search\n");
    head = (struct queue *)malloc(sizeof(struct queue));
    head->next = NULL;
    head->data = 0;
    front = head;
    rear = head;
    enqueue(n);
    while (front != head)
    {
        u = dequeue();
        struct linkedList *tmp;
        if (HEAD == NULL)
        {
            HEAD = (struct linkedList *)malloc(sizeof(struct linkedList));
            HEAD->data = u;
            HEAD->link = NULL;
            tmp = HEAD;
        }
        else
        {

            if (traverse(u))
            {
                struct linkedList *node;
                node = (struct linkedList *)malloc(sizeof(struct linkedList));
                node->data = u;
                node->link = NULL;
                tmp->link = node;
                tmp = tmp->link;
            }
        }
        for (size_t i = 0; i < v; ++i)
        {
            if (a[u][i] == 1 && traverse(i))
            {
                enqueue(i);
            }
        }
    }
    printVisited();
    freeLL();
    puts("");
    // Storing indegree of vertices
    int indeg[v], outdeg[v];
    int c = 0, o = 0;
    for (size_t i = 0; i < v; ++i)
    {
        for (size_t j = 0; j < v; ++j)
        {
            if (a[j][i] == 0)
            {
                ++c;
            }
            if (a[i][j] == 0)
            {
                ++o;
            }
        }
        indeg[i] = v - c;
        outdeg[i] = v - o;
        c = 0;
        o = 0;
    }
    printf("Implementing Topological sort\n");
    for (int i = 0; i < v; ++i)
    {
        if (indeg[i] == 0 && outdeg[i] != 0)
        {
            enqueue(i);
        }
    }
    while (front != head)
    {
        u = dequeue();
        struct linkedList *tmp;
        if (HEAD == NULL)
        {
            HEAD = (struct linkedList *)malloc(sizeof(struct linkedList));
            HEAD->data = u;
            HEAD->link = NULL;
            tmp = HEAD;
        }
        else
        {
            struct linkedList *node;
            node = (struct linkedList *)malloc(sizeof(struct linkedList));
            node->data = u;
            node->link = NULL;
            tmp->link = node;
            tmp = tmp->link;
        }
        for (size_t i = 0; i < v; ++i)
        {
            if (a[u][i] == 1)
            {
                indeg[i] -= 1;
                if (indeg[i] == 0)
                {
                    enqueue(i);
                }
            }
        }
    }
    printVisited();
    freeLL();
    puts("");
    // Printing Adjacency List
    printf("\nAdjacency List\n\n");
    for (size_t i = 0; i < v; ++i)
    {
        printf("%d -> ", b[i]->data);
        tmp = b[i]->adj;
        while (tmp)
        {
            printf("%d ", tmp->data);
            tmp = tmp->adj;
        }
        puts("");
    }
    puts("");
    printf("\nON ADJACENCY List\n");
    printf("Implementing Breadth-first search\n");
    push(n);
    while (top)
    {
        u = pop();
        struct AL *tmpv = b[u]->adj;
        struct linkedList *tmp;
        if (HEAD == NULL)
        {
            HEAD = (struct linkedList *)malloc(sizeof(struct linkedList));
            HEAD->data = u;
            HEAD->link = NULL;
            tmp = HEAD;
        }
        else
        {
            if (traverse(u))
            {
                struct linkedList *node;
                node = (struct linkedList *)malloc(sizeof(struct linkedList));
                node->data = u;
                node->link = NULL;
                tmp->link = node;
                tmp = tmp->link;
            }
        }
        while (tmpv)
        {
            if (traverse(tmpv->data))
            {
                push(tmpv->data);
            }
            tmpv = tmpv->adj;
        }
    }
    printVisited();
    freeLL();
    puts("");
    printf("Implementing Depth-first search\n");
    head = (struct queue *)malloc(sizeof(struct queue));
    head->next = NULL;
    head->data = 0;
    front = head;
    rear = head;
    enqueue(n);
    while (front != head)
    {
        u = dequeue();
        struct AL *tmpv = b[u]->adj;
        struct linkedList *tmp;
        if (HEAD == NULL)
        {
            HEAD = (struct linkedList *)malloc(sizeof(struct linkedList));
            HEAD->data = u;
            HEAD->link = NULL;
            tmp = HEAD;
        }
        else
        {
            if (traverse(u))
            {
                struct linkedList *node;
                node = (struct linkedList *)malloc(sizeof(struct linkedList));

                node->data = u;
                node->link = NULL;
                tmp->link = node;
                tmp = tmp->link;
            }
        }
        while (tmpv)
        {
            if (traverse(tmpv->data))
            {
                enqueue(tmpv->data);
            }
            tmpv = tmpv->adj;
        }
    }
    printVisited();
    freeLL();
    puts("");
    // Storing indegree and outdegree of vertices
    for (size_t i = 0; i < v; ++i)
    {
        for (size_t j = 0; j < v; ++j)
        {
            if (a[j][i] == 0)
            {
                ++c;
            }
        }
        indeg[i] = v - c;
        c = 0;
    }
    printf("Implementing Topological sort\n");
    for (int i = 0; i < v; ++i)
    {
        if (indeg[i] == 0 && outdeg[i] != 0)
        {
            enqueue(i);
        }
    }

    while (front != head)
    {
        u = dequeue();
        struct AL *tmpv = b[u]->adj;
        struct linkedList *tmp;
        if (HEAD == NULL)
        {
            HEAD = (struct linkedList *)malloc(sizeof(struct linkedList));
            HEAD->data = u;
            HEAD->link = NULL;
            tmp = HEAD;
        }
        else
        {
            struct linkedList *node;
            node = (struct linkedList *)malloc(sizeof(struct linkedList));
            node->data = u;
            node->link = NULL;
            tmp->link = node;
            tmp = tmp->link;
        }
        while (tmpv)
        {
            indeg[tmpv->data] -= 1;
            if (indeg[tmpv->data] == 0)
            {
                enqueue(tmpv->data);
            }
            tmpv = tmpv->adj;
        }
    }
    printVisited();
    freeLL();
    puts("");
    return 0;
}
