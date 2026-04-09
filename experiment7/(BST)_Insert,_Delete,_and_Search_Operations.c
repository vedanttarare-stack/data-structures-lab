/*Write a program to implement the following operations in a Binary Search Tree (BST)

 1. Inserting a node
 2. Deleting a node 
 3. Search a node*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_OPS 100
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
int main() {
    int opCount;
    scanf("%d", &opCount);
    Node *root = NULL;
    char outputs[MAX_OPS][50];
    int outIndex = 0;
    int op, key;
    for (int i = 0; i < opCount; i++) {
        scanf("%d", &op);
        if (op == 1 || op == 2 || op == 3)
            scanf("%d", &key);
        if (op == 1) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = key;
            newNode->left = newNode->right = NULL;
            if (root == NULL) {
                root = newNode;
            } else {
                Node* curr = root;
                Node* parent = NULL;
                while (curr != NULL) {
                    parent = curr;
                    if (key < curr->data)
                        curr = curr->left;
                    else if (key > curr->data)
                        curr = curr->right;
                    else
                        break;
                }
                if (curr == NULL) {
                    if (key < parent->data)
                        parent->left = newNode;
                    else
                        parent->right = newNode;
                } else {
                    free(newNode);
                }
            }
        }
        else if (op == 2) {
            Node* curr = root;
            Node* parent = NULL;
            while (curr != NULL && curr->data != key) {
                parent = curr;
                if (key < curr->data)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
            if (curr != NULL) {
                if (curr->left == NULL || curr->right == NULL) {
                    Node* newCurr;
                    if (curr->left == NULL)
                        newCurr = curr->right;
                    else
                        newCurr = curr->left;
                    if (parent == NULL)
                        root = newCurr;
                    else if (parent->left == curr)
                        parent->left = newCurr;
                    else
                        parent->right = newCurr;
                    free(curr);
                } else {
                    Node* temp = curr->right;
                    Node* tempParent = curr;
                    while (temp->left != NULL) {
                        tempParent = temp;
                        temp = temp->left;
                    }
                    curr->data = temp->data;
                    if (tempParent->left == temp)
                        tempParent->left = temp->right;
                    else
                        tempParent->right = temp->right;
                    free(temp);
                }
            }
        }
        else if (op == 3) {
            Node* curr = root;
            int found = 0;
            while (curr != NULL) {
                if (curr->data == key) {
                    found = 1;
                    break;
                }
                if (key < curr->data)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
            if (found)
                strcpy(outputs[outIndex++], "found");
            else
                strcpy(outputs[outIndex++], "not found");
        }
    }
    for (int i = 0; i < outIndex; i++) {
        printf("%s\n", outputs[i]);
    }
    return 0;
}
