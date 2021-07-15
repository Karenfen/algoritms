// Author - Ilia Kiselev
// created from Code Blocks

#include <stdio.h>

int primeNumb (int a){
    int isPrime = 1;

    for (int i = 2; i < a; i++){
     if (a % i == 0){
        isPrime = 0;
        break;
     }
    }
   return isPrime;
}

int main (const int argc, const char**argv){

int num;

printf("inter a number for check: ");
scanf("%d", &num);

if(primeNumb(num)){
    printf("number %d is prime\n", num);
}else{
   printf("number %d is not prime\n", num);
}

return 0;
}
