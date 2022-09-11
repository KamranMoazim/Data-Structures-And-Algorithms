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
    void printAllPathsHelper(TreeNode<T>* node){

        // base case
        if (node == NULL) {
            return;
        }
    
        // create an empty stack to store a pair of tree nodes and
        // its path from the root node
        stack<pair<TreeNode<T>*, string>> stack;
    
        // push the root node
        stack.push(make_pair(node, ""));
    
        // loop till stack is empty
        while (!stack.empty())
        {
            // pop a node from the stack and push the data into the output stack
            pair<TreeNode<T>*, string> p = stack.top();
            stack.pop();
    
            // fetch current node
            TreeNode<T>* curr = p.first;
            string path = p.second;
    
            // add the current node to the existing path
            string delim = (path == "") ? "\n" : " —> ";
            path += (delim + to_string(curr->data));
    
            // print the path if the node is a leaf
            if (curr->left == NULL && curr->right == NULL) {
                cout << path;
            }
    
            // push the left and right child of the popped node into the stack
            if (curr->right) {
                stack.push(make_pair(curr->right, path));
            }
    
            if (curr->left) {
                stack.push(make_pair(curr->left, path));
            }
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
    void printAllPaths(){
        printAllPathsHelper(root);
    }
    void displayInRange (T , T );
};







