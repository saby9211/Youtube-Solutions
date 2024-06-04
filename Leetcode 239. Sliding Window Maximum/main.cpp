#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // code here
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for(int i=0; i<n; i++){
        	while(!dq.empty() && nums[dq.back()] < nums[i]){
        		dq.pop_back();
        	}
        	dq.push_back(i);
        	if(dq.front() == i-k){
        		dq.pop_front();
        	}
        	if(i >= k-1){
        		ans.push_back(nums[dq.front()]);
        	}
        }
        return ans;
    }
};


int main(){
	int t = 1;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int> nums(n);
		for(int i=0; i<n; i++){
			cin>>nums[i];
		}
		Solution obj;
		vector<int> ans = obj.maxSlidingWindow(nums, k);
		for(auto x : ans){
			cout<<x<<" ";
		}
		cout<<"\n";
	}


	return 0;
}