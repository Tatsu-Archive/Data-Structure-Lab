#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int n)
    {
        data = n;
        next = NULL;
        prev = NULL;
    }
};

class linked_list
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void add_node(int n)
    {
        Node *temp = new Node(n);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void printfwd()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printbwd()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void convert()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                temp->next->prev = temp;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    linked_list list;
    int n, num;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        list.add_node(num);
    }
    cout << "The list is: ";
    list.printfwd();
    list.convert();
    cout << "The list in forward direction is: ";
    list.printfwd();
    cout << "The list in backward direction is: ";
    list.printbwd();

    Node *temp = list.head;
    while (temp != NULL)
    {
        Node *temp2 = temp;
        temp = temp->next;
        delete temp2;
    }

    return 0;
}

/*
Input/Output
Enter the number of elements: 9
Enter the elements: 1 2 3 4 5 6 7 8 9
The list is: 1 2 3 4 5 6 7 8 9
The list in forward direction is: 1 2 3 4 5 6 7 8 9
The list in backward direction is: 9 8 7 6 5 4 3 2 1
*/