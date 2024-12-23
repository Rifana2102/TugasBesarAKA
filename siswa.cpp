#include <iostream>
#include "siswa.h"

using namespace std;

// Merge function for mergeSort
void merge(Student arr[], int left, int mid, int right, int& operationCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student* leftArr = new Student[n1];
    Student* rightArr = new Student[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        operationCount++; // Increment operation count for comparison
        if (leftArr[i].averageScore <= rightArr[j].averageScore) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
        operationCount++;
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
        operationCount++;
    }

    delete[] leftArr;
    delete[] rightArr;
};

// Recursive mergeSort
void mergeSort(Student arr[], int left, int right, int& operationCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, operationCount);
        mergeSort(arr, mid + 1, right, operationCount);
        merge(arr, left, mid, right, operationCount);
    }
};

// Iterative bubbleSort
void bubbleSort(Student arr[], int n, int& operationCount) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            operationCount++; // Comparison
            if (arr[j].averageScore > arr[j + 1].averageScore) {
            swap(arr[j], arr[j + 1]);
            operationCount++; // Swap
            }
        }
    }
};

// Print students
void printStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].name
             << ", Semester Score: " << arr[i].semesterScore
             << ", Daily Score: " << arr[i].dailyScore
             << ", Average Score: " << arr[i].averageScore << endl;
    }
};
