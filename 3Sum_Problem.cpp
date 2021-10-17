// A program to find all Unique triplets whose sum equals to 0

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &num)
{
    vector<vector<int>> res;
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
    {
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back)
        {
            int sum = num[front] + num[back];
            if (sum < target)
                front++;
            else if (sum > target)
                back--;
            else
            {
                vector<int> triplet = {num[i], num[front], num[back]};
                res.push_back(triplet);

                while (front < back && num[front] == triplet[1])
                    front++;

                while (front < back && num[back] == triplet[2])
                    back--;
            }
        }
        while (i + 1 < num.size() && num[i + 1] == num[i])
            i++;
    }
    return res;
}

int main()
{
    int n, i, element;
    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> arr;
    vector<vector<int>> ans;
    cout<<"Enter array elements "<<endl;
    for (i = 0; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }
    ans = threeSum(arr);
    cout << "Unique Triplets with sum equal to 0 are"<<endl;
    for (auto x : ans)
    {
        for (auto i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}