#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pic;


vector<pic> ask(){
    int n;
    cin>>n;
    vector<pic> input;
    for(int i = 0; i < n; i++){
        int a;
        char c;
        cin>>a>>c;
        input.push_back({a, c});
    }

    return input;
}

void solve(vector<pic> stream){
    vector<char> store(stream.size(), 'A');
    vector<int> dashes;
    vector<string> ans;

    for(auto& two : stream){
        int id = two.first;
        char c = two.second;

        store[id-1] = c;
        if(c == '-'){
            dashes.push_back(id-1);
            sort(dashes.begin(), dashes.end());
        }

        if(dashes.size() > 1){
            vector<string> temp;
            int count = 0, j = 0;
            for(int i = dashes[0]; i <= dashes[dashes.size()-1]; i++){
                if(store[i] != 'A' and i != dashes[j]){
                    count++;
                }
                if(i == dashes[j]){
                    if(j != 0 and count == i - dashes[j-1] + 1 -2){
                        string ss = "";
                        for(int k = dashes[j-1]+1; k < dashes[j]; k++){
                            ss += store[k];
                        }
                        temp.push_back(ss);
                    }
                    count = 0;
                    j++;
                }
            }
            if(temp.size() == 1){
                dashes.clear();
                for(auto& c : store) c = 'A';
                ans.push_back(temp[0]);
            }
            else if(temp.size() == 2){
                dashes.clear();
                for(auto& c : store) c = 'A';
                ans.push_back(temp[1]);
            }
        }
    }

    for(auto& s : ans){
        cout<<s<<endl;
    }
}

int main(){
    vector<pic> input = ask();
    solve(input);
    return 0;
}