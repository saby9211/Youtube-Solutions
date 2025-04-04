#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

int main() {
    
    ll n,d;
    cin >> n >> d;
    
    vector<ll> arr(n);
    
    for(auto &x : arr) cin >> x;
    
    sort(arr.begin(), arr.end());
    
    auto check = [&] (ll k) -> bool {
        ll curr_time = 0;
        ll cnt = 1;
        ll prev_x = 0;
        for(auto x : arr) {
            ll time_needed = x - prev_x + 2;
            
            if(curr_time + time_needed <= k) {
                curr_time += time_needed;
                prev_x = x;
            }
            else {
                cnt++;
                curr_time = x + 2;
                prev_x = x;
            }
        }
        return cnt <= d;
    };
    
    
    ll low = arr.back() + 2, high = 1e17, ans = -1;
    
    while(high >= low) {
        ll mid = low + (high - low) / 2;
        
        if(check(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
