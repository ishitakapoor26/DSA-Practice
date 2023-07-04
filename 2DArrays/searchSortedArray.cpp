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

pair<int,int> searchSortedArray(int** arr, int n, int key){
    pair<int, int> p;
    int i=0, j=n-1;
    while (i<n && j>=0)
    {
        if(key==arr[i][j]){
            p.first=i;
            p.second=j;
            return p;
        }else if(key<arr[i][j]){
            j--;
        }else{
            i++;
        }
    }
    
}

int main()
{
    int n, key;
    cout << "Enter number of rows " << endl;
    cin >>n;
    cout<<"Enter element to be searched: "<<endl;
    cin>>key;
    int **arr = new int *[n];
    setVAlues(arr, n);
    cout << "Final array is: " << endl;
    display(arr, n);
    cout << endl;
    pair<int, int> p=searchSortedArray(arr, n, key);
    cout<<p.first<<" "<<p.second;
    return 0;
}