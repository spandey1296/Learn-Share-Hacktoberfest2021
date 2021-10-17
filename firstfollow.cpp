#include <bits/stdc++.h>
using namespace std;

void findFollow(char & find, int & l, vector<string> & prod, map<char, int> & ans);

void findFirst(char & find, int & l, vector<string> & prod, map<char, int> & ans){

    if(find >= 'a' && find <= 'z'){
        ans[find] = 1;
        return;
    }

    for(int i = 0; i < l; i++){
        if(prod[i][0] == find){
            // Calc first.

            if(prod[i][2] >= 'a' && prod[i][2] <= 'z'){
                ans[prod[i][2]] = 1;
            }
            else if(prod[i][2] >= 'A' && prod[i][2] <= 'Z'){
                findFirst(prod[i][2], l, prod, ans);
            }
            else if(prod[i][2] == '#'){
                findFollow(find, l, prod, ans);
            }
        }
    }
}

void findFollow(char & find, int & l, vector<string> & prod, map<char, int> & ans){

    // For 'S'.
    if(prod[0][0] == find){
        ans['$'] = 1;
    }

    for(int i = 0; i < l; i++){
        for(int j = 2; j < prod[i].size(); j++){

            // Character matches.
            if(prod[i][j] == find){

                // If it's last character then call first Follow.
                if(j == prod[i].size() - 1 && prod[i][0] != find){
                    findFollow(prod[i][0], l, prod, ans);
                }
                else{
                    findFirst(prod[i][j + 1], l, prod, ans);
                }
            }
        }
    }
}

void solve(){
    // cout<<0<<endl;
    int l;
    cout<<"Enter total productions : ";
    cin>>l;

    vector<string> prod(l);
    for(int i = 0; i < l; i++){
        cout<<"Enter production "<< (i + 1) <<" : ";
        cin>>prod[i];
    }

    while(true){

        char find;
        cout<<"Enter character to find First & Follow (Z to exit):";
        cin>>find;
        if(find == 'Z'){
            break;
        }

        map<char, int> ans;
        findFirst(find, l, prod, ans);
        cout<<"First :=>  ";
        for(auto itr:ans){
            cout<<itr.first<<" , ";
        }
        cout<<endl;
        ans.clear();

        findFollow(find, l, prod, ans);
        cout<<"Follow :=>  ";
        for(auto itr:ans){
            cout<<itr.first<<" , ";
        }
        cout<<endl;
    }
}

signed main() {
    int q = 1;
    while(q--){
        solve();
    }
}
