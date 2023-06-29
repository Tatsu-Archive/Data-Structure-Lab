#include <iostream>
using namespace std;

void read_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int *merge(int arr1[], int arr2[], int arr3[], int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        arr3[k] = arr1[i];
        arr3[k + size] = arr2[i];
        k++;
    }
    for (int i = 0; i < size * 2; i++)
    {
        for (int j = i + 1; j < size * 2; j++)
        {
            if (arr3[j] > arr3[i])
            {
                int temp = arr3[j];
                arr3[j] = arr3[i];
                arr3[i] = temp;
            }
        }
    }

    return arr3;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr1[size], arr2[size];
    int *arr3 = new int[size * 2];
    cout << "\nEnter the elements of the array 1: ";
    read_arr(arr1, size);
    cout << "\nEnter the elements of the array 2: ";
    read_arr(arr2, size);
    cout << "The elements of the arrays are: ";
    print_arr(arr1, size);
    cout << "| ";
    print_arr(arr2, size);
    arr3 = merge(arr1, arr2, arr3, size);
    cout << "\nThe merged array is: ";
    print_arr(arr3, size * 2);
    return 0;
}

/*
Enter the size of the array: 5

Enter the elements of the array 1: 1
2
3
4
5

Enter the elements of the array 2: 6
7
8
9
10
The elements of the arrays are: 1 2 3 4 5 | 6 7 8 9 10 
The merged array is:10 9 8 7 6 5 4 3 2 1
*/