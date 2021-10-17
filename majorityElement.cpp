//que : find the majority element i.e. element which is occuring more than floor(n/2) times.
#include <bits/stdc++.h>
using namespace std;
int majority(vector<int> v)
{
    int major, count = 0;
    for (int n : v)
    {
        if (count == 0)
        {
            major = n;
        }
        if (n == major)
            count++;
        else
            count--;
    }
    return major;
}
int main()
{
    vector<int> v{1, 2, 2, 2, 3};
    int res = majority(v);
    cout << res << endl;
    return 0;
}
