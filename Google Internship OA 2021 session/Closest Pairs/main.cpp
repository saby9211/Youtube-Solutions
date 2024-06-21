// Google Intern OA 2021
// Q1
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {

	ll t = 1;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;

		vector<vector<ll>> adj(n+1);
		vector<ll> vis(n+1, 0);
		vector<ll> ans(n+1);
		vector<ll> val(n+1);
		

		for(ll i=1; i<=n; i++) {
			cin>>val[i];
		}

		for(ll i=1; i<=n-1; i++) {
			ll u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		vector<ll> path;
		// path vector will store all the nodes(ancestors) of curr node
		function<void(ll, vector<ll> &)> dfs = [&] (ll node, vector<ll> &path) {
			vis[node] = 1;
			ll sz = path.size();

			bool flag = false;

			for(ll i=sz-1; i>=0; i--) {
				if(__gcd(val[path[i]], val[node]) == 1) {
					ans[node] = path[i];
					flag = true; // valid ancestor is there
					break;
				}
			}

			if(!flag) { // no valid ancestor is there
				ans[node] = -1;
			}

			path.push_back(node);
			for(auto v : adj[node]) {
				if(!vis[v]) {
					dfs(v, path);
				}
			}

			path.pop_back(); // removing curr node from ancestor path, while returning to prev dfs call
		};

		dfs(1, path);

		for(ll i=1; i<=n; i++) {
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}