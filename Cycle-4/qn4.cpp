#include<iostream>
using namespace std;

class Queue
{
    int front, rear, size;
    int *arr;
public:

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value){
        if(isFull()){
            cout << "Queue is full" << endl;
        }
        else{
            if(front == -1){
                front = 0;
            }
            rear = (rear + 1) % size;
            arr[rear] = value;
            cout << "Inserted " << value << endl;
        }
    }

    int deQueue(){
        int value;
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        else{
            value = arr[front];
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front + 1) % size;
            }
            return value;
        }
    }

    void displayQueue(){
        int i;
        if(isEmpty()){
            cout << "Queue is empty" << endl;
        }
        else{
            cout << "Front -> " << front;
            cout << "\nItems -> ";
            for(i = front; i != rear; i = (i + 1) % size){
                cout << arr[i] << " ";
            }
            cout << arr[i];
            cout << "\nRear -> " << rear << endl;
        }
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if((front == 0 && rear == size - 1) || (front == rear + 1)){
            return true;
        }
        return false;
    }
    int queueSize(){
        if(front == -1){
            return 0;
        }
        return (size - front + rear + 1) % size;
    }
};

int main()
{
    int choice, value, size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);
    while (1)
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Size\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            q.enQueue(value);
            break;
        case 2:
            value = q.deQueue();
            if (value != -1)
                cout << "Deleted value = " << value << endl;
            break;
        case 3:
            q.displayQueue();
            break;
        case 4:
            cout << "Size of Queue = " << q.queueSize() << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

/*
Output
Enter the size of the queue: 5
1. Enqueue
2. Dequeue
3. Display
4. Size
5. Exit
Enter your choice: 1
Enter the value to be inserted: 5
Inserted 5
Enter your choice: 1
Enter the value to be inserted: 9
Inserted 9
Enter your choice: 1
Enter the value to be inserted: 7
Inserted 7
Enter your choice: 2
Deleted value = 5
Enter your choice: 3
Front -> 1
Items -> 9 7
Rear -> 2
Enter your choice: 4
Size of Queue = 2
Enter your choice: 5
*/