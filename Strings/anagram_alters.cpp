#include<bits/stdc++.h>
using namespace std;


int countSentence(vector<string> wordlist, string sentence){
    map<map<char, int>, int> lookup;
    
    for(int i = 0; i < wordlist.size(); i++){
        map<char, int> temp;
        for(auto& c : wordlist[i]) temp[c]++;
        lookup[temp]++;
    } 
    
    string store = "";
    int ans = 1;
    for(int i = 0; i < sentence.length()+1; i++){
        if(i == sentence.length() or sentence[i] == ' '){
            map<char, int> temp;
            for(auto& c : store) temp[c]++;
            if(lookup.find(temp) != lookup.end()){
                ans *= lookup[temp];
            }
            store = "";
        }
        else store += sentence[i];
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> wordlist(n, "");
        for(auto& s : wordlist) cin>>s;
        cin.ignore();

        string sentence;
        getline(cin, sentence);
        int ans = countSentence(wordlist, sentence);

        cout<<ans<<endl;
    }
}