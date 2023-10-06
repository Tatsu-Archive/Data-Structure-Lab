// Implement a hash table using Linked List with separate chaining with the following operations : INSERT(key), DELETE(key), SEARCH(key).


#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class HashTable{
    Node **arr;
    int size;
    int hash(int key){
        return key % size;
    }
public:
    HashTable(int size){
        this->size = size;
        arr = new Node*[size];
        for(int i = 0; i < size; i++)
            arr[i] = NULL;
    }
    
    ~HashTable(){
        for(int i = 0; i < size; i++){
            Node *temp = arr[i];
            while(temp != NULL){
                Node *temp2 = temp;
                temp = temp->next;
                delete temp2;
            }
        }
        delete[] arr;
    }

    void insert(int);
    void search(int);
    void del(int);
    void display();
};

void HashTable::insert(int key){
    int index = hash(key);
    if(arr[index] == NULL){
        arr[index] = new Node(key);
        return;
    }
    Node *temp = arr[index];
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new Node(key);
}

void HashTable::search(int key){
    int index = hash(key);
    Node *temp = arr[index];
    while(temp != NULL){
        if(temp->data == key){
            cout << "Key found at index " << index << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Key not found" << endl;
}

void HashTable::del(int key){
    int index = hash(key);
    Node *temp = arr[index];
    if(temp->data == key){
        arr[index] = temp->next;
        delete temp;
        return;
    }
    while(temp->next != NULL){
        if(temp->next->data == key){
            Node *temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            return;
        }
        temp = temp->next;
    }
    cout << "Key not found" << endl;
}

void HashTable::display(){
    for(int i = 0; i < size; i++){
        cout << i << ": ";
        Node *temp = arr[i];
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    int size, choice, key;
    cout << "Enter size of hash table: ";
    cin >> size;
    HashTable ht(size);
    while(true){
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.del(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

/*
Output
Enter size of hash table: 10
1. Insert
2. Search
3. Delete
4. Display
5. Exit
Enter your choice: 1
Enter key to insert: 5
Enter your choice: 1
Enter key to insert: 3
Enter your choice: 1
Enter key to insert: 7
Enter your choice: 4
0:
1:
2:
3: 3
4:
5: 5
6:
7: 7
8:
9:
Enter your choice: 2
Enter key to search: 5
Key found at index 5
Enter your choice: 3
Enter key to delete: 5
Enter your choice: 4
0:
1:
2:
3: 3
4:
5:
6:
7: 7
8:
9:
Enter your choice: 5
*/