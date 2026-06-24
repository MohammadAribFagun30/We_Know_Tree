#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

Node* root = nullptr;

void insertNode(int Item) {
    Node* newNode = new Node();
    newNode->info = Item;
    newNode->left = nullptr;
    newNode->right = nullptr;

    Node* p = root;
    Node* back = nullptr;

    while (p != nullptr) {
        back = p;
        if (p->info > Item) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    if (back == nullptr) {
        root = newNode;
    } else if (back->info > Item) {
        back->left = newNode;
    } else {
        back->right = newNode;
    }
}

bool searchNode(int target) {
    Node* p = root;
    
    while (p != nullptr) {
        if (p->info == target) {
            return true;
        } else if (p->info > target) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return false;
}

int main() {
    int N;
    cout<<"Enter Number of elements : ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        int VAL;
        cout<<"Search value : ";
        cin >> VAL;
        insertNode(VAL);
    }

    int target;
    cin >> target;

    if (searchNode(target)) {
        cout << "Element found in the tree." << endl;
    } else {
        cout << "Element not found in the tree." << endl;
    }

    return 0;
}