#include <bits/stdc++.h>
using namespace std;

struct nodeType
{
    int info;
    struct nodeType *left;
    struct nodeType *right;
};

typedef struct nodeType *nodeptr;
nodeptr root;

int insertNode(int Item)
{
    nodeptr p, newNode, back;

    p = root;
    back = NULL;

    newNode = (nodeType *)malloc(sizeof(nodeType));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->info = Item;

    while (p != NULL)
    {
        back = p;
        if (p->info > Item)
            p = p->left;
        else
            p = p->right;
    }

    if (back == NULL)
        root = newNode;
    else if (back->info > Item)
        back->left = newNode;
    else
        back->right = newNode;

    return 0;
}

nodeptr deleteNode(nodeptr root, int item)
{
    if (root == NULL)
        return root;

    if (item < root->info)
        root->left = deleteNode(root->left, item);

    else if (item > root->info)
        root->right = deleteNode(root->right, item);

    else
    {
        if (root->left == NULL)
        {
            nodeptr temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            nodeptr temp = root->left;
            free(root);
            return temp;
        }

        nodeptr temp = root->right;

        while (temp->left != NULL)
            temp = temp->left;

        root->info = temp->info;

        root->right = deleteNode(root->right, temp->info);
    }

    return root;
}

void inOrder(nodeptr p)
{
    if (p != NULL)
    {
        inOrder(p->left);
        printf("%d ", p->info);
        inOrder(p->right);
    }
}

void preOrder(nodeptr p)
{
    if (p != NULL)
    {
        printf("%d ", p->info);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void postOrder(nodeptr p)
{
    if (p != NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        printf("%d ", p->info);
    }
}

void Display()
{
    if (root)
    {
        printf("\nTraverse Tree INORDER\n");
        inOrder(root);

        printf("\nTraverse Tree PREORDER\n");
        preOrder(root);

        printf("\nTraverse Tree POSTORDER\n");
        postOrder(root);

        printf("\n");
    }
    else
    {
        printf("\nBST IS NULL\n");
    }
}

int menu()
{
    int n;

    printf("\n\nMain Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n\n");
    printf("Enter Choice(1-4): ");
    scanf("%d", &n);

    return n;
}

int main()
{
    int VAL;
    root = NULL;

    while (1)
    {
        int n = menu();

        if (n == 1)
        {
            printf("\nInsert a value: ");
            scanf("%d", &VAL);
            insertNode(VAL);
        }
        else if (n == 2)
        {
            printf("\nEnter value to delete: ");
            scanf("%d", &VAL);
            root = deleteNode(root, VAL);
        }
        else if (n == 3)
        {
            Display();
        }
        else if (n == 4)
        {
            break;
        }
        else
        {
            printf("\nWrong Choice\n");
        }
    }

    return 0;
}