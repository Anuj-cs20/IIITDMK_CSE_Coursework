// 2. Create a Binary Search Tree(BST) from random N numbers.
// N should be taken as input from the user.Using the same N numbers,
// create the corresponding AVL tree.Show the height difference
// between both these trees(BST vs AVL).
// cs20b1100 K.Anuj
// Complexity: O(nlogn)

#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int value;
    struct BST *left;
    struct BST *right;
    int height;
};

struct AVL
{
    int key;
    struct AVL *left;
    struct AVL *right;
    int height;
};

int AVLheight(struct AVL *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int BSTheight(struct BST *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct AVL *newNode(int key)
{
    struct AVL *node = (struct AVL *)malloc(sizeof(struct AVL));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct AVL *rightRotate(struct AVL *y)
{
    struct AVL *x = y->left;
    struct AVL *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(AVLheight(y->left), AVLheight(y->right)) + 1;
    x->height = max(AVLheight(x->left), AVLheight(x->right)) + 1;
    return x;
}

struct AVL *leftRotate(struct AVL *x)
{
    struct AVL *y = x->right;
    struct AVL *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(AVLheight(x->left), AVLheight(x->right)) + 1;
    y->height = max(AVLheight(y->left), AVLheight(y->right)) + 1;
    return y;
}

int getBalance(struct AVL *N)
{
    if (N == NULL)
        return 0;
    return AVLheight(N->left) - AVLheight(N->right);
}

struct AVL *insert(struct AVL *node, int key)
{
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(AVLheight(node->left), AVLheight(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct BST *createNode(int data)
{
    struct BST *newNode = malloc(sizeof(struct BST));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

struct BST *insertNode(struct BST *current, int data)
{
    if (current == NULL)
        return createNode(data);
    if (current->value < data)
        current->right = insertNode(current->right, data);
    else if (current->value > data)
        current->left = insertNode(current->left, data);
    current->height = 1 + max(BSTheight(current->left), BSTheight(current->right));
    return current;
}

void deleteBSTTree(struct BST *node)
{
    if (node == NULL)
        return;
    deleteBSTTree(node->left);
    deleteBSTTree(node->right);
    free(node);
}

void deleteAVLTree(struct AVL *node)
{
    if (node == NULL)
        return;
    deleteAVLTree(node->left);
    deleteAVLTree(node->right);
    free(node);
}

int main()
{
    int x, n;
    struct BST *root1 = NULL;
    struct AVL *root2 = NULL;
    printf("Enter values of tree\n");
    scanf("%d", &n);
    x = rand() % 100;
    root1 = insertNode(root1, x);
    root2 = insert(root2, x);
    for (int i = 1; i < n; ++i)
    {
        x = rand() % 100;
        insertNode(root1, x);
        root2 = insert(root2, x);
    }
    printf("Height difference between both these trees(BST vs AVL) is %d\n", (root1->height - root2->height));
    deleteBSTTree(root1);
    deleteAVLTree(root2);
    return 0;
}