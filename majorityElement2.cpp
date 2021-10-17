//que : find the majority element i.e. element which is appearing more than floor(n/3) times. there are 2 majority element maximum
#include <bits/stdc++.h>
using namespace std;
int majority(vector<int> v)
{
    int n = v.size();
    int major1,count1=0;
    int major2,count2=0;
    for(int ele : v){
        if(major1==ele)count1++;
        else if(major2 ==ele)count2++;
        else if(count1==0){
            major1 = ele;
        }
        else if(count2==0){
            major2=ele;
        }else{
            count1--;
            count2--;
        }
    }
    for(int ele :v){
        
    }
}
int main()
{
    vector<int> v{1, 2, 2, 2, 3, 3, 3};
    int res = majority(v);
    cout << res << endl;
    return 0;
}
