#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> nums(n, 0);
    for(auto& i : nums) cin>>i;

    sort(nums.begin(), nums.end(), greater<int>());
    auto comp = [&nums](const pii& a, const pii& b){
        return (nums[a.first]+ nums[a.second]) < (nums[b.first] + nums[b.second]); 
    };
    priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
    pq.push({0, 1});
    vector<int> ans;

    while(!pq.empty() and k--){
        auto v = pq.top();
        pq.pop();
        int id1 = v.first;
        int id2 = v.second;
        ans.push_back(nums[id1]+nums[id2]);
        if(id2+1 < n){
            pq.push({id1, id2+1});
            if(id1+1 == id2) pq.push({id1+1, id2+1});
        }
    }

    for(auto& i : ans) cout<<i<<" ";
    cout<<endl;


}

int main(){
    solve();
}