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
    int size, choice, data;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack s(size);
    while (1)
    {
        cout << "1. Push\n2. Pop\n3. Display\n4. Size of Stack\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data: ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Size of Stack: " << s.sizeOfStack() << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}

/*Input
Enter the size of the stack: 5
1. Push
2. Pop
3. Display
4. Size of Stack
5. Exit
Enter your choice: 1
Enter the data: 5
Enter your choice: 1
Enter the data: 1
Enter your choice: 1
Enter the data: 9
Enter your choice: 1
Enter the data: 3
Enter your choice: 3
3 9 1 5
Enter your choice: 2
Popped Element: 3
Enter your choice: 3
9 1 5
Enter your choice: 4
Size of Stack: 3
*/