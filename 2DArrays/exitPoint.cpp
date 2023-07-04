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

void exitPoint(int** arr, int n){
    // 0 -e, 1-s, 2-w, 3-n
    int dir=0;
    int i=0;
    int j=0;
    while(true){
        dir= (dir+ arr[i][j] % 4);
        if(dir==0){
            j++;
        }else if(dir==1){
            i++;
        }else if(dir==2){
            j--;
        }else if(dir==3){
            i--;
        }
        if(i<0){
            i++;
            break;
        }else if(j<0){
            j++;
            break;
        }
        else if(i==n){
            i--;
            break;
        }else if(j==n){
            j--;
            break;
        }
    }
    cout<<i<<" "<<j;
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
    exitPoint(arr, n);
    return 0;
}