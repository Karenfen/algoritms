// Author - Ilia Kiselev

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

// Функция перестановки.
void swap (int* a, int* b){
    int val = *a;
    *a = *b;
    *b = val;
}

// Медиана.
int median(int* a, int* b, int* c){
    int val;

    if (*a >= *b && *a >= *c){
        val = (*b > *c)? *b : *c;
        swap(c, (*b > *c)? b : c);
        return val;
    } else if (*b >= *a && *b >= *c){
        val = (*a > *c)? *a : *c;
        swap(c, (*a > *c)? a : c);
        return val;
    } else {
        val = (*a > *b)? *a : *b;
        swap(c, (*a > *b)? a : b);
        return val;
        }
}

// Функция улучшенной быстрой сортировки.
void qSort(int* arr, int first, int last){
    int a = first;
    int b = last;

    if ((b - a + 1) > 10){
        int mid = median(&arr[first], &arr[last], &arr[(first + last) / 2]);

        do {
            while (arr[a] < mid) a++;
            while (arr[b] > mid) b--;

            if(a <= b){
                swap (&arr[a], &arr[b]);
                a++;
                b--;
            }
        } while (a <= b);

        if(a < last) qSort(arr, a, last);
        if(b > first) qSort(arr, first, b);
    }else{
        int val, pos;
        int len = last - first + 1;

        for(int i = first + 1; i < last + 1; ++i){
            val = arr[i];
            pos = i - 1;

            while (pos >= 0 && arr[pos] > val){
                arr[pos + 1] = arr[pos];
                pos--;
            }
            arr[pos + 1] = val;
        }
    }
}

// Функция блочной сортировки.
void bSort(int* arr, int len){
    const int max = len;
    const int b = 10;

    int buckets[b][max + 1];
    for (int i = 0; i < b; i++){
        buckets[i][max] = 0;
    }

    for (int dig = 1; dig < 100000000; dig*=10){
        for (int i = 0; i < max; i++){
            while (arr[i] % 2 != 0) i++;
            int d = (arr[i] / dig) % b;
           buckets[d][buckets[d][max]++] = arr[i];
        }
        int id = 0;
        for (int i = 0; i < b; i++){
            for (int j = 0; j < buckets[i][max]; j++){
                while (arr[id] % 2 != 0) id++;
                arr[id++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

// Функция заполнения массива.
void randomArray (int* arr, int len, int S){
    for(int i = 0; i < len; i++){
        *(arr + i) = rand() % S;
    }
}

// Функция печати массива.
void printArray (int*arr, int len){
    for (int i = 0; i < len; i++){
        printf("%4d", arr[i]);
    }
    cout << endl;
}

void divide(int* a){
    cout << "TASK - " << *a <<" -----------------------------------" << endl;
    *a = *a + 1;
}

int main (const int argc, const char** argv){
    int count = 1;
    const int SIZE = 20;
    int ARR[SIZE] = {0};

// TASK - 1 ------------------------------
    divide(&count);

    randomArray(ARR, SIZE, 1000);
    printArray(ARR, SIZE);
    qSort(ARR, 0, SIZE - 1);
    printArray(ARR, SIZE);

// TASK - 2 ------------------------------
    divide(&count);

    const int LEN = 10;
    int ARRAY[LEN] = {0};

    randomArray(ARRAY, LEN, 10);
    printArray(ARRAY, LEN);
    bSort(ARRAY, LEN);
    printArray(ARRAY, LEN);

    system("pause");
    return 0;
}
