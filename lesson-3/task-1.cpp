// Author - Ilia Kiselev
// created from Code Blocks

#include <cstdlib>
#include <iostream>
#include <math.h>

bool primeNumb (int a){
    bool isPrime = 1;
    if (a % 2 == 0) return 0;
    for (int i = 3; i < sqrt(a); i += 2){
     if (a % i == 0){
        isPrime = 0;
        break;
     }
    }
   return isPrime;
}

int main (const int argc, const char**argv){

int num;

std::cout << "inter a number for check: ";
std::cin >> num;

if(primeNumb(num)){
    std::cout << "number " << num <<  " is prime." << std::endl;
}else{
    std::cout << "number " << num <<  " is not prime." << std::endl;
}

system("pause");
return 0;
}
