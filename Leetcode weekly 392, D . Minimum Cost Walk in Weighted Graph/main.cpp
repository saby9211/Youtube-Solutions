class Solution {
public:
    #define pb push_back
    typedef vector<int> vi;

    vi p, sz, And;

    int get(int a){
        if(a == p[a]){
            return a;
        }
        return p[a] = get(p[a]);
    }

    void merge(int a, int b, int w){
        a = get(a);
        b = get(b);

        if(sz[a] < sz[b]){
            swap(a, b);
        }
        And[a] &= And[b];
        And[a] &= w;
        sz[a] += sz[b];
        p[b] = a;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        long long temp = (1 << 30);
        temp--;
        // cout<<temp<<'\n';
        int m = edges.size();
        p.resize(n+1);
        sz.resize(n+1);
        And.resize(n+1);

        for(int i=0; i<n; i++){
            p[i] = i;
            sz[i] = 1;
            And[i] = temp;
        }

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(get(u) != get(v)){
                merge(u, v, w);
            }
            else{
                // beacause I have to consider all the edge weights of a component
                And[get(u)] &= w; 
            }
        }

        vi ans;
        for(auto q : query){
            int s = q[0];
            int t = q[1];
            if(get(s) != get(t)){
                ans.pb(-1);
            }
            else{
                ans.pb(And[get(s)]);
            }
        }
        return ans;
    }
};