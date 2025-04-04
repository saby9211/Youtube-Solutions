#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin >> s;

    ll x = 0, y = 0;
    ll mn = 0, mx = 0;

    for(ll i=0; i<s.length(); i++) {
        if(s[i] == 'N') {
            y++;
        }
        else {
            if(s[i] == 'E') {
                x++;
            }
            else {
                x--;
            }

            mn = min(mn, x);
            mx = max(mx, x);
        }
    }

    ll cost1 = y - x + 2 * (mx + 1);
    ll cost2 = x + y - 2 * (mn - 1);

    string ans = "";

    if(cost1 < cost2) {
        while(x <= mx) {
            ans += "E";
            x++;
        }

        while(y > 0) {
            ans += "S";
            y--;
        }

        while(x != 0) {
            ans += "W";
            x--;
        }
    }
    else {
        while(x >= mn) {
            ans += "W";
            x--;
        }
        while(y > 0) {
            ans += "S";
            y--;
        }
        while(x != 0) {
            ans += "E";
            x++;
        }
    }

    cout << ans << "\n";

}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}