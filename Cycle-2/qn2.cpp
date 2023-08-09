#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]<temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void printarray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void getarray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    getarray(arr, n);
    cout<<"Unsorted array: ";
    printarray(arr, n);
    insertionSort(arr, n);
    cout<<"Sorted array: ";
    printarray(arr, n);
    return 0;
}

/*
Input
Enter the number of elements: 5
Enter the elements: 6 7 4 2 9
Output
Unsorted array: 6 7 4 2 9
Sorted array: 2 4 6 7 9
*/