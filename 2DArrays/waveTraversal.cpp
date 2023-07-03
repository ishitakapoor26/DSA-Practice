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

void waveTraversal(int **arr, int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        if(i%2==0){
        for (int j = 0; j < r; j++)
        {
            cout << arr[j][i] << endl;
        }
        }else{
            for(int j=r-1;j>=0;j--){
                cout<<arr[j][i]<<endl;
            }
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
    waveTraversal(arr, r, c);
    return 0;
}