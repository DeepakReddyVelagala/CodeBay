# include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int ch = 0, boxes = 0, eb = 0;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;

        if(val == 1){
            ch++;
            if(eb==0) boxes++;
            else eb--;
        }

        else{
            if(ch % 2 == 0) eb = boxes - (ch/2) - (ch!=0);
            else eb = boxes - (ch+1)/2;
        }
    }

    cout<<boxes<<endl;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}