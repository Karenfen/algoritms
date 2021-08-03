// Author - Ilia Kiselev

#include <cstdlib>
#include <iostream>

#define Q int
#define COPY_LIST copy
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

Node* removeNode (List *lst, Q val){
    if (lst->head == NULL){
        cout << "ERROR! List is empty!" << endl;
        return NULL;
    }

    Node *current = lst->head;
    Node *previous;

    while (current->next != NULL && current->date != val) {
        previous = current;
        current = current->next;
    }

    if (current->date != val) {
        printf("ERROR! Node with value %d is not in the list!\n", val);
        return NULL;
    }

    if (current == lst->head){
       lst->head = current->next;
       lst->size--;
       printf("Node with value %d is deleted!\n", val);
       return current;
    } else {
        previous->next = current->next;
        lst->size--;
        printf("Node with value %d is deleted!\n", val);
        return current;
    }
}

void printNode(Node *N){
    if (N == NULL){
        cout << "[] ";
        return;
    }

    printf("[%d] ", N->date);
    return;
}

void printList (List *lst){
    if (lst->head == NULL){
        cout << "List is empty!" << endl;
        return;
    }

    cout << "LIST: ";
    Node *current = lst->head;

    do {
        printNode(current);
        cout << "-> ";
        current = current->next;
    } while (current != NULL);

    cout << "NULL" << endl;
    cout << "List size: " << lst->size << endl;
}

// Task-1 ====================================

// Task-2 ====================================

bool copyList(List* from_list, List* to_list){
    if (from_list->head == NULL){
        cout << "Origin list is empty!" << endl;
        return false;
    }

    Node *current = from_list->head;
    Node *previous;

    while (current != NULL) {
        insertNode(to_list, current->date);
        current = current->next;
    }
    
    to_list->size = from_list->size;
    cout << "Copying of the list is complete!" << endl;
    cout << "New list:" << endl;

    return true;
}

// Task-3 ====================================

int main (const int argc, const char** argv){

    List *lst = (List*)malloc(sizeof(List));

    initList(lst);
    printList(lst);
    insertNode(lst, 21);
    insertNode(lst, 5);
    insertNode(lst, 12);
    insertNode(lst, 0);
    insertNode(lst, 6);
    printList(lst);    
    free(removeNode(lst, 5));
    printList(lst);
    free(removeNode(lst, 21));
    printList(lst);
    free(removeNode(lst, 5));
    printList(lst);

// Task-1 ====================================
cout << "// Task-1 ====================================" << endl;
    List *COPY_LIST = (List*)malloc(sizeof(List));
    initList(COPY_LIST);
    
    if (copyList(lst, COPY_LIST)) {
        printList(COPY_LIST);
    }
    
// Task-2 ====================================
cout << "// Task-2 ====================================" << endl;


// Task-3 ====================================
cout << "// Task-3 ====================================" << endl;

    system("pause");
    return 0;
}