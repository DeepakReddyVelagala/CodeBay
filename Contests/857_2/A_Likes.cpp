# include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    int n;
    cin>>n;

    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        x < 0? neg++: pos++;
    }

    for(int i = 1; i  <= pos; i++){
        cout<<i<<" ";
    }
    for(int i = 1; i <= neg; i++){
        cout<<pos-i<<" ";
    }
    cout<<endl;

    for(int i = 0; i < neg; i++){
        cout<<1<<" "<<0<<" ";
    }
    for(int i = 1; i <= pos-neg; i++){
        cout<<i<<" ";
    }

    cout<<endl;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}