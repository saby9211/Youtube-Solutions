// Google Intern OA 2021
// Q2
#include<bits/stdc++.h>
using namespace std;

int main() {

	int t = 1;
	cin>>t;
	while(t--) {
		int q;
		cin>>q;
		vector<pair<int, int>> queries; // for storing queries
		for(int i=0; i<q; i++) {
			int a, x;
			cin>>a>>x;
			queries.push_back({a, x});
		}

		vector<int> ans;
		int suffxor = 0; // to store suffix xor from curr query
		for(int i=queries.size() - 1; i>=0; i--) {
			pair<int, int> currquery = queries[i];
			
			int a = currquery.first;
			int x = currquery.second;
			
			if(a == 0) {
				ans.push_back(suffxor ^ x); // as newly inserted element will get xored with suffix xor from that query
			}
			else {
				suffxor ^= x; // suffxor will get updated for query : 1 , X
			}
		}
		ans.push_back(suffxor ^ 0); // as 0 was also there in list initially

		sort(ans.begin(), ans.end()); // last step

		for(auto ele : ans) {
			cout<<ele<<" ";
		}
		cout<<"\n";
	}


	return 0;
}