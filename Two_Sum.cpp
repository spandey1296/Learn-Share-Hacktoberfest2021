#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<nums.size();j++) {
                if((i!=j)&&(nums[i]+nums[j])==target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                    }
            }
        }
        return res;
}
int main(void) {
    int n;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++) {
        int ele;
        cin>>ele;
        nums.emplace_back(ele);
    }
    int target;
    cout<<"Enter the target sum: ";
    cin>>target;
    vector<int> res=twoSum(nums,target);
    cout<<"The indices to the targeted sum are: ";
    for(auto &i:res) cout<<i<<" ";
    return 0;
}