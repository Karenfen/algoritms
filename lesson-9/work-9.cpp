// Author - Ilia Kiselev

#include <cstdlib>
#include <iostream>

#define SZ 10
#define SIZE 100
#define true 1==1
#define false 1!=1

typedef struct{
    int pr;
    int dat;
} Node;

Node* ARR[SZ];
int head;
int tail;
int items;

void init(){
    for (int i = 0; i < SZ; i++){
        ARR[SZ] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void printQ(){
    for(int i = 0; i < SZ; i++){
        if(ARR[i] == NULL){
            std::cout << "[*, *] ";
        }else{
            printf("[%d, %d] ", ARR[i]->pr, ARR[i]->dat);
        }
    }
    std::cout << std::endl;
}

// TASK-1 =================================

void insert(int pr, int dat){
    Node* element = (Node*)malloc(sizeof(Node));
    element->pr = pr;
    element->dat = dat;

    if (items == SZ){
        std::cout << "Queue is full!" << std::endl;
        return;
    }
    
    ARR[tail++ % SZ] = element;
    items++;
}

Node* remove(){
    if (items == 0){
        std::cout << "Queue is empty!" << std::endl;
        return NULL;
    } else if (items == 1){
        int indx = head++ % SZ;
        Node* temp = ARR[indx];
        ARR[indx] = NULL;
        items--;
        return temp; 
    }else{
        int i, index;

        for(int k = 1; k <= SZ; k++){
            for (i = head; i < tail; i++){
                index = i % SZ;

                if (ARR[index]->pr == k){
                    Node* temp = ARR[index];
                    Node* swap;

                    while(i > head){
                        index = i % SZ;
                        swap = ARR[index];
                        ARR[index] = ARR[index-1];
                        ARR[index-1] = swap;
                        i--;
                    }
                    ARR[head] = NULL;
                    items--;
                    head++;
                    return temp;
                }
            }
        }

    }
}

// TASK-2 =================================
    typedef int boolean;

    int stack[SIZE] = {0};
    int cursor = -1;

boolean push(int data){
    if (cursor < SIZE){
        stack[++cursor] = data;
        return true;
    }else {
        std::cout << "Stack overflow!" << std::endl;
        return false;
    }
}

int pop(){
    if(cursor != -1){
        return stack[cursor--];
    }else{
        std::cout << "Stack is empty!" << std::endl;
    }
}

void bynary(int n){
    std::cout << "Binary form of number " << n << " : " << std::endl;

    if (n == 0){
        std::cout << 0 << std::endl;
    }

    while (n > 0){
        push(n % 2);
        n /=2;
    }

    while (cursor != -1){
        printf("%2d", pop());
    }

    std::cout << std::endl;
}

int main (const int argc, const char** argv){
/// TASK-1 ------------------------
    std::cout << "TASK-1 ------------------------" << std::endl;

    init();
    printQ();
    insert(8, 13);
    insert(2, 12);
    insert(1, 10);
    insert(6, 11);
    insert(4, 14);
    insert(1, 16);
    insert(3, 15);
    insert(2, 18);
    printQ();
    remove();
    remove();
    remove();
    remove();
    printQ();
    insert(1, 13);
    insert(2, 12);
    insert(1, 10);
    insert(6, 11);
    insert(4, 14);
    insert(5, 16);
    insert(7, 16);
    printQ();

// TASK-2 -----------------------------
    std::cout << "TASK-2 ------------------------" << std::endl;

    int num;

    std::cout << "Inter a number: ";
    std::cin >> num;
    
    bynary(num);

    system("pause");
    return 0;
}