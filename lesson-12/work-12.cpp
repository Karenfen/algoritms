// Author - Kiselev Ilia

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>

#define NUMBER_OF_TREES 50
#define AMOUNT_OF_ELEMENTS 1000
#define MAX 100

using namespace std;

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} treeNode;

bool insertTreeNode (treeNode *root, int data) {
    treeNode *newNode;
    newNode = (treeNode*)malloc(sizeof(treeNode));

    if (newNode == NULL) {
        cout << "Stack overflow!" << endl;
        return false;
    }

    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;

    treeNode *current = root;
    treeNode *parent = root;

    while (true) {
        parent = current;
        if (current->key > data) {
            current = current->left;
            if (current == NULL) {
                parent->left = newNode;
                return true;
            }
        } else if (current->key == data) {
            newNode->left = current->left;
            current->left = newNode;
            return true;
        } else {
            current = current->right;
            if (current == NULL) {
                parent->right = newNode;
                return true;
            }
        }
    }
}

void CoutDoubleTree (treeNode* root) {
    if (root != NULL) {
        CoutDoubleTree(root->left);
        cout << root->key << " ";
        CoutDoubleTree(root->right);
    }
}

void printTree (treeNode* root) {
    if (root) {
        cout << root->key;
        if (root->left || root->right) {
            cout << "(";
            if (root->left) {
                printTree(root->left);
            } else {
                cout << "NULL";
            }
            cout << ",";
            if (root->right) {
                printTree(root->right);
            } else {
                cout << "NULL";
            }
            cout << ")";
        }
    }
}

// TASK-1 ==========================================================
int countingNodes (treeNode* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return (1 + countingNodes(root->left) + countingNodes(root->right));
}

bool balanceCheck (treeNode* root) {
    int L = countingNodes(root->left);
    int R = countingNodes(root->right);

    if (L == R || L + 1 == R || R + 1 == L) {
        return true;
    } else {
        return false;
    }
}

// TASK-4 ==========================================================
bool binSearch (treeNode* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->key == value){
        return true;
    } else {
        if (value > root->key) {
            binSearch(root->right, value);
        } else {
            binSearch(root->left, value);
        }
    }
}

int main (const int argc, const char** argv){
// TASK-1 ==========================================================
cout << "TASK-1 ===================================" << endl << endl;

    srand( time(0) );
    int value = 50;

    treeNode *tree_1 = (treeNode*)malloc(sizeof(treeNode));
    if(tree_1 == NULL) {
        cout << "Stack overflow!" << endl;
    } else  {
        tree_1->key = value;
        tree_1->left = NULL;
        tree_1->right = NULL;
    }
    
    for (int i = 0; i < 9; i++) {
        value = 1 + rand() %  MAX;
        insertTreeNode (tree_1, value);
    }

    CoutDoubleTree(tree_1);
    cout << endl;
    printf("tree_1 is balanced: %s\n", balanceCheck(tree_1) ? "true" : "false");
    printTree(tree_1);

cout << endl << endl;
// TASK-2 ==========================================================
cout << "TASK-2 ===================================" << endl << endl;
 
    treeNode* tree[NUMBER_OF_TREES];
    for (int i = 0; i < NUMBER_OF_TREES; i++) {
        tree[i] = (treeNode*) malloc (sizeof(treeNode));

        if(tree[i] == NULL) {
        cout << "Stack overflow!" << endl;
        } else  {
            tree[i]->key = value;
            tree[i]->left = NULL;
            tree[i]->right = NULL;
        }
    }

    for (int i = 0; i < NUMBER_OF_TREES; i++) {
        for (int j = 1; j < AMOUNT_OF_ELEMENTS; j++){
            value = 1 + rand() % MAX;
            insertTreeNode(tree[i], value);
        }
    }    
    
    cout << "Trees created: " << NUMBER_OF_TREES << " with " << AMOUNT_OF_ELEMENTS << " elements each." << endl << endl;

// TASK-3 ==========================================================
cout << "TASK-3 ===================================" << endl << endl;

    double procent = NUMBER_OF_TREES*1.0 / 100;
    double result = 0;

    for (int i = 0; i < NUMBER_OF_TREES; i++) {
        if (balanceCheck(tree[i])){
            result++;
        }     
    }

    cout << "Found " << result << " balanced trees." << endl;
    printf("This is %.2f %% to all.\n\n", result/procent);

// TASK-4 ==========================================================
cout << "TASK-4 ===================================" << endl << endl;
int num;

cout << "Inter a number to search: ";
cin >> num;

printf("tree_1 have an element with a value %d: %s\n", num, binSearch(tree_1, num) ? "true" : "false");

cout << endl;
system("pause");
return 0;
}