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

void fillShellFromOned(int **arr, int s, int r, int c, int *oned)
{
    int minr, minc;
    minr = minc = s - 1;
    int maxr, maxc;
    maxr = maxc = r - s;
    int idx = 0;
    // lw
    for (int i = minr, j = minc; i <= maxr; i++)
    {
        arr[i][j]= oned[idx];
        idx++;
    }
    // bw
    for (int i = maxr, j = minc + 1; j <= maxc; j++)
    {
        arr[i][j]= oned[idx];
        idx++;
    }
    // rw
    for (int i = maxr - 1, j = maxc; i >= minr; i--)
    {
        arr[i][j]= oned[idx];
        idx++;
    }
    // tw
    for (int j = maxr - 1, i = minr; j >= minc + 1; i--)
    {
        arr[i][j]= oned[idx];
        idx++;
    }
}

void fillOnedFromShell(int **arr, int s, int r, int c, int *oned)
{
    int minr, minc;
    minr = minc = s - 1;
    int maxr, maxc;
    maxr = maxc = r - s;
    int idx = 0;
    // lw
    for (int i = minr, j = minc; i <= maxr; i++)
    {
        oned[idx] = arr[i][j];
        idx++;
    }
    // bw
    for (int i = maxr, j = minc + 1; j <= maxc; j++)
    {
        oned[idx] = arr[i][j];
        idx++;
    }
    // rw
    for (int i = maxr - 1, j = maxc; i >= minr; i--)
    {
        oned[idx] = arr[i][j];
        idx++;
    }
    // tw
    for (int j = maxr - 1, i = minr; j >= minc + 1; i--)
    {
        oned[idx] = arr[i][j];
        idx++;
    }
}

void reverse(int *oned, int start, int end)
{
    while (start < end)
    {
        int temp = oned[start];
        oned[start] = oned[end];
        oned[end] = temp;
        start++;
        end--;
    }
}

void rotate(int *oned, int n, int length)
{
    n = n % length;
    if (n < 0)
    {
        n = n + length;
    }
    reverse(oned, 0, length - n-1);
    reverse(oned, length - n, length-1);
    reverse(oned, 0, length-1);
}


void shellRotate(int **arr, int r, int c, int s, int n)
{
    int *oned;
    int minr, minc;
    minr = minc = s - 1;
    int maxr, maxc;
    maxr = maxc = r - s;
    oned = new int[2 * (maxr - minr + maxc - minc)];
    fillOnedFromShell(arr, s, r, c, oned);
    rotate(oned, n, r * c);
    fillShellFromOned(arr, s, r, c, oned);
}

int main()
{
    int r, c, n, s;
    cout << "Enter number of rows and columns " << endl;
    cin >> r >> c;
    cout << "Enter shell number and number of rotations: " << endl;
    cin >> s >> n;
    int **arr = new int *[r];
    setVAlues(arr, r, c);
    cout << "Final array is: " << endl;
    display(arr, r, c);
    cout << endl;
    shellRotate(arr, r, c, s, n);
    display(arr,r,c);
    return 0;
}