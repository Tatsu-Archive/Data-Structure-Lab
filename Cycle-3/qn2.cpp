#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linked_list
{
public:
    Node *head, *tail;

    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void printList(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void alternate_splice(Node *head)
    {
        if (head == NULL)
            return;

        Node *first = head;
        Node *second = head->next;

        Node *secondHead = second; // Store the head of the second sublist

        while (first != NULL && second != NULL)
        {
            first->next = second->next;
            first = first->next;

            if (first != NULL)
            {
                second->next = first->next;
                second = second->next;
            }
        }

        cout << "First Sublist: ";
        printList(head);
        cout << "Second Sublist: ";
        printList(secondHead);
    }
};

int main()
{
    linked_list a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.add_node(x);
    }
    a.alternate_splice(a.head);
    return 0;
}

/*
Input/Output
9
6 4 10 13 1 7 88 10 5
First Sublist: 6 10 1 88 5
Second Sublist: 4 13 7 10
*/