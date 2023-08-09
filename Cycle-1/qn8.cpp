#include <iostream>
using namespace std;

int count_dup(char arr[], int size)
{
    int ascii_count[256] = {0};
    for (int i = 0; i < size; i++)
    {
        ascii_count[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < 256; i++)
    {
        if (ascii_count[i] > 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    char arr[size];

    cout << "Enter the Character: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "The number of duplicate Elements in the character array ->"<<arr<<" : " << count_dup(arr,size) << endl;
    return 0;
}

/*
Input:
Enter the size of the array: 14
Enter the Character: pythonisbetter
Output:
The number of duplicate Elements in the character array ->pythonisbetter : 2
*/

