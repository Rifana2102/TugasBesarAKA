#include <iostream>
#include "siswa.h"
using namespace std;

int main() {
    Student students[] = {
        {"Alice", 80, 78, (80 + 78) / 2},
        {"Bob", 65, 70, (65 + 70) / 2},
        {"Charlie", 90, 88, (90 + 88) / 2},
        {"Diana", 85, 80, (85 + 80) / 2},
        {"Eve", 75, 72, (75 + 72) / 2}
    };
    int n = 5;

    cout << "Original Student Data:\n";
    printStudents(students, n);

    // Bubble Sort
    Student bubbleSorted[5];
    for (int i = 0; i < n; i++) {
        bubbleSorted[i] = students[i];
    }
    int bubbleOperationCount = 0;
    bubbleSort(bubbleSorted, n, bubbleOperationCount);

    // Merge Sort
    Student mergeSorted[5];
    for (int i = 0; i < n; i++) {
        mergeSorted[i] = students[i];
    }
    int mergeOperationCount = 0;
    mergeSort(mergeSorted, 0, n - 1, mergeOperationCount);

    cout << "\nFinal Sorted Order (Bubble Sort):\n";
    printStudents(bubbleSorted, n);

    cout << "\nOperation Counts per Student (Bubble Sort):\n";
    for(int i = 0; i < n; i++) {
        cout << bubbleSorted[i].name << ": " << bubbleOperationCount/n << " operations\n";
    }
    cout << "Total Bubble Sort Operations: " << bubbleOperationCount << "\n";

    cout << "\nFinal Sorted Order (Merge Sort):\n";
    printStudents(mergeSorted, n);

    cout << "\nOperation Counts per Student (Merge Sort):\n";
    for(int i = 0; i < n; i++) {
        cout << mergeSorted[i].name << ": " << mergeOperationCount/n << " operations\n";
    }
    cout << "Total Merge Sort Operations: " << mergeOperationCount << "\n";

    return 0;
}
