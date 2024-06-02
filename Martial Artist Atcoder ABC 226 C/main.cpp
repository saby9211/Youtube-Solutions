#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


/*........... templates and typedefs.........*/


typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
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

/*...............................................................................*/

// CODE HERE





void solve(){
    ll n, k;
    cin >> n;
    vector<ll> adj[n+1], t(n+1);
    vector<ll> vis(n+1, 0);
    for(ll i = 1; i <= n; i ++){
        cin >> t[i];
        cin >> k;
        for(ll j=1; j<=k; j ++){
            ll v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    ll ans = 0;
    queue<ll> q;
    q.push(n);
    ans += t[n];
    vis[n] = true;
    while(q.size()){
        ll front = q.front();
        q.pop();
        for(auto v : adj[front]){
             if(!vis[v]){
                q.push(v);
                ans += t[v];
                vis[v] = true;
             }
        }

    }
    cout << ans << '\n';
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test = 1;
    //cin>>t;
    while(test--){
        solve();
    }

    return 0;
}