#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, p;
    cin>>n>>p;
    vector<int> cost(n, 0);
    for(auto& i : cost) cin>>i;

    bitset<1000> sum(1);
    for(auto& i : cost){
        sum |= sum<<i;
    }


    int pos = 0;
    int count = 0;
    while(pos <= p){
        while (sum[pos]) {
            pos++;
        }
        if(pos > p) continue;
        sum |= sum<<pos;
        count++;
    }
    cout<<count<<endl;
}

int main(){
    solve();
}