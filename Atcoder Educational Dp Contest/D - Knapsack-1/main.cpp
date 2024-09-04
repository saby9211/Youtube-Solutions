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


ll dp[105][100005];

// dp[idx][wtaken] : max sum of vals Taro can achieve in [idx .... n-1] such that wtaken has already been picked

ll rec(ll idx, ll wtaken, vector<ll> &w, vector<ll> &v, ll W) {
    // pruning

    // base case
    if(idx == w.size()) {
        return 0;
    }
    // cache check
    if(dp[idx][wtaken] != -1) {
        return dp[idx][wtaken];
    }
    // compute
    ll ans = 0;

    // not take
    ans = max(ans, rec(idx + 1, wtaken, w, v, W));

    // taking 

    if(wtaken + w[idx] <= W) {
        ans = max(ans, v[idx] + rec(idx + 1, wtaken + w[idx], w, v, W));
    }
    // save and return
    return dp[idx][wtaken] = ans;
}


void solve(){
    ll n, W;
    cin >> n >> W;

    vector<ll> w(n);
    vector<ll> v(n);

    for(ll i=0; i<n; i++) {
        cin >> w[i] >> v[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << rec(0, 0, w, v, W) << "\n";


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