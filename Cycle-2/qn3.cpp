#include<iostream>
using namespace std;

void selectionSort(string arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        string temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

void printarray(string arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void getarray(string arr[], int n)
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
    string arr[n];
    cout<<"Enter the elements: ";
    getarray(arr, n);
    cout<<"Unsorted array: ";
    printarray(arr, n);
    selectionSort(arr, n);
    cout<<"Sorted array: ";
    printarray(arr, n);
    return 0;
}

/*
Input
Enter the number of elements: 9
Enter the elements: one picture is worth more than ten thousand words
Output
Unsorted array: one picture is worth more than ten thousand words
Sorted array: is more one picture ten than thousand words worth
*/