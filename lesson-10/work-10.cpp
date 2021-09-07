// Author - Ilia Kiselev

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

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

    if (newNode == NULL) {
        cout << "Stack overflow!" << endl;
        return;
    }

    newNode->date = data;
    newNode->next = NULL;

    if (lst->head == NULL){
        lst->head = newNode;
        lst->size++;
    } else {
        Node *current = lst->head;
        newNode->next = current;
        lst->head = newNode;
        lst->size++;
    }
}

Node* removeVal (List *lst, Q val){
    if (lst->head == NULL){
        cout << "ERROR! List is empty!" << endl;
        return NULL;
    }

    Node *current = lst->head;
    Node *previous = NULL;

    while (current->next != NULL && current->date != val) {
        previous = current;
        current = current->next;
    }

    if (current->date != val) {
        cout << "ERROR! Node with value (" << val << ") is not deleted!" << endl;
        return NULL;
    }

    if (current == lst->head){
       lst->head = current->next;
       lst->size--;
    } else {
        previous->next = current->next;
        lst->size--;
    }

    cout << "Node with value (" << val << ") is deleted!" << endl;
    return current;
}

void removeAlllist (List *lst) {
    if (lst->head == NULL) {
        cout << "List is empty." << endl;
    } else {
        Node *current = lst->head;

        while (lst->head != NULL) {
            lst->head = current->next;
            free(current);
            current = lst->head;
            lst->size--;
        }
    }
}

void printNode (Node *N){
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
        cout << " -> ";
        current = current->next;
    } while (current != NULL);

    cout << "NULL" << endl;
    cout << "List size: " << lst->size << endl;
}

// Task-1 ====================================

void removeNode (List* lst, Node* element) {
    if (lst->head == element) {
        lst->head = element->next;
        lst->size--;
    } else {
        Node* curent = lst->head;
        Node* previous = NULL;

        while (curent != element){
            previous = curent;
            curent = curent->next;
        }
        previous->next = curent->next;
        free(element);
        lst->size--;
    }
}

void freeList (List* lst, Node* head) {
    if (lst->head == NULL){
        return;
    } else if (head->next == NULL){
        removeNode(lst, head);
        return;
    } else {
        freeList (lst, head->next);
    }
}

bool checkBrackets (string alg){

    List* stack = (List*)malloc(sizeof(List));
    initList(stack);
    int i = 0; 

    while (alg[i] != '\0') {
        if ((alg[i] == '(') || (alg[i] == ')') || (alg[i] == '[') || (alg[i] == ']') || (alg[i] == '{') || (alg[i] == '}')) {
            int N = alg[i];
            insertNode(stack, N);
        }
        i++;
    }

    if (stack->size < 2) {
        freeList(stack, stack->head);
        free(stack);
        return false;
    } else {
        Node* curent = stack->head;

        while (curent->next != NULL) {
            if ((curent->date == 40 && curent->next->date == 41) || (curent->date == 91 && curent->next->date == 93) || (curent->date == 123 && curent->next->date == 125)) {
                removeNode(stack, curent->next);
                removeNode(stack, curent);

                if (stack->size < 2) break;

                curent = stack->head;
                continue;
            }
            curent = curent->next;
        }

        if (stack->size == 0) {
            free(stack);
            return true;
        } else {
            freeList(stack, stack->head);
            free(stack);
            return false;
        }
    }
}

// Task-2 ====================================

bool copyList (List* from_list, List* to_list){
    if (from_list->head == NULL){
        cout << "Origin list is empty!" << endl;
        return false;
    }

    Node *current = from_list->head;
    int count = from_list->size;

    while (count > 0) {
        for (int i = 1; i < count; i++) {
            current = current->next;
        }
        insertNode(to_list, current->date);
        count--;
        current = from_list->head; 
    }
    
    to_list->size = from_list->size;
    cout << "Copying of the list is complete!" << endl;
    cout << "New list:" << endl;

    return true;
}

// Task-3 ====================================

bool chekList (List* lst){
    if (lst->size < 2) {
        cout << "Few nodes to check!" << endl;
        return false;
    } else {
        Node* current = lst->head;

        while (current->next != NULL && current->date <= current->next->date)
        {
            current = current->next;
        }
        
        if (current->next == NULL){
            return true;
        } else {
            current = lst->head;

            while (current->next != NULL && current->date >= current->next->date)
            {
                current = current->next;
            }

            if (current->next == NULL) {
                return true;
            } else {
                return false;
            }
        }
    }
}

int main (const int argc, const char** argv){
cout << endl;

    List *lst = (List*)malloc(sizeof(List));

    initList(lst);
    printList(lst);
    insertNode(lst, 20);
    insertNode(lst, 12);
    insertNode(lst, 12);
    insertNode(lst, 10);
    insertNode(lst, 7);
    printList(lst);    
    free(removeVal(lst, 20));
    printList(lst);
    free(removeVal(lst, 20));
    printList(lst);
    
cout << endl;
// Task-1 ====================================
cout << "|| Task-1 ====================================" << endl << endl;

    string algebra;

    getline(cin, algebra);
    
    if (checkBrackets(algebra)){
        cout << "Brackets are placed correctly!" << endl;
    } else {
        cout << "Brackets are placed not correctly!" << endl;
    }

cout << endl;
// Task-2 ====================================
cout << "|| Task-2 ====================================" << endl << endl;

    List *COPY_LIST = (List*)malloc(sizeof(List));
    initList(COPY_LIST);
    
    cout << "Origin List: " << endl;
    printList(lst);

    if (copyList(lst, COPY_LIST)) {
        printList(COPY_LIST);
    }

    freeList(lst, lst->head);
    free(lst);

cout << endl;
// Task-3 ====================================
cout << "|| Task-3 ====================================" << endl << endl;

    printList(COPY_LIST);
    
    if (chekList(COPY_LIST)) {
        cout << "The list  is sorted!" << endl;
    } else {
        cout << "The list  is not sorted!" << endl;
    }

    freeList(COPY_LIST, COPY_LIST->head);
    free(COPY_LIST);

    cout << endl;
    system("pause");
    return 0;
}