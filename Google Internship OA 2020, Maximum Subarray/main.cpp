// google oa Q2
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


int main() {
	ll t = 1;
	cin>>t;
	while(t--) {
		ll n, k;
		cin>>n>>k;
		vector<ll> a(n);
		for(ll i=0; i<n; i++) {
			cin>>a[i];
			if(a[i] > k) {
				a[i] = 1;
			}
			else if(a[i] < k) {
				a[i] = -1;
			}
			else {
				a[i] = 0;
			}
		}

		ll sum = accumulate(a.begin(), a.end(), 0); // sum of original array
		if(sum == 0) {
			cout<<n<<"\n"; // if sum == 0 i.e number of 1s == number of -1s, i.e no need to delete subarray, original array is the resulting maximum len array
			continue;
		}
		unordered_map<ll, ll> mp; // {key -> val} : prefix sum -> last index of that prefix sum to minimize length of subarray to be deleted
		mp[0] = -1;
		ll s = 0;
		ll ans = 1e9;
		for(ll i=0; i<n; i++) {
			s += a[i];
			if(mp.find(s - sum) != mp.end()) {
				ans = min(ans, i - mp[s - sum]);
			}
			mp[s] = i;
		}
		cout<<n - ans<<"\n";
	}


	return 0;
}