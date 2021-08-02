// Author - Ilia Kiselev

#include <cstdlib>
#include <iostream>

#define Q int
using namespace std;

typedef struct Node {
    Q date;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    int size;
} List;

void initList (List *lst){
    lst->head = NULL;
    lst->size = 0;
}

void insertNode (List *lst, Q data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->date = data;
    newNode->next = NULL;

    if (lst->head == NULL){
        lst->head = newNode;
        lst->size++;
        return;
    }

    Node *current = lst->head;

    while (current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    lst->size++;
}

Node *removeNode (List *lst, Q val){
    
}
void printList (List *lst){

}

// Task-1 ====================================

// Task-2 ====================================

void copyList(Node* list){

}

// Task-3 ====================================

int main (const int argc, const char** argv){
// Task-1 ====================================
cout << "// Task-1 ====================================" << endl;

// Task-2 ====================================
cout << "// Task-1 ====================================" << endl;

// Task-3 ====================================
cout << "// Task-1 ====================================" << endl;

    system("pause");
    return 0;
}