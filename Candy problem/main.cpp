class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();// number of children
        vector<int> c(n, 1);// ci = 1 -> step1
        // step2

        // traverse from left to right

        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                c[i] = c[i-1] + 1;
            }
        }

        // step3

        // traverse from right to left

        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1] && c[i] <= c[i+1]){
                c[i] = c[i+1] + 1;
            }
        }

        // step4 : count ttl number of candies

        int ans = accumulate(c.begin(), c.end(), 0);
        return ans;

    }
};