#include<bits/stdc++.h>
using namespace std;
int mod = 1000000009;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> nums(n, 0);
    for(auto& i : nums) cin>>i;
    
    long long int total_sum = accumulate(nums.begin(), nums.end(), 0LL);
    if(total_sum < 2*k){
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> dp(k, vector<int>(n+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i < k; i++){
        dp[i][0] = 0;
    }
    for(int j = 1; j < n+1; j++){
        dp[0][j] = 0;
    }

    for(int i = 0; i < k; i++){
        for(int j = 1; j < n+1; j++){
            dp[i][j] += dp[i][j-1]%mod;
            if(i-nums[j-1] >= 0) dp[i][j] += dp[i-nums[j-1]][j-1]%mod;
        }
    }

    long long ans = 0;
    for(int i = 0; i < k; i++){
        ans = (ans+dp[i][n])%mod;
    }

    cout<<binpow(2, n, mod) - (2*ans)%mod<<endl;


}


int main(){

    solve();
    return 0;
}