// 1. Create a doubly Linked List(Two - way Linked List) from the
// Calander month names(January, February, March........December).
// Convert this to it's corresponding balanced Binary Search Tree (BST).
// Perform the In-order traversal.
// cs20b1100 K.Anuj
// Complexity: O(1)

#include <stdio.h>
#include <stdlib.h>

struct BST
{
    char *month;
    struct BST *left;
    struct BST *right;
} *head, *last, *root;

void createTwowayLinkedList()
{
    for (int i = 0; i < 12; ++i)
    {
        struct BST *ptr, *prv;
        ptr = (struct BST *)malloc(sizeof(struct BST));
        if (i == 0)
        {
            prv = ptr;
            head = ptr;
            ptr->left = NULL;
            ptr->right = NULL;
        }
        else
        {
            ptr->left = prv;
            prv->right = ptr;
            ptr->right = NULL;
            prv = prv->right;
            if (i == 11)
            {
                last = ptr;
            }
        }
        switch (i)
        {
        case 0:
            ptr->month = "january";
            break;
        case 1:
            ptr->month = "february";
            break;
        case 2:
            ptr->month = "march";
            break;
        case 3:
            ptr->month = "april";
            break;
        case 4:
            ptr->month = "may";
            break;
        case 5:
            ptr->month = "june";
            break;
        case 6:
            ptr->month = "july";
            break;
        case 7:
            ptr->month = "august";
            break;
        case 8:
            ptr->month = "september";
            break;
        case 9:
            ptr->month = "october";
            break;
        case 10:
            ptr->month = "november";
            break;
        case 11:
            ptr->month = "december";
            break;
        }
    }
}

struct BST *createBinarySearchTree(struct BST *tmp1, struct BST *tmp2)
{
    struct BST *p, *tmp3, *tmp4;
    tmp3 = tmp1;
    tmp4 = tmp2;
    while (tmp1 != tmp2)
    {
        tmp1 = tmp1->right;
        if (tmp1 == tmp2)
        {
            p = tmp1;
            p->left = createBinarySearchTree(tmp3, tmp2->left);
            if (tmp1 == tmp4)
            {
                p->right = NULL;
            }

            else
            {
                p->right = createBinarySearchTree(tmp1->right, tmp4);
            }
            return p;
        }
        tmp2 = tmp2->left;
        if (tmp1 == tmp2)
        {
            p = tmp1;
            p->left = createBinarySearchTree(tmp3, tmp2->left);
            p->right = createBinarySearchTree(tmp1->right, tmp4);
            return p;
        }
    }
    tmp1->right = NULL;
    tmp1->left = NULL;
    p = tmp1;
    return p;
}

void inorder(struct BST *t1)
{
    if (t1)
    {
        inorder(t1->left);
        printf("%s ", t1->month);
        inorder(t1->right);
    }
    if (root == NULL)
    {
        printf("!!!Tree is empty!!!");
    }
}

void deleteTree(struct BST *node)
{
    if (node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}

int main()
{
    createTwowayLinkedList();
    root = createBinarySearchTree(head, last);
    printf("\nThe inorder traversal of tree is:\n");
    inorder(root);
    deleteTree(root);
    return 0;
}
