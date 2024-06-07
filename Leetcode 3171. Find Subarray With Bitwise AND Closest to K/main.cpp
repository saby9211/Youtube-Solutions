#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		int findand(int l, int r, vector<vector<int>> &pref){
        int andval = 0;
        for(int i=0; i<32; i++){
            if(pref[i][r+1] - pref[i][l] == (r - l + 1) && (r - l + 1) > 0){
                andval |= (1 << i);
            }
        }
        return andval;
    }   
    
	public:
		int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> pref(32, vector<int> (n+1, 0)); // 1 based
        for(int i=0; i<32; i++){
            for(int j=1; j<=n; j++){
                pref[i][j] = pref[i][j-1] + (((1 << i) & nums[j-1]) != 0);
            }
        }
        
        int ans = 1e9;
        int l = 0, r;
        for(r=0; r<n; r++){
            while(l < r && findand(l, r, pref) <= k){
                ans = min(ans, abs(findand(l, r, pref) - k)); // where k >= andval
                l++;
            }
            // where k <= andval
            ans = min(ans, abs(findand(l, r, pref) - k));
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
		cout<<obj.minimumDifference(nums, k)<<"\n";
	}

	return 0;
}