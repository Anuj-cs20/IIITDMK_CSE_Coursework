// 1. Create an integer Binary Tree (height>=3) of your choice using Linked List.
// Fill the integers randomly. After creation of the Tree,
// Write the recursive functions for Pre-Order, In-Order and Post-Order traversals.
//  While traversing, find the Mean and Standard Deviation of the elements in the tree.
// cs20b1100 K.Anuj
// Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    float data;
    struct node *left;
    struct node *right;
} *root;
float s, m;
int n = 0;
struct node *createBinaryTree()
{
    struct node *p;
    float x;
    printf("Enter data(-1 for no data):");
    scanf("%f", &x);
    if (x == -1)
    {
        return NULL;
    }
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    printf("Enter left child of %f:\n", x);
    p->left = createBinaryTree();
    printf("Enter right child of %f:\n", x);
    p->right = createBinaryTree();
    return p;
}
void inorder(struct node *t1)
{
    if (t1)
    {
        inorder(t1->left);
        printf("%f ", t1->data);
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
        printf("%f ", t2->data);
        s += t2->data;
        m += pow(t2->data, 2);
        ++n;
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
        printf("%f ", t3->data);
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
    root = (struct node *)malloc(sizeof(struct node));
    root = createBinaryTree();
    printf("\nThe inorder traversal of tree is:\n");
    inorder(root);
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\nThe postorder traversal of tree is:\n");
    postorder(root);
    printf("\nMean and Standard Deviation of the elements in the tree\n");
    s = (float)s / n;
    printf("%f\n", s);

    m = (float)m / n;
    m = m - pow(s, 2);
    m = sqrt(m);
    printf("%f\n", m);
    deleteTree(root);
    return 0;
}
