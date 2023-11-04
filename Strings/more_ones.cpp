// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums, int l, int mid, int r){
	int i = l, j = mid+1, k = 0, ans = 0;
	vector<int> temp(r-l+1, 0);

	while(i <= mid and j <= r){
		if(nums[i] <= nums[j]){
			temp[k++] = nums[i++];
		}
		else{
			temp[k++] = nums[j++];
			ans += mid-i+1;
		}
	}

	while(i <= mid) temp[k++] = nums[i++];
	while(j <= r) temp[k++] = nums[j++];

	for(int i = 0; i < (r-l+1); i++) nums[l + i] = temp[i];
	return ans;
}


int merge_sort(vector<int>& nums, int l, int r){
	if(r-l+1 == 1) return 0;
	int ans = 0, mid = l + (r-l)/2;
	ans += merge_sort(nums, l, mid);
	ans += merge_sort(nums, mid+1, r);
	ans += merge(nums, l, mid, r);

	return ans;
}

int getSubsCount(string s){
	vector<int> nums;
	for(auto& c : s){
		int n = c-'0';
		nums.push_back(n==0?-1:n);
	}

	vector<int> pre(nums.size(), 0);
	int sum = 0, ans = 0;

	for(int i = 0; i < nums.size(); i++){
		sum += nums[i];
		pre[nums.size()-i-1] = sum;
		if(pre[nums.size()-i-1] > 0) ans++;
	}

	ans += merge_sort(pre, 0, pre.size()-1);

	return ans;
}



// Driver Code
int main()
{

	// Given Input
	string input;
    cin>>input;

	// Function Call
	int ans = getSubsCount(input);

	cout << ans << endl;

	return 0;
}
