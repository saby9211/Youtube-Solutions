#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    
        ll n;
        cin >> n;

        vector<ll> arr(n);

        for(ll i=0; i<n; i++) {
            cin >> arr[i];
            if(arr[i] == 0) {
                cout << -1 << "\n";
                return 0;
            }
        }

        unordered_map<ll, ll> freq; // freq : prime, freq

        for(auto x : arr) {
            ll y = x;

            while(y % 2 == 0) {
                y /= 2;
                freq[2]++;
            }

            for(ll i =3; i*i <= y; i+=2) {
                while(y % i == 0) {
                    y /= i;
                    freq[i]++;
                }
            }

            if(y != 1) {
                freq[y]++;
            }
        }

        ll mini = min(freq[2], freq[5]);

        freq[2] -= mini;
        freq[5] -= mini;

        ll curr = 1;

        for(auto it : freq) {
            for(ll j=0; j<it.second; j++) {
                curr = curr * it.first;
                curr %= 10;
            }
        }

        cout << curr << "\n";
    

    return 0;
}


// More Optimal
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binpow(ll a, ll b) {
    ll res = 1;

    while(b > 0) {
        if(b & 1) {
            res = (res * 1LL * a) % 10;
        }
        a = (a * a) % 10;

        b >>= 1;
    }
    return res;
}

int main() {
    

   
        ll n;
        cin >> n;

        vector<ll> a(n);

        for(ll i=0; i<n; i++) {
            cin >> a[i];
            if(a[i] == 0) {
                cout << -1 <<"\n";
                return 0;
            }
        }

        unordered_map<ll, ll> mp;

        for(auto x : a) {
            ll y = x;

            while(y % 2 == 0) {
                y /= 2;

                mp[2]++;
            }

            for(ll i = 3; i*i <= y; i+=2) {
                while(y % i == 0) {
                    y /= i;

                    mp[i]++;
                }
            }
            if(y !=1) {
                mp[y]++;
            }
        }

        ll mini = min(mp[2], mp[5]);

        mp[2] -= mini, mp[5] -= mini;

        ll curr = 1;

        for(auto it : mp) {
            curr = (curr * binpow(it.first, it.second)) % 10;
        }

        

        if(curr == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << curr % 10 << "\n";
        }
    


    return 0;
}