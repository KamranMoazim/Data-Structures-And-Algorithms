#pragma once

#include <iostream>
#include <stack>
#include <string>
#include "queue.cpp"
// #include "stack.cpp"

using namespace std;






template <typename T>
class BST;


template <typename T>
class TreeNode {
    friend class BST<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
};


template <typename T>
class BST {
private:
    TreeNode<T>* root;
    void removeNode(TreeNode<T>* );
    TreeNode<T>* copyNode(TreeNode<T>* );

    TreeNode<T>* doubleCopyNode(TreeNode<T>* node){
        if(node != NULL){

            node->left = doubleCopyNode(node->left);
            node->right = doubleCopyNode(node->right);

            TreeNode<T>* temp = new TreeNode<T>();
            temp->data = node->data;
            temp->right = NULL;
            temp->left = node->left;
            node->left = temp;

            return node;

        } else {
            return NULL;
        }

    }
    bool Equal(TreeNode<T>* , TreeNode<T>* );
    void visitNode(TreeNode<T>* );
    void preOrderPrivate(TreeNode<T>* );
    void inOrderPrivate(TreeNode<T>* );
    void postOrderPrivate(TreeNode<T>* );
    bool recursiveSearchPrivate(T, TreeNode<T>*);
    T findMaxPrivate(TreeNode<T>*);
    T findMinPrivate(TreeNode<T>*);
    int countNodes (TreeNode<T>* );
    int getHeight (TreeNode<T>* );
    TreeNode<T>* createBalancedTreeHelper (int* , int , int );
    void displayInRangeHelper(TreeNode<T>* , T, T);
    void printAllPathsByArrayHelper(TreeNode<T>* node, T* array, int currIndex){
        if(node->left == NULL && node->right == NULL){
            for(int i=0; i<currIndex; i++){
                cout<<array[i]<<" —> ";
            }
            cout<<node->data<<endl;
        } else {
            array[currIndex++] = node->data;
            if(node->left != NULL){
                printAllPathsByArrayHelper(node->left, array, currIndex);
            } 
            if(node->right != NULL) {
                printAllPathsByArrayHelper(node->right, array, currIndex);
            }
            currIndex--;
        }
    }
public:
    BST();
    BST(const BST<T>&);
    ~BST();
    bool operator == (const BST<T>&);
    void levelOrderDisplay();
    bool recursiveSearch(T);
    T findMax();
    T findMin();
    bool iterativeSearch(T);
    bool insertNode(T);
    bool removeNode(T);
    void preOrderDisplay();
    void inOrderDisplay();
    void postOrderDisplay();
    int countNodes();
    int getHeight();
    void createBalancedTree (int* , int , int );
    void printAllPathsByArray(){
        T* arr = new T[100];
        printAllPathsByArrayHelper(root, arr, 0);
    }
    void doubleTree(){
        root = doubleCopyNode(root);
    }
    void displayInRange (T , T );
};







