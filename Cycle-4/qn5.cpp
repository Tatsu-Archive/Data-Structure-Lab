#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = nullptr;
    }

    Node(){
        left = right = nullptr;
    }
};

class BinarySearchTree{
    Node *root;
public:
    BinarySearchTree(){
        root = nullptr;
    }

    void insert(int);
    bool search(int);
    void deleteNode(int);
    void inorder();
    void preorder();
    void postorder();
    void inorderNode(Node*);
    void preorderNode(Node*);
    void postorderNode(Node*);
};

void BinarySearchTree::insert(int data){
    Node *newNode = new Node(data);
    if(root == nullptr){
        root = newNode;
        return;
    }
    Node *temp = root;
    while(true){
        if(data < temp->data){
            if(temp->left == nullptr){
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else{
            if(temp->right == nullptr){
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

bool BinarySearchTree::search(int data){
    Node *temp = root;
    while(temp != nullptr){
        if(temp->data == data)
            return true;
        else if(data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

void BinarySearchTree::deleteNode(int data){
    Node *temp = root, *prev = nullptr;
    while(temp != nullptr){
        if(temp->data == data)
            break;
        else if(data < temp->data){
            prev = temp;
            temp = temp->left;
        }
        else{
            prev = temp;
            temp = temp->right;
        }
    }
    if(temp == nullptr){
        cout << "Node not found" << endl;
        return;
    }
    if(temp->left == nullptr && temp->right == nullptr){
        if(prev == nullptr)
            root = nullptr;
        else if(prev->left == temp)
            prev->left = nullptr;
        else
            prev->right = nullptr;
        delete temp;
    }
    else if(temp->left == nullptr){
        if(prev == nullptr)
            root = temp->right;
        else if(prev->left == temp)
            prev->left = temp->right;
        else
            prev->right = temp->right;
        delete temp;
    }
    else if(temp->right == nullptr){
        if(prev == nullptr)
            root = temp->left;
        else if(prev->left == temp)
            prev->left = temp->left;
        else
            prev->right = temp->left;
        delete temp;
    }
    else{
        Node *temp2 = temp->right, *prev2 = temp;
        while(temp2->left != nullptr){
            prev2 = temp2;
            temp2 = temp2->left;
        }
        temp->data = temp2->data;
        if(prev2->left == temp2)
            prev2->left = temp2->right;
        else
            prev2->right = temp2->right;
        delete temp2;
    }
}

void BinarySearchTree::inorder(){
    if (root){
        cout << "Inorder traversal: ";
        inorderNode(root);
        cout << endl;
    }
    else
        cout << "Tree is empty" << endl;
}

void BinarySearchTree::inorderNode(Node *temp){
    if(temp->left != nullptr)
        inorderNode(temp->left);
    cout << temp->data << " ";
    if(temp->right != nullptr)
        inorderNode(temp->right);
}

void BinarySearchTree::preorder(){
    if (root){
        cout << "Preorder traversal: ";
        preorderNode(root);
        cout << endl;
    }
    else
        cout << "Tree is empty" << endl;
}

void BinarySearchTree::preorderNode(Node *temp){
    cout << temp->data << " ";
    if(temp->left != nullptr)
        preorderNode(temp->left);
    if(temp->right != nullptr)
        preorderNode(temp->right);
}

void BinarySearchTree::postorder(){
    if (root){
        cout << "Postorder traversal: ";
        postorderNode(root);
        cout << endl;
    }
    else
        cout << "Tree is empty" << endl;
}

void BinarySearchTree::postorderNode(Node *temp){
    if(temp->left != nullptr)
        postorderNode(temp->left);
    if(temp->right != nullptr)
        postorderNode(temp->right);
    cout << temp->data << " ";
}

int main(){
    BinarySearchTree bst;
    int choice, data;
    while(true){
        cout << "1. Insert\n2. Search\n3. Delete\n4. Inorder\n5. Preorder\n6. Postorder\n7. Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter data: ";
                cin >> data;
                bst.insert(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                if(bst.search(data))
                    cout << "Found" << endl;
                else
                    cout << "Not found" << endl;
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                bst.deleteNode(data);
                break;
            case 4:
                bst.inorder();
                break;
            case 5:
                bst.preorder();
                break;
            case 6:
                bst.postorder();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

/*
Output
1. Insert
2. Search
3. Delete
4. Inorder
5. Preorder
6. Postorder
7. Exit
Enter your choice: 1
Enter data: 5
Enter your choice: 1
Enter data: 3
Enter your choice: 1
Enter data: 7
Enter your choice: 1
Enter data: 2
Enter your choice: 2
Enter data: 7
Found
Enter your choice: 2
Enter data: 9
Not found
Enter your choice: 3
Enter data: 7
Enter your choice: 4
Inorder traversal: 2 3 5
Enter your choice: 5
Preorder traversal: 5 3 2
Enter your choice: 6
Postorder traversal: 2 3 5
Enter your choice: 7
*/
