/*Implement a queue using array with the following operations : ENQUEUE, DEQUEUE,ISEMPTY, SIZE()*/

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

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout <<"\n";
    q.display();
    cout <<"\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "Size of Queue: " << q.sizeOfQueue() << endl;
    cout << "Is Queue Empty: " << q.isEmpty() << endl;
    return 0;

}

/*Input
5
10
20
30
40

10 20 30 40
Dequeued Element: 10
Dequeued Element: 20
Dequeued Element: 30
Dequeued Element: 40
Queue Underflow

Size of Queue: 0
Is Queue Empty: 1
*/