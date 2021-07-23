// Author - Kiselev Ilia

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

// Функция заполнения массива.
void randomArray (int* arr, int len){
    for(int i = 0; i < len; i++){
        *(arr + i) = rand() % len;
    }
}

// Функция печати массива.
void printArray (int*arr, int len){
    for (int i = 0; i < len; i++){
        printf("%4d", arr[i]);
    }
    cout << endl;
}

// Функция перестановки.
void swap (int* a, int* b){
    int val = *a;
    *a = *b;
    *b = val;
}

// Функция пузырьковой сортировки массива.
void sortArray (int* arr, int len){
    for(int j = 0; j < len; j++){
        for (int i = 0; i < len - 1 - j; i++){
            if (*(arr + i) > *(arr + i + 1)){
                swap(&arr[i], &arr[i + 1]);
            }
        }
    }
}

// Функция заполнения массива числами вручную.
void INSERT (int* arr, int len){
    printf("Inter %d numbers: \n", len);

    for (int i = 0; i < len; i++){
        cin >> arr[i];
    }
}

// Функция инвертирования массива.
void REVERT (int* arr, int len){
    for (int i = 0; i < len / 2; i++){
        swap(&arr[i], &arr[len - i - 1]);
    }
}

// Функция проверки элементов массива.
void checkArray (int* arr, int len){
    for(int i = 0; i < len; i++){
        if((sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3)) > 400){
            printf("%d-th namber ERROR!\n", i + 1);
        }
    }
}

void divide(int* a){
    cout << "TASK - " << *a++ <<" -----------------------------------" << endl;
}

int main (const int argc, const char** argv){

    int cnt = 1;

// TASK-1 -----------------------------------

    const int SIZE = 10;
    int array[SIZE] = {0};

    divide(&cnt);

    randomArray(array, SIZE);
    printArray(array, SIZE);
    sortArray(array, SIZE);
    printArray(array, SIZE);

// TASK-2 -----------------------------------

    const int AMO = 11;
    int SEQ[AMO] = {0};

    divide(&cnt);

    INSERT(SEQ, AMO);
    REVERT(SEQ, AMO);
    printArray(SEQ, AMO);
    checkArray(SEQ, AMO);

    return 0;
}