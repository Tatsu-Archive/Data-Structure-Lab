/*Implement a stack using Linked List with the following operations : PUSH, POP, ISEMPTY, SIZE()*/


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

int main(){
    Node *head = NULL;
    Node obj(0);
    obj.push(&head, 6);
    obj.push(&head, 2);
    obj.push(&head, 8);
    obj.push(&head, 1);
    cout <<"\n";
    obj.display(&head);
    cout <<"\n";
    obj.pop(&head);
    cout <<"\n";
    obj.display(&head);
    cout <<"\n";
    cout << "Size of Stack: " << obj.sizeOfStack(&head) << endl;
    cout << "Is Stack Empty: " << obj.isEmpty(&head) << endl;
    return 0;
}

/*Input
6
2
8
1
Popped Element: 1
8
2
6
Size of Stack: 3
Is Stack Empty: 0
*/