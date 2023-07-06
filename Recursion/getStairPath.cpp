// Important concepts: getSubsequence, this one as well, get keypad combination

#include <iostream>
#include <vector>
using namespace std;

vector<string> getStairPaths(int n)
{
    if (n == 0 || n<0)
    {
        vector<string> bres;
        bres.push_back("");
    }

    vector<string> paths1 = getStairPaths(n - 1);
    vector<string> paths2 = getStairPaths(n - 2);
    vector<string> paths3 = getStairPaths(n - 3);
    vector<string> paths;

    for (string path : paths1)
    {
        paths.push_back('1' + path);
    }

    for (string path : paths2)
    {
        paths.push_back('2' + path);
    }

    for (string path : paths3)
    {
        paths.push_back('3' + path);
    }
    return paths;
}

int main()
{
    int n;
    cin >> n;
    vector<string> paths = getStairPaths(n);
    for (string i : paths)
    {
        cout << i << endl;
    }
    return 0;
}