/*
Create a Binary Search Tree which supports the following operations:
◦ insert(tree, element) – adds the node specified by element (which contains the data)
into the BST specified by tree.
◦ search(tree, key) – searches for the data specified by key in the BST specified by
tree.
◦ delete(tree, element) – removes the node specified by element from the BST
specified by
◦ tree.
◦ inorder(tree) – To do a recursive inorder traversal of the BST.
◦ preorder(tree) – To do a recursive preorder traversal of the BST.
◦ postorder(tree) – To do a recursive postorder traversal of the BST.
Write a menu driven program to demonstrate these operations.
*/

#include<iostream>
using namespace std;

class Node{
    int data;
    Node *left, *right;
public:
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
    friend class BST;
};

class BST{
    Node *root;
public:
