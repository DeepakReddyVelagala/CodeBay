#include<bits/stdc++.h>
using namespace std;

/**
def is_palindrome(s):
    return s == s[::-1]

def countPalindromes(arr):
    n = len(arr)
    count = 0

    for x in range(n):
        for y in range(n):
            if x == y:
                continue
            for i in range(len(arr[x])):
                for j in range(len(arr[y])):
                    temp_x = list(arr[x])
                    temp_y = list(arr[y])
                    temp_x[i], temp_y[j] = temp_y[j], temp_x[i]
                    if is_palindrome("".join(temp_x)):
                        count += 1

    return count

# Example usage:
arr = ["xy", "tz", "abab"]
result = countPalindromes(arr)
print(result)  # Output: 2
*/

int countPalindromes(vector<string> arr){

}

int main(){
    int n;
    cin>>n;
    vector<strings> arr(n, "");
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<countPalindromes(arr)<<endl;
}