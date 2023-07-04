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

void saddlePoint(int** arr, int n){
    int sj=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[i][j] < arr[i][sj]){
                sj = j;
            }
        }
        bool flag= true;
        for(int  k=0;k<n;k++){
            if(arr[k][sj]>arr[i][sj]){
               flag=false;     
            }
        }
        if(flag==true){
            cout<<arr[i][sj];
            return;
        }
    }
    cout<<"Invalid Input";
}

int main()
{
    int n;
    cout << "Enter number of rows " << endl;
    cin >>n;
    int **arr = new int *[n];
    setVAlues(arr, n);
    cout << "Final array is: " << endl;
    display(arr, n);
    cout << endl;
    saddlePoint(arr, n);
    return 0;
}