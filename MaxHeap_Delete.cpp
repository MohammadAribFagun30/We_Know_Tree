#include <iostream>

using namespace std;

void insertIntoMaxHeap(int maxHeap[], int &heapSize, int newValue) {
    heapSize++;
    int currentIndex = heapSize - 1;
    maxHeap[currentIndex] = newValue;

    while (currentIndex != 0 && maxHeap[(currentIndex - 1) / 2] < maxHeap[currentIndex]) {
        int temp = maxHeap[currentIndex];
        maxHeap[currentIndex] = maxHeap[(currentIndex - 1) / 2];
        maxHeap[(currentIndex - 1) / 2] = temp;

        currentIndex = (currentIndex - 1) / 2;
    }
}

void deleteRootFromMaxHeap(int maxHeap[], int &heapSize) {
    if (heapSize <= 0) {
        return;
    }

    maxHeap[0] = maxHeap[heapSize - 1];
    heapSize--;

    int parentIndex = 0;

    while (true) {
        int largestIndex = parentIndex;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        if (leftChildIndex < heapSize && maxHeap[leftChildIndex] > maxHeap[largestIndex]) {
            largestIndex = leftChildIndex;
        }

        if (rightChildIndex < heapSize && maxHeap[rightChildIndex] > maxHeap[largestIndex]) {
            largestIndex = rightChildIndex;
        }

        if (largestIndex != parentIndex) {
            int temp = maxHeap[parentIndex];
            maxHeap[parentIndex] = maxHeap[largestIndex];
            maxHeap[largestIndex] = temp;

            parentIndex = largestIndex;
        } else {
            break;
        }
    }
}

int main() {
    int totalNodes;
    cin >> totalNodes;

    int maxHeap[totalNodes];
    int heapSize = 0;

    for (int inputIndex = 0; inputIndex < totalNodes; inputIndex++) {
        int newValue;
        cin >> newValue;
        insertIntoMaxHeap(maxHeap, heapSize, newValue);
    }

    deleteRootFromMaxHeap(maxHeap, heapSize);

    for (int outputIndex = 0; outputIndex < heapSize; outputIndex++) {
        cout << maxHeap[outputIndex] << " ";
    }

    cout << endl;

    return 0;
}