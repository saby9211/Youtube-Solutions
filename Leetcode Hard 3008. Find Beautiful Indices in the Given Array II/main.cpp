// problem I
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length(), m1 = a.length(), m2 = b.length();
        vector<int> arr, brr;
        for(int i=0; i<= n-m1; i++){
            if(s.substr(i, m1) == a){
                arr.push_back(i);
            }
        }
        for(int j=0; j<=n-m2; j++){
            if(s.substr(j, m2) == b){
                brr.push_back(j);
            }
        }
        // step3
        vector<int> ans;
        for(auto i : arr){
            auto it = lower_bound(brr.begin(), brr.end(), i-k);
            if(it != brr.end() && *it <= i + k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Problem II
class Solution {
public:
    vector<int> kmp(string &s, string &pat){
        string ttl = pat + "#" + s;
        int n = ttl.length(), m = pat.length();
        vector<int> pi(n, 0);
        for(int i=1; i<n; i++){
            int j = pi[i-1];
            while(j > 0 && ttl[i] != ttl[j]){
                j = pi[j-1];
            }
            if(ttl[i] == ttl[j]){
                j++;
            }
            pi[i] = j;
        }
        vector<int> ans; // which will help me to store the matching indices
        for(int i=m+1; i<n; i++){
            if(pi[i] == m){
                ans.push_back(i-2*m);
            }
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> arr = kmp(s, a);
        vector<int> brr = kmp(s, b);
        // step3;
        vector<int> ans;
        for(auto i : arr){
            auto it = lower_bound(brr.begin(), brr.end(), i-k);
            if(it != brr.end() && *it <= i + k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};