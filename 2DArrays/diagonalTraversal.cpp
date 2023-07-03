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

void diagonalTraversal(int **arr, int r, int c)
{
    for (int g = 0; g < r; g++)
    {
        for (int i = 0, j = g; j < r; i++, j++)
        {
            cout << arr[i][j] << endl;
        }
    }
}

int main()
{
    int r, c;
    cout << "Enter number of rows and columns " << endl;
    cin >> r >> c;
    int **arr = new int *[r];
    setVAlues(arr, r, c);
    cout << "Final array is: " << endl;
    display(arr, r, c);
    cout << endl;
    diagonalTraversal(arr, r, c);
    return 0;
}