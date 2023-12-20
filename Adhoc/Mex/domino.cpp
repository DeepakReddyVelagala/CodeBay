#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1000000007;

int countDistinctColorings(vector<string> domino){
    string a, b;
    int n;
    a = domino[0];
    b = domino[1];
    n = a.size();

    ll ans=1;
	ll cur=-1;
	for(int i=0;i<n;i++){
		if(a[i]==b[i]){
			if(cur==-1){
				ans*=3;
				ans%=mod;
			}
			else if(cur==0){
				ans*=2;
				ans%=mod;
			}
			cur=0;
		}
		else{
			if(cur==-1){
				ans*=6;
				ans%=mod;
			}
			else if(cur==0){
				ans*=2;
				ans%=mod;
			}
			else{
				ans*=3;
				ans%=mod;
			}
			cur=1;
			i++;
		}
	}

    return (int)ans;
}



int main(){
    vector<string> domino(2, "");
    int n;
    cin>>n;
    cin>>domino[0];
    cin>>domino[1];
    cout<<countDistinctColorings(domino)<<endl;
}