// Author - Ilia Kiselev
// created from Code Blocks

#include <cstdlib>

bool primeNumb (int a){
    bool isPrime = 1;

    for (int i = 2; i < a / 2; i++){
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
