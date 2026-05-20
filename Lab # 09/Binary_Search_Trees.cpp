#include <iostream>
using namespace std;

//What are Tree Structures?
//A tree is a hierarchical data structure that consists of nodes connected by edges. Each node contains data and may have child nodes. The topmost node is called the root, and nodes with no children are called leaves. Trees are used to represent various types of data, such as hierarchical relationships, file systems, and more.

//What are Binary Search Trees?
//A binary search tree (BST) is a type of binary tree that maintains a specific ordering property. In a BST, for any given node, the value of all nodes in its left subtree is less than the node's value, and the value of all nodes in its right subtree is greater than the node's value. This property allows for efficient searching, insertion, and deletion operations.

//It cannot work on ordered insertion as it would create a skewed tree, which is a type of binary tree where all the nodes have only one child, either left or right. This results in a tree that resembles a linked list. Skewed trees can occur when elements are inserted in sorted order, leading to inefficient operations with a time complexity of O(n) for search, insertion, and deletion.

//What are skewed trees?
//A skewed tree is a type of binary tree where all the nodes have only one child, either left or right. This results in a tree that resembles a linked list. Skewed trees can occur when elements are inserted in sorted order, leading to inefficient operations with a time complexity of O(n) for search, insertion, and deletion.

//rules of binary search trees
//1. The left subtree of a node contains only nodes with keys less than the node's key.
//2. The right subtree of a node contains only nodes with keys greater than the node's key.

//Rules for deletion
//1. If the node to be deleted is a leaf node, simply remove it.
//2. If the node to be deleted has one child, replace the node with its child.
//3. If the node to be deleted has two children, find the inorder successor (or predecessor), replace the node's value with the successor's value, and then delete the successor.

//Postorder Traversal: is used for deletion because it ensures that we delete the child nodes before the parent node, which helps maintain the integrity of the tree structure during deletion operations.

//Inorder Traversal: In an inorder traversal, the nodes are visited in the following order: left subtree, root node, right subtree. This traversal method is particularly useful for binary search trees because it visits the nodes in sorted order. When you perform an inorder traversal on a binary search tree, you will get the values of the nodes in ascending order.

//Preorder Traversal: In a preorder traversal, the nodes are visited in the following order: root node, left subtree, right subtree. This traversal method is useful for creating a copy of the tree or for getting a prefix expression of an expression tree.


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

//utility functions of BST

Node* CreateNode(int value) {
    Node* newNode = new Node(value);
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//Insertion function for BST

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return CreateNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value); // Recursively insert into the left subtree, consider the case when the value is less than the root's data, we need to insert it into the left subtree. We call the insert function recursively on the left child of the root node, passing the left child and the value to be inserted as arguments. This process continues until we find a null position where we can insert the new node.
        //The Left child is considered to be the root now, and the function will continue to traverse down the left subtree until it finds a null position to insert the new node.
    } else if (value > root->data) {
        root->right = insert(root->right, value); // Recursively insert into the right subtree
        //Similarly, if the value is greater than the root's data, we need to insert it into the right subtree. We call the insert function recursively on the right child of the root node, passing the right child and the value to be inserted as arguments. This process continues until we find a null position where we can insert the new node.
    }
    return root;
}

//Find the minimum value in a BST

Node* findMin(Node* root) {
    while (root->left != nullptr && root->left->left != nullptr) { //Left will reach the minimum value first, and we need to check if the left child of the current node is not null and if the left child of the left child is also not null. This is because we want to ensure that we are not at a leaf node, which would be the minimum value in the BST. If both conditions are satisfied, we can continue traversing down the left subtree to find the minimum value.
        root = root->left;
    }
    return root;
}

//Find the maximum value in a BST

Node* findMax(Node* root) {
    while (root->right != nullptr) { //right will reach the maximum value first, and we need to check if the right child of the current node is not null. If it is not null, we can continue traversing down the right subtree to find the maximum value.
        root = root->right;
    }
    return root;
}

//Sir Nasru ka ahsan tha

Node* deleteNode(Node* root, int key) {
    //value is used when inserting while key is used when deleting, and we need to find the node with the given key in the BST to delete it. We start by checking if the root is null, which means we have reached a leaf node and the key is not found in the tree. If the root is not null, we compare the key with the data of the current node. If the key is less than the current node's data, we need to search for the key in the left subtree, so we call the deleteNode function recursively on the left child of the current node. If the key is greater than the current node's data, we need to search for the key in the right subtree, so we call the deleteNode function recursively on the right child of the current node. If the key matches the current node's data, we have found the node to be deleted.
    if (root == nullptr) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//why are we using only single pointer in the BST functions?
//In the BST functions, we are using single pointers because we are passing the root node of the tree as an argument to the functions. The root node is a pointer to the first node of the tree, and we can use this pointer to access and manipulate the entire tree structure. By using single pointers, we can easily traverse the tree, insert new nodes, delete nodes, and perform other operations without needing to manage multiple pointers or references. This simplifies the implementation and makes it easier to understand and maintain the code.

//we dont need to use double pointers because we are not modifying the pointer itself, but rather the data it points to. When we pass a pointer to a function, we are passing the address of the variable, and any changes made to the data at that address will be reflected outside the function. Therefore, we can achieve the desired functionality using single pointers without the need for double pointers.


//postorder traversal for BST

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left); // Traverse the left subtree first
    postorder(root->right); // Then traverse the right subtree
    cout << root->data << " "; // Finally, visit the root node
}

//inorder traversal for BST

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left); // Traverse the left subtree first
    cout << root->data << " "; // Then visit the root node
    inorder(root->right); // Finally, traverse the right subtree
}


//preorder traversal for BST

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " "; // Visit the root node first
    preorder(root->left); // Then traverse the left subtree
    preorder(root->right); // Finally, traverse the right subtree
}

int main(){  
    
    

}