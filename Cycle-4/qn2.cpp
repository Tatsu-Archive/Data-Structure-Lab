#include <iostream>
using namespace std;

class Node
{
    Node *next;
    int data;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    void push(Node **head, int data)
    {
        Node *newNode = new Node(data);
        if (*head == NULL)
        {
            *head = newNode;
            return;
        }
        newNode->next = *head;
        *head = newNode;
    }

    void pop(Node **head)
    {
        if (*head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node *temp = *head;
        *head = (*head)->next;
        cout << "Popped Element: " << temp->data << endl;
        delete temp;
    }

    bool isEmpty(Node **head)
    {
        if (*head == NULL)
            return true;
        else
            return false;
    }

    int sizeOfStack(Node **head)
    {
        int count = 0;
        Node *temp = *head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display(Node **head)
    {
        if (*head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        Node *temp = *head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){ //menu driven
    Node *head = NULL;
    Node obj(0);
    int choice, data;
    while (1)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Is Empty" << endl;
        cout << "4. Size of Stack" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            obj.push(&head, data);
            break;
        case 2:
            obj.pop(&head);
            break;
        case 3:
            if (obj.isEmpty(&head))
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            cout << "Size of Stack: " << obj.sizeOfStack(&head) << endl;
            break;
        case 5:
            obj.display(&head);
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}

/*Input
1. Push
2. Pop
3. Is Empty
4. Size of Stack
5. Display
6. Exit

Enter your choice: 1
Enter data: 5
Enter your choice: 1
Enter data: 1
Enter your choice: 1
Enter data: 9
Enter your choice: 5
9 1 5 
Enter your choice: 2
Popped Element: 9
Enter your choice: 5
1 5
Enter your choice: 3
Stack is not Empty
Enter your choice: 4
Size of Stack: 2
Enter your choice: 6
*/