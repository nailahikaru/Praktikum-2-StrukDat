/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 *
 * Implementasi untuk Bahasa C++
 */

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/* Node structure */

struct BSTNode {
    BSTNode *left, *right, *parent;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    BSTNode* find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return NULL;

        if (temp->key == value)
            return temp;
        else
            return NULL;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value, NULL);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

private:
    // Utility Function
    BSTNode* __createNode(int value, BSTNode *parent) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        newNode->parent = parent;
        return newNode;
    }

    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value, BSTNode *parent) {
        if (root == NULL){
            return __createNode(value, parent);
        }

        if (value < root->key)
            root->left = __insert(root->left, value, root);
        else if (value > root->key)
            root->right = __insert(root->right, value, root);

        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key)
            root->right = __remove(root->right, value);
        else if (value < root->key)
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST bst;
    bst.init();

    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      bst.insert(x);
    }

    vector<string> query;
    string s;
    while(cin >> s) {
      query.push_back(s);
    }
    BSTNode* start = bst.find(stoi(query[query.size() - 1]));
    for(int i = query.size() - 1; i >= 0; i--) {
      if(query[i] == "parent") { //for reference, this is how to find parent
        if(start->parent == NULL) {
          printf("-1\n"); return 0;
        } else {
          start = start->parent;
        }
      } else if(query[i] == "grandparent") {
        if(!(start->parent == NULL)){
            if((start->parent)->parent == NULL) {
             printf("-1\n"); return 0;
           } else {
             start = (start->parent)->parent;
           }
        } else {printf("-1\n"); return 0;}
      } else if(query[i] == "uncle") {
        if(!(start->parent)==NULL){
            if((start->parent)->parent == NULL) {
             printf("-1\n"); return 0;
           } else {
               if(((start->parent)->parent)->left == start->parent) {
                   if(((start->parent)->parent)->right == NULL) {
                       printf("-1\n"); return 0;
                   } else {
                       start = ((start->parent)->parent)->right;}
               } else if(((start->parent)->parent)->right == start->parent) {
                   if(((start->parent)->parent)->left == NULL) {
                   printf("-1\n"); return 0;
                   } else {
                   start = ((start->parent)->parent)->left;}
                   }
               }
        } else { printf("-1\n"); return 0;}
        } else continue;
        }

    printf("%d\n", start->key);
}
