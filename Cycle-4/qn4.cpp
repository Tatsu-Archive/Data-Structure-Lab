/*Implement a circular queue using array with the following operations : ENQUEUE,
DEQUEUE, ISEMPTY, SIZE()*/

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
    Queue q(5);

    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    q.displayQueue();

    cout << "Deleted value = " << q.deQueue() << endl;
    cout << "Deleted value = " << q.deQueue() << endl;

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20);
    return 0;
}

/*Input
14
22
13
-6
Output
Inserted 14
Inserted 22
Inserted 13
Inserted -6
Front -> 0
Items -> 14 22 13 -6
Rear -> 3
Deleted value = 14
Deleted value = 22
Front -> 2
Items -> 13 -6
Rear -> 3
Inserted 9
Inserted 20
Inserted 5
Front -> 2
Items -> 13 -6 9 20 5
Rear -> 1
Queue is full
*/