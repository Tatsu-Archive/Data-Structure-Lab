#include<iostream>
using namespace std;

void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1=m-l+1;
    int n2=r-m;
    float L[n1], R[n2];
    for(i=0; i<n1; i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(float arr[], int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m ,r);
    }
}

void printarray(float arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void getarray(float arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
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
    mergeSort(arr, 0, n-1);
    cout<<"Sorted array: ";
    printarray(arr, n);
    return 0;
}

/*
Input
Enter the number of elements: 5
Enter the elements: 12 2 1 5 8
Output
Unsorted array: 12 2 1 5 8
Sorted array: 1 2 5 8 12
*/