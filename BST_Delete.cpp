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
        cout << p->info << " ";
        inOrder(p->right);
    }
}

void preOrder(nodeptr p)
{
    if (p != NULL)
    {
        cout << p->info << " ";
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
        cout << p->info << " ";
    }
}

void Display()
{
    if (root)
    {
        cout << "\nTraverse Tree INORDER\n";
        inOrder(root);

        cout << "\nTraverse Tree PREORDER\n";
        preOrder(root);

        cout << "\nTraverse Tree POSTORDER\n";
        postOrder(root);

        cout << "\n";
    }
    else
    {
        cout << "\nBST IS NULL\n";
    }
}

int menu()
{
    int n;

    cout << "\n\nMain Menu\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Display\n";
    cout << "4. Exit\n\n";
    cout << "Enter Choice(1-4): ";
    cin >> n;

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
            cout << "\nInsert a value: ";
            cin >> VAL;
            insertNode(VAL);
        }
        else if (n == 2)
        {
            cout << "\nEnter value to delete: ";
            cin >> VAL;
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
            cout << "\nWrong Choice\n";
        }
    }

    return 0;
}