#include<bits/stdc++.h>
using namespace std;


/*........... templates and typedefs.........*/
#define pb push_back

typedef long long ll;

/*...............................................................................*/

// CODE HERE

vector<ll> bd; // containing binary decimals upto 10^5 + 5

int main(){
// fast input , output
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<ll> q;

    q.push(1);
    while(!q.empty()){
        ll front = q.front();
        q.pop();
        if(front != 1){
            bd.pb(front);
        }

        if(front > 1e5 + 5){
            break;
        }

        q.push(front*10);
        q.push(front*10 + 1);
    }
    reverse(bd.begin(), bd.end());
    // for(auto x : bd){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";


    ll t = 1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string ans = "NO";
        
        for(auto x : bd){
            while(n % x == 0){
                n /= x;
            }
        }
        if(n == 1){
            ans = "YES";
        }
        cout<<ans<<"\n";
    }

    return 0;
}