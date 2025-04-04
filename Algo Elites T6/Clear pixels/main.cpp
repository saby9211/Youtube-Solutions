#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(){
    ll n;
    cin >> n;

    vector<ll> pixel(n);

    for(ll i=0; i<n; i++) {
        cin >> pixel[i];
    }

    vector<ll> left_peeks(n), right_peeks(n);

    ll k = 0;
    for(ll i=0; i<n; i++) {
        k++;
        left_peeks[i] = min(k, pixel[i]);
    }
    k = 0;
    for(ll i=n-1; i>=0; i--) {
        k++;
        right_peeks[i] = min(k, pixel[i]);
    }

    ll mountain = 0;

    for(ll i=0; i<n; i++) {
        mountain = max(mountain, min(left_peeks[i], right_peeks[i]));
    }

    ll sum = accumulate(pixel.begin(), pixel.end(), 0LL);

    cout << sum - mountain * mountain << "\n";
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}