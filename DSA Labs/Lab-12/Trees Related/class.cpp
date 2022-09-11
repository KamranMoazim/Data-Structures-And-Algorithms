#pragma once

#include <iostream>
#include "class.h"

using namespace std;




// ************ Binary Search Tree








// ****************** Task # 1.1

template <typename T>
void BST<T>::displayInRangeHelper(TreeNode<T>* node, T start, T end){
    if( node == NULL ){
        return;
    } else {

        
        if(node->data >= start){
            displayInRangeHelper(node->left, start, end);
        }
        visitNode(node);
        if(node->data < end){
            displayInRangeHelper(node->right, start, end);
        }

    }
}



template <typename T>
void BST<T>::displayInRange(T start, T end){
    displayInRangeHelper(root, start, end);
}



























template <typename T>
bool BST<T>::removeNode(T val){
    
    TreeNode<T>* parent = NULL;
    TreeNode<T>* child = NULL;
    TreeNode<T>* curr = root;

    while(curr != NULL && curr->data != val ){
        parent = curr;
        if(curr->data > val){
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }


    if(curr == NULL){
        return false;
    } else {

        // following code handle (delete) degree 2 node
        TreeNode<T>* tempParent = NULL;
        TreeNode<T>* tempCurr = curr->left;
        if(curr->left != NULL && curr->right != NULL){
            while(tempCurr->right != NULL){
                tempParent = tempCurr;
                tempCurr = tempCurr->right;
            }
            curr->data = tempCurr->data;
            parent = tempParent;
            curr = tempCurr;
        }


        // following code handle (delete) degree 0 and 1 node
        if(curr->left != NULL){
            child = curr->left;
        } else {
            child = curr->right;
        }

        if(parent == NULL){ // deleting root (which is only node in tree)
            root = NULL;
        } else {

            if(parent->left == curr){
                parent->left = child;
            } else {
                parent->right = child;
            }

        }

        delete curr;
        curr = NULL;

        return true;
    }

}



template <typename T>
bool BST<T>::insertNode(T val){
    
    TreeNode<T>* parent = NULL;
    TreeNode<T>* curr = root;

    while(curr != NULL){
        if(curr->data == val){
            return false;
        } else if(curr->data > val){
            parent = curr;
            curr = curr->left;
        } else {
            parent = curr;
            curr = curr->right;
        }
    }

    TreeNode<T>* temp = new TreeNode<T>;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        root = temp;
    } else {
        if(parent->data > val){
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    }

    return true;
}



template <typename T>
bool BST<T>::iterativeSearch(T key){
    TreeNode<T>* curr = root;
    while(curr != NULL){
        if(curr->data == key){
            cout<<curr->data;
            return true;
        } else if(curr->data > key){
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return false;
}




template <typename T>
void BST<T>::visitNode(TreeNode<T>* node){
    cout<<node->data<<"\t";
}

template <typename T>
void BST<T>::preOrderPrivate(TreeNode<T>* node){
    if(node != NULL){
        visitNode(node);
        preOrderPrivate(node->left);
        preOrderPrivate(node->right);
    }
}

template <typename T>
void BST<T>::inOrderPrivate(TreeNode<T>* node){
    if(node != NULL){
        inOrderPrivate(node->left);
        visitNode(node);
        inOrderPrivate(node->right);
    }
}

template <typename T>
void BST<T>::postOrderPrivate(TreeNode<T>* node){
    if(node != NULL){
        postOrderPrivate(node->left);
        postOrderPrivate(node->right);
        visitNode(node);
    }
}


template <typename T>
void BST<T>::preOrderDisplay(){
    preOrderPrivate(root);
}

template <typename T>
void BST<T>::inOrderDisplay(){
    inOrderPrivate(root);
}

template <typename T>
void BST<T>::postOrderDisplay(){
    postOrderPrivate(root);
}













// ****************** Task # 1.2
template <typename T>
int BST<T>::countNodes(TreeNode<T>* node){

    if(node != NULL){
        return 1 + countNodes(node->right) + countNodes(node->left);
    }

    return 0;

}



template <typename T>
int BST<T>::countNodes(){
    int c = countNodes(root);
    return c;
}












// ****************** Task # 1.3

template <typename T>
int BST<T>::getHeight(TreeNode<T>* node){
    if(node == NULL){
        return 0;
    } else {
        int leftTreeHeight = getHeight(node->left);
        int rightTreeHeight = getHeight(node->right);

        if(leftTreeHeight > rightTreeHeight){
            return 1 + leftTreeHeight;
        } else {
            return 1 + rightTreeHeight;
        }
    }
}


template <typename T>
int BST<T>::getHeight(){
    return getHeight(root);
}













// ****************** Task # 1.4
template <typename T>
TreeNode<T>* BST<T>::createBalancedTreeHelper(int* arr, int start, int end){

    if(start <= end){
        int mid = (end + start) / 2;

        TreeNode<T>* temp = new TreeNode<T>;
        temp->data = arr[mid];
        temp->left = createBalancedTreeHelper(arr, start, mid-1);
        temp->right = createBalancedTreeHelper(arr, mid+1, end);


        return temp;
    } else {

        return NULL;
    }

}

template <typename T>
void BST<T>::createBalancedTree (int* arr, int start, int end){

    removeNode(root);
    root = NULL;
    root = createBalancedTreeHelper(arr, start, end);

}















template <typename T>
T BST<T>::findMaxPrivate(TreeNode<T>* node){
    if(node->right == NULL){
        return node->data;
    } else {
        return findMaxPrivate(node->right);
    }
}


template <typename T>
T BST<T>::findMinPrivate(TreeNode<T>* node){
    if(node->left == NULL){
        return node->data;
    } else {
        return findMinPrivate(node->left);
    }
}




template <typename T>
T BST<T>::findMax(){
    return findMaxPrivate(root);
}


template <typename T>
T BST<T>::findMin(){
    return findMinPrivate(root);
}







template <typename T>
bool BST<T>::recursiveSearchPrivate(T key, TreeNode<T>* node){
    if(node != NULL){
        if(node->data == key){
            return true;
        } else if(node->data > key){
            recursiveSearchPrivate(key, node->left);
        } else {
            recursiveSearchPrivate(key, node->right);
        }
    }

    return false;
}
template <typename T>
bool BST<T>::recursiveSearch(T key){
    return recursiveSearchPrivate(key, root);
}
















template <typename T>
BST<T>::BST() {
    root = NULL;
}





template <typename T>
TreeNode<T>* BST<T>::copyNode(TreeNode<T>* node){
    if(node != NULL){

        TreeNode<T>* temp = new TreeNode<T>();
        temp->data = node->data;
        temp->left = copyNode(node->left);
        temp->right = copyNode(node->right);
        return temp;

    } else {
        return NULL;
    }
}
template <typename T>
BST<T>::BST(const BST<T>& tree) {
    root = copyNode(tree.root);
}







template <typename T>
void BST<T>::removeNode(TreeNode<T>* node){
    if(node != NULL){
        removeNode(node->left);
        removeNode(node->right);
        delete node;
    }
}
template <typename T>
BST<T>::~BST(){
    removeNode(root);
    root = NULL;
}







template <typename T>
bool BST<T>::Equal(TreeNode<T>* orgNode, TreeNode<T>* comingNode){
    if(orgNode == NULL && comingNode == NULL){
        return true;
    } else {
        return orgNode->data == comingNode->data && Equal(orgNode->left, comingNode->left) && Equal(orgNode->right, comingNode->right);
    }
}
template <typename T>
bool BST<T>::operator == (const BST<T>& tree){
    return Equal(root, tree.root);
}
















template <typename T>
void BST<T>::levelOrderDisplay(){
    LinkedListQueue< TreeNode<T>* > q;
    TreeNode<T>* currNode = root;

    while(currNode){

        visitNode(currNode);

        if(currNode->left){
            q.enqueue(currNode->left);
        }
        if(currNode->right){
            q.enqueue(currNode->right);
        }

        if(q.isEmpty()) return;

        q.dequeue(currNode);
    }

}