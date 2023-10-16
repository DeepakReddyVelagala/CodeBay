#include<bits/stdc++.h>
using namespace std;

int getMaximumMex(vector<int> arr, int x){
    int n = arr.size();
    vector<int> check(n, 0);
    for(auto& i : arr){
        if(i >= n) continue;
        check[i]++;
    }

    for(int i = 0; i < n; i++){
        // cout<<i<<" - ";
        if(check[i] >= 1) continue;
        for(int j = 0; j < n; j++){
            // cout<<j<<" - "<<check[j]<<" | ";
            if(check[j] <= 1) continue;
            if((abs(j-i) % x) != 0) continue;
            check[j]--;
            check[i]++;
            break;
        }
        // cout<<endl<<" ";
        if(check[i] == 1) continue;
        for(int j = n-1; j > i; j--){
            // cout<<j<<" - "<<check[j]<<" | ";
            if(check[j] == 0) continue;
            if((abs(j-i) % x) != 0) continue;
            check[j]--;
            check[i]++;
            break;
        }
        // cout<<endl;
       if(check[i] == 0) return i;
    }
    // for(auto& i : check) cout<<i<<"|";
        
    return n;
}

int getMaximumMex_2(vector<int> arr, int x){
    vector<int> check(x, 0);
    for(auto& i : arr){
         i = i % x;
         check[i]++;
    }
    int ans = INT_MAX, itr = 0;
    for(auto& i : check){
        ans = min(x*i + itr, ans);
        itr++;
    }
    return ans;
}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<int> arr(n, 0);
        for(auto& i : arr) cin>>i;
        int ans = getMaximumMex_2(arr, x);
        cout<<ans<<endl;
    }
    return 0;
}