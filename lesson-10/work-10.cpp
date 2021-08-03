// Author - Ilia Kiselev

#include <cstdlib>
#include <iostream>
#include <cstring>

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
       cout << "Node with value (" << val << ") is deleted!" << endl;
       return current;
    } else {
        previous->next = current->next;
        lst->size--;
        cout << "Node with value (" << val << ") is deleted!" << endl;
        return current;
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
        cout << "<-> ";
        current = current->next;
    } while (current != NULL);

    cout << "NULL" << endl;
    cout << "List size: " << lst->size << endl;
}

// Task-1 ====================================

void removeNode (List* lst, Node* element) {
    if (lst->head == element) {
        lst->head = element->next;
        free(element);
        return;
    } else {
        Node* curent = lst->head;
        Node* previous = NULL;

        while (curent != element){
            previous = curent;
            curent = curent->next;
        }
        previous->next = curent->next;
        curent = NULL;
        free(element);
        return;
    }
}

bool checkBrackets (char alg[]){
    List* lst = (List*) malloc (sizeof(List));
    int i = 0;

    while (alg[i] != '\0') {
        if (alg[i] == '(' || alg[i] == ')' || alg[i] == '[' || alg[i] == ']' || alg[i] == '{' || alg[i] == '}') {
            insertNode(lst, alg[i]);
        }
        i++;
    }

    if (lst->size < 2) {
        free(lst);
        return false;
    } else {
        Node* curent = lst->head;

        while (curent->next != NULL) {
            if ((curent->date == 40 && curent->next->date == 41) || (curent->date == 91 && curent->next->date == 93) || (curent->date == 123 && curent->next->date == 125)) {
                removeNode(lst, curent->next);
                removeNode(lst, curent);
                lst->size -= 2;
                curent = lst->head;
                continue;
            }
            curent = curent->next;
        }
        
        if (lst->size == 0) {
            free(lst);
            return true;
        } else {
            free(lst);
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
    

// Task-1 ====================================
cout << "|| Task-1 ====================================" << endl;

    char algebra[] = "( 4 + 5) * [ 5 - 2]";

    if (checkBrackets(algebra)){
        cout << "Brackets are placed correctly!" << endl;
    } else {
        cout << "Brackets are placed not correctly!" << endl;
    }
    
// Task-2 ====================================
cout << "|| Task-2 ====================================" << endl;
    List *COPY_LIST = (List*)malloc(sizeof(List));
    initList(COPY_LIST);
    
    if (copyList(lst, COPY_LIST)) {
        printList(COPY_LIST);
    }

// Task-3 ====================================
cout << "|| Task-3 ====================================" << endl;

    if (chekList(COPY_LIST)) {
        cout << "The list  is sorted!" << endl;
    } else {
        cout << "The list  is not sorted!" << endl;
    }
    system("pause");
    return 0;
}