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
    Queue obj(5);
    int choice, data;
    
    return 0;

}

/*Input

*/