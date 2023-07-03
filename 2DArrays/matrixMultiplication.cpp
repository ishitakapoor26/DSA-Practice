#include <iostream>
using namespace std;

void setVAlues(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void display(int **arr, int r1, int c1)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixMultiplication(int **arr1, int **arr2, int **arr3, int c1, int r1, int c2, int r2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                cout << arr1[i][k] << " " << arr2[k][j];
                arr3[i][j] += arr1[i][k] * arr2[k][j];
                cout << i << "," << j << "," << k << " " << arr3[i][j] << endl;
            }
            cout << endl;
        }
    }
    display(arr3, r1, c2);
}

int main()
{
    int m1, m2, n1, n2;
    cout << "Enter number of rows for matrix 1 and 2: " << endl;
    cin >> m1 >> m2;
    cout << "Enter number of columns for matrix 1 and 2: " << endl;
    cin >> n1 >> n2;
    int **arr1 = new int *[m1];
    int **arr2 = new int *[m2];
    int **arr3 = new int *[m1];
    for (int i = 0; i < m1; i++)
    {
        arr3[i] = new int[n2];
    }
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            arr3[i][j] = 0;
        }
    }
    setVAlues(arr1, m1, n1);
    display(arr1, m1, n1);
    cout << "Matrix 2: " << endl;
    setVAlues(arr2, m2, n2);
    display(arr2, m2, n2);
    if (n1 == m2)
    {
        matrixMultiplication(arr1, arr2, arr3, n1, m1, n2, m2);
    }
    else
    {
        cout << "Invalid Matrix Multiplication" << endl;
    }
    return 0;
}