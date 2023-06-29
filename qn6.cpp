#include <iostream>
using namespace std;

void read_arr(int *arr, int n)
{
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void print_arr(int *arr, int n)
{
    cout << "The elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void search_arr(int *arr, int n, int elem)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elem)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "SORRY" << endl;
    }
}

void get_max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "The maximum element is: " << max << endl;
}

void get_min(int *arr, int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "The minimum element is: " << min << endl;
}


int main(){
    bool flag = false,loop = true;
    int n, choice, elem, *arr;
    cout << "1. Read integer n (<=100) , the size of array followed by n integer elements of ARR" << endl;
    cout << "2. Print the elements of array ARR" << endl;
    cout << "3. Read an integer elem to search in the array. Print FOUND/SORRY accordingly" << endl;
    cout << "4. Print the largest and smallest element of the array" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while (loop)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the size of the array: ";
            cin >> n;
            if (n > 100)
            {
                cout << "Please enter a size less than 100" << endl;
                break;
            }
            arr = new int[n];
            read_arr(arr, n);
            flag = true;
            break;
        case 2:
            if (flag)
            {
                print_arr(arr, n);
            }
            else
            {
                cout << "Please enter the array first" << endl;
            }
            break;
        case 3:
            if (flag)
            {
                cout << "Enter the element to search: ";
                cin >> elem;
                search_arr(arr, n, elem);
            }
            else
            {
                cout << "Please enter the array first" << endl;
            }
            break;
        case 4:
            if (flag)
            {
                get_max(arr, n);
                get_min(arr, n);
            }
            else
            {
                cout << "Please enter the array first" << endl;
            }
            break;
        case 5:
            cout << "Exiting..." << endl;
            loop = false;
            break;
        default:
            cout << "Please enter a valid choice" << endl;
            break;
        }
        if (loop)
        {
            cout << "Enter your choice: ";
            cin >> choice;
        }
    }
}

/*
Output:
1. Read integer n (<=100) , the size of array followed by n integer elements of ARR
2. Print the elements of array ARR
3. Read an integer elem to search in the array. Print FOUND/SORRY accordingly
4. Print the largest and smallest element of the array
5. Exit
Enter your choice: 1
Enter the size of the array: 5
Enter the elements of the array:
1 2 3 4 5
Enter your choice: 2
The elements of the array are: 1 2 3 4 5
Enter your choice: 3
Enter the element to search: 3
FOUND
Enter your choice: 3
Enter the element to search: 6
SORRY
Enter your choice: 4
The maximum element is: 5
The minimum element is: 1
Enter your choice: 5
Exiting...
*/