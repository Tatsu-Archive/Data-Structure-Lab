#include<iostream>
using namespace std;

class HashTable{
    int *arr;
    int size;
    int hash(int key){
        return key % size;
    }

    int hash2(int key){
        return 7 - (key % 7);
    }
public:
    HashTable(int size){
        this->size = size;
        arr = new int[size];
        for(int i = 0; i < size; i++)
            arr[i] = -1;
    }
    
    ~HashTable(){
        delete[] arr;
    }

    void insert(int);
    void search(int);
    void del(int);
    void display();
};

void HashTable::insert(int key){
    int index = hash(key);
    if(arr[index] == -1){
        arr[index] = key;
        return;
    }
    int i = 1;
    while(true){
        int newIndex = (index + i*hash2(key)) % size;
        if(arr[newIndex] == -1){
            arr[newIndex] = key;
            return;
        }
        i++;
    }
}

void HashTable::search(int key){
    int index = hash(key);
    if(arr[index] == key){
        cout << "Key found at index " << index << endl;
        return;
    }
    int i = 1;
    while(true){
        int newIndex = (index + i*hash2(key)) % size;
        if(arr[newIndex] == key){
            cout << "Key found at index " << newIndex << endl;
            return;
        }
        i++;
    }
}

void HashTable::del(int key){
    int index = hash(key);
    if(arr[index] == key){
        arr[index] = -1;
        return;
    }
    int i = 1;
    while(true){
        int newIndex = (index + i*hash2(key)) % size;
        if(arr[newIndex] == key){
            arr[newIndex] = -1;
            return;
        }
        i++;
    }
}

void HashTable::display(){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;
    HashTable ht(size);
    int choice, key;
    while(true){
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ";
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
Enter choice: 1
Enter key to insert: 5
Enter choice: 1
Enter key to insert: 3
Enter choice: 1
Enter key to insert: 7
Enter choice: 1
Enter key to insert: 9
Enter choice: 1
Enter key to insert: 11
Enter choice: 1
Enter key to insert: 13
Enter choice: 1
Enter key to insert: 15
Enter choice: 1
Enter key to insert: 17
Enter choice: 4
-1 1 3 -1 5 7 9 11 13 15
Enter choice: 2
Enter key to search: 7
Key found at index 5
Enter choice: 2
Enter key to search: 8
Key found at index 6
Enter choice: 3
Enter key to delete: 7
Enter choice: 4
-1 1 3 -1 5 -1 9 11 13 15
Enter choice: 5
*/