#include<iostream>
using namespace std;

void bubbleSort(float arr[], int n)
{   
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                float temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp; 
            }
        }
    }
}

void printarray(float arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void getarray(float arr[], int n)
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
    float arr[n];
    cout<<"Enter the elements: ";
    getarray(arr, n);
    cout<<"Unsorted array: ";
    printarray(arr, n);
    bubbleSort(arr, n);
    cout<<"Sorted array: ";
    printarray(arr, n);
    return 0;
}

/*
Input           
Enter the number of elements: 5
Enter the elements: 5 4 3 2 1
Output
Unsorted array: 5 4 3 2 1
Sorted array: 1 2 3 4 5        
*/