#include <iostream>
using namespace std;

void toh(int n, int A, int B, int C)
{
    if (n == 0)
    {
        return;
    }

    // will print the instructions to move n-1 discs from A to C using B
    toh(n - 1, A, C, B);
    cout << n << " [ " << A << "->" << B << " ]" << endl;
    toh(n - 1, C, B, A);
}

int main()
{
    int n;
    cout << "Enter number of discs" << endl;
    cin >> n;
    toh(n, 1, 2, 3);
    return 0;
}