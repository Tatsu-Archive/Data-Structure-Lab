#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void insert(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void search(int key)
    {
        Node *temp = head;
        int pos = 1;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Found at position " << pos << endl;
                found = true;
            }

            temp = temp->next;
            pos++;
        }

        if (!found)
        {
            cout << "NOT FOUND" << endl;
        }
    }

    void count_duplicates(int key)
    {
        Node *temp = head;
        int count = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                count++;
            }

            temp = temp->next;
        }

        if (count == 0)
        {
            cout << "NO DUPLICATES" << endl;
        }
        else
        {
            cout << count - 1 << endl;
        }
    }

    void remove_duplicates(int key)
    {
        Node *temp = head;
        Node *prev = NULL;
        bool keyFound = false;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                if (keyFound)
                {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
                else
                {
                    keyFound = true;
                    prev = temp;
                    temp = temp->next;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }

    void insert_pos(int key, int pos)
    {
        if (pos == 1)
        {
            Node *newNode = new Node();
            newNode->data = key;
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            int count = 1;

            while (temp != NULL)
            {
                if (count == pos - 1)
                {
                    Node *newNode = new Node();
                    newNode->data = key;
                    newNode->next = temp->next;
                    temp->next = newNode;
                    break;
                }

                temp = temp->next;
                count++;
            }

            if (temp == NULL)
            {
                cout << "LIST TOO SMALL" << endl;
            }
        }
    }

    void execute(char op, int key, int pos)
    {
        switch (op)
        {
        case 's':
            search(key);
            break;
        case 'c':
            count_duplicates(key);
            break;
        case 'r':
            remove_duplicates(key);
            break;
        case 'i':
            insert_pos(key, pos);
            break;
        }
    }
};

int main()
{
    LinkedList list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        list.insert(data);
    }

    list.display();

    char op;
    cin >> op;

    while (op != 'e')
    {
        int key, pos;
        cin >> key;

        if (op == 'i')
        {
            cin >> pos;
        }

        list.execute(op, key, pos);
        list.display();
        cin >> op;
    }

    return 0;
}

/*
Input/Output
6
10 1 0 14 5 45
10 -> 1 -> 0 -> 14 -> 5 -> 45 -> NULL
s 11
NOT FOUND
10 -> 1 -> 0 -> 14 -> 5 -> 45 -> NULL
i 5 7
10 -> 1 -> 0 -> 14 -> 5 -> 45 -> 5 -> NULL
s 5
Found at position 5
Found at position 7
10 -> 1 -> 0 -> 14 -> 5 -> 45 -> 5 -> NULL
i 50 9
LIST TOO SMALL
10 -> 1 -> 0 -> 14 -> 5 -> 45 -> 5 -> NULL
i 5 2
10 -> 5 -> 1 -> 0 -> 14 -> 5 -> 45 -> 5 -> NULL
c 5
2
10 -> 5 -> 1 -> 0 -> 14 -> 5 -> 45 -> 5 -> NULL
r 5
10 -> 5 -> 1 -> 0 -> 14 -> 45 -> NULL
e
*/