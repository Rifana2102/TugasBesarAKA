#ifndef SISWA_H_INCLUDED
#define SISWA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int semesterScore;
    int dailyScore;
    int averageScore;
};

// Function declarations
void mergeSort(Student arr[], int left, int right, int& operationCount);
void merge(Student arr[], int left, int mid, int right, int& operationCount);
void bubbleSort(Student arr[], int n, int& operationCount);
void printStudents(Student arr[], int n);



#endif // SISWA_H_INCLUDED
