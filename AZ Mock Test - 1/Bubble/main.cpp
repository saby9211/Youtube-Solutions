#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[202][202];

int main() {
    ll t = 1;

    cin >> t;

    while(t--) {
        ll n;

        cin >> n;

        vector<ll> nums(n+2);
        nums[0] = 1LL;
        for(ll i=1; i<=n; i++) {
            cin >> nums[i];
        }
        nums[n+1] = 1LL;

        function<ll(ll, ll)> rec = [&] (ll l, ll r) -> ll {
            // pruning
            
            // base case
            if(l > r) {
                return 0;
            }
            // cache check
            if(dp[l][r] != -1) {
                return dp[l][r];
            }
            // compute
            ll ans = 0;

            for(ll k = l; k<=r; k++) {
                ans = max(ans, nums[k] * nums[l-1] * nums[r+1] + rec(l, k-1) + rec(k+1, r)); // Pass j to recursive calls
            }
            // save and return
            return dp[l][r] = ans;
        };

        memset(dp, -1, sizeof(dp));

        ll result = rec(1, n); 

        cout << result << "\n";
    }

    return 0;
}