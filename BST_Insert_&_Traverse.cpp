/* Binary Search Tree(BST) */

#include <iostream>
#include <cstdlib>

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

    // "Allocate memory for one node and treat the returned address as a nodeType*."
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

void inOrder(nodeptr p)
{
    if (p != NULL)
    {
        inOrder(p->left);
        cout << p->info << "  ";
        inOrder(p->right);
    }
}

void preOrder(nodeptr p)
{
    if (p != NULL)
    {
        cout << p->info << "  ";
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
        cout << p->info << "  ";
    }
}

int menu()
{
    int n;

    cout << "\n\nMain Menu\n";
    cout << "1. Insert\n";
    cout << "2. Display\n";
    cout << "3. Exit\n\n";
    cout << "Enter Choice(1-3): ";
    cin >> n;
    cout << "\n";

    return n;
}

void Display()
{
    if (root)
    {
        cout << "\nTraverse Tree INorder\n";
        inOrder(root);

        cout << "\nTraverse Tree PREorder\n";
        preOrder(root);

        cout << "\nTraverse Tree POSTorder\n";
        postOrder(root);
    }
    else
        cout << "\nBST IS NULL\n";
}

int main()
{
    nodeptr p;
    int VAL;

    root = NULL;

    char ch[11];
    int n = 2;

    n = menu();

    do
    {
        if (n == 1)
        {
            cout << "\nInsert a val :";
            cin >> VAL;
            insertNode(VAL);
            // Display();
        }

        if (n == 2)
        {
            Display();
        }

        if (n == 3)
        {
            cout << "\n";
            break;
        }

        if (n > 3)
            cout << "\nWrong Choice\n";

        n = menu();

    } while (1);

    return 0;
}