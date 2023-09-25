#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped Element: " << arr[top] << endl;
        top--;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    int sizeOfStack()
    {
        return top + 1;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s(10);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.display();
    s.pop();
    s.display();
    cout << "Size of Stack: " << s.sizeOfStack() << endl;
    cout << "Is Stack Empty: " << s.isEmpty() << endl;
    return 0;
}

/*Input
4
5
6
7
Output
7 6 5 4
Popped Element: 7
6 5 4
Size of Stack: 3
Is Stack Empty: 0
*/