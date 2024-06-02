#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		// dfs(u, par, ans) : returns longest path from u to leaf node
		int dfs1(int u, int par, int &ans, vector<vector<int>> &adj){
			// base case
			if(adj[u].empty()){ // leaf node
				return 1;
			}
			int longest = 0, seclongest = 0; // for storing 2 longest path wali branches
			for(auto v : adj[u]){
				int path = dfs1(v, u, ans, adj);
				ans = max(ans, path); // updating ans for chld
				if(path > longest){ // updating two longest path branches
					seclongest = longest;
					longest = path;
				}
				else if(path > seclongest){
					seclongest = path;
				}
			}

			ans = max(ans, 1 + longest + seclongest); // updating ans for curr node
			return 1 + longest; // returning longest path from curr node to leaf node
		}
		int dfs2(int u, int par, int &ans, vector<vector<int>> &adj, string &s){
			
			// base case

			if(adj[u].empty()){ // leaf node
				return 1;
			}

			int longest = 0, seclongest = 0;
			for(auto v : adj[u]){

				int path = dfs2(v, u, ans, adj, s);
				ans = max(ans, path); // updating ans for child

				if(s[u] == s[v]){ // skipping non valid branches , since value[u] == value[v]
					continue;
				}
				if(path > longest){
					seclongest = longest; // updating longest path branches
					longest = path;
				}
				else if(path > seclongest){
					seclongest = path;
				}
			}
			ans = max(ans, 1 + longest + seclongest);
			return 1 + longest;

		}
	public:
		int diameter(vector<int> &parent){
			// create adj list
			int n = parent.size();
			vector<vector<int>> adj(n);
			// leave node 0 as it is the root
			for(int i=1; i<n; i++){
				int u = parent[i];
				int v = i;
				adj[u].push_back(v);
			}
			int ans = 1;
			dfs1(0, -1, ans, adj);
			return ans;

		}
		int longestPath(vector<int>& parent, string s) {
        	// create adj list
			int n = parent.size();
			vector<vector<int>> adj(n);
			// leave node 0 as it is the root
			for(int i=1; i<n; i++){
				int u = parent[i];
				int v = i;
				adj[u].push_back(v);
			}
			int ans = 1;
			dfs2(0, -1, ans, adj, s);
			return ans;
    	}
};


int main(){
	int t = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> parent(n);
		for(int i=0; i<n; i++){
			cin>>parent[i];
		}
		string s;
		cin>>s;
		Solution obj;
		cout<<obj.diameter(parent)<<"\n";
		cout<<obj.longestPath(parent, s)<<"\n";
	}

	return 0;
}