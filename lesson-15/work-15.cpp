// Author - Ilia Kiselev

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

/// other ///
void divide(int* a){
    *a = *a + 1;
    cout << endl << "TASK - " << *a <<" -----------------------------------" << endl << endl;
}

//// TASK - 1 ------------------------------
unsigned int getHash (string str) {
    unsigned int result = 0xF;
    int i = 0;

    while (str[i] != '\0') {
        unsigned int N = 0xF;
        N = str[i] * pow(33, i);
        result += N;
        i++;
    }
    return result;
}

//// TASK - 2 ------------------------------
void smartWallet (int *arr, const int S, int MAX) {
    int sum = 0;
    int amount = 0;
    for (int i = 0; i < S; i++) {
        while (sum + arr[i] <= MAX) {
            sum += arr[i];
            amount++;
            cout << arr[i] << " ";
        }
    }
    cout << endl << "minimum of coins: " << amount << endl;
    cout << "max sum: " << sum << endl;
}

int main (const int argc, const char **argv) {
    int count = 0;   /// Other ///
    divide(&count);  /// Other ///
//// TASK - 1 ------------------------------

    string value;

    cout << "Inter a line: ";
    getline(cin, value);

    printf("Hash: %x\n", getHash(value));
    
    divide(&count);  /// Other ///
//// TASK - 2 ------------------------------

    const int size = 5;
    int denom[size] = {50, 10, 5, 2, 1};
    int amount = 0;
    int sum = 98;

    smartWallet(denom, size, sum);

    cout << endl;
    system("pause");  /// Other ///
    return 0;
}