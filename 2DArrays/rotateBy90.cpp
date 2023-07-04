#include <iostream>
using namespace std;

void setVAlues(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void display(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateArray(int **arr, int n)
{
    int **arr2 = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr2[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr2[i][j] = arr[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = arr2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        delete[] arr2[i];
    }
    delete[] arr2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            int temp= arr[i][j];
            arr[i][j]= arr[i][n-1-j];
            arr[i][n-1-j]=temp;
        }
    }
    display(arr,n);
}

int main()
{
    int n;
    cout << "Enter number of rows " << endl;
    cin >> n;
    int **arr = new int *[n];
    setVAlues(arr, n);
    cout << "Final array is: " << endl;
    display(arr, n);
    cout << endl;
    rotateArray(arr, n);
    return 0;
}