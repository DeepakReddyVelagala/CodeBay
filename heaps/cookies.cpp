#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void solve(){
    int n, k;
    cin>>n;
    vector<int> h(n, 0);
    vector<int> e(n, 0);
    for(auto& i : h) cin>>i;
    for(auto& i : e) cin>>i;
    cin>>k;
    
    auto comp = [](pii a, pii b){
        return a.first == b.first? a.second >= b.second : a.first < b.first;
    };

    vector<pii> data;
    for(int i = 0; i < n; i++){
        data.push_back({h[i], e[i]});
    }

    sort(data.begin(), data.end(), comp);
    priority_queue<int> pq;
    vector<int> ener_ans;
    for(auto& p : data){
        if(p.first > k){
            while(p.first > k and !pq.empty()){
                k += pq.top();
                pq.pop();
                ener_ans.push_back(k);
            }
        }
        if(p.first <= k){
            pq.push(p.second);
        }
    }
    while(!pq.empty()) {
        k += pq.top(); pq.pop();
        ener_ans.push_back(k);
    }
    cout<<ener_ans.size()<<" ";
    for(auto& i : ener_ans) cout<<i<<" ";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}