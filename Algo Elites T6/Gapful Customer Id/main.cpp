#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    ll n;
    cin >> n;
    
    ll left = 1e9;
    
    for(ll i=100; i <= n; i++) {
        string s = to_string(i);
        ll num = stoll(s.substr(0, 1) + s.substr(s.length()-1));
        if(i % num == 0) {
            left = i;
        }
    }
    ll right = -1e9;
    for(ll i  = max(n, 100LL); i <= 1e5; i++) {
        string s = to_string(i);
        ll num = stoll(s.substr(0, 1) + s.substr(s.length()-1));
        if(i % num == 0) {
            right = i;
            break;
        }
    }
    
    if(n - left < right - n) {
        cout << left << "\n";
    }
    else if(right - n < n - left) {
        cout << right << "\n";
    }
    else {
        cout << left << "\n";
    }
    
    return 0;
}
