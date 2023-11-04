#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& nums, int l, int r, vector<vector<int>>& dp){

    if(l > r) return 0;
    int ans = 0;
    if(dp[l][r] != -1) return dp[l][r];
    ans = max(ans, nums[l] + min(func(nums, l+2, r, dp), func(nums, l+1, r-1, dp)));
    ans = max(ans, nums[r] + min(func(nums, l+1, r-1, dp), func(nums, l, r-2,dp)));

    return dp[l][r] = ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(auto& i : arr) cin>>i;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<func(arr, 0, n-1, dp)<<endl;
    return;

}

int main(){
    solve();
}