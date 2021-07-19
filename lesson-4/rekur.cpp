/// Author - Ilia Kiselev

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/// task-1 (Перевод из десятичной в двоичную систему счисления)
void decTObinRecur (int num){
    if(num > 1){
        decTObinRecur (num / 2);
    }
    cout << num % 2;
}

/// task-2 (Возведение числа в степень етеративным способом)
int exponenIter (int num, int ext){
int res = num;

if (num == 1){
    return 1;
}else if(num == 0){
    return 0;
}else {
    for (int i = 1; i < ext; i++){
        res *= num;
    }
return res;
}
}

/// task-3 (Возведение числа в степень рекурсивным способом)
int exponenRecur (int num, int ext){
int res = 1;

if (num == 1){
    return 1;
}else if(num == 0){
    return 0;
}else {
    if (ext > 0){
        res = num * exponenRecur(num, ext - 1);
    }
    return res;
}
}

/// task-4 (Возведение числа в степень рекурсивным способом с учётом чётности степени)
int DoubleExponenRecur (int num, int ext){
int res = 1;

if (num == 1){
    return 1;
}else if(num == 0){
    return 0;
}else {
    if (ext > 0){
        if (ext % 2 == 0){
            num *= num;
            ext /= 2;
         }
        res = num * exponenRecur(num, ext - 1);
    }
    return res;
}
}

/// task-5 (Поиск возможных маршрутов)
int routKing (int** arr, int x, int y){
if (x == 0 && y == 0){
    return 0;
}else if(arr[x][y]){
        return 0;
}else if(y == 0 || x == 0){
        return 1;
}
return routKing(arr, x -1, y) + routKing(arr, x, y -1);
}

int main (const int argc, const char** argv){

int N;
int A;

cout << "Введите число: ";
cin >> N;
decTObinRecur (N);
cout << endl;

cout << "Введите степень, в которую нужно возвести число: ";
cin >> A;
cout << exponenIter(N, A) << endl;
cout << exponenRecur (N, A) << endl;
cout << DoubleExponenRecur (N, A) << endl;

cout << "--------------------------" << endl;

const int X = 8;
const int Y = 8;
int** field = new int*[X];
for (int i = 0; i < X; i++){
    field[i] = new int [Y * sizeof(int)];
}
for (int i = 0; i < X; i++){
    for (int j = 0; j < Y; j++){
        field[i][j] = 0;
    }
}
field[7][5] = 1;
field[5][2] = 1;
field[0][3] = 1;
field[4][7] = 1;
field[6][0] = 1;
field[5][6] = 1;

 for (int i = 0; i < X; i++){
    for(int j = 0; j < Y; j++){
        cout << field[i][j] << " ";
    }
    cout << endl;
 }
cout << "--------------------------" << endl;

  for (int i = 0; i < X; i++){
    for(int j = 0; j < Y; j++){
        cout << routKing(field, i, j) << "\t" << " ";
    }
    cout << endl;
 }

cout << "--------------------------" << endl;



 for (int i = 0; i < X; i++){
    delete []field[i];
 }
 delete []field;
return 0;
}
