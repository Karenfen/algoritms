// Author - Ilia Kiselev

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 8;
int matrix[N][N] = {
    {0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0},
};
int visited[N] = {0};
int STACK[N];
int references[N] = {0};
int cursore = -1;

bool push (int val) {
    if (cursore < N){
        STACK[++cursore] = val;
        return true;
    } else {
        cout << "Stack is full!" << endl;
        return false;
    }
}

int pop(){
    if (cursore >= 0) {
        return STACK[cursore--] ;
    }
}

void popAll () {
    while (cursore >= 0) {
        int value;
        value = pop();
        cout << value << " - " << references[value] << endl;
    }
}

void resetArr (int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

void reset2dArr (int **arr, const int ROWS, const int COLUMNS) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            arr[i][j] = 0;
        }
    }
}

// TASK-1 ====================================

void depthTraversWithStack (int start) {
    int next;
    visited[start] = 1;
    for (next = 0; next < N; next++) {
        if (matrix[start][next] == 1){
            references[start]++;
            if (!visited[next]) {
                depthTraversWithStack(next);
            }
        }
    }
    push(start);
}

// TASK-2 ====================================

void depthTravers (int start = 0) {
    int next;
    visited[start] = 1;
    for (next = 0; next < N; next++) {
        if (matrix[start][next] == 1){
            references[next]++;
            if (!visited[next]) {
                depthTravers(next);
            }
        }
    }
}

void checkAllRefereces () {
    int node[N] = {0};
    int ref[N] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1)
                references[i]++;
        }
    }
    for (int i = 0; i < N; i++) {
        ref[i] = references[i];
        node[i] = i;
    }
    int tempN, tempR, pos;
    for (int i = 1; i < N; ++i) {
        tempN = node[i];
        tempR = ref[i];
        pos = i - 1;
        while (pos >= 0 && ref[pos] > tempR) {
            ref[pos + 1] = ref[pos];
            node[pos + 1] = node[pos];
            pos--;
        }
        ref[pos + 1] = tempR;
        node[pos + 1] = tempN;
    }
    for (int i = N - 1; i >= 0; i--) {
        cout << node[i] << " - " << ref[i] << endl;
    }
    resetArr(references, N);
    resetArr(visited, N);
}

int main (const int argc, const char** argv) {
// TASK-1 ====================================
cout << "TASK-1 ====================================" << endl << endl;

    depthTraversWithStack(1);
    while (cursore >= 0) {
        cout << pop() << " ";
    }
    cout << endl;
    resetArr(visited, N);
    resetArr(references, N);

    depthTraversWithStack(7);
    while (cursore >= 0) {
        cout << pop() << " ";
    }
    cout << endl;
    resetArr(visited, N);
    resetArr(references, N);

cout << endl;
// TASK-2 ====================================
cout << "TASK-2 ====================================" << endl << endl;
    
    depthTraversWithStack(3);
    popAll();
    resetArr(references, N);
    resetArr(visited, N);

cout << endl;

    checkAllRefereces();

system("pause");
return 0;
}