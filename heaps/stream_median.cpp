#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> stream(n, 0);
    for(auto& i : stream) cin>>i;

    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    double med = 0;
    for(auto& i : stream){
        maxheap.push(i);
        if(maxheap.size() > 1 + minheap.size() or (!minheap.empty() and maxheap.top() > minheap.top())){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size() > 1 + maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }

        if(maxheap.size() == minheap.size()){
            med = (maxheap.top() + 0.0 + minheap.top())/2;
        }
        else if(maxheap.size() > minheap.size()){
            med = maxheap.top();
        }
        else med = minheap.top();

        cout<<med<<endl;
    }

}

int main(){
    solve();
}