#include<iostream>
using namespace std;

void read_array(int arr[], int size){
    cout<<"Enter the Elements of the array : ";
    for( int i =0 ;i<size; i++){
        cin>> arr[i];
    }
}
void print_array(int arr[], int size){
    cout<<"\nThe Elements of the array are : ";
    for( int i =0 ;i<size; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

void second_largest(int arr[], int size){
    if (size<2){
        cout<<"There need to be atleast 2 elements in the array!!"<<endl;
    }
    else{    
        for( int i=0;i<size;i++){
        for (int j = i+1;j<size;j++){
            if(arr[j]>arr[i]){
                int temp = arr[j];
                arr[j]= arr[i];
                arr[i] = temp;
            }
        }}
        cout<<"The second largest element of the array is : "<<arr[1]<<endl;
    }
}

int  main(){
    int size;
    cout<<"Enter the size of the array  : ";
    cin>> size;
    int arr[size];
    read_array(arr,size);
    print_array(arr,size);
    second_largest(arr,size);
    return 0;
}

/*
Input:  
Enter the size of the array  : 5
Enter the Elements of the array : 1 2 3 4 5
Output: 
The Elements of the array are : 1 2 3 4 5
The second largest element of the array is : 4
*/