#include <iostream>

using namespace std;

int findLargest(int numbers[], int size) {
    int largest = numbers[0];

    for (int idx = 1; idx < size; idx++) {
        if (numbers[idx] > largest) {
            largest = numbers[idx];
        }
    }

    return largest;
}

void digitCountingSort(int numbers[], int size, int placeValue) {
    int temp[size];
    int frequency[10] = {0};

    for (int idx = 0; idx < size; idx++) {
        frequency[(numbers[idx] / placeValue) % 10]++;
    }

    for (int digit = 1; digit < 10; digit++) {
        frequency[digit] += frequency[digit - 1];
    }

    for (int idx = size - 1; idx >= 0; idx--) {
        int digit = (numbers[idx] / placeValue) % 10;
        temp[frequency[digit] - 1] = numbers[idx];
        frequency[digit]--;
    }

    for (int idx = 0; idx < size; idx++) {
        numbers[idx] = temp[idx];
    }
}

void performRadixSort(int numbers[], int size) {
    int largest = findLargest(numbers, size);

    for (int place = 1; largest / place > 0; place *= 10) {
        digitCountingSort(numbers, size, place);
    }
}

int main() {
    int totalElements;
    cin >> totalElements;

    int values[totalElements];

    for (int pos = 0; pos < totalElements; pos++) {
        cin >> values[pos];
    }

    performRadixSort(values, totalElements);

    for (int pos = 0; pos < totalElements; pos++) {
        cout << values[pos] << " ";
    }

    cout << endl;

    return 0;
}