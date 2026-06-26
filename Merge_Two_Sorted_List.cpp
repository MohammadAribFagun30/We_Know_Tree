#include <iostream>

using namespace std;

void combineArrays(int firstArr[], int size1, int secondArr[], int size2, int finalArr[]) {
    int p = 0, q = 0, r = 0;

    while (p < size1 && q < size2) {
        if (firstArr[p] < secondArr[q]) {
            finalArr[r] = firstArr[p];
            p++;
        } else {
            finalArr[r] = secondArr[q];
            q++;
        }
        r++;
    }

    while (p < size1) {
        finalArr[r] = firstArr[p];
        p++;
        r++;
    }

    while (q < size2) {
        finalArr[r] = secondArr[q];
        q++;
        r++;
    }
}

int main() {
    int lengthA, lengthB;

    cin >> lengthA >> lengthB;

    int firstArray[lengthA], secondArray[lengthB], mergedArray[lengthA + lengthB];

    for (int index = 0; index < lengthA; index++) {
        cin >> firstArray[index];
    }

    for (int index = 0; index < lengthB; index++) {
        cin >> secondArray[index];
    }

    combineArrays(firstArray, lengthA, secondArray, lengthB, mergedArray);

    for (int index = 0; index < lengthA + lengthB; index++) {
        cout << mergedArray[index] << " ";
    }

    cout << endl;

    return 0;
}