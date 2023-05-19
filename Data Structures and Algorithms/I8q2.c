// 2. Create a Complete Binary Tree made up of all the alphabets (A to Z) using Linked List.
//  A is the root of the tree. B and C will be the left and right children of A,
// respectively, and so on. Write the recursive functions for Pre-Order, In-Order
// and Post-Order traversals to print the elements in the Tree.
// cs20b1100 K.Anuj
// Complexity: O(1)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
} *root, *HEAD, *FRONT, *REAR;
int size = 0;

void enqueue(struct node *newnode)
{
    if (FRONT == HEAD)
    {
        HEAD->right = newnode;
        HEAD->left = NULL;
        FRONT = newnode;
        REAR = newnode;
        REAR->right = NULL;
        ++size;
    }
    else
    {
        REAR->right = newnode;
        REAR = newnode;
        REAR->right = NULL;
        ++size;
    }
}

struct node *dequeue()
{
    struct node *tmp = FRONT;
    if (FRONT == REAR)
    {
        FRONT = HEAD;
        REAR = HEAD;
        HEAD->right = NULL;
        tmp->right = NULL;
        --size;
        return tmp;
    }
    else if (FRONT == HEAD)
    {
        return NULL;
    }
    else
    {
        FRONT = FRONT->right;
        HEAD->right = FRONT;
        tmp->right = NULL;
        --size;
        return tmp;
    }
}

struct node *createBinaryTree()
{
    int i = 65;
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = i;
    p->right = NULL;
    p->left = NULL;
    enqueue(p);
    ++i;
    do
    {
        struct node *tmp, *newnode1;
        newnode1 = (struct node *)malloc(sizeof(struct node));
        newnode1->right = NULL;
        newnode1->left = NULL;
        tmp = dequeue();
        tmp->left = newnode1;
        newnode1->data = i;
        ++i;
        enqueue(tmp->left);
        if (i <= 90)
        {
            struct node *newnode2;
            newnode2 = (struct node *)malloc(sizeof(struct node));
            newnode2->right = NULL;
            newnode2->left = NULL;
            tmp->right = newnode2;
            newnode2->data = i;
            ++i;
            enqueue(tmp->right);
        }
        else
        {
            tmp->right = NULL;
        }
    } while (i <= 90);
    if (i > 90)
    {
        while (size > 0)
        {
            struct node *tmp1;
            tmp1 = dequeue();
            tmp1->right = NULL;
            tmp1->left = NULL;
        }
    }
    return p;
}

void inorder(struct node *t1)
{
    if (t1)
    {
        inorder(t1->left);
        printf("%c ", t1->data);
        inorder(t1->right);
    }
    if (root == NULL)
    {
        printf("!!!Tree is empty!!!");
    }
}

void preorder(struct node *t2)
{
    if (t2)
    {
        printf("%c ", t2->data);
        preorder(t2->left);
        preorder(t2->right);
    }
    if (root == NULL)
    {
        printf("!!!Tree is empty!!!");
    }
}

void postorder(struct node *t3)
{
    if (t3)
    {
        postorder(t3->left);
        postorder(t3->right);
        printf("%c ", t3->data);
    }

    if (root == NULL)
    {
        printf("!!!Tree is empty!!!");
    }
}

void deleteTree(struct node *node)
{
    if (node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}

int main()
{
    HEAD = (struct node *)malloc(sizeof(struct node));
    FRONT = HEAD;
    REAR = HEAD;
    root = (struct node *)malloc(sizeof(struct node));
    root = createBinaryTree();
    printf("\nThe inorder traversal of tree is:\n");
    inorder(root);
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\nThe postorder traversal of tree is:\n");
    postorder(root);
    deleteTree(root);
    return 0;
}