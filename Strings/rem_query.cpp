#include <bits/stdc++.h>
using namespace std;


// dp[i][j] = true if there is a subset of the first i digits of N that sums to j mod K
void solve(string N, int K, vector<int> Q) {
    vector<vector<bool>> dp(N.size()+1, vector<bool>(K, false));
    dp[0][0] = true;

    for (int i = 1; i <= N.size(); i++) {
        int digit = N[i-1] - '0';
        for (int j = 0; j < K; j++) {
            dp[i][j] = dp[i-1][j];
            if (dp[i-1][(j-digit+K)%K]) {
                dp[i][j] = true;
            }
        }
    }

    for (int X : Q) {
        cout << (dp[N.size()][X] ? "YES" : "NO") << endl;
    }
}

int main() {
    string N = "174";
    int K = 9;
    vector<int> Q = {0,1,2};
    solve(N, K, Q);
    return 0;
}