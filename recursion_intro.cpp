#include <iostream>
using namespace std;

// High level thinking of recursion 3 steps:
// 1. Establish the expectation pd(5) will print 543210
// 2. Generate the faith the pd(4) outcome will definitely be 43210
// 3. Link expectation and faith.

void print_decreasing(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << n<<endl;;
        print_decreasing(n - 1);
    }
}

int main()
{
    print_decreasing(5);
    return 0;
}