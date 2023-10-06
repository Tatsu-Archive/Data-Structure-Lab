#include<iostream>
using namespace std;

class Queue
{
    int front, rear, size;
    int *arr;   

public:

    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        arr = new int[size];
    }

    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = data;
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Dequeued Element: " << arr[front] << endl;
        front++;
    }

    bool isEmpty()
    {
        if (front == -1 || front > rear)
            return true;
        else
            return false;
    }

    int sizeOfQueue()
    {
        int count = 0;
        for (int i = front; i <= rear; i++)
            count++;
        return count;
    }

    void display(){
        if (front == -1 or front > rear)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

};

int main(){ //menu driven
    int size, choice, data;
    cout << "Enter the size of the queue: ";
    cin >> size;    
    Queue q(size);
    while (1)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Size of Queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Size of Queue: " << q.sizeOfQueue() << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
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
4. Size of Queue
5. Exit
Enter your choice: 1
Enter the data: 9
Enter your choice: 1
Enter the data: 20
Enter your choice: 1
Enter the data: 11
Enter your choice: 1
Enter the data: 5
Enter your choice: 1
Enter the data: 4
Enter your choice: 3
9 20 11 5 4
Enter your choice: 2
Dequeued Element: 9
Enter your choice: 3
20 11 5 4
Enter your choice: 4
Size of Queue: 4
Enter your choice: 5
*/