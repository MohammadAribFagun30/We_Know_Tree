#include <iostream>

using namespace std;

void insertIntoMaxHeap(int maxHeap[], int &heapSize, int value) {
    heapSize++;
    int index = heapSize - 1;
    maxHeap[index] = value;

    while (index != 0 && maxHeap[(index - 1) / 2] < maxHeap[index]) {
        int temp = maxHeap[index];
        maxHeap[index] = maxHeap[(index - 1) / 2];
        maxHeap[(index - 1) / 2] = temp;

        index = (index - 1) / 2;
    }
}

int main() {
    int n;
    cin >> n;

    int maxHeap[n];
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        insertIntoMaxHeap(maxHeap, heapSize, num);
    }

    for (int i = 0; i < heapSize; i++) {
        cout << maxHeap[i] << " ";
    }

    cout << endl;

    return 0;
}