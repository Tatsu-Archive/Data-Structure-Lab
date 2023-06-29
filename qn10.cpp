#include <iostream>
using namespace std;

void readMatrix(int **matrix, int m, int n)
{
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int **matrix, int m, int n)
{
    cout << "The matrix is: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void rowSum(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << sum << endl;
    }
}

void columnSum(int **matrix, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += matrix[j][i];
        }
        cout << "Sum of column " << i + 1 << ": " << sum << endl;
    }
}

void maxRowSum(int **matrix, int m, int n)
{
    int maxSum = 0, maxRow = 0;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += matrix[i][j];
        if (sum > maxSum)
        {
            maxSum = sum;
            maxRow = i + 1;
        }
    }
    cout << "Row with the maximum sum: " << maxRow << endl;
}

void maxColumnSum(int **matrix, int m, int n)
{
    int maxSum = 0, maxColumn = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
            sum += matrix[j][i];
        if (sum > maxSum)
        {
            maxSum = sum;
            maxColumn = i + 1;
        }
    }
    cout << "Column with the maximum sum: " << maxColumn << endl;
}

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    int **matrix = new int *[m];
    readMatrix(matrix, m, n);
    printMatrix(matrix, m, n);
    rowSum(matrix, m, n);
    columnSum(matrix, m, n);
    maxRowSum(matrix, m, n);
    maxColumnSum(matrix, m, n);
    return 0;
}

/*
Input:  3 3
        1 2 3
        4 5 6
        7 8 9
Output: The matrix is:
            1 2 3
            4 5 6
            7 8 9
Sum of row 1: 6
Sum of row 2: 15
Sum of row 3: 24
Sum of column 1: 12
Sum of column 2: 15
Sum of column 3: 18
Row with the maximum sum: 3
Column with the maximum sum: 3
*/