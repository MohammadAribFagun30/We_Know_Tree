#include <bits/stdc++.h>

using namespace std;

void adjustHeap(int arr[], int size, int root) {
    int maxIndex = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < size && arr[leftChild] > arr[maxIndex]) {
        maxIndex = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[maxIndex]) {
        maxIndex = rightChild;
    }

    if (maxIndex != root) {
        int swapValue = arr[root];
        arr[root] = arr[maxIndex];
        arr[maxIndex] = swapValue;

        adjustHeap(arr, size, maxIndex);
    }
}

void performHeapSort(int arr[], int length) {
    for (int parent = length / 2 - 1; parent >= 0; parent--) {
        adjustHeap(arr, length, parent);
    }

    for (int endPos = length - 1; endPos > 0; endPos--) {
        int swapValue = arr[0];
        arr[0] = arr[endPos];
        arr[endPos] = swapValue;

        adjustHeap(arr, endPos, 0);
    }
}

int main() {
    int totalElements;
    cin >> totalElements;

    int numbers[totalElements];

    for (int index = 0; index < totalElements; index++) {
        cin >> numbers[index];
    }

    performHeapSort(numbers, totalElements);

    for (int index = 0; index < totalElements; index++) {
        cout << numbers[index] << " ";
    }

    cout << "\n";
    return 0;
}