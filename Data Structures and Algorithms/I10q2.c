// 2. Take a complete graph of N nodes.N should be input from the user.
// Store it using either Adjacency Matrix or Adjacency List.
// Edge weights(> 0, integer) can be taken as random.
// Find out the Minimum spannging tree using Prim's and Kruskal Algorithm.
// cs20b1100 K.Anuj
// Complexity: O(ElogV)

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
struct MST
{
    int p, c, w;
    struct MST *link;
} *MSTp, *MSTk;
struct Ver
{
    int v;
    struct Ver *next;
} *nonT;
void NonTree(int v)
{
    struct Ver *tmp;
    nonT = (struct Ver *)malloc(sizeof(struct Ver));
    nonT->v = 0;
    nonT->next = NULL;
    tmp = nonT;
    for (int i = 1; i < v; ++i)
    {
        struct Ver *newNode;
        newNode = (struct Ver *)malloc(sizeof(struct Ver));
        newNode->v = i;
        newNode->next = NULL;
        tmp->next = newNode;
        tmp = newNode;
    }
}
void deletebyKey(int v)
{
    struct Ver *tmp1, *tmp = nonT;
    while (v != tmp->v)
    {
        tmp1 = tmp;
        tmp = tmp->next;
    }
    if (nonT->next == NULL && nonT->v == v)
    {
        nonT = NULL;
    }
    else if (v == nonT->v)
    {
        nonT = nonT->next;
        free(tmp);
    }
    else if (tmp->next == NULL && tmp->v == v)
    {
        tmp1->next = NULL;
        free(tmp);
    }
    else
    {
        tmp1->next = tmp->next;
        free(tmp);
    }
}
void insertp(int p, int c, int w)
{
    if (!MSTp)
    {
        MSTp = (struct MST *)malloc(sizeof(struct MST));
        MSTp->p = p;
        MSTp->c = c;
        MSTp->w = w;
        MSTp->link = NULL;
    }
    else
    {
        struct MST *tmp = MSTp;
        while (tmp->link)
        {
            tmp = tmp->link;
        }
        struct MST *newNode;
        newNode = (struct MST *)malloc(sizeof(struct MST));
        newNode->p = p;
        newNode->c = c;
        newNode->w = w;
        newNode->link = NULL;
        tmp->link = newNode;
    }
}
void insertk(int p, int c, int w)
{
    if (!MSTk)
    {
        MSTk = (struct MST *)malloc(sizeof(struct MST));
        MSTk->p = p;
        MSTk->c = c;
        MSTk->w = w;
        MSTk->link = NULL;
    }
    else
    {
        struct MST *tmp = MSTk;
        while (tmp->link)
        {
            tmp = tmp->link;
        }
        struct MST *newNode;
        newNode = (struct MST *)malloc(sizeof(struct MST));
        newNode->p = p;
        newNode->c = c;
        newNode->w = w;
        newNode->link = NULL;
        tmp->link = newNode;
    }
}
void printandFreeMSTp()
{
    struct MST *tmp1, *tmp = MSTp;
    printf("parent\tchild\t->\tweight\n");
    while (tmp)
    {
        printf("%d\t%d\t->\t%d\n", tmp->p, tmp->c, tmp->w);
        tmp1 = tmp;
        tmp = tmp->link;
        free(tmp1);
    }
}
void printandFreeMSTk()
{
    struct MST *tmp1, *tmp = MSTk;
    printf("parent\tchild\t->\tweight\n");
    while (tmp)
    {
        printf("%d\t%d\t->\t%d\n", tmp->p, tmp->c, tmp->w);
        tmp1 = tmp;
        tmp = tmp->link;
        free(tmp1);
    }
}
int main()
{
    int n;
    printf("Enter Number of vertices:");
    scanf("%d", &n);
    int a[n][n];
    srand(time(NULL));
    // Storing generated Random Adjacency Matrix of a complete graph
    for (size_t j = 0; j < n; ++j)
    {
        for (size_t i = j; i < n; ++i)
        {
            if (j != i)
            {
                a[j][i] = 1 + rand() % 9;
                a[i][j] = a[j][i];
            }
            else
            {
                a[j][i] = 0;
            }
        }
    }
    printf("\nAdjacency Matrix\n");
    // Printing Adjacency Matrix of a complete graph printf(" ");
    for (size_t i = 0; i < n; ++i)
    {
        printf("%zu ", i);
    }
    puts("");
    for (size_t i = 0; i < n; ++i)
    {
        printf("%zu ", i);
        for (size_t j = 0; j < n; ++j)
        {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    puts("");
    printf("\nMINIMUN SPANNING TREE\n");
    printf("\n by PRIM'S ALGORITHM\n");
    NonTree(n);
    int y = 0, x = 0, min = a[0][1];
    deletebyKey(x);
    for (int i = 1; i < n; ++i)
    {
        if (min >= a[x][i])
        {
            min = a[x][i];
            y = i;
        }
    }
    insertp(x, y, min);
    x = y;
    deletebyKey(x);
    while (nonT)
    {
        struct Ver *tmp = nonT;
        min = a[x][tmp->v];
        y = tmp->v;
        while (tmp)
        {
            if (min >= a[x][tmp->v])
            {
                min = a[x][tmp->v];
                y = tmp->v;
            }
            tmp = tmp->next;
        }
        insertp(x, y, min);
        x = y;
        deletebyKey(x);
    }
    printandFreeMSTp();
    printf("\n by KRUSKAL'S ALGORITHM\n");
    NonTree(n);
    min = a[0][1];
    x = 0;
    y = 1;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = i; j < n; ++j)
        {
            if (min >= a[i][j] && i != j)
            {
                min = a[i][j];
                x = i;
                y = j;
            }
        }
    }
    insertk(x, y, min);
    deletebyKey(x);
    deletebyKey(y);
    while (nonT)
    {
        struct Ver *tmp = nonT;
        struct MST *tmp1 = MSTk;
        min = a[tmp1->p][tmp->v];
        x = tmp1->p;
        y = tmp->v;
        while (tmp)
        {
            if (min >= a[tmp1->p][tmp->v])
            {
                min = a[tmp1->p][tmp->v];
                x = tmp1->p;
                y = tmp->v;
            }
            tmp = tmp->next;
        }
        while (tmp1)
        {
            tmp = nonT;
            while (tmp)
            {
                if (min >= a[tmp1->c][tmp->v])
                {
                    min = a[tmp1->c][tmp->v];
                    x = tmp1->c;
                    y = tmp->v;
                }
                tmp = tmp->next;
            }
            tmp1 = tmp1->link;
        }
        insertk(x, y, min);
        deletebyKey(y);
    }
    printandFreeMSTk();
    return 0;
}