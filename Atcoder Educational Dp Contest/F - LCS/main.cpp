#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


/*........... templates and typedefs.........*/
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

/*................... Some important functions ........ */

const ll mod = 1e9 + 7;
ll binpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = (res*1LL*a)%mod;
        }
        a = (a*1LL*a)%mod;
        b >>= 1;
    }
    return res;
}

ll ncr(ll n, ll r){
    ll fact[n+1];
    ll inv[n+1];
    fact[0] = 1;
    inv[0] = 1;
    for(ll i=1; i<=n; i++){
        fact[i] = (i*fact[i-1])%mod;
    }
    for(ll i=1; i<=n; i++){
        inv[i] = binpow(fact[i], mod-2);
    }
   
    
    if(r > n) return 0;
    return ((fact[n]*inv[r])%mod*inv[n-r])%mod;
}   



ll calc_hash(string const& s) {
    const ll p = 31;
    const ll m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
/*......................... Bit manupulation tricks ...................*/

// a|b = a⊕b + a&b
// a⊕(a&b) = (a|b)⊕b
// b⊕(a&b) = (a|b)⊕a
// (a&b)⊕(a|b) = a⊕b
 
 
// a+b = a|b + a&b
// a+b = a⊕b + 2(a&b)
 
// a-b = (a⊕(a&b))-((a|b)⊕a)
// a-b = ((a|b)⊕b)-((a|b)⊕a)
// a-b = (a⊕(a&b))-(b⊕(a&b))
// a-b = ((a|b)⊕b)-(b⊕(a&b))


/*...............................................................................*/

// CODE HERE

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

ll Dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
ll Dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};


void solve(){
    string s, t;
    cin >> s >> t;

    ll n = s.length(), m = t.length();

    vvll dp(n+1, vll(m+1, -1));

    function<ll(ll, ll)> rec = [&] (ll i, ll j) -> ll {
        // pruning

        // base case
        if(i >= n || j >= m) {
            return 0;
        }
        // cache check
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        // compute
        ll ans = 0;
        ans = max(ans, rec(i, j+1));
        ans = max(ans, rec(i+1, j));

        if(s[i] == t[j]) {
            ans = max(ans, 1 + rec(i + 1, j + 1));
        }
        // save and return

        return dp[i][j] = ans;
    };

    string ans = "";

    function<void(ll, ll)> printsol = [&] (ll i, ll j) {
        if(i == n || j == m) {
            return;
        }

        if(rec(i, j) == rec(i + 1, j)) {
            printsol(i+1, j);
        }

        else if(rec(i, j) == rec(i, j+1)) {
            printsol(i, j+1);
        }

        else {
            ans += s[i];
            printsol(i+1, j+1);
        }
    };

    ll lcs = rec(0, 0);

    printsol(0, 0);
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